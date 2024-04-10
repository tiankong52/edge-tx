/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "updatecloudbuild.h"
#include "repo.h"
#include "appdata.h"
#include "eeprominterface.h"
#include "flashfirmwaredialog.h"

constexpr char STATUS_UNKNOWN[]            {"STATUS_UNKNOWN"};
constexpr char STATUS_WAITING_FOR_BUILD[]  {"WAITING_FOR_BUILD"};
constexpr char STATUS_BUILD_IN_PROGRESS[]  {"BUILD_IN_PROGRESS"};
constexpr char STATUS_BUILD_SUCCESS[]      {"BUILD_SUCCESS"};
constexpr char STATUS_BUILD_ERROR[]        {"BUILD_ERROR"};

UpdateCloudBuild::UpdateCloudBuild(QWidget * parent) :
  UpdateInterface(parent, CID_CloudBuild, tr("CloudBuild"), Repo::REPO_TYPE_BUILD,
                  QString("https://cloudbuild.edgetx.org/api"), "nightly"),
  m_objBody(nullptr),
  m_docResp(nullptr)
{
  init(); // call after UpdateInterface ctor due to virtual functions
}

UpdateCloudBuild::~UpdateCloudBuild()
{
  if (m_objBody)
    delete m_objBody;
  if (m_docResp)
    delete m_docResp;
}

void UpdateCloudBuild::assetSettingsInit()
{
  if (!isSettingsIndexValid())
    return;

  g.component[id()].initAllAssets();

  ComponentAssetData &cad = g.component[id()].asset[0];

  cad.desc("binary");
  cad.processes((UPDFLG_Common_Asset | UPDFLG_AsyncInstall | UPDFLG_Build) &~ UPDFLG_Decompress);
  cad.flags(cad.processes() | UPDFLG_CopyFiles | UPDFLG_Locked);
  cad.filterType(UpdateParameters::UFT_Exact);
  cad.filter("%FWFLAVOUR%");
  cad.destSubDir("FIRMWARE");
  cad.copyFilterType(UpdateParameters::UFT_Pattern);
  cad.copyFilter("^%FWFLAVOUR%-%LANGUAGE%.*-%RELEASE%\\.bin$");
  cad.maxExpected(1);

  qDebug() << "Asset settings initialised";
}

bool UpdateCloudBuild::addBuildLanguage(const QString & flag, const QJsonArray & values, QJsonArray & buildFlags)
{
  QString val;

  if (values.contains(params()->language.toLower()))
    val = params()->language.toLower();
  else if (values.contains(params()->language.toUpper()))
    val = params()->language.toUpper();
  else {
    status()->reportProgress(tr("Radio profile language '%1' not supported").arg(params()->language), QtCriticalMsg);
    return false;
  }

  addBuildFlag(buildFlags, flag, val);

  return true;
}

bool UpdateCloudBuild::addBuildFai(const QString & flag, const QJsonArray & values, QJsonArray & buildFlags)
{
  if (!m_profileOpts.contains("faichoice") && !m_profileOpts.contains("faimode"))
    return true;

  if (!values.contains("CHOICE") && !values.contains("YES")) {
    status()->reportProgress(tr("fai_mode values do not contain CHOICE and YES"), QtCriticalMsg);
    return false;
  }

  QString val;

  if (m_profileOpts.contains("faichoice"))
    val = "CHOICE";
  else if (m_profileOpts.contains("faimode"))
    val = "YES";

  m_buildFlags.append(QString("-%1").arg("fai"));
  addBuildFlag(buildFlags, flag, val);

  return true;
}

void UpdateCloudBuild::addBuildFlag(QJsonArray & buildFlags, const QString & flag, const QString & val)
{
  QJsonObject bldFlag;
  bldFlag.insert("name", flag);
  bldFlag.insert("value", val);
  buildFlags.append(QJsonValue(bldFlag));
}

bool UpdateCloudBuild::arrayExists(const QJsonObject & parent, const QString child)
{
  return !parent.value(child).isUndefined() && parent.value(child).isArray();
}

int UpdateCloudBuild::asyncInstall()
{
  status()->reportProgress(tr("Write firmware to radio: %1").arg(g.currentProfile().burnFirmware() ? tr("true") : tr("false")), QtDebugMsg);

  if (!g.currentProfile().burnFirmware())
    return true;

  status()->progressMessage(tr("Install"));

  repo()->assets()->setFilterFlags(UPDFLG_AsyncInstall);
  status()->reportProgress(tr("Asset filter applied: %1 Assets found: %2").arg(updateFlagsToString(UPDFLG_AsyncInstall)).arg(repo()->assets()->count()), QtDebugMsg);

  if (repo()->assets()->count() < 1)
    return true;

  if (repo()->assets()->count() != params()->assets.at(0).maxExpected) {
    status()->reportProgress(tr("Expected %1 asset for install but %2 found").arg(params()->assets.at(0).maxExpected).arg(repo()->assets()->count()), QtCriticalMsg);
    return false;
  }

  QString destPath = updateDir();

  if (!repo()->assets()->subDirectory().isEmpty())
    destPath.append("/" % repo()->assets()->subDirectory());

  const UpdateParameters::AssetParams &ap = params()->assets.at(0);

  QString pattern(params()->buildFilterPattern(ap.copyFilterType, ap.copyFilter));
  QRegularExpression filter(pattern, QRegularExpression::CaseInsensitiveOption);

  QDirIterator it(destPath);

  bool found = false;

  while (it.hasNext())
  {
    QFileInfo file(it.next());

    if ((!filter.pattern().isEmpty()) && (!file.fileName().contains(filter)))
      continue;

    destPath.append("/" % file.fileName());
    found = true;
    break;
  }

  if (!found) {
    status()->reportProgress(tr("Firmware not found in %1 using filter %2").arg(destPath).arg(filter.pattern()), QtCriticalMsg);
    return false;
  }

  g.currentProfile().fwName(destPath);

  int ret = QMessageBox::question(status()->progress(), CPN_STR_APP_NAME, tr("Write the updated firmware to the radio now ?"), QMessageBox::Yes | QMessageBox::No);
  if (ret == QMessageBox::Yes) {
    FlashFirmwareDialog *dlg = new FlashFirmwareDialog(this);
    dlg->exec();
    dlg->deleteLater();
  }

  return true;
}

bool UpdateCloudBuild::buildFlaggedAsset(const int row)
{
  m_buildFlags.clear();
  m_jobStatus.clear();
  m_profileOpts.clear();

  m_radio = repo()->assets()->name(row);

  status()->progressMessage(tr("Building firmware target %1").arg(m_radio));

  QJsonObject target;

  network()->saveJsonObjToFile(*repo()->config(), QString("%1/targets.txt").arg(downloadDir()));

  if (!objectExists(*repo()->config(), "targets")) {
    status()->reportProgress(tr("Unexpected format for build targets meta data"), QtCriticalMsg);
    return false;
  }

  const QJsonObject &targets = repo()->config()->value("targets").toObject();
  target = targets.value(m_radio).toObject();

  if (target.isEmpty()) {
    status()->reportProgress(tr("No build support for target %1").arg(m_radio), QtCriticalMsg);
    return false;
  }

  network()->saveJsonObjToFile(target, QString("%1/%2_target.txt").arg(downloadDir()).arg(m_radio));

  QJsonArray arrTags = target.value("tags").toArray();

  if (arrTags.isEmpty()) {
    status()->reportProgress(tr("Build target %1 has no valid tags").arg(m_radio), QtCriticalMsg);
    return false;
  }

  Firmware *fw = getCurrentFirmware();
  m_profileOpts = fw->getId().split("-");
  // [0] = edgetx
  // [1] = radio id
  // [last] = language code

  // add tags based on radio profile and do not duplicate defaults
  if (m_profileOpts.contains("bluetooth") && !arrTags.contains(QJsonValue("bluetooth")))
    arrTags.append(QJsonValue("bluetooth"));

  //===============================
  //  TODO tags more to be added!!!
  //===============================

  const QJsonObject flags = repo()->config()->value("flags").toObject();

  if (flags.isEmpty()) {
    status()->reportProgress(tr("No flag entries found"), QtCriticalMsg);
    return false;
  }

  QJsonArray arrBuildFlags;
  QStringList flagKeys = flags.keys();

  for (auto i = flagKeys.cbegin(), end = flagKeys.cend(); i != end; ++i) {
    const QJsonObject &flag = flags.value(*i).toObject();
    const QJsonArray &fvals = flag.value("values").toArray();

    if (*i == "language") {
      if (!addBuildLanguage(*i, fvals, arrBuildFlags))
        return false;
    }
    else if (*i == "fai_mode") {
      if (!addBuildFai(*i, fvals, arrBuildFlags))
        return false;
    }

  //===============================
  //  TODO flags more to be added!!!
  //===============================

  }

  if (m_objBody)
    delete m_objBody;

  m_objBody = new QJsonObject();
  m_objBody->insert("release", QJsonValue(params()->releaseUpdate));
  m_objBody->insert("target", QJsonValue(m_radio));
  m_objBody->insert("flags", QJsonValue(arrBuildFlags));

  QJsonDocument *docBody = new QJsonDocument(*m_objBody);

  if (m_docResp)
    delete m_docResp;

  m_docResp = new QJsonDocument();

  m_buildStartTime = QTime::currentTime();

  network()->saveJsonDocToFile(docBody, QString("%1/%2_body.txt").arg(downloadDir()).arg(m_radio));

  network()->submitRequest(tr("Submit firmware build"), repo()->urlJobs(), docBody, m_docResp);

  network()->saveBufferToFile(QString("%1/%2_buffer.txt").arg(downloadDir()).arg(m_radio));

  if (!network()->isSuccess()) {
    status()->reportProgress(tr("Failed to initiate build job"), QtCriticalMsg);
    return false;
  }

  if (!m_docResp->isObject()) {
    status()->reportProgress(tr("Unexpected response format when submitting build job"), QtCriticalMsg);
    return false;
  }

  network()->saveJsonDocToFile(m_docResp, QString("%1/%2_response.txt").arg(downloadDir()).arg(m_radio));

  const QJsonObject &obj = m_docResp->object();

  if (stringExists(obj, "error")) {
    status()->reportProgress(tr("Build error: %1").arg(obj.value("error").toString()), QtCriticalMsg);
    return false;
  }
  else if (obj.value("target").toString() != m_radio || obj.value("release").toString() != params()->releaseUpdate) {
    status()->reportProgress(tr("Process status not returned when submitting build job"), QtCriticalMsg);
    return false;
  }
  else {
    m_jobStatus = obj.value("status").toString(QString(STATUS_UNKNOWN));
  }

  if (isStatusInProgress())
    waitForBuildFinish();

  status()->reportProgress(tr("Firmware build finished with status %1").arg(m_jobStatus), QtDebugMsg);

  if (m_jobStatus == QString(STATUS_BUILD_SUCCESS) && setAssetDownload())
    return true;

  return false;
}

void UpdateCloudBuild::cancel()
{
  status()->reportProgress(tr("Build firmware cancelled"), QtWarningMsg);
  cleanup();
}

void UpdateCloudBuild::checkStatus()
{
  if (m_buildStartTime.secsTo(QTime::currentTime()) > 180) {
    status()->reportProgress(tr("Build firmware timeout"), QtWarningMsg);
    cleanup();
  }

  getStatus();

  if (!isStatusInProgress())
    cleanup();

}

void UpdateCloudBuild::cleanup()
{
  if (m_timer.isActive())
    m_timer.stop();

  if (m_eventLoop.isRunning())
   m_eventLoop.quit();
}

bool UpdateCloudBuild::getStatus()
{
  m_jobStatus = QString(STATUS_UNKNOWN);
  QJsonDocument *docBody = new QJsonDocument(*m_objBody);

  if (m_docResp)
    delete m_docResp;

  m_docResp = new QJsonDocument();
  network()->submitRequest(tr("Submit get build status"), repo()->urlStatus(), docBody, m_docResp);

  network()->saveJsonDocToFile(m_docResp, QString("%1/%2_status_%3.txt").arg(downloadDir()).arg(m_radio).arg(QTime::currentTime().toString("hhmmss")));

  if (m_docResp->isObject())
    m_jobStatus = m_docResp->object().value("status").toString(QString(STATUS_UNKNOWN));

  if (m_jobStatus == QString(STATUS_UNKNOWN)) {
    status()->reportProgress(tr("Build status unknown"), QtCriticalMsg);
    return false;
  }

  return true;
}

bool UpdateCloudBuild::isStatusInProgress()
{
  if (m_jobStatus == QString(STATUS_WAITING_FOR_BUILD) || m_jobStatus == QString(STATUS_BUILD_IN_PROGRESS))
    return true;

  return false;
}

bool UpdateCloudBuild::objectExists(const QJsonObject & parent, const QString child)
{
  return !parent.value(child).isUndefined() && parent.value(child).isObject();
}

bool UpdateCloudBuild::setAssetDownload()
{
  //  this format MUST align with the asset copy filter
  QString name = QString("%1-%2%3-%4.bin").arg(m_radio).arg(params()->language.toLower()).arg(m_buildFlags/* has a leading hyphen*/).arg(repo()->releases()->name());

  repo()->assets()->setDownloadName(name.toLower());

  const QJsonObject &obj = m_docResp->object();

  if (arrayExists(obj, "artifacts")) {
    const QJsonArray &artifacts = obj.value("artifacts").toArray();
    if (artifacts.count() > 1) {
      status()->reportProgress(tr("Build status contains %1 artifacts when only 1 expected").arg(artifacts.count()), QtWarningMsg);
    }
    for (int i = 0; i < artifacts.count(); i++) {
      if (artifacts[i].isObject()) {
        const QJsonObject &artifact = artifacts[i].toObject();
        if (stringExists(artifact, "slug") && artifact.value("slug").toString() == "firmware") {
          if (stringExists(artifact, "download_url")) {
            repo()->assets()->setDownloadUrl(artifact.value("download_url").toString());
          }
          else {
            status()->reportProgress(tr("Build status does not contain download url"), QtCriticalMsg);
            return false;
          }
        }
        else {
          status()->reportProgress(tr("Build status does not contain firmware artifact"), QtCriticalMsg);
          return false;
        }
      }
      else {
        status()->reportProgress(tr("Build status firmware artifact not in expected format"), QtCriticalMsg);
        return false;
      }
    }
  }
  else {
    status()->reportProgress(tr("Build status does not contain artifacts"), QtCriticalMsg);
    return false;
  }

  return true;
}

bool UpdateCloudBuild::stringExists(const QJsonObject & parent, const QString child)
{
  return !parent.value(child).isUndefined() && parent.value(child).isString();
}

void UpdateCloudBuild::waitForBuildFinish()
{
  status()->progressMessage(tr("Waiting for firmware build to finish..."));
  m_timer.setInterval(2000);  // check status every 2 seconds

  connect(this, &UpdateInterface::stop, this, &UpdateCloudBuild::cancel);
  connect(&m_timer, &QTimer::timeout, this, &UpdateCloudBuild::checkStatus);

  m_timer.start();
  m_eventLoop.exec();

  disconnect(this, &UpdateInterface::stop, this, &UpdateCloudBuild::cancel);
  disconnect(&m_timer, nullptr);
}

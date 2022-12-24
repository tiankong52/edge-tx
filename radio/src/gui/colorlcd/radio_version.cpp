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

#include "radio_version.h"
#include "opentx.h"
#include "options.h"
#include "libopenui.h"
#include "fw_version.h"

#if defined(CROSSFIRE)
  #include "mixer_scheduler.h"
#endif

char *getVersion(char *str, PXX2Version version)
{
  if (version.major == 0xFF && version.minor == 0x0F &&
      version.revision == 0x0F) {
    return strAppend(str, "---", 4);
  } else {
    sprintf(str, "%u.%u.%u", (1 + version.major) % 0xFF, version.minor,
            version.revision);
    return str;
  }
}

static const lv_coord_t col_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(2), LV_GRID_TEMPLATE_LAST};
static const lv_coord_t row_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

class VersionDialog : public Dialog
{
  Window*     int_module_name_w;
  StaticText* int_name;
  Window*     int_module_status_w;
  StaticText* int_status;

  Window*     int_rx_name_w;
  StaticText* int_rx_name;
  Window*     int_rx_status_w;
  StaticText* int_rx_status;

  Window*     ext_module_name_w;
  StaticText* ext_name;
  Window*     ext_module_status_w;
  StaticText* ext_status;
  
  Window*     ext_rx_name_w;
  StaticText* ext_rx_name;
  Window*     ext_rx_status_w;
  StaticText* ext_rx_status;
  
 public:
  VersionDialog(Window *parent) :
    Dialog(parent, STR_MODULES_RX_VERSION, rect_t{ 0, 0, 200, 100 })
  {
    memclear(&reusableBuffer.hardwareAndSettings.modules,
             sizeof(reusableBuffer.hardwareAndSettings.modules));
    reusableBuffer.hardwareAndSettings.updateTime = get_tmr10ms();

    // Query modules
    if (isModulePXX2(INTERNAL_MODULE) && IS_INTERNAL_MODULE_ON()) {
      moduleState[INTERNAL_MODULE].readModuleInformation(
          &reusableBuffer.hardwareAndSettings.modules[INTERNAL_MODULE],
          PXX2_HW_INFO_TX_ID, PXX2_MAX_RECEIVERS_PER_MODULE - 1);
    }

    if (isModulePXX2(EXTERNAL_MODULE) && IS_EXTERNAL_MODULE_ON()) {
      moduleState[EXTERNAL_MODULE].readModuleInformation(
          &reusableBuffer.hardwareAndSettings.modules[EXTERNAL_MODULE],
          PXX2_HW_INFO_TX_ID, PXX2_MAX_RECEIVERS_PER_MODULE - 1);
    }

    setCloseWhenClickOutside(true);

    // define grid layout
    FlexGridLayout grid(col_dsc, row_dsc);
    
    // define form
    auto form = &content->form;
    form->setFlexLayout();
    
    // headline "Internal module"
    new StaticText(form, rect_t{}, STR_INTERNAL_MODULE, 0, COLOR_THEME_PRIMARY1);

    // Internal module name
    int_module_name_w = form->newLine(&grid);
    new StaticText(int_module_name_w, rect_t{}, STR_MODULE, 0, COLOR_THEME_PRIMARY1);
    int_name = new StaticText(int_module_name_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);

    // internal module status
    int_module_status_w = form->newLine(&grid);
    new StaticText(int_module_status_w, rect_t{}, STR_STATUS, 0, COLOR_THEME_PRIMARY1);
    int_status = new StaticText(int_module_status_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(int_module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    // internal receiver name
    int_rx_name_w = form->newLine(&grid);
    new StaticText(int_rx_name_w, rect_t{}, STR_RECEIVER, 0, COLOR_THEME_PRIMARY1);
    int_rx_name = new StaticText(int_rx_name_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(int_rx_name_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    // internal reciever status
    int_rx_status_w = form->newLine(&grid);
    new StaticText(int_rx_status_w, rect_t{}, STR_STATUS, 0, COLOR_THEME_PRIMARY1);
    int_rx_status = new StaticText(int_rx_status_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(int_rx_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    // headline "External module"
    new StaticText(form, rect_t{}, STR_EXTERNAL_MODULE, 0, COLOR_THEME_PRIMARY1);

    // external module name
    ext_module_name_w = form->newLine(&grid);
    new StaticText(ext_module_name_w, rect_t{}, STR_MODULE, 0, COLOR_THEME_PRIMARY1);
    ext_name = new StaticText(ext_module_name_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    
    // external module status
    ext_module_status_w = form->newLine(&grid);
    new StaticText(ext_module_status_w, rect_t{}, STR_STATUS, 0, COLOR_THEME_PRIMARY1);
    ext_status = new StaticText(ext_module_status_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(ext_module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    // external receiver name
    ext_rx_name_w = form->newLine(&grid);
    new StaticText(ext_rx_name_w, rect_t{}, STR_RECEIVER, 0, COLOR_THEME_PRIMARY1);
    ext_rx_name = new StaticText(ext_rx_name_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(ext_rx_name_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    // external receiver status
    ext_rx_status_w = form->newLine(&grid);
    new StaticText(ext_rx_status_w, rect_t{}, STR_STATUS, 0, COLOR_THEME_PRIMARY1);
    ext_rx_status = new StaticText(ext_rx_status_w, rect_t{}, "", 0, COLOR_THEME_PRIMARY1);
    lv_obj_add_flag(ext_rx_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

    content->setWidth(LCD_W * 0.8);
    update();
  }

  void update()
  {
    updateModule(INTERNAL_MODULE, 
                 int_name, 
                 int_module_status_w, int_status, 
                 int_rx_name_w, int_rx_name, 
                 int_rx_status_w, int_rx_status);
    updateModule(EXTERNAL_MODULE, 
                 ext_name, 
                 ext_module_status_w, ext_status, 
                 ext_rx_name_w, ext_rx_name, 
                 ext_rx_status_w, ext_rx_status);
    content->updateSize();
  }

  void updateModule(uint8_t module, 
                    StaticText* name, 
                    Window* module_status_w, StaticText* status, 
                    Window* rx_name_w, StaticText* rx_name, 
                    Window* rx_status_w, StaticText* rx_status) {
    // initialize module name with module selection made in model settings
    // initialize to module does not provide status
    // PXX2 will overwrite name
    // CRSF, MPM, NV14 and PXX2 will overwrite status
    name->setText(STR_INTERNAL_MODULE_PROTOCOLS[g_model.moduleData[module].type]);
    lv_obj_add_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

/*
#if defined(CROSSFIRE)
    // CRSF is able to provide status
    if (isModuleCrossfire(module)) {
      char statusText[64];

      auto hz = 1000000 / getMixerSchedulerRealPeriod(module);
      snprintf(statusText, 64, "%d Hz %" PRIu32 " Err", hz, telemetryErrors);
      status->setText(statusText);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
    }
#endif
*/
#if defined(CROSSFIRE)
    // CRSF is able to provide status
    if (isModuleCrossfire(module)) {
      char statusText[64];

      auto period = getMixerSchedulerRealPeriod(module);
      auto divider = getMixerSchedulerDivider(module);
      snprintf(statusText, 64, "p:%d d:%d f:%d", period, divider, 1000000/period);

      status->setText(statusText);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
    }
#endif

#if defined(PCBNV14) && defined(AFHDS2)
    // NV14 AFHDS2A internal module is able to provide FW version
    extern uint32_t NV14internalModuleFwVersion;
    if (isModuleAFHDS2A(module)) {
      sprintf(reusableBuffer.moduleSetup.msg, "FW Ver %d.%d.%d",
              (int)((NV14internalModuleFwVersion >> 16) & 0xFF),
              (int)((NV14internalModuleFwVersion >> 8) & 0xFF),
              (int)(NV14internalModuleFwVersion & 0xFF));
      status->setText(reusableBuffer.moduleSetup.msg);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
    }
#endif

/*
#if defined(MULTIMODULE)
    // MPM is able to provide status
    if (isModuleMultimodule(module)) {
      char MPMstatus[32];
      char statusText[64];
   
      auto hz = 1000000 / getMixerSchedulerRealPeriod(module);
      getMultiModuleStatus(module).getStatusString(MPMstatus);
      
      snprintf(statusText, 64, "%s %d Hz", MPMstatus, hz);
      status->setText(statusText);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
    }
#endif
*/
#if defined(MULTIMODULE)
    // MPM is able to provide status
    if (isModuleMultimodule(module)) {
      char statusText[64];
   
      auto period = getMixerSchedulerRealPeriod(module);
      auto divider = getMixerSchedulerDivider(module);
      snprintf(statusText, 64, "p:%d d:%d f:%d", period, divider, 1000000/period);

      status->setText(statusText);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
    }
#endif




#if defined(PXX2)
    // PXX2 modules are able to provide status
    if (isModulePXX2(module)) {
      char tmp[20];
      
      // PXX2 module name
      name->setText(getPXX2ModuleName(reusableBuffer.hardwareAndSettings.modules[module]
                                      .information.modelID));

      // PXX2 module status
      std::string mod_ver;
      if (reusableBuffer.hardwareAndSettings.modules[module]
              .information.modelID) {

        mod_ver += getVersion(tmp, reusableBuffer.hardwareAndSettings.modules[module]
                          .information.hwVersion);
        mod_ver += " / ";
        mod_ver += getVersion(tmp, reusableBuffer.hardwareAndSettings.modules[module]
                          .information.swVersion);

        static const char *variants[] = {"FCC", "EU", "FLEX"};
        uint8_t variant = reusableBuffer.hardwareAndSettings.modules[module]
                              .information.variant - 1;
        if (variant < DIM(variants)) {
          mod_ver += " ";
          mod_ver += variants[variant];
        }
      }
      status->setText(mod_ver);
      lv_obj_clear_flag(module_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);

      // PXX2 Receivers
      std::string rx_n;
      std::string rx_ver;

      for (uint8_t receiver = 0; receiver < PXX2_MAX_RECEIVERS_PER_MODULE; receiver++) {
        if (reusableBuffer.hardwareAndSettings.modules[module]
                .receivers[receiver]
                .information.modelID) {

          if (!rx_ver.empty()){
            rx_n += "\n";
            rx_ver += "\n";
          }
          
          // Receiver model
          uint8_t modelId = reusableBuffer.hardwareAndSettings.modules[module]
                                .receivers[receiver]
                                .information.modelID;
          rx_n += getPXX2ReceiverName(modelId);

          // Receiver version
          rx_ver += getVersion(tmp, reusableBuffer.hardwareAndSettings.modules[module]
                               .receivers[receiver]
                               .information.hwVersion);
          rx_ver += " / ";
          rx_ver += getVersion(tmp, reusableBuffer.hardwareAndSettings.modules[module]
                               .receivers[receiver]
                               .information.swVersion);
        }
      }

      if (!rx_n.empty() && !rx_ver.empty()) {
        // unhide RX labels
        rx_name->setText(rx_n);
        lv_obj_clear_flag(rx_name_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
        rx_status->setText(rx_ver);
        lv_obj_clear_flag(rx_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
      } else {
        // hide RX labels
        lv_obj_add_flag(rx_name_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(rx_status_w->getLvObj(), LV_OBJ_FLAG_HIDDEN);
      }
    }
#endif
  }

  void checkEvents() override
  {
    if (get_tmr10ms() >= reusableBuffer.hardwareAndSettings.updateTime) {
      // Query modules
      if (isModulePXX2(INTERNAL_MODULE) && IS_INTERNAL_MODULE_ON()) {
        moduleState[INTERNAL_MODULE].readModuleInformation(
            &reusableBuffer.hardwareAndSettings.modules[INTERNAL_MODULE],
            PXX2_HW_INFO_TX_ID, PXX2_MAX_RECEIVERS_PER_MODULE - 1);
      }
      if (isModulePXX2(EXTERNAL_MODULE) && IS_EXTERNAL_MODULE_ON()) {
        moduleState[EXTERNAL_MODULE].readModuleInformation(
            &reusableBuffer.hardwareAndSettings.modules[EXTERNAL_MODULE],
            PXX2_HW_INFO_TX_ID, PXX2_MAX_RECEIVERS_PER_MODULE - 1);
      }
      reusableBuffer.hardwareAndSettings.updateTime = get_tmr10ms() + 500 /* 5s*/;
    }
    update();
    Dialog::checkEvents();
  }
};

RadioVersionPage::RadioVersionPage():
  PageTab(STR_MENUVERSION, ICON_RADIO_VERSION)
{
}

#if defined(PCBNV14)
extern const char* boardLcdType;
#endif

void RadioVersionPage::build(FormWindow * window)
{
  window->setFlexLayout(LV_FLEX_FLOW_COLUMN, lv_dpx(8));
  lv_obj_set_style_pad_all(window->getLvObj(), lv_dpx(8), 0);

  std::string nl("\n");
  std::string version;

  version += fw_stamp + nl;
  version += vers_stamp + nl;
  version += date_stamp + nl;
  version += time_stamp + nl;
  version += "OPTS: ";

  for (uint8_t i = 0; options[i]; i++) {
    if (i > 0) version += ", ";
    version += options[i];
  }

#if defined(PCBNV14) && !defined(SIMU)
  version += nl;
  version += "LCD: ";
  version += boardLcdType;
#endif

  auto txt = new StaticText(window, rect_t{}, version, 0, COLOR_THEME_PRIMARY1);
  lv_obj_set_width(txt->getLvObj(), lv_pct(100));

  // Module and receivers versions
  auto btn = new TextButton(window, rect_t{}, STR_MODULES_RX_VERSION);
  btn->setPressHandler([=]() -> uint8_t {
    new VersionDialog(window);
    return 0;
  });
  lv_obj_set_width(btn->getLvObj(), lv_pct(100));
}

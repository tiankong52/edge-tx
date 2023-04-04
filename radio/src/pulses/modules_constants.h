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

#ifndef _MODULES_CONSTANTS_H_
#define _MODULES_CONSTANTS_H_

#include "storage/yaml/yaml_defs.h"

enum ModuleType {
  MODULE_TYPE_NONE = 0,
  MODULE_TYPE_PPM,
  MODULE_TYPE_XJT_PXX1,
  MODULE_TYPE_ISRM_PXX2,
  MODULE_TYPE_DSM2,
  MODULE_TYPE_CROSSFIRE,
  MODULE_TYPE_MULTIMODULE,
  MODULE_TYPE_R9M_PXX1,  // R9M
  MODULE_TYPE_R9M_PXX2,  // R9M ACCESS
  MODULE_TYPE_R9M_LITE_PXX1,  //R9MLite
  MODULE_TYPE_R9M_LITE_PXX2,  //R9MLP
  MODULE_TYPE_GHOST,
  MODULE_TYPE_R9M_LITE_PRO_PXX2,
  MODULE_TYPE_SBUS,
  MODULE_TYPE_XJT_LITE_PXX2,
  MODULE_TYPE_FLYSKY,
  MODULE_TYPE_LEMON_DSMP,
  MODULE_TYPE_COUNT SKIP,
  MODULE_TYPE_MAX SKIP = MODULE_TYPE_COUNT - 1
};

/* FrSky XJT / ISRM */

enum ModuleSubtypePXX1 {
  MODULE_SUBTYPE_PXX1_OFF = -1,
  MODULE_SUBTYPE_PXX1_ACCST_D16,
  MODULE_SUBTYPE_PXX1_ACCST_D8,
  MODULE_SUBTYPE_PXX1_ACCST_LR12,
  MODULE_SUBTYPE_PXX1_LAST = MODULE_SUBTYPE_PXX1_ACCST_LR12
};

enum ModuleSubtypeISRM_PXX2 {
  MODULE_SUBTYPE_ISRM_PXX2_ACCESS,
  MODULE_SUBTYPE_ISRM_PXX2_ACCST_D16,
  MODULE_SUBTYPE_ISRM_PXX2_ACCST_LR12,
  MODULE_SUBTYPE_ISRM_PXX2_ACCST_D8,
  MODULE_SUBTYPE_ISRM_PXX2_LAST = MODULE_SUBTYPE_ISRM_PXX2_ACCST_D8
};

enum R9MLiteLBTPowerValues {
  R9M_LITE_LBT_POWER_25_8CH = 0,
  R9M_LITE_LBT_POWER_25_16CH,
  R9M_LITE_LBT_POWER_100_16CH_NOTELEM,
  R9M_LITE_LBT_POWER_MAX = R9M_LITE_LBT_POWER_100_16CH_NOTELEM
};

enum R9MFCCPowerValues {
  R9M_FCC_POWER_10 = 0,
  R9M_FCC_POWER_100,
  R9M_FCC_POWER_500,
  R9M_FCC_POWER_1000,
  R9M_FCC_POWER_MAX = R9M_FCC_POWER_1000
};

enum R9MLBTPowerValues {
  R9M_LBT_POWER_25_8CH = 0,
  R9M_LBT_POWER_25_16CH,
  R9M_LBT_POWER_200_16CH_NOTELEM,
  R9M_LBT_POWER_500_16CH_NOTELEM,
  R9M_LBT_POWER_MAX = R9M_LBT_POWER_500_16CH_NOTELEM
};

enum AntennaTypes {
  XJT_INTERNAL_ANTENNA = 0,
  XJT_EXTERNAL_ANTENNA
};

/* FrSky R9M / R9M-Lite & co */

enum ModuleSubtypeR9M {
  MODULE_SUBTYPE_R9M_FCC,
  MODULE_SUBTYPE_R9M_EU,
  MODULE_SUBTYPE_R9M_EUPLUS,
  MODULE_SUBTYPE_R9M_AUPLUS,
  MODULE_SUBTYPE_R9M_LAST=MODULE_SUBTYPE_R9M_AUPLUS
};

enum MMDSM2Subtypes {
  MM_RF_DSM2_SUBTYPE_DSM2_22,
  MM_RF_DSM2_SUBTYPE_DSM2_11,
  MM_RF_DSM2_SUBTYPE_DSMX_22,
  MM_RF_DSM2_SUBTYPE_DSMX_11,
  MM_RF_DSM2_SUBTYPE_AUTO
};



enum ModuleSubtypeDSM2 {
  DSM2_PROTO_LP45,
  DSM2_PROTO_DSM2,
  DSM2_PROTO_DSMX,
};

enum ModuleSubtypeFlysky {
  FLYSKY_SUBTYPE_AFHDS3=0,
  FLYSKY_SUBTYPE_AFHDS2A
};

enum FailsafeModes {
  FAILSAFE_NOT_SET,
  FAILSAFE_HOLD,
  FAILSAFE_CUSTOM,
  FAILSAFE_NOPULSES,
  FAILSAFE_RECEIVER,
  FAILSAFE_LAST SKIP = FAILSAFE_RECEIVER
};

enum AntennaModes {
  ANTENNA_MODE_INTERNAL = -2,
  ANTENNA_MODE_ASK = -1,
  ANTENNA_MODE_PER_MODEL = 0,
  ANTENNA_MODE_EXTERNAL = 1,
  ANTENNA_MODE_FIRST SKIP = ANTENNA_MODE_INTERNAL,
  ANTENNA_MODE_LAST SKIP = ANTENNA_MODE_EXTERNAL
};

enum AfhdsModes {
  AFHDS_SUBTYPE_FIRST,
  AFHDS_SUBTYPE_PWM_IBUS = AFHDS_SUBTYPE_FIRST,
  AFHDS_SUBTYPE_PWM_SBUS,
  AFHDS_SUBTYPE_PPM_IBUS,
  AFHDS_SUBTYPE_PPM_SBUS,
  AFHDS_SUBTYPE_LAST = AFHDS_SUBTYPE_PPM_SBUS
};

#endif // _MODULES_CONSTANTS_H_

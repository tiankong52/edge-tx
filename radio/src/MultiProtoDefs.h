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

#pragma once

//
// Common list of supported Multi protocols (currently reflecting Multi firmware version 1.3.3.20)
// 
enum ModuleSubtypeMulti {
  MODULE_SUBTYPE_MULTI_FIRST = 0,
  MODULE_SUBTYPE_MULTI_FLYSKY = MODULE_SUBTYPE_MULTI_FIRST,
  MODULE_SUBTYPE_MULTI_HUBSAN, //1
  MODULE_SUBTYPE_MULTI_FRSKY,  //2
  MODULE_SUBTYPE_MULTI_HISKY,  //3
  MODULE_SUBTYPE_MULTI_V2X2,   //4
  MODULE_SUBTYPE_MULTI_DSM2,   //5
  MODULE_SUBTYPE_MULTI_DEVO,
  MODULE_SUBTYPE_MULTI_YD717,
  MODULE_SUBTYPE_MULTI_KN,
  MODULE_SUBTYPE_MULTI_SYMAX,
  MODULE_SUBTYPE_MULTI_SLT,    //10
  MODULE_SUBTYPE_MULTI_CX10,
  MODULE_SUBTYPE_MULTI_CG023,
  MODULE_SUBTYPE_MULTI_BAYANG,
  MODULE_SUBTYPE_MULTI_FRSKYX,
  MODULE_SUBTYPE_MULTI_ESky,   //15
  MODULE_SUBTYPE_MULTI_MT99XX,
  MODULE_SUBTYPE_MULTI_MJXQ,
  MODULE_SUBTYPE_MULTI_SHENQI,
  MODULE_SUBTYPE_MULTI_FY326,
  MODULE_SUBTYPE_MULTI_FUTABA, //20
  MODULE_SUBTYPE_MULTI_J6PRO,
  MODULE_SUBTYPE_MULTI_FQ777,
  MODULE_SUBTYPE_MULTI_ASSAN,
  MODULE_SUBTYPE_MULTI_FRSKYV,
  MODULE_SUBTYPE_MULTI_HONTAI, //25
  MODULE_SUBTYPE_MULTI_OLRS,
  MODULE_SUBTYPE_MULTI_FS_AFHDS2A,
  MODULE_SUBTYPE_MULTI_Q2X2,
  MODULE_SUBTYPE_MULTI_WK_2X01,
  MODULE_SUBTYPE_MULTI_Q303,   //30
  MODULE_SUBTYPE_MULTI_GW008,
  MODULE_SUBTYPE_MULTI_DM002,
  MODULE_SUBTYPE_MULTI_CABELL,
  MODULE_SUBTYPE_MULTI_ESKY150,
  MODULE_SUBTYPE_MULTI_H83D,   //35
  MODULE_SUBTYPE_MULTI_CORONA,
  MODULE_SUBTYPE_MULTI_CFLIE,
  MODULE_SUBTYPE_MULTI_HITEC,
  MODULE_SUBTYPE_MULTI_WFLY,
  MODULE_SUBTYPE_MULTI_BUGS,   //40
  MODULE_SUBTYPE_MULTI_BUGS_MINI,
  MODULE_SUBTYPE_MULTI_TRAXXAS,  
  MODULE_SUBTYPE_MULTI_NCC1701,
  MODULE_SUBTYPE_MULTI_E01X,
  MODULE_SUBTYPE_MULTI_V911S,  //45
  MODULE_SUBTYPE_MULTI_GD00X,
  MODULE_SUBTYPE_MULTI_V761,
  MODULE_SUBTYPE_MULTI_KF606,
  MODULE_SUBTYPE_MULTI_REDPINE,
  MODULE_SUBTYPE_MULTI_POTENSIC, //50
  MODULE_SUBTYPE_MULTI_ZSX,
  MODULE_SUBTYPE_MULTI_HEIGHT,
  MODULE_SUBTYPE_MULTI_SCANNER,
  MODULE_SUBTYPE_MULTI_FRSKYX_RX,
  MODULE_SUBTYPE_MULTI_AFHDS2A_RX, //55
  MODULE_SUBTYPE_MULTI_HOTT,
  MODULE_SUBTYPE_MULTI_FX,
  MODULE_SUBTYPE_MULTI_BAYANG_RX,
  MODULE_SUBTYPE_MULTI_PELIKAN,
  MODULE_SUBTYPE_MULTI_TIGER,  //60
  MODULE_SUBTYPE_MULTI_XK,
  MODULE_SUBTYPE_MULTI_XN297DUMP,
  MODULE_SUBTYPE_MULTI_FRSKYX2,
  MODULE_SUBTYPE_MULTI_FRSKY_R9,
  MODULE_SUBTYPE_MULTI_PROPEL, //65
  MODULE_SUBTYPE_MULTI_FRSKYL,
  MODULE_SUBTYPE_MULTI_SKYARTEC,
  MODULE_SUBTYPE_MULTI_ESKY150V2,
  MODULE_SUBTYPE_MULTI_DSM_RX,
  MODULE_SUBTYPE_MULTI_JJRC345, //70
  MODULE_SUBTYPE_MULTI_Q90C,
  MODULE_SUBTYPE_MULTI_KYOSHO,
  MODULE_SUBTYPE_MULTI_RLINK,
  MODULE_SUBTYPE_MULTI_ELRS,
  MODULE_SUBTYPE_MULTI_REALACC, //75
  MODULE_SUBTYPE_MULTI_OMP,
  MODULE_SUBTYPE_MULTI_MLINK,
  MODULE_SUBTYPE_MULTI_WFLY2,
  MODULE_SUBTYPE_MULTI_E016HV2,
  MODULE_SUBTYPE_MULTI_E010R5,  //80
  MODULE_SUBTYPE_MULTI_LOLI,
  MODULE_SUBTYPE_MULTI_E129,
  MODULE_SUBTYPE_MULTI_JOYSWAY,
  MODULE_SUBTYPE_MULTI_E016H,
  MODULE_SUBTYPE_MULTI_CONFIG,  //85
  MODULE_SUBTYPE_MULTI_IKEAANSLUTA,
  MODULE_SUBTYPE_MULTI_WILLIFM,
  MODULE_SUBTYPE_MULTI_LOSI,
  MODULE_SUBTYPE_MULTI_MOULDKG,
  MODULE_SUBTYPE_MULTI_XERALL,  //90
  MODULE_SUBTYPE_MULTI_MT99XX2,
  MODULE_SUBTYPE_MULTI_KYOSHO2,
  MODULE_SUBTYPE_MULTI_LAST = MODULE_SUBTYPE_MULTI_KYOSHO2
};

//
// Common list of Multi protocol names
//
#define PROTO_NAMES \
  "FlySky","Hubsan","FrSkyD","Hisky","V2x2","DSM","Devo","YD717","KN","SymaX",\
  "SLT","CX10","CG023","Bayang","FrSkyX","ESky","MT99XX","MJXq","Shenqi","FY326",\
  "Futaba","J6 Pro","FQ777","Assan","FrSkyV","Hontai","OpenLrs","FlSky2A","Q2x2","Walkera", \
  "Q303","GW008","DM002","Cabell","Esky150","H8 3D","Corona","CFlie","Hitec","WFly",\
  "Bugs","BugMini","Traxxas","NCC1701","E01X","V911S","GD00X","V761","KF606","Redpine",\
  "Potensi","ZSX","Height","Scanner","FrSkyRX","FS2A_RX","HoTT","FX","BayanRX","Pelikan",\
  "Tiger", "XK","XN297DU","FrSkyX2","FrSkyR9","Propel","FrSkyL","Skyartc","ESky-v2","DSM RX",\
  "JJRC345","Q90C","Kyosho","RadLink","ExpLRS","Realacc","OMP","M-Link","Wfly 2","E016Hv2",\
  "E010r5","LOLI","E129","JOYSWAY","E016H","Config","IKEA","WILLIFM","Losi","MouldKg",\
  "Xerall","MT99XX2", "Kyosho2"

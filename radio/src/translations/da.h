/*
 * Copyright (C) OpenTX
 *
 * Based on code named
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
 *
 */

// DK translations author: Henrik Thuren <thuren.henrik@gmail.com>

/*
 * !!!!! DO NOT EDIT da.h - EDIT da.h.txt INSTEAD !!!!!!!
 *
 * In order to make translations easier dk.h.txt is parsed and national
 * characters are replaced by bitmap codes. The result is dk.h.
 *
 * See translate.py in the util folder for the list of character codes
 *
 * !!!!! DO NOT EDIT dk.h - EDIT dk.h.txt INSTEAD !!!!!!!
 */

/*
 * Formatting octal codes available in TR_ strings:
 *  \037\x           -sets LCD x-coord (x value in octal)
 *  \036             -newline
 *  \035             -horizontal tab (ARM only)
 *  \001 to \034     -extended spacing (value * FW/2)
 *  \0               -ends current string
 */


// NON ZERO TERMINATED STRINGS
#define LEN_OFFON              "\003"
#define TR_OFFON               "Fra""Til"

#define LEN_MMMINV             "\003"
#define TR_MMMINV              "---""INV"

#define LEN_VBEEPMODE          "\005"
#define TR_VBEEPMODE           "Stil.""Alarm""EjKnp""Alle\0"

#define LEN_COUNTDOWNVALUES    "\003"
#define TR_COUNTDOWNVALUES     "5s\0""10s""20s""30s"

#define LEN_VRENAVIG           "\003"
#define TR_VRENAVIG            "IngREaREb"

#define LEN_VBLMODE            TR("\005", "\010")
#define TR_VBLMODE             TR("Fra  ""Knapp""Spak\0""Alt\0 ""På\0  ", "Fra\0    ""Knappar\0""Spakar\0 ""Allt\0   ""På\0     ")

#define LEN_TRNMODE            "\002"
#define TR_TRNMODE             "Av""+="":="

#define LEN_TRNCHN             "\003"
#define TR_TRNCHN              "KN1KN2KN3KN4"

#define LEN_AUX_SERIAL_MODES   "\022"
#define TR_AUX_SERIAL_MODES    "Fra\0              ""Spejling af S-Port""Telemetri\0        ""SBUS Træner\0      ""LUA\0              ""CLI\0              ""GPS\0              ""Debug\0            "

#define LEN_SWTYPES            "\006"
#define TR_SWTYPES             "Ingen\0""Flipp\0""2Pos\0 ""3Pos\0"

#define LEN_POTTYPES           TR("\013","\020")
#define TR_POTTYPES            TR("None\0      ""Pot w. det\0""Multipos\0  ""Pot\0       ", "Ingen\0          ""Mittläges-pot\0  ""Flerlägesväljare""Potentiometer\0")

#define LEN_SLIDERTYPES        "\010"
#define TR_SLIDERTYPES         "Ingen\0  ""Skyder\0  "

#define LEN_VLCD               "\006"
#define TR_VLCD                "NormalOptrex"

#define LEN_VPERSISTENT        "\014"
#define TR_VPERSISTENT         "Av\0         ""Flygning\0   ""Nolla Själv\0"

#define LEN_COUNTRY_CODES       TR("\002", "\007")
#define TR_COUNTRY_CODES        TR("US""JP""EU", "Amerika""Japan\0 ""Europa\0")

#define LEN_USBMODES           TR("\006", "\010")
#define TR_USBMODES            TR("Ask\0  ""Joyst\0""SDCard""Serial", "Ask\0    ""Joystick""Storage\0""Serial\0 ")

#define LEN_JACK_MODES          "\007"
#define TR_JACK_MODES           "Spørg\0 ""Audio\0 ""Træner\0"

#define LEN_TELEMETRY_PROTOCOLS "\017"
#define TR_TELEMETRY_PROTOCOLS "FrSky S.PORT\0  ""FrSky D\0       ""FrSky D (Kabel)""TBS Crossfire\0 ""Spektrum\0      ""AFHDS2A IBUS\0  ""Multi Telemetry"

#define TR_MULTI_CUSTOM        "Custom"

#define LEN_VTRIMINC           TR("\006","\014")
#define TR_VTRIMINC            TR("Expo\0 ""xFin\0 ""Fin\0  ""Medium""Grov\0 ","Exponentiel""Extra Fin\0  ""Fin\0        ""Medium\0     ""Grov\0       ")

#define LEN_VDISPLAYTRIMS      "\005"
#define TR_VDISPLAYTRIMS       "Nej\0 ""Ændre""Ja\0  "

#define LEN_VBEEPCOUNTDOWN     "\007"
#define TR_VBEEPCOUNTDOWN      "Tavs\0 ""Bip\0   ""Stemme\0""Vibrer\0"

#define LEN_VVARIOCENTER       "\004"
#define TR_VVARIOCENTER        "Bip\0""Tavs"

#define LEN_CURVE_TYPES        "\006"
#define TR_CURVE_TYPES         "Normal""Egen\0 "

#define LEN_ADCFILTERVALUES    "\006"
#define TR_ADCFILTERVALUES     "Global""Av\0   ""På\0   "

#define LEN_RETA123            "\001"

#if defined(PCBX10)
  #define TR_RETA123           "RHGS1324567LR"
#elif defined(PCBHORUS)
  #define TR_RETA123           "RHGS13245LR"
#elif defined(PCBX9E)
  #define TR_RETA123           "RHGS1234HVHV"
#elif defined(PCBTARANIS)
  #define TR_RETA123           "RHGS123HV"
#else
  #define TR_RETA123           "RHGS123"
#endif


#define LEN_VCURVEFUNC         "\003"
#define TR_VCURVEFUNC          "---""x>0""x<0""|x|""f>0""f<0""|f|"

#define LEN_VMLTPX             "\010"
#define TR_VMLTPX              "Addere ""Forstærk""Erstat  "

#define LEN_VMLTPX2            "\002"
#define TR_VMLTPX2             "+=""*="":="

#define LEN_VMIXTRIMS          "\003"

#if defined(PCBHORUS)
  #define TR_VMIXTRIMS         "Fra""Til""Sid""Høj""Gas""Kræ""T5\0""T6\0"
#else
  #define TR_VMIXTRIMS         "Fra""Til""Sid""Høj""Gas""Kræ"
#endif

#if defined(PCBTARANIS)
  #define TR_CSWTIMER          "Timer"
  #define TR_CSWSTICKY         "Sej\0 "
  #define TR_CSWRANGE          "Vidd\0"
  #define TR_CSWSTAY           "Kant\0"
#else
  #define TR_CSWTIMER          "Time\0"
  #define TR_CSWSTICKY         "Sej\0 "
    #define TR_CSWRANGE        "Vidde"
    #define TR_CSWSTAY         "Kant\0"
#endif

  #define TR_CSWEQUAL          "a=x\0 "

#define LEN_VCSWFUNC           "\005"
// add ≥ char to the fonts  #define TR_VCSWFUNC            "---\0 " TR_CSWEQUAL "a~x\0 ""a>x\0 ""a<x\0 " TR_CSWRANGE "|a|>x""|a|<x""AND\0 ""OR\0  ""XOR\0 " TR_CSWSTAY "a=b\0 ""a>b\0 ""a<b\0 ""Δ}x\0 ""|Δ|}x" TR_CSWTIMER TR_CSWSTICKY
#define TR_VCSWFUNC      "---",TR_CSWEQUAL,"a~x","a>x","a<x",TR_CSWRANGE,"|a|>x","|a|<x","AND","OR","XOR",TR_CSWSTAY,"a=b","a>b","a<b",STR_CHAR_DELTA "≥x","|" STR_CHAR_DELTA "|≥x",TR_CSWTIMER,TR_CSWSTICKY

#define LEN_VFSWFUNC           "\012"

#if defined(VARIO)
  #define TR_VVARIO            "Vario\0    "
#else
  #define TR_VVARIO            "[Vario]   "
#endif

#if defined(AUDIO)
  #define TR_SOUND             "Afspil lyd"
#else
  #define TR_SOUND             "Bip\0      "
#endif

#if defined(HAPTIC)
  #define TR_HAPTIC            "Vibrator\0 "
#else
  #define TR_HAPTIC            "[Vibrator]"
#endif

#if defined(VOICE)
    #define TR_PLAY_TRACK      "Spela upp\0"
  #define TR_PLAY_BOTH         "Spela Båda"
  #define TR_PLAY_VALUE        TR("Säg värdet", "Säg värdet")
#else
  #define TR_PLAY_TRACK        "[Sp. Spår]"
  #define TR_PLAY_BOTH         "[Sp. Båda]"
  #define TR_PLAY_VALUE        "[Sp. Värd]"
#endif

#define TR_SF_BG_MUSIC        "BgMusik\0  ""BgMusik ||"

#if defined(SDCARD)
  #define TR_SDCLOGS           "SD log\0   "
#else
  #define TR_SDCLOGS           "[SD log]\0 "
#endif

#ifdef GVARS
  #define TR_ADJUST_GVAR       "Justere\0  "
#else
  #define TR_ADJUST_GVAR       "[Just. GV]"
#endif

#if defined(LUA)
  #define TR_SF_PLAY_SCRIPT   "Lua Script"
#else
  #define TR_SF_PLAY_SCRIPT   "[Lua]\0    "
#endif

#if defined(DEBUG)
  #define TR_SF_TEST          "Test\0"
#else
  #define TR_SF_TEST
#endif

#if defined(OVERRIDE_CHANNEL_FUNCTION) && LCD_W >= 212
  #define TR_SF_SAFETY        "Sikkerhed \0"
#elif defined(OVERRIDE_CHANNEL_FUNCTION)
  #define TR_SF_SAFETY        "Sikkerhed \0"
#else
  #define TR_SF_SAFETY        "---\0      "
#endif

#define TR_SF_SCREENSHOT      "Skærmbil.\0"
#define TR_SF_RACING_MODE     "RacingMode"
#define TR_SF_DISABLE_TOUCH   "No Touch"
#define TR_SF_RESERVE         "[reserve]\0"

#define TR_VFSWFUNC            TR_SF_SAFETY "Træner\0  ""Sæt Trim\0 ""Nulstil\0  ""Sätt\0     " TR_ADJUST_GVAR "Volum\0    " "SetFailsfe" "RangeCheck" "ModuleBind" TR_SOUND TR_PLAY_TRACK TR_PLAY_VALUE TR_SF_RESERVE TR_SF_PLAY_SCRIPT TR_SF_RESERVE TR_SF_BG_MUSIC TR_VVARIO TR_HAPTIC TR_SDCLOGS "Belysning\0" TR_SF_SCREENSHOT TR_SF_RACING_MODE TR_SF_DISABLE_TOUCH TR_SF_TEST

#define LEN_VFSWRESET          TR("\004", "\011")

#define TR_FSW_RESET_TELEM     TR("Telm", "Telemetry")

#if defined(PCBTARANIS)
  #define TR_FSW_RESET_TIMERS  "Timer 1\0 ""Timer 2\0 ""Timer 3\0 "
#else
  #define TR_FSW_RESET_TIMERS  "Tmr1""Tmr2""Tmr3"
#endif

#define TR_VFSWRESET           TR(TR_FSW_RESET_TIMERS "All\0" TR_FSW_RESET_TELEM, TR_FSW_RESET_TIMERS "Alla\0    " TR_FSW_RESET_TELEM)

#define LEN_FUNCSOUNDS         TR("\004", "\006")
#define TR_FUNCSOUNDS          TR("Bp1\0""Bp2\0""Bp3\0""Wrn1""Wrn2""Chee""Rata""Tick""Sirn""Ring""SciF""Robt""Chrp""Tada""Crck""Alrm", "Bip1  ""Bip2  ""Bip3  ""Advar1""Advar2""Cheep ""Ratata""Tick  ""Sirene""Ring  ""SciFi ""Robot ""Chirp ""Tada  ""Crickt""AlmClk")

#define LEN_VTELEMCHNS         "\004"

  #define TR_TELEM_RESERVE     TR("[--]", "[---]")
  #define TR_TELEM_TIME        TR("Tid\0", "Tid\0 ")
  #define TR_RAS               TR("SWR\0", "SWR\0 ")
  #define TR_RX_BATT           TR("[NA]", "[NA]\0")
  #define TR_A3_A4             TR("A3\0 ""A4\0 ", "A3\0  ""A4\0  ")
  #define TR_A3_A4_MIN         TR("A3-\0""A4-\0", "A3-\0 ""A4-\0 ")

#define TR_ASPD_MAX            TR("ASp+", "ASpd+")

#if defined(PCBTARANIS)
  #define TR_TELEM_RSSI_RX     "RSSI\0"
#else
  #define TR_TELEM_RSSI_RX     TR("Rx\0  ", "Rx\0 ")
#endif

  #define TR_TELEM_TIMERS      TR("Tmr1""Tmr2""Tmr3", "Tmr1\0""Tmr2\0""Tmr3\0")

#define LENGTH_UNIT_IMP        "fod"
#define SPEED_UNIT_IMP         "mph"
#define LENGTH_UNIT_METR       "m\0 "
#define SPEED_UNIT_METR        "kmh"

#define LEN_VUNITSSYSTEM     TR("\006", "\010")
#define TR_VUNITSSYSTEM      TR("Metri.""Imper.", "Metrisk""Imperiel")
#define LEN_VTELEMUNIT       "\003"
#define TR_VTELEMUNIT        "-\0 ""V\0 ""A\0 ""mA\0""kts""m/s""f/s""kmh""mph""m\0 ""ft\0""@C\0""@F\0""%\0 ""mAh""W\0 ""mW\0""dB\0""rpm""g\0 ""@\0 ""rad""ml\0""fOz""mlm""Hz\0""mS\0""uS\0""km\0"

#define STR_V                  (STR_VTELEMUNIT+1)
#define STR_A                  (STR_VTELEMUNIT+4)

#define LEN_VTELEMSCREENTYPE   "\007"
#define TR_VTELEMSCREENTYPE    "Ingen\0 ""Ciffer\0""Staplar""Script\0"

#define LEN_GPSFORMAT          "\004"
#define TR_GPSFORMAT           "HMS NMEA"

#define LEN2_VTEMPLATES        12
#define LEN_VTEMPLATES         "\014"
#define TR_TEMPLATE_CLEAR_MIXES        "Nulstil Mix "
#define TR_TEMPLATE_SIMPLE_4CH         "Enkel 4kanal"
#define TR_TEMPLATE_STICKY_TCUT        "Gas klipning"
#define TR_TEMPLATE_VTAIL              "V-Hale      "
#define TR_TEMPLATE_DELTA              "Delta vinge "
#define TR_TEMPLATE_ECCPM              "eCCPM       "
#define TR_TEMPLATE_HELI               "Helikopter  "
#define TR_TEMPLATE_SERVO_TEST         "Servotest   "

#define LEN_VSWASHTYPE         "\004"
#define TR_VSWASHTYPE          "--- ""120 ""120X""140 ""90\0 "

#define LEN_VSWITCHES          "\003"
#define LEN_VSRCRAW            "\004"


#define TR_STICKS_VSRCRAW        STR_CHAR_STICK "Sid"  STR_CHAR_STICK "Høj"  STR_CHAR_STICK "Gas"  STR_CHAR_STICK "Kræ"

#if defined(PCBHORUS)
  #define TR_TRIMS_VSRCRAW       STR_CHAR_TRIM "Sid"  STR_CHAR_TRIM "Høj"  STR_CHAR_TRIM "Gas"  STR_CHAR_TRIM "Kræ"  STR_CHAR_TRIM "T5\0"  STR_CHAR_TRIM "T6\0"
#else
  #define TR_TRIMS_VSRCRAW     TR("TrmR""TrmH""TrmG""TrmS",   STR_CHAR_TRIM "Sid"  STR_CHAR_TRIM "Høj"  STR_CHAR_TRIM "Gas"  STR_CHAR_TRIM "Kræ")
#endif

#if defined(PCBHORUS)
  #define TR_TRIMS_SWITCHES      STR_CHAR_TRIM "Rv"  STR_CHAR_TRIM "Rh"  STR_CHAR_TRIM "Hn"  STR_CHAR_TRIM "Hu"  STR_CHAR_TRIM "Gn"  STR_CHAR_TRIM "Gu"  STR_CHAR_TRIM "Sv"  STR_CHAR_TRIM "Sh"  STR_CHAR_TRIM "5d"  STR_CHAR_TRIM "5u"  STR_CHAR_TRIM "6d"  STR_CHAR_TRIM "6u"
#else
  #define TR_TRIMS_SWITCHES    TR("tRv""tRh""tHn""tHu""tGn""tGu""tSv""tSh",   STR_CHAR_TRIM "Rv"  STR_CHAR_TRIM "Rh"  STR_CHAR_TRIM "Hn"  STR_CHAR_TRIM "Hu"  STR_CHAR_TRIM "Gn"  STR_CHAR_TRIM "Gu"  STR_CHAR_TRIM "Sv"  STR_CHAR_TRIM "Sh")
#endif

  #define TR_ROTARY_ENCODERS
  #define TR_ROTENC_SWITCHES

#define TR_ON_ONE_SWITCHES     "Til""Et\0"

#if defined(GYRO)
  #define TR_GYR_VSRCRAW       "GyrX""GyrY"
#else
  #define TR_GYR_VSRCRAW
#endif

#if defined(HELI)
  #define TR_CYC_VSRCRAW       "CYK1""CYK2""CYK3"
#else
  #define TR_CYC_VSRCRAW       "[C1]""[C2]""[C3]"
#endif

#define TR_RESERVE_VSRCRAW   "[--]"
#define TR_EXTRA_VSRCRAW     "Batt""Tid\0""GPS\0" TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW TR_RESERVE_VSRCRAW "Tmr1""Tmr2""Tmr3"

#define LEN_VTMRMODES          "\003"
#define TR_VTMRMODES           "Fra""Til""Spd""GA%""GAt"

#define LEN_VTRAINERMODES              "\022"
#define TR_VTRAINER_MASTER_OFF         "FRA\0              "
#define TR_VTRAINER_MASTER_JACK        "Træner/Udtag\0     "
#define TR_VTRAINER_SLAVE_JACK         "Elev./Udtag\0      "
#define TR_VTRAINER_MASTER_SBUS_MODULE "Træner/SBUS-Modul\0"
#define TR_VTRAINER_MASTER_CPPM_MODULE "Træner/CPPM-Modul\0"
#define TR_VTRAINER_MASTER_BATTERY     "Traner/Serial\0    "
#define TR_VTRAINER_BLUETOOTH          TR("Master/BT\0        ""Slave/BT\0", "Master/Bluetooth\0 ""Slave/Bluetooth\0  ")
#define TR_VTRAINER_MULTI              "Master/Multi"

#define LEN_VFAILSAFE          "\011"
#define TR_VFAILSAFE           "Ikke sat\0""Lås Servo""Tilpasset""Pulsfri\0""Modtagere"


#define LEN_VSENSORTYPES        "\010"
#define TR_VSENSORTYPES        "Tilpasset""Beregnet"

#define LEN_VFORMULAS          "\014"
#define TR_VFORMULAS           "Addera\0     ""Medelvärde\0 ""Min\0        ""Max\0        ""Multiplicera""Totalsumma\0 ""Cell\0       ""Förbrukning ""Sträcka    "

#define LEN_VPREC              "\004"
#define TR_VPREC               "0.--""0.0 ""0.00"

#define LEN_VCELLINDEX         "\010"
#define TR_VCELLINDEX          "Længste\0 ""1\0      ""2\0      ""3\0      ""4\0      ""5\0      ""6\0      ""Højeste""Skillnad"

#define LEN_GYROS                      "\004"
#define TR_GYROS                       "GyrX""GyrY"

#define LEN_TEXT_SIZE          "\010"
#define TR_TEXT_SIZE           "Standard""Tiny\0   ""Small\0  ""Med\0    ""Double\0 "

#define LEN_SUBTRIMMODES               "\017"
#define TR_SUBTRIMMODES                STR_CHAR_DELTA" (center kun) ""= (symetrisk) "

// ZERO TERMINATED STRINGS
#if defined(COLORLCD)
  #define INDENT
  #define LEN_INDENT           3
  #define INDENT_WIDTH         12
  #define BREAKSPACE           "\036"
#else
  #define INDENT               "\001"
  #define LEN_INDENT           1
  #define INDENT_WIDTH         (FW/2)
  #define BREAKSPACE           " "
#endif

#if defined(PCBFRSKY)
  #define TR_ENTER             "[ENTER]"
#elif defined(PCBNV14)
  #define TR_ENTER                     "[NEXT]"
#else
  #define TR_ENTER                     "[MENU]"
#endif

#if defined(PCBHORUS)
  #define TR_EXIT                      "RTN"
  #define TR_OK                        TR_ENTER
#else
  #define TR_EXIT                      "EXIT"
  #define TR_OK                        TR("\010" "\010" "\010" "[OK]", "\010" "\010" "\010" "\010" "\010" "[OK]")
#endif

#if defined(PCBTARANIS)
  #define TR_POPUPS_ENTER_EXIT         TR(TR_EXIT "\010" TR_ENTER, TR_EXIT "\010" "\010" "\010" "\010" TR_ENTER)

#else
  #define TR_POPUPS_ENTER_EXIT         TR_ENTER "\010" TR_EXIT
#endif

#define TR_MENUWHENDONE        CENTER "\011" TR_ENTER " Afslutter "
#define TR_FREE                "tilbage"
#define TR_YES                         "Yes"
#define TR_NO                          "No"
#define TR_DELETEMODEL         "Slet model    "
#define TR_COPYINGMODEL        "Kopier modell "
#define TR_MOVINGMODEL         "Flyt model    "
#define TR_LOADINGMODEL        "Indlæs model  "
#define TR_NAME                "Navn"
#define TR_MODELNAME           "Model navn  "
#define TR_PHASENAME           "Läges navn  "
#define TR_MIXNAME             "Mix navn    "
#define TR_INPUTNAME           "Indgang navn"
#if defined(PCBTARANIS)
  #define TR_EXPONAME          "Radnamn"
#else
  #define TR_EXPONAME          "Exponamn"
#endif
#define TR_BITMAP              "Model ikon"
#define TR_TIMER               TR("Timer","Timer ")
#define TR_START               "Start"
#define TR_ELIMITS             TR("Gränser++","Utökade Gränser")
#define TR_ETRIMS              TR("Trimmar++","Utökade Trimmar")
#define TR_TRIMINC             TR("Trimning","Trimökning")
#define TR_DISPLAY_TRIMS       "Display Trims"
#define TR_TTRACE              TR("Följ Gas", INDENT "Följ Gas")
#define TR_TTRIM               TR("Gastrim", INDENT "Gastrim")
#define TR_TTRIM_SW            TR("T-Trim-Sw", INDENT "Trim switch")
#define TR_BEEPCTR             TR("Cent.pip", "Centerpip")
#define TR_USE_GLOBAL_FUNCS    TR("Glob.Funkt", "Anvend Global Funk.")
#define TR_PROTOCOL            TR("Proto", "Protokol")
#define TR_PPMFRAME            INDENT "PPM-pakke"
#define TR_REFRESHRATE         TR(INDENT "Refresh", INDENT "Refresh rate")
#define STR_WARN_BATTVOLTAGE   TR(INDENT "Output is VBAT: ", INDENT "Warning: output level is VBAT: ")
#define TR_WARN_5VOLTS         "Warning: output level is 5 volts"
#define TR_MS                  "ms"
#define TR_FREQUENCY           INDENT "Frekvens"
#define TR_SWITCH              "Kontakter"
#define TR_TRIMS               "Trimme"
#define TR_FADEIN              "Tone Ind"
#define TR_FADEOUT             "Tone Ud"
#define TR_DEFAULT             "Standard"
#define TR_CHECKTRIMS          CENTER "\006Check\012Trimme"
#define OFS_CHECKTRIMS         CENTER_OFS+(9*FW)
#define TR_SWASHTYPE           "Swashtype"
#define TR_COLLECTIVE          "Kollektiv"
#define TR_AILERON             "Krængror-kilde"
#define TR_ELEVATOR            "Højderor-kilde"
#define TR_SWASHRING           "Swashring"
#define TR_ELEDIRECTION        "HøJD Riktning"
#define TR_AILDIRECTION        "SKEV Riktning"
#define TR_COLDIRECTION        "PITCH Riktn. "
#define TR_MODE                "Tilstand"
#define TR_SUBTYPE             INDENT "Subtype"
#define TR_NOFREEEXPO          "Expo mangler!"
#define TR_NOFREEMIXER         "Mix mangler!"
#define TR_SOURCE              "Kilde"
#define TR_WEIGHT              "Vægt"
#define TR_EXPO                TR("Expo","Exponentiel")
#define TR_SIDE                "Side"
#define TR_DIFFERENTIAL        "Diff."
#define TR_OFFSET              "Offset"
#define TR_TRIM                "Trim"
#define TR_DREX                "DRex"
#define DREX_CHBOX_OFFSET      30
#define TR_CURVE               "Kurve"
#define TR_FLMODE              TR("Tilstand","Flyvetilstand")
#define TR_MIXWARNING          "Advarsel"
#define TR_OFF                 "Fra"
#define TR_ANTENNA                     "Antenne"
#define TR_NO_INFORMATION              TR("No info", "No information")
#define TR_MULTPX              "Multpx"
#define TR_DELAYDOWN           "Dröj Ned"
#define TR_DELAYUP             "Dröj Upp"
#define TR_SLOWDOWN            "Trög Ned"
#define TR_SLOWUP              "Trög Upp"
#define TR_MIXES               "MIXAR"
#define TR_CV                  "KU"
#if defined(PCBNV14)
#define TR_GV                  "GV"
#else
#define TR_GV                  TR("G", "GV")
#endif
#define TR_ACHANNEL            "A\004kanal  "
#define TR_RANGE               INDENT"MinMax"
#define TR_CENTER              INDENT "Center"
#define TR_BAR                 "Data"
#define TR_ALARM               "Alarm"
#define TR_USRDATA             "Anvenderdata"
#define TR_BLADES              "Blad"
#define TR_SCREEN              "Skærm "
#define TR_SOUND_LABEL         "Lyd "
#define TR_LENGTH              "Tid"
#define TR_BEEP_LENGTH         "Bip-længde"
#define TR_BEEP_PITCH           "Bip-tone"
#define TR_HAPTIC_LABEL        "Vibrator"
#define TR_STRENGTH            "Styrke"
#define TR_GYRO_LABEL          "Gyro"
#define TR_GYRO_OFFSET         "Offset"
#define TR_GYRO_MAX            "Max"
#define TR_CONTRAST            "Kontrast"
#define TR_ALARMS_LABEL        "Alarm"
#define TR_BATTERY_RANGE       "Batteri MinMax"
#define TR_BATTERYCHARGING     "Lader..."
#define TR_BATTERYFULL         "Batteri fuldt"
#define TR_BATTERYNONE         "None!"
#define TR_BATTERYWARNING      "Batteri"
#define TR_INACTIVITYALARM     "Inaktivitet"
#define TR_MEMORYWARNING       "Hukommelse lav"
#define TR_ALARMWARNING        "Lyd fra"
#define TR_RSSI_SHUTDOWN_ALARM   TR("Rssi Shutdown", "Check Rssi on Shutdown")
#define TR_MODEL_STILL_POWERED "Model stadig forbundet"
#define TR_USB_STILL_CONNECTED         "USB stadig forbundet"
#define TR_MODEL_SHUTDOWN              "Shutdown ?"
#define TR_PRESS_ENTER_TO_CONFIRM      "Press enter to confirm"
#define TR_THROTTLE_LABEL      "Gas"
#define TR_THROTTLEREVERSE     TR("Inv.Gas", INDENT "Omvendt Gas")
#define TR_MINUTEBEEP          "Minutpip"
#define TR_BEEPCOUNTDOWN       INDENT "Nedtælling"
#define TR_PERSISTENT          TR("Jævnt til", INDENT"Altid til")
#define TR_BACKLIGHT_LABEL     "Belysning"
#define TR_GHOST_MENU_LABEL            "GHOST MENU"
#define TR_STATUS                      "Status"
#define TR_BLDELAY             INDENT "Fra efter"
#define TR_BLONBRIGHTNESS      INDENT "Til Lysstyrke"
#define TR_BLOFFBRIGHTNESS     INDENT "Fra Lysstyrke"
#define TR_KEYS_BACKLIGHT              "Keys backlight"
#define TR_SPLASHSCREEN        "Startbillede"
#define TR_PWR_ON_DELAY                "Pwr On delay"
#define TR_PWR_OFF_DELAY               "Pwr Off delay"
#define TR_BLCOLOR             "Color"
#define TR_THROTTLE_WARNING     TR("Gasadvarsel", INDENT "Gas advarsel")
#define TR_CUSTOM_THROTTLE_WARNING     TR(INDENT INDENT INDENT INDENT "Cust-Pos", INDENT INDENT INDENT INDENT "Custom position?")
#define TR_CUSTOM_THROTTLE_WARNING_VAL TR("Pos. %", "Position %")
#define TR_SWITCHWARNING       TR("Bryt.varn.", INDENT "Brytarvarning")
#define TR_POTWARNINGSTATE     TR(INDENT "Pot&Slid.", INDENT "Drejekontakt & skydekontakt")
#define TR_SLIDERWARNING       TR(INDENT "Slid. pos.", INDENT "Skydekontakt position")
#define TR_POTWARNING          TR("Drej.Advar.", INDENT "Drejekontakt advarsel")
#define TR_TIMEZONE            TR("Tidszone", "GPS Tidszone")
#define TR_ADJUST_RTC          TR("Juster RTC", "Juster RTC")
#define TR_GPS                 "GPS"
#define TR_RXCHANNELORD        "Kanaler i RX"
#define TR_STICKS              "Pinde"
#define TR_POTS                "Drejekontakt"
#define TR_SWITCHES            "Kontakter"
#define TR_SWITCHES_DELAY      "Kontakt forsinkelse"
#define TR_SLAVE               "Elev"
#define TR_MODESRC             " Tilstand\004% Kilde"
#define TR_MULTIPLIER          "Styrka"
#define TR_CAL                 "Kalib."
#define TR_CALIBRATION                 "Kalibrering"
#define TR_VTRIM               "Trim- +"
#define TR_BG                  "BG:"
#define TR_CALIB_DONE                  "Kalibrering færdig"
#if defined(PCBHORUS)
  #define TR_MENUTOSTART       "Press [Enter] to start"
  #define TR_SETMIDPOINT       "Centrer pinde/drejekontakter/skydere og tryk [Enter]"
  #define TR_MOVESTICKSPOTS    "Flyt pinde/drejekontakter/skydere og tryk [Enter]"
#elif defined(COLORLCD)
  #define TR_MENUTOSTART       TR_ENTER " Starter "
  #define TR_SETMIDPOINT       "Centrer alt"
  #define TR_MOVESTICKSPOTS    "Flyt pinde/drejekontakter"
#else
  #define TR_MENUTOSTART       CENTER "\011" TR_ENTER " Starter "
  #define TR_SETMIDPOINT       TR(CENTER "\012Centrer Alt",CENTER "\013Centrer Alt")
  #define TR_MOVESTICKSPOTS    TR(CENTER "\005Flyt pinde/drejekontakter.",CENTER "\006Flyt pinde/drejekontakter")
#endif
#define TR_RXBATT              "Rx Batt:"
#define TR_TXnRX               "Tx:\0Rx:"
#define OFS_RX                 4
#define TR_ACCEL               "Acc:"
#define TR_NODATA              CENTER "DATA SAVNES"
#define TR_US                         "us"
#define TR_HZ                         "Hz"
#define TR_TMIXMAXMS                  "Tmix max"
#define TR_FREE_STACK                 "Free stack"
#define TR_INT_GPS_LABEL               "Intern GPS"
#define TR_HEARTBEAT_LABEL             "Heartbeat"
#define TR_LUA_SCRIPTS_LABEL          "Lua scripts"
#define TR_FREE_MEM_LABEL             "Free mem"
#define TR_TIMER_LABEL                "Timer"
#define TR_THROTTLE_PERCENT_LABEL     "Gas %"
#define TR_BATT_LABEL                 "Batteri"
#define TR_SESSION                    "Session"
#define TR_MENUTORESET         TR_ENTER " Nulstil"
#define TR_PPM_TRAINER         "TR"
#define TR_CH                  "KN"
#define TR_MODEL               "Model"
#define TR_FM                  "FL"
#define TR_MIX                 "MIX"
#define TR_EEPROMLOWMEM        "Minnesbrist"
#define TR_PRESS_ANY_KEY_TO_SKIP   "Tryk en knap"
#define TR_THROTTLE_NOT_IDLE     "Gas er aktiveret!"
#define TR_ALARMSDISABLED      "Alarm afkoblet!"
#define TR_PRESSANYKEY         "Tryk en knap"
#define TR_BADEEPROMDATA       "Minnet kan inte tolkas"
#define TR_BAD_RADIO_DATA      "Data från radion kan inte tolkas"
#define TR_EEPROMFORMATTING    "Minnet Nulstils"
#define TR_STORAGE_FORMAT      "SD kort formateres"
#define TR_EEPROMOVERFLOW      "Minnesfel"
#define TR_RADIO_SETUP      "INDSTILLINGER"
#define TR_MENUDATEANDTIME     "DAG OG TID"
#define TR_MENUTRAINER         "TRÆNER (PPM IN)"
#define TR_MENUSPECIALFUNCS    "GLOBALE FUNKTIONER"
#define TR_MENUVERSION         "VERSION"
#define TR_MENU_RADIO_SWITCHES            TR("KONTAKTER","TEST AF KONTAKTER")
#define TR_MENU_RADIO_ANALOGS             "ANALOGE VÆRDIER"
#define TR_MENU_RADIO_ANALOGS_CALIB       "KALIBRATED ANALOGE"
#define TR_MENU_RADIO_ANALOGS_RAWLOWFPS   "RAW ANALOGE (5 Hz)"
#define TR_MENUCALIBRATION     "KALIBRERING"
#if defined(COLORLCD)
  #define TR_TRIMS2OFFSETS     "[Gem Trimværdier]"
#else
  #define TR_TRIMS2OFFSETS     "\006[Gem Trimværdier]"
#endif
#define TR_CHANNELS2FAILSAFE   "Channels=>Failsafe"
#define TR_CHANNEL2FAILSAFE    "Channel=>Failsafe"
#define TR_MENUMODELSEL        TR("MODEL","VÆLG MODEL")
#define TR_MENU_MODEL_SETUP           TR("VÄRDEN","MODELLINSTÄLLNINGAR")
#define TR_MENUFLIGHTMODE      "FLYGLÄGE"
#define TR_MENUFLIGHTMODES     "FLYGLÄGEN"
#define TR_MENUHELISETUP       "HELIKOPTER"

  #define TR_MENUINPUTS        "INPUT"
  #define TR_MENULIMITS        "SERVON"

#define TR_MENUCURVES          "KURVE"
#define TR_MENUCURVE           "KURVE"
#define TR_MENULOGICALSWITCH   "LOGISK KONTAKT"
#define TR_MENULOGICALSWITCHES "LOGISKE KONTAKTER"
#define TR_MENUCUSTOMFUNC      "KONTAKT FUNKTIONER"
#define TR_MENUCUSTOMSCRIPTS   "SPECIALKOD"
#define TR_MENUTELEMETRY       "TELEMETRI"
#define TR_MENUTEMPLATES       "TEMPLATE"
#define TR_MENUSTAT            "STATISTIK"
#define TR_MENUDEBUG           "DEBUG"
#define TR_MONITOR_CHANNELS1   "CHANNELS MONITOR 1/8"
#define TR_MONITOR_CHANNELS2   "CHANNELS MONITOR 9/16"
#define TR_MONITOR_SWITCHES    "LOGICAL SWITCHES MONITOR"
#define TR_MONITOR_CHANNELS3   "CHANNELS MONITOR 17/24"
#define TR_MONITOR_CHANNELS4   "CHANNELS MONITOR 25/32"
#define TR_MONITOR_OUTPUT_DESC "Udgange"
#define TR_MONITOR_MIXER_DESC  "Mixere"
#define TR_RECEIVER_NUM        TR("RxNum", "Mottagare Nr.")
#define TR_RECEIVER            "Modtager"
#define TR_SYNCMENU            "Synk [MENU]"
#define TR_MULTI_RFTUNE        TR("Freq tune", "RF Freq. fine tune")
#define TR_MULTI_RFPOWER               "RF power"
#define TR_MULTI_WBUS                  "Output"
#define TR_MULTI_TELEMETRY     "Telemetri"
#define TR_MULTI_VIDFREQ       TR("Vid. freq.", "Video frequency")
#define TR_RF_POWER             "RF Power"
#define TR_MULTI_FIXEDID               TR("FixedID", "Fixed ID")
#define TR_MULTI_OPTION        TR("Option", "Option value")
#define TR_MULTI_AUTOBIND      TR(INDENT "Bind Ch.",INDENT "Bind on channel")
#define TR_DISABLE_CH_MAP              TR("No Ch. map", "Disable Ch. map")
#define TR_DISABLE_TELEM               TR("No Telem", "Disable Telemetry")
#define TR_MULTI_DSM_AUTODTECT TR(INDENT "Autodetect", INDENT "Autodetect format")
#define TR_MULTI_LOWPOWER      TR(INDENT "Low power", INDENT "Low power mode")
#define TR_MULTI_LNA_DISABLE            INDENT "LNA disable"
#define TR_MODULE_TELEMETRY            TR(INDENT "S.Port", INDENT "S.Port link")
#define TR_MODULE_TELEM_ON             TR("ON", "Enabled")
#define TR_DISABLE_INTERNAL         TR("Disable int. RF", "Disable internal RF")
#define TR_MODULE_NO_SERIAL_MODE       TR("!serial mode", "Not in serial mode")
#define TR_MODULE_NO_INPUT             TR("No input", "No serial input")
#define TR_MODULE_NO_TELEMETRY         TR3( "No telmetry", "No MULTI_TELEMETRY", "No telemetry (enable MULTI_TELEMETRY)")
#define TR_MODULE_WAITFORBIND          "Bind to load protocol"
#define TR_MODULE_BINDING              "Binding"
#define TR_MODULE_UPGRADE_ALERT        TR3("Upg. needed", "Module upgrade required", "Module\nUpgrade required")
#define TR_MODULE_UPGRADE              TR("Upg. advised", "Module update recommended")
#define TR_REBIND                      "Parring nødvendig"
#define TR_REG_OK                      "Registrering ok"
#define TR_BIND_OK                     "Parring lykkes"
#define TR_BINDING_CH1_8_TELEM_ON               "Ch1-8 Telem ON"
#define TR_BINDING_CH1_8_TELEM_OFF               "Ch1-8 Telem OFF"
#define TR_BINDING_CH9_16_TELEM_ON               "Ch9-16 Telem ON"
#define TR_BINDING_CH9_16_TELEM_OFF               "Ch9-16 Telem OFF"
#define TR_PROTOCOL_INVALID            TR("Prot. invalid", "Protocol invalid")
#define TR_MODULE_STATUS                TR(INDENT "Status", INDENT "Module Status")
#define TR_MODULE_SYNC                 TR(INDENT "Sync", INDENT "Proto Sync Status")
#define TR_MULTI_SERVOFREQ     TR("Servo rate", "Servo update rate")
#define TR_MULTI_MAX_THROW             TR("Max. Throw", "Enable max. throw")
#define TR_MULTI_RFCHAN                TR("RF Channel", "Select RF channel")
#define TR_LIMIT               INDENT "Nivå"
#define TR_MINRSSI             "Min Rssi"
#define TR_FLYSKY_TELEMETRY            TR("FlySky RSSI #", "Use FlySky RSSI value without rescalling")
#define TR_LATITUDE            "Breddegrad"
#define TR_LONGITUDE           "Længdegrad"
#define TR_GPS_COORDS_FORMAT            TR("GPS koordinater", "GPS koordinatsystem")
#define TR_VARIO               TR("Vario", "Variometer")
#define TR_PITCH_AT_ZERO       "Ton vid Noll"
#define TR_PITCH_AT_MAX        "Ton vid Max"
#define TR_REPEAT_AT_ZERO      "Repetera vid Noll"
#define TR_SHUTDOWN            "LUKKER NED"
#define TR_SAVE_MODEL           "Gem modelindstillinger."
#define TR_BATT_CALIB          "Kalib. Batteri"
#define TR_CURRENT_CALIB       "Kalib. Strøm"
#define TR_VOLTAGE             INDENT"Volt"
#define TR_CURRENT             INDENT"Ampere"
#define TR_SELECT_MODEL        "Välj Modell"
#define TR_MODEL_CATEGORIES            "Model kategorier"
#define TR_MODELS                      "Modeller"
#define TR_SELECT_MODE                 "Vælg tilstand"
#define TR_CREATE_CATEGORY     "Ny Kategori"
#define TR_RENAME_CATEGORY     "Skif Kat.navn"
#define TR_DELETE_CATEGORY     "Slet Kategori"
#define TR_CREATE_MODEL        "Ny model"
#define TR_DUPLICATE_MODEL     "Dupl. Model"
#define TR_COPY_MODEL          "Kopier Model"
#define TR_MOVE_MODEL          "Flyt Model"
#define TR_BACKUP_MODEL        "Model backup"
#define TR_DELETE_MODEL        "Slet Model"
#define TR_RESTORE_MODEL       "Genskab Model"
#define TR_DELETE_ERROR        "Slette fejl"
#define TR_CAT_NOT_EMPTY       "Kategori er ikke tom"
#define TR_SDCARD_ERROR        "SDCARD-fejl"
#define TR_SDCARD                      "SD Card"
#define TR_NO_FILES_ON_SD              "Ingen filer på SD!"
#define TR_NO_SDCARD           "SDCARD mangler"
#define TR_WAITING_FOR_RX              "Venter på RX..."
#define TR_WAITING_FOR_TX              "Venter på TX..."
#define TR_WAITING_FOR_MODULE          TR("Venter på modul", "Venter på modul...")
#define TR_NO_TOOLS                    "No tools available"
#define TR_NORMAL                      "Normal"
#define TR_NOT_INVERTED                "Not inv"
#define TR_NOT_CONNECTED               "!Forbundet"
#define TR_CONNECTED                   "Forbundet"
#define TR_FLEX_915                    "Flex 915MHz"
#define TR_FLEX_868                    "Flex 868MHz"
#define TR_16CH_WITHOUT_TELEMETRY      TR("16CH uden telem.", "16CH uden telemetri")
#define TR_16CH_WITH_TELEMETRY         TR("16CH med telem.", "16CH med telemetri")
#define TR_8CH_WITH_TELEMETRY          TR("8CH med telem.", "8CH med telemetri")
#define TR_EXT_ANTENNA                 "Ext. antenne"
#define TR_PIN                         "Pin"
#define TR_UPDATE_RX_OPTIONS           "Update RX options?"
#define TR_UPDATE_TX_OPTIONS           "Update TX options?"
#define TR_MODULES_RX_VERSION          "Modules / RX version"
#define TR_MENU_MODULES_RX_VERSION     "MODULES / RX VERSION"
#define TR_MENU_FIRM_OPTIONS           "FIRMWARE OPTIONS"
#define TR_GYRO                        "Gyro"
#define TR_STICKS_POTS_SLIDERS         "Pinde/drejekontakter/skydere"
#define TR_PWM_STICKS_POTS_SLIDERS     "PWM pinde/drejekontakter/skydere"
#define TR_RF_PROTOCOL                 "RF Protokol"
#define TR_MODULE_OPTIONS              "Modul options"
#define TR_POWER                       "Power"
#define TR_NO_TX_OPTIONS               "No TX options"
#define TR_RTC_BATT                    "RTC Batteri"
#define TR_POWER_METER_EXT             "Strøm Meter (EXT)"
#define TR_POWER_METER_INT             "Power Meter (INT)"
#define TR_SPECTRUM_ANALYSER_EXT       "Spectrum (EXT)"
#define TR_SPECTRUM_ANALYSER_INT       "Spectrum (INT)"
#define TR_SDCARD_FULL                 "SD-kort Fullt"
#define TR_NEEDS_FILE                  "NEEDS FILE"
#define TR_EXT_MULTI_SPEC              "opentx-inv"
#define TR_INT_MULTI_SPEC              "stm-opentx-noinv"
#define TR_INCOMPATIBLE        "Inkompatibel"
#define TR_WARNING             "ADVARSEL"
#define TR_EEPROMWARN          "EEPROM"
#define TR_STORAGE_WARNING     "LAGRING"
#define TR_EEPROM_CONVERTING   "EEPROM Konvertering"
#define TR_SDCARD_CONVERSION_REQUIRE   "SD card conversion required"
#define TR_CONVERTING                  "Converting: "
#define TR_THROTTLE_UPPERCASE        "GAS"
#define TR_ALARMSWARN          "ALARM"
#define TR_SWITCHWARN          "KONTAKTER"
#define TR_FAILSAFEWARN        "FEJLSIKRING"
#define TR_TEST_WARNING        TR("TESTING", "TEST BUILD")
#define TR_TEST_NOTSAFE        "Use for tests only"
#define TR_SDCARDVERSIONWARN   "SD Card Check"
#define TR_WRONG_SDCARDVERSION TR("Forventet ver: ","Forventet version: ")
#define TR_WARN_RTC_BATTERY_LOW        "RTC Battery low"
#define TR_WARN_MULTI_LOWPOWER         "Low power mode"
#define TR_BATTERY                     "BATTERY"
#define TR_WRONG_PCBREV        "Wrong PCB detected"
#define TR_EMERGENCY_MODE      "EMERGENCY MODE"
#define TR_PCBREV_ERROR        "PCB error"
#define TR_NO_FAILSAFE         "Fejlsikring ikke valgt"
#define TR_KEYSTUCK            "Knap-felj"
#define TR_INVERT_THR          TR("Omvendt Gas?", "Omvendt Gas?")
#define TR_VOLUME              "Volume"
#define TR_LCD                 "LCD"
#define TR_BRIGHTNESS          "Lysstyrke"
#define TR_CPU_TEMP            "CPU temp.\016>"
#define TR_CPU_CURRENT         "Strøm\022>"
#define TR_CPU_MAH             "Forbrug"
#define TR_COPROC              "CoProc."
#define TR_COPROC_TEMP         "MB temp. \016>"
#define TR_CAPAWARNING         INDENT "Låg Kapacitet"
#define TR_TEMPWARNING         TR(INDENT "Hög Temp ", INDENT "Hög Temperatur")
#define TR_TTL_WARNING         "Warning: use 3.3V logic levels"
#define TR_FUNC                "Funk"
#define TR_V1                  "V1"
#define TR_V2                  "V2"
#define TR_DURATION            "Varighed"
#define TR_DELAY               "Forsinkelse"
#define TR_SD_CARD             "SD-kort"
#define TR_SDHC_CARD           "SD/HC-kort"
#define TR_NO_SOUNDS_ON_SD     "Ingen lyd på SD"
#define TR_NO_MODELS_ON_SD     "Ingen model på SD"
#define TR_NO_BITMAPS_ON_SD    "Ikoner mangler på SD"
#define TR_NO_SCRIPTS_ON_SD    "Program mangler på SD"
#define TR_SCRIPT_SYNTAX_ERROR  TR("Syntax error", "Script syntax error")
#define TR_SCRIPT_PANIC        "Script panic"
#define TR_SCRIPT_KILLED       "Script killed"
#define TR_SCRIPT_ERROR        "Unkendt fejl"
#define TR_PLAY_FILE           "Afspil"
#define TR_DELETE_FILE         "Slette"
#define TR_COPY_FILE           "Kopiere"
#define TR_RENAME_FILE         "Omdøb"
#define TR_ASSIGN_BITMAP       "Tildel ikon"
#define TR_ASSIGN_SPLASH       "Splash screen"
#define TR_EXECUTE_FILE        "Udfør"
#define TR_REMOVED             " slettet"
#define TR_SD_INFO             "Information"
#define TR_SD_FORMAT           "Format"
#define TR_NA                  "N/A"
#define TR_HARDWARE            "Hårdvara"
#define TR_FORMATTING          "Formatere..."
#define TR_TEMP_CALIB          "Temp. kalib."
#define TR_TIME                "Tid "
#define TR_MAXBAUDRATE         "Max bauds"
#define TR_BAUDRATE            "Baudrate"
#define TR_SAMPLE_MODE         "Sample Mode"
#define LEN_SAMPLE_MODES       "\006"
#define TR_SAMPLE_MODES        "Normal""OneBit"
#define TR_SELECT_TEMPLATE_FOLDER "VÆLG ET TEMPLATE KATALOG:"
#define TR_SELECT_TEMPLATE     "VÆLG EN MODEL TEMPLATE:"
#define TR_NO_TEMPLATES        "No model templates were found in this folder"
#define TR_SAVE_TEMPLATE       "Gem som template"
#define TR_BLANK_MODEL                 "Tom Model"
#define TR_BLANK_MODEL_INFO            "Opret tom model"
#define TR_FILE_EXISTS         "FIL FINDES ALLEREDE"
#define TR_ASK_OVERWRITE       "Vil du overkrive?"

#define TR_BLUETOOTH            "Bluetooth"
#define TR_BLUETOOTH_DISC       "Discover"
#define TR_BLUETOOTH_INIT       "Init"
#define TR_BLUETOOTH_DIST_ADDR  "Dist addr"
#define TR_BLUETOOTH_LOCAL_ADDR "Local addr"
#define TR_BLUETOOTH_PIN_CODE   "PIN code"
#define TR_BLUETOOTH_BAUDRATE   "BT Baudrate"
#define LEN_BLUETOOTH_MODES     "\011"
#if defined(PCBX9E)
#define TR_BLUETOOTH_MODES      "---\0     ""Enabled\0 "
#else
#define TR_BLUETOOTH_MODES      "---\0     ""Telemetry""Trainer\0"
#endif
#define TR_SD_INFO_TITLE       "SD INFO"
#define TR_SD_TYPE             "Type: "
#define TR_SD_SPEED            "Hastighed:"
#define TR_SD_SECTORS          "Sektorer:"
#define TR_SD_SIZE             "Stør:"
#define TR_TYPE                INDENT "Typ "
#define TR_GLOBAL_VARS         "Globale Variable"
#define TR_GVARS               "GLOBALE V."
#define TR_GLOBAL_VAR          "Global Variabel"
#define TR_MENU_GLOBAL_VARS      "GLOBALE VARIABLER"
#define TR_OWN                 "Egen"
#define TR_DATE                "Dato"
#define TR_MONTHS              { "Jan", "Feb", "Mar", "Apr", "Maj", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dec" }
#define TR_ROTARY_ENCODER      "R.Enks"
#define TR_INVERT_ROTARY       "Invert Rotary"
#define TR_CHANNELS_MONITOR    "Kanalöversikt"
#define TR_MIXERS_MONITOR      "MIXER-SKÆRM"
#define TR_PATH_TOO_LONG       "For lang sti"
#define TR_VIEW_TEXT           "Vise Tekst"
#define TR_FLASH_BOOTLOADER    "Skriv BootLoader"
#define TR_FLASH_DEVICE                TR("Flash device","Flash device")
#define TR_FLASH_EXTERNAL_DEVICE "Flash External Device"
#define TR_FLASH_RECEIVER_OTA          "Flash receiver OTA"
#define TR_FLASH_RECEIVER_BY_EXTERNAL_MODULE_OTA "Flash RX by ext. OTA"
#define TR_FLASH_RECEIVER_BY_INTERNAL_MODULE_OTA "Flash RX by int. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_EXTERNAL_MODULE_OTA "Flash FC by ext. OTA"
#define TR_FLASH_FLIGHT_CONTROLLER_BY_INTERNAL_MODULE_OTA "Flash FC by int. OTA"
#define TR_FLASH_BLUETOOTH_MODULE      TR("Flash BT module", "Flash Bluetooth module")
#define TR_FLASH_POWER_MANAGEMENT_UNIT          "Flash pwr mngt unit"
#define TR_DEVICE_NO_RESPONSE          TR("Device not responding", "Device not responding")
#define TR_DEVICE_FILE_ERROR           TR("Device file prob.", "Device file prob.")
#define TR_DEVICE_DATA_REFUSED         TR("Device data refused", "Device data refused")
#define TR_DEVICE_WRONG_REQUEST        TR("Device access problem", "Device access problem")
#define TR_DEVICE_FILE_REJECTED        TR("Device file refused", "Device file refused")
#define TR_DEVICE_FILE_WRONG_SIG       TR("Device file sig.", "Device file sig.")
#define TR_CURRENT_VERSION             TR("Current vers. ", "Current version: ")
#define TR_FLASH_INTERNAL_MODULE "Flash Internal Module"
#define TR_FLASH_INTERNAL_MULTI        TR("Flash Int. Multi", "Flash Internal Multi")
#define TR_FLASH_EXTERNAL_MODULE       "Flash external module"
#define TR_FLASH_EXTERNAL_MULTI        TR("Flash Ext. Multi", "Flash External Multi")
#define TR_FLASH_EXTERNAL_ELRS         TR("Flash Ext. ELRS", "Flash External ELRS")
#define TR_FIRMWARE_UPDATE_ERROR TR("FW update Error","Firmware update error")
#define TR_FIRMWARE_UPDATE_SUCCESS     "Flash successful"
#define TR_WRITING                     "Skriver..."
#define TR_CONFIRM_FORMAT              "Formatere Hukommelse?"
#define TR_INTERNALRF                  "Intern Radio"
#define TR_INTERNAL_MODULE             TR("Int. module","Internal module")
#define TR_EXTERNAL_MODULE             TR("Ext. module","External module")
#define TR_OPENTX_UPGRADE_REQUIRED     "OpenTX upgrade required"
#define TR_TELEMETRY_DISABLED          "Telem. disabled"
#define TR_MORE_OPTIONS_AVAILABLE      "More options available"
#define TR_NO_MODULE_INFORMATION       "No module information"
#define TR_EXTERNALRF          "Extern Radiomodul"
#define TR_FAILSAFE            TR(INDENT "Failsafe", INDENT "Failsafeläge")
#define TR_FAILSAFESET         "FailsafeInställning"
#define TR_REG_ID                      "Reg. ID"
#define TR_OWNER_ID                    "Owner ID"
#define TR_PINMAPSET                   "PINMAP"
#define TR_HOLD                "Hold"
#define TR_HOLD_UPPERCASE              "HOLD"
#define TR_NONE                "None"
#define TR_NONE_UPPERCASE              "NONE"
#define TR_MENUSENSOR          "SENSOR"
#define TR_POWERMETER_PEAK             "Peak"
#define TR_POWERMETER_POWER            "Power"
#define TR_POWERMETER_ATTN             "Attn"
#define TR_POWERMETER_FREQ             "Freq."
#define TR_MENUTOOLS                   "TOOLS"
#define TR_TURN_OFF_RECEIVER           "Turn off receiver"
#define TR_STOPPING                    "Stopping..."
#define TR_MENU_SPECTRUM_ANALYSER      "SPECTRUM ANALYSER"
#define TR_MENU_POWER_METER            "POWER METER"
#define TR_SENSOR              "SENSOR"
#define TR_COUNTRY_CODE         "Landskod"
#define TR_USBMODE             "USB Mode"
#define TR_JACK_MODE                    "Jack Mode"
#define TR_VOICE_LANGUAGE           "Röstspråk"
#define TR_UNITS_SYSTEM         "Enheter"
#define TR_EDIT                "Redigera"
#define TR_INSERT_BEFORE       "Addera Före"
#define TR_INSERT_AFTER        "Addera Efter"
#define TR_COPY                "Kopiera"
#define TR_MOVE                "Flytta"
#define TR_PASTE               "Infoga"
#define TR_PASTE_AFTER                 "Paste After"
#define TR_PASTE_BEFORE                "Paste Before"
#define TR_DELETE              "Radera"
#define TR_INSERT              "Addera"
#define TR_RESET_FLIGHT        "Nulstil Flygning"
#define TR_RESET_TIMER1        "Nulstil Timer1"
#define TR_RESET_TIMER2        "Nulstil Timer2"
#define TR_RESET_TIMER3        "Nulstil Timer3"
#define TR_RESET_TELEMETRY     "Nulstil Telemetri"
#define TR_STATISTICS          "Statistik"
#define TR_ABOUT_US            "Om Oss"
#define TR_USB_JOYSTICK        "USB Joystick (HID)"
#define TR_USB_MASS_STORAGE    "USB Storage (SD)"
#define TR_USB_SERIAL          "USB Serial (VCP)"
#define TR_SETUP_SCREENS       "Setup screens"
#define TR_MONITOR_SCREENS     "Monitors"
#define TR_AND_SWITCH          "OCH Brytare"
#define TR_SF                  "BF"
#define TR_GF                  "GF"
#define TR_ANADIAGS_CALIB      "Calibrated analogs"
#define TR_ANADIAGS_FILTRAWDEV "Filtered raw analogs with deviation"
#define TR_ANADIAGS_UNFILTRAW  "Unfiltered raw analogs"
#define TR_ANADIAGS_MINMAX     "Min., max. and range"
#define TR_ANADIAGS_MOVE       "Move analogs to their extremes!"
#define TR_SPEAKER             INDENT"Högtalare"
#define TR_BUZZER              INDENT"Summer"
#define TR_BYTES               "byte"
#define TR_MODULE_BIND         TR("[Bnd]", "[Bind]")
#define TR_POWERMETER_ATTN_NEEDED      "Attenuator needed"
#define TR_PXX2_SELECT_RX              "Select RX"
#define TR_PXX2_DEFAULT                "<default>"
#define TR_BT_SELECT_DEVICE            "Select device"
#define TR_DISCOVER             "Discover"
#define TR_BUTTON_INIT                 BUTTON("Init")
#define TR_WAITING                     "Waiting..."
#define TR_RECEIVER_DELETE             "Delete receiver?"
#define TR_RECEIVER_RESET              "Reset receiver?"
#define TR_SHARE                       "Share"
#define TR_BIND                        "Bind"
#define TR_REGISTER                    TR("Reg", "Register")
#define TR_MODULE_RANGE        TR("[Tst]", "[Testa]")
#define TR_RECEIVER_OPTIONS            TR("REC. OPTIONS", "RECEIVER OPTIONS")
#define TR_DEL_BUTTON                  BUTTON(TR("Del", "Delete"))
#define TR_RESET_BTN           "[Nulstil]"
#define TR_DEBUG                       "Debug"
#define TR_KEYS_BTN                BUTTON(TR("SW","Switches"))
#define TR_ANALOGS_BTN                 BUTTON(TR("Analog","Analogs"))
#define TR_TOUCH_NOTFOUND              "Touch hardware not found"
#define TR_TOUCH_EXIT                  "Touch screen to exit"
#define TR_SET                 "[Spara]"
#define TR_TRAINER             "Trainer"
#define TR_CHANS                       "Chans"
#define TR_ANTENNAPROBLEM      CENTER "Fejl på TX-antennen"
#define TR_MODELIDUSED         TR("ID finns redan","ModellID används redan")
#define TR_MODULE              "Modul"
#define TR_RX_NAME                     "Rx Name"
#define TR_TELEMETRY_TYPE      "Telemetrityp"
#define TR_TELEMETRY_SENSORS   "Sensorer"
#define TR_VALUE               "Värde"
#define TR_REPEAT                      "Repeat"
#define TR_ENABLE                      "Enable"
#define TR_TOPLCDTIMER         "Top LCD Timer"
#define TR_UNIT                "Enhet"
#define TR_TELEMETRY_NEWSENSOR INDENT "Lägg till sensor..."
#define TR_CHANNELRANGE        INDENT "Kanalområde"
#define TR_RXFREQUENCY         TR("Rx Freqency", "Rx Servo Frequency")
#define TR_AFHDS3_RX_FREQ              TR("RX freq.", "RX frequency")
#define TR_AFHDS3_ONE_TO_ONE_TELEMETRY TR("Unicast/Tel.", "Unicast/Telemetry")
#define TR_AFHDS3_ONE_TO_MANY          "Multicast"
#define TR_AFHDS3_ACTUAL_POWER         TR("Act. pow", "Actual power")
#define TR_AFHDS3_POWER_SOURCE         TR("Power src.", "Power source")
#define TR_ANTENNACONFIRM1     "EXT. ANTENNA"
#if defined(PCBX12S)
#define LEN_ANTENNA_MODES      "\023"
#define TR_ANTENNA_MODES       "Internal\0          ""Ask\0               ""Per model\0         ""Internal + External"
#else
#define LEN_ANTENNA_MODES      "\011"
#define TR_ANTENNA_MODES       "Internal\0""Ask\0     ""Per model""External"
#endif
#define TR_USE_INTERNAL_ANTENNA        TR("Use int. antenna", "Use internal antenna")
#define TR_USE_EXTERNAL_ANTENNA        TR("Use ext. antenna", "Use external antenna")
#define TR_ANTENNACONFIRM2     TR("Check antenna", "Make sure antenna is installed!")
#define TR_MODULE_PROTOCOL_FLEX_WARN_LINE1                "Requires non"
#define TR_MODULE_PROTOCOL_FCC_WARN_LINE1         "Requires FCC"
#define TR_MODULE_PROTOCOL_EU_WARN_LINE1          "Requires EU"
#define TR_MODULE_PROTOCOL_WARN_LINE2                "certified firmware"
#define TR_LOWALARM            INDENT "Låg-alarm"
#define TR_CRITICALALARM       INDENT "Kritiskt alarm"
#define TR_RSSIALARM_WARN             TR("RSSI","TELEMETRY RSSI")
#define TR_NO_RSSIALARM                TR(INDENT "Alarms disabled", INDENT "Telemetry alarms disabled")
#define TR_DISABLE_ALARM               TR(INDENT "Disable alarms", INDENT "Disable telemetry alarms")
#define TR_ENABLE_POPUP        "Slå på Dialog"
#define TR_DISABLE_POPUP       "Slå av Dialog"
#define TR_POPUP               "Popup"
#define TR_MIN                 "Min"
#define TR_MAX                 "Max"
#define TR_CURVE_PRESET        "Lutning..."
#define TR_PRESET              "Lutning"
#define TR_MIRROR              "Spegla"
#define TR_CLEAR               "Töm"
#define TR_RESET               "Nulstil"
#define TR_RESET_SUBMENU       "Nulstil..."
#define TR_COUNT               "Antal"
#define TR_PT                  "pt"
#define TR_PTS                 "pkt"
#define TR_SMOOTH              "Mjuk"
#define TR_COPY_STICKS_TO_OFS  TR("Cpy stick->subtrim", "Spara spakar som subtrim")
#define TR_COPY_MIN_MAX_TO_OUTPUTS     TR("Cpy min/max to all",  "Copy min/max/center to all outputs")
#define TR_COPY_TRIMS_TO_OFS   TR("Cpy trim->subtrim", "Spara trimmar som subtrim")
#define TR_INCDEC              "Inkr/Dekrement"
#define TR_GLOBALVAR           "Globala Var"
#define TR_MIXSOURCE           "Mixer Källa"
#define TR_CONSTANT            "Konstant"
#define TR_PERSISTENT_MAH      INDENT "Lagra mAh"
#define TR_PREFLIGHT           "Startkontroller"
#define TR_CHECKLIST           TR(INDENT "Checklista", INDENT "Vise Checklista")
#define TR_FAS_OFFSET          TR(INDENT "FAS Ofs", INDENT "FAS Offset")
#define TR_AUX_SERIAL_MODE     "Serieporten"
#define TR_AUX2_SERIAL_MODE    "Serieporten 2"
#define TR_AUX_SERIAL_PORT_POWER       "Port power"
#define TR_SCRIPT              "Programkod"
#define TR_INPUTS              "Input"
#define TR_OUTPUTS             "Outputs"
#define STR_EEBACKUP            "Säkerhetskopiera EEPROM"
#define STR_FACTORYRESET        "Factory reset"
#define TR_CONFIRMRESET        "Erase ALL models and settings?"
#define TR_TOO_MANY_LUA_SCRIPTS "För många Lua-scripts!"
#define TR_SPORT_UPDATE_POWER_MODE     "SP Power"
#define LEN_SPORT_UPDATE_POWER_MODES   "\004"
#define TR_SPORT_UPDATE_POWER_MODES    "AUTO""ON\0 "
#define TR_NO_TELEMETRY_SCREENS        "No Telemetry Screens"
#define TR_TOUCH_PANEL                 "Touch panel:"
#define TR_FILE_SIZE                   "File size"
#define TR_FILE_OPEN                   "Open anyway?"

// Horus and Taranis column headers
#define TR_PHASES_HEADERS_NAME         "Namn"
#define TR_PHASES_HEADERS_SW           "Brytare"
#define TR_PHASES_HEADERS_RUD_TRIM     "Rodertrim"
#define TR_PHASES_HEADERS_ELE_TRIM     "Höjdrodertrim"
#define TR_PHASES_HEADERS_THT_TRIM     "Gastrim"
#define TR_PHASES_HEADERS_AIL_TRIM     "Skevrodertrim"
#define TR_PHASES_HEADERS_CH5_TRIM     "Trim 5"
#define TR_PHASES_HEADERS_CH6_TRIM     "Trim 6"
#define TR_PHASES_HEADERS_FAD_IN       "Tona Upp"
#define TR_PHASES_HEADERS_FAD_OUT      "Tona Ned"

#define TR_LIMITS_HEADERS_NAME         "Namn"
#define TR_LIMITS_HEADERS_SUBTRIM      "Subtrim"
#define TR_LIMITS_HEADERS_MIN          "Min"
#define TR_LIMITS_HEADERS_MAX          "Max"
#define TR_LIMITS_HEADERS_DIRECTION    "Riktning"
#define TR_LIMITS_HEADERS_CURVE        "Kurva"
#define TR_LIMITS_HEADERS_PPMCENTER    "PPM-center"
#define TR_LIMITS_HEADERS_SUBTRIMMODE  "Subtrim-tilstand"
#define TR_INVERTED     "Inverted"

#define TR_LSW_HEADERS_FUNCTION        "Funktion"
#define TR_LSW_HEADERS_V1              "V1"
#define TR_LSW_HEADERS_V2              "V2"
#define TR_LSW_HEADERS_ANDSW           "OG Kontakter"
#define TR_LSW_HEADERS_DURATION        "Varighed"
#define TR_LSW_HEADERS_DELAY           "Forsinkelse"

#define TR_GVAR_HEADERS_NAME          "Navn"
#define TR_GVAR_HEADERS_FM0           "Værdi hvis FM0"
#define TR_GVAR_HEADERS_FM1           "Værdi hvis FM1"
#define TR_GVAR_HEADERS_FM2           "Værdi hvis FM2"
#define TR_GVAR_HEADERS_FM3           "Værdi hvis FM3"
#define TR_GVAR_HEADERS_FM4           "Værdi hvis FM4"
#define TR_GVAR_HEADERS_FM5           "Værdi hvis FM5"
#define TR_GVAR_HEADERS_FM6           "Værdi hvis FM6"
#define TR_GVAR_HEADERS_FM7           "Værdi hvis FM7"
#define TR_GVAR_HEADERS_FM8           "Værdi hvis FM8"

// Horus footer descriptions
#define TR_LSW_DESCRIPTIONS    { "Comparison type or function", "First variable", "Second variable or constant", "Second variable or constant", "Additional condition for line to be enabled", "Minimum ON duration of the logical switch", "Minimum TRUE duration for the switch to become ON" }

// Horus layouts and widgets
#define TR_FIRST_CHANNEL               "Første kannal"
#define TR_FILL_BACKGROUND             "Fyld baggrund?"
#define TR_BG_COLOR                    "BG Color"
#define TR_SLIDERS_TRIMS               "Skydere+Trims"
#define TR_SLIDERS                     "Skydere"
#define TR_FLIGHT_MODE                 "Flyve tilstand"
#define TR_INVALID_FILE                "Invalid Fil"
#define TR_TIMER_SOURCE                "Timer kilde"
#define TR_SIZE                        "Size"
#define TR_SHADOW                      "Shadow"
#define TR_TEXT                        "Text"
#define TR_COLOR                       "Color"
#define TR_MAIN_VIEW_X                 "Main view X"
#define TR_PANEL1_BACKGROUND           "Panel1 baggrund"
#define TR_PANEL2_BACKGROUND           "Panel2 baggrund"

// About screen
#define TR_ABOUTUS             "Om Os"

#define TR_CHR_SHORT           's'
#define TR_CHR_LONG            'l'
#define TR_CHR_TOGGLE          't'
#define TR_CHR_HOUR            'h'
#define TR_CHR_INPUT           'I'   // Values between A-I will work

#define TR_BEEP_VOLUME         "Volume Bip"
#define TR_WAV_VOLUME          "Volume Wav"
#define TR_BG_VOLUME           "Volume Bg"

#define TR_TOP_BAR             "Titelraden"
#define TR_FLASH_ERASE                 "Flash erase..."
#define TR_FLASH_WRITE                 "Flash write..."
#define TR_OTA_UPDATE                  "OTA update..."
#define TR_MODULE_RESET                "Module reset..."
#define TR_UNKNOWN_RX                  "Unknown RX"
#define TR_UNSUPPORTED_RX              "Unsupported RX"
#define TR_OTA_UPDATE_ERROR            "OTA update error"
#define TR_DEVICE_RESET                "Device reset..."
#define TR_ALTITUDE            INDENT "Höjd"
#define TR_SCALE               "Skala"
#define TR_VIEW_CHANNELS       "Vis Kanaler"
#define TR_VIEW_NOTES          "Vis Noteringars"
#define TR_MODEL_SELECT        "Vælg Model"
#define TR_MODS_FORBIDDEN      "Modifikationer forbudt!"
#define TR_UNLOCKED            "Ulåst"
#define TR_ID                  "ID"
#define TR_PRECISION           "Precision"
#define TR_RATIO               "Ratio"
#define TR_FORMULA             "Formel"
#define TR_CELLINDEX           "Cell index"
#define TR_LOGS                "Logge"
#define TR_OPTIONS             "Tilvalg"
#define TR_FIRMWARE_OPTIONS    "Firmware tilvalg"

#define TR_ALTSENSOR           "Højdesensor"
#define TR_CELLSENSOR          "Cell sensor"
#define TR_GPSSENSOR           "GPS sensor"
#define TR_CURRENTSENSOR       "Sensor"
#define TR_AUTOOFFSET          "Auto Offset"
#define TR_ONLYPOSITIVE        "Positiv"
#define TR_FILTER              "Filter"
#define TR_TELEMETRYFULL       "Alle telemetripladser optaget!"
#define TR_SERVOS_OK           "Servos OK"
#define TR_SERVOS_KO           "Servos KO"
//TODO: translation
#define TR_INVERTED_SERIAL     INDENT "Invert"
#define TR_IGNORE_INSTANCE     TR(INDENT "Inst.fejl", INDENT "Håndter Instansfejl")
#define TR_DISCOVER_SENSORS    "Find nye sensorer"
#define TR_STOP_DISCOVER_SENSORS "Afbryd søgning"
#define TR_DELETE_ALL_SENSORS  "Slet alle sensorer"
#define TR_CONFIRMDELETE       "Slet alle?"
#define TR_SELECT_WIDGET       "Vælg widget"
#define TR_REMOVE_WIDGET       "Slet widget"
#define TR_WIDGET_SETTINGS     "Widget indstillinger"
#define TR_REMOVE_SCREEN       "Slet screen"
#define TR_SETUP_WIDGETS       "Setup widgets"
#define TR_USER_INTERFACE      "User interface"
#define TR_THEME               "Thema"
#define TR_SETUP               "Setup"
#define TR_LAYOUT              "Layout"
#define TR_ADD_MAIN_VIEW         "Add main view"
#define TR_BACKGROUND_COLOR    "Background color"
#define TR_MAIN_COLOR          "Main color"
#define TR_BAR2_COLOR                  "Secondary bar color"
#define TR_BAR1_COLOR                  "Main bar color"
#define TR_TEXT_COLOR                  "Text color"
#define TR_TEXT_VIEWER                 "Text Viewer"

#define TR_MENU_INPUTS          STR_CHAR_INPUT "Indgange"
#define TR_MENU_LUA             STR_CHAR_LUA "Lua scripts"
#define TR_MENU_STICKS           STR_CHAR_STICK "Pinde"
#define TR_MENU_POTS            STR_CHAR_POT "Drejekontakter"
#define TR_MENU_MAX             STR_CHAR_FUNCTION "MAX"
#define TR_MENU_HELI            STR_CHAR_CYC "Cyclic"
#define TR_MENU_TRIMS            STR_CHAR_TRIM "Trim"
#define TR_MENU_SWITCHES        STR_CHAR_SWITCH "Kontakter"
#define TR_MENU_LOGICAL_SWITCHES  STR_CHAR_SWITCH "Logiske kontakter"
#define TR_MENU_TRAINER         STR_CHAR_TRAINER "Træner"
#define TR_MENU_CHANNELS        STR_CHAR_CHANNEL "Servo"
#define TR_MENU_GVARS           STR_CHAR_SLIDER "GVars"
#define TR_MENU_TELEMETRY       STR_CHAR_TELEMETRY "Telemetri"
#define TR_MENU_DISPLAY        "DISPLAY"
#define TR_MENU_OTHER          "Andet"
#define TR_MENU_INVERT         "Omvendt"
#define TR_JITTER_FILTER       "ADC Filter"
#define TR_DEAD_ZONE           "Dead zone"
#define TR_RTC_CHECK           TR("Check RTC", "Check RTC voltage")
#define TR_AUTH_FAILURE                "Auth-failure"
#define TR_RACING_MODE                 "Racing mode"

#define STR_VFR               "VFR"
#define STR_RSSI              "RSSI"
#define STR_R9PW                      "R9PW"
#define STR_RAS               "SWR"
#define STR_A1                "A1"
#define STR_A2                "A2"
#define STR_A3                "A3"
#define STR_A4                "A4"
#define STR_BATT              "RxBt"
#define STR_ALT               "Alt"
#define STR_TEMP1             "Tmp1"
#define STR_TEMP2             "Tmp2"
#define STR_TEMP3                     "Tmp3"
#define STR_TEMP4                     "Tmp4"
#define STR_RPM2                      "RPM2"
#define STR_PRES                      "Pres"
#define STR_ODO1                      "Odo1"
#define STR_ODO2                      "Odo2"
#define STR_TXV                       "TX_V"
#define STR_CURR_SERVO1               "CSv1"
#define STR_CURR_SERVO2               "CSv2"
#define STR_CURR_SERVO3               "CSv3"
#define STR_CURR_SERVO4               "CSv4"
#define STR_DIST                      "Dist"
#define STR_ARM                       "Arm"
#define STR_C50                       "C50"
#define STR_C200                      "C200"
#define STR_RPM               "RPM"
#define STR_FUEL              "Fuel"
#define STR_VSPD              "VSpd"
#define STR_ACCX              "AccX"
#define STR_ACCY              "AccY"
#define STR_ACCZ              "AccZ"
#define STR_GYROX             "GYRX"
#define STR_GYROY             "GYRY"
#define STR_GYROZ             "GYRZ"
#define STR_CURR              "Curr"
#define STR_CAPACITY          "Capa"
#define STR_VFAS              "VFAS"
#define STR_BATT_PERCENT      "Bat%"
#define STR_ASPD              "ASpd"
#define STR_GSPD              "GSpd"
#define STR_HDG               "Hdg"
#define STR_SATELLITES        "Sats"
#define STR_CELLS             "Cels"
#define STR_GPSALT            "GAlt"
#define STR_GPSDATETIME       "Date"
#define STR_BATT1_VOLTAGE     "RB1V"
#define STR_BATT2_VOLTAGE     "RB2V"
#define STR_BATT1_CURRENT     "RB1A"
#define STR_BATT2_CURRENT     "RB2A"
#define STR_BATT1_CONSUMPTION "RB1C"
#define STR_BATT2_CONSUMPTION "RB2C"
#define STR_BATT1_TEMP        "RB1T"
#define STR_BATT2_TEMP        "RB2T"
#define STR_RB_STATE          "RBS"
#define STR_CHANS_STATE       "RBCS"
#define STR_RX_RSSI1          "1RSS"
#define STR_RX_RSSI2          "2RSS"
#define STR_RX_QUALITY        "RQly"
#define STR_RX_SNR            "RSNR"
#define STR_RX_NOISE          "RNse"
#define STR_RF_MODE           "RFMD"
#define STR_TX_POWER          "TPWR"
#define STR_TX_RSSI           "TRSS"
#define STR_TX_QUALITY        "TQly"
#define STR_TX_SNR            "TSNR"
#define STR_TX_NOISE          "TNse"
#define STR_PITCH             "Højd"
#define STR_ROLL              "Kræn"
#define STR_YAW               "Side"
#define STR_THROTTLE          "Gas"
#define STR_QOS_A             "FdeA"
#define STR_QOS_B             "FdeB"
#define STR_QOS_L             "FdeL"
#define STR_QOS_R             "FdeR"
#define STR_QOS_F             "FLss"
#define STR_QOS_H             "Hold"
#define STR_LAP_NUMBER        "Lap "
#define STR_GATE_NUMBER       "Gate"
#define STR_LAP_TIME          "LapT"
#define STR_GATE_TIME         "GteT"
#define STR_ESC_VOLTAGE       "EscV"
#define STR_ESC_CURRENT       "EscA"
#define STR_ESC_RPM           "Erpm"
#define STR_ESC_CONSUMPTION   "EscC"
#define STR_ESC_TEMP          "EscT"
#define STR_SD1_CHANNEL       "Chan"
#define STR_GASSUIT_TEMP1     "GTp1"
#define STR_GASSUIT_TEMP2     "GTp2"
#define STR_GASSUIT_RPM       "GRPM"
#define STR_GASSUIT_FLOW      "GFlo"
#define STR_GASSUIT_CONS      "GFue"
#define STR_GASSUIT_RES_VOL   "GRVl"
#define STR_GASSUIT_RES_PERC  "GRPc"
#define STR_GASSUIT_MAX_FLOW  "GMFl"
#define STR_GASSUIT_AVG_FLOW  "GAFl"
#define STR_SBEC_VOLTAGE      "BecV"
#define STR_SBEC_CURRENT      "BecA"
#define STR_RB3040_EXTRA_STATE        "RBES"
#define STR_RB3040_CHANNEL1           "CH1A"
#define STR_RB3040_CHANNEL2           "CH2A"
#define STR_RB3040_CHANNEL3           "CH3A"
#define STR_RB3040_CHANNEL4           "CH4A"
#define STR_RB3040_CHANNEL5           "CH5A"
#define STR_RB3040_CHANNEL6           "CH6A"
#define STR_RB3040_CHANNEL7           "CH7A"
#define STR_RB3040_CHANNEL8           "CH8A"
#define STR_ESC_VIN                   "EVIN"
#define STR_ESC_TFET                  "TFET"
#define STR_ESC_CUR                   "ECUR"
#define STR_ESC_TBEC                  "TBEC"
#define STR_ESC_BCUR                  "CBEC"
#define STR_ESC_VBEC                  "VBEC"
#define STR_ESC_THR                   "ETHR"
#define STR_ESC_POUT                  "EOUT"
#define STR_SMART_BAT_BTMP            "BTmp"
#define STR_SMART_BAT_BCUR            "BCur"
#define STR_SMART_BAT_BCAP            "BUse"
#define STR_SMART_BAT_MIN_CEL         "CLMi"
#define STR_SMART_BAT_MAX_CEL         "CLMa"
#define STR_SMART_BAT_CYCLES          "Cycl"
#define STR_SMART_BAT_CAPACITY        "BCpT"
#define STR_CL01                      "Cel1"
#define STR_CL02                      "Cel2"
#define STR_CL03                      "Cel3"
#define STR_CL04                      "Cel4"
#define STR_CL05                      "Cel5"
#define STR_CL06                      "Cel6"
#define STR_CL07                      "Cel7"
#define STR_CL08                      "Cel8"
#define STR_CL09                      "Cel9"
#define STR_CL10                      "Cl10"
#define STR_CL11                      "Cl11"
#define STR_CL12                      "Cl12"
#define STR_CL13                      "Cl13"
#define STR_CL14                      "Cl14"
#define STR_CL15                      "Cl15"
#define STR_CL16                      "Cl16"
#define STR_CL17                      "Cl17"
#define STR_CL18                      "Cl18"
#define STR_FRAME_RATE                "FRat"
#define STR_TOTAL_LATENCY             "TLat"
#define STR_VTX_FREQ                  "VFrq"
#define STR_VTX_PWR                   "VPwr"
#define STR_VTX_CHAN                  "VChn"
#define STR_VTX_BAND                  "VBan"
#define STR_SERVO_CURRENT             "SrvA"
#define STR_SERVO_VOLTAGE             "SrvV"
#define STR_SERVO_TEMPERATURE         "SrvT"
#define STR_SERVO_STATUS              "SrvS"
#define STR_LOSS                      "Loss"
#define STR_SPEED                     "Spd "
#define STR_FLOW                      "Flow"

// The following content is Untranslated)

#define TR_USE_THEME_COLOR              "Use theme color"

#define TR_ADD_ALL_TRIMS_TO_SUBTRIMS    "Add all Trims to Subtrims"
#if LCD_W > LCD_H
  #define TR_OPEN_CHANNEL_MONITORS        "Open Channel Monitor"
#else
  #define TR_OPEN_CHANNEL_MONITORS        "Open Channel Mon."
#endif
#define TR_DUPLICATE                    "Duplicate"
#define TR_ACTIVATE                     "Set Active"
#define TR_RED                          "Rød"
#define TR_BLUE                         "Blå"
#define TR_GREEN                        "Grøn"
#define TR_COLOR_PICKER                 "Farve vælger"
#define TR_EDIT_THEME_DETAILS           "Edit Theme Details"
#define TR_AUTHOR                       "Author"
#define TR_DESCRIPTION                  "Description"
#define TR_SAVE                         "Gem"
#define TR_CANCEL                       "Fortryd"
#define TR_EDIT_THEME                   "EDIT THEME"
#define TR_DETAILS                      "Details"
#define TR_THEME_EDITOR                 "THEMES"

// Main menu
#define TR_MAIN_MENU_SELECT_MODEL       "Select\nModel"
#define TR_MAIN_MENU_MODEL_NOTES        "Model\nNotes"
#define TR_MAIN_MENU_CHANNEL_MONITOR    "Channel\nMonitor"
#define TR_MAIN_MENU_MODEL_SETTINGS     "Model\nSettings"
#define TR_MAIN_MENU_RADIO_SETTINGS     "Radio\nSettings"
#define TR_MAIN_MENU_SCREEN_SETTINGS    "Screens\nSettings"
#define TR_MAIN_MENU_RESET_TELEMETRY    "Reset\nTelemetry"
#define TR_MAIN_MENU_STATISTICS         "Statistics"
#define TR_MAIN_MENU_ABOUT_EDGETX       "About\nEdgeTX"
// End Main menu

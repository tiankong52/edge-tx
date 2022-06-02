#!/bin/bash

LVGLDIR="../../thirdparty/libopenui/thirdparty/lvgl"
TTF_DIR="../"

SYMBOLS_FONT="${LVGLDIR}/scripts/built_in_font/FontAwesome5-Solid+Brands+Regular.woff"
SYMBOLS="61441,61448,61451,61452,61453,61457,61459,61461,61465,61468,61473,61478,61479,61480,61502,61507,61512,61515,61516,61517,61521,61522,61523,61524,61543,61544,61550,61552,61553,61556,61559,61560,61561,61563,61587,61589,61636,61637,61639,61641,61664,61671,61674,61683,61724,61732,61787,61931,62016,62017,62018,62019,62020,62087,62099,62212,62189,62810,63426,63650"

EXTRA_FONT="EdgeTX/extra.ttf"
EXTRA_SYM="0x88-0x94"

ASCII="0x20-0x7F"
DEGREE="0xB0"
BULLET="0x2022"
LATIN1="0xC0-0xFF"

TW_SYMBOLS="0x4e00,0x4e0a,0x4e0b,0x4e0d,0x4e2d,0x4e32,0x4e3b,0x4e4b,0x4e58,0x4e8c,0x4eab,0x4eae,0x4ecb,0x4ef0,0x4ef6,0x4efb,0x4efd,0x4f48,0x4f4d,0x4f4e,0x4f4f,0x4f5c,0x4f7f,0x4f86,0x4f8b,0x4fdd,0x4fe1,0x4fee,0x4fef,0x500b,0x500d,0x5012,0x503c,0x504f,0x505c,0x5074,0x5099,0x50b3,0x50cf,0x5100,0x511f,0x5132,0x5141,0x5145,0x5149,0x5165,0x5167,0x5168,0x516c,0x5176,0x5177,0x517c,0x518a,0x51fa,0x5206,0x5217,0x521d,0x5225,0x522a,0x5230,0x5236,0x5237,0x524d,0x5275,0x529f,0x52a0,0x52d5,0x5305,0x5316,0x5340,0x5347,0x5354,0x5361,0x53c3,0x53ca,0x53cd,0x53d6,0x53e3,0x53ea,0x53ef,0x540c,0x540d,0x5411,0x5426,0x542b,0x542f,0x544a,0x548c,0x554f,0x555f,0x55ae,0x55ce,0x5668,0x56de,0x56fa,0x570b,0x570d,0x5716,0x5728,0x5730,0x5740,0x5747,0x578b,0x57f7,0x57fa,0x5831,0x584a,0x586b,0x589e,0x58d3,0x5916,0x591a,0x5927,0x5929,0x592a,0x5931,0x593e,0x597d,0x59cb,0x5b50,0x5b54,0x5b58,0x5b78,0x5b83,0x5b89,0x5b8c,0x5b9a,0x5bb9,0x5beb,0x5bec,0x5bf8,0x5c04,0x5c07,0x5c0d,0x5c0e,0x5c0f,0x5c3a,0x5c40,0x5c45,0x5c4f,0x5c55,0x5de5,0x5dee,0x5df2,0x5e36,0x5e38,0x5e40,0x5e45,0x5e55,0x5e73,0x5e74,0x5e8f,0x5ea6,0x5ee0,0x5ef6,0x5efa,0x5f00,0x5f0f,0x5f15,0x5f31,0x5f37,0x5f48,0x5f62,0x5f71,0x5f85,0x5f88,0x5f8c,0x5f91,0x5f9e,0x5fa9,0x5faa,0x5fae,0x5ffd,0x6020,0x6025,0x6062,0x606f,0x60c5,0x610f,0x611f,0x614b,0x6162,0x61c9,0x6210,0x6216,0x622a,0x6232,0x6236,0x6240,0x6247,0x624b,0x6253,0x627e,0x62c9,0x62d2,0x62fe,0x6301,0x6307,0x6309,0x632f,0x6383,0x63a1,0x63a5,0x63a7,0x63cf,0x63d0,0x63d2,0x63da,0x63db,0x6416,0x6478,0x64ad,0x64c7,0x64ca,0x64cd,0x64da,0x64e6,0x64f4,0x652f,0x6536,0x6539,0x653e,0x6545,0x6548,0x6557,0x6559,0x6574,0x6578,0x6587,0x659c,0x65b0,0x65b7,0x65b9,0x65bc,0x65cb,0x65e5,0x660e,0x6620,0x662f,0x6642,0x666f,0x66ab,0x66f2,0x66f4,0x66ff,0x6700,0x6708,0x6709,0x671f,0x672a,0x672c,0x6746,0x675f,0x677f,0x67c4,0x67e5,0x6821,0x683c,0x6848,0x687f,0x689d,0x6975,0x6a02,0x6a19,0x6a21,0x6a23,0x6a5f,0x6a6b,0x6a94,0x6aa2,0x6b04,0x6b50,0x6b62,0x6b63,0x6b64,0x6b65,0x6b8a,0x6bb5,0x6bd4,0x6c60,0x6c92,0x6cb9,0x6cbf,0x6cd5,0x6ce2,0x6ce8,0x6d32,0x6d41,0x6d88,0x6df7,0x6dfb,0x6e05,0x6e1b,0x6e2c,0x6e90,0x6e96,0x6eab,0x6ed1,0x6eef,0x6efe,0x6eff,0x6f38,0x6ffe,0x70b9,0x70ba,0x7121,0x71b1,0x7247,0x7248,0x7259,0x7279,0x72c0,0x7387,0x73fe,0x74b0,0x751f,0x7528,0x7535,0x754c,0x7559,0x7565,0x7576,0x758a,0x767c,0x767d,0x7684,0x76e3,0x76e4,0x76ee,0x76f4,0x76f8,0x770b,0x771f,0x77e5,0x786c,0x78ba,0x78bc,0x793a,0x7981,0x79d2,0x79fb,0x7a0b,0x7a31,0x7a7a,0x7a97,0x7aef,0x7af6,0x7b2c,0x7b49,0x7b97,0x7bc0,0x7bc4,0x7c3d,0x7c98,0x7cbe,0x7cfb,0x7d05,0x7d1a,0x7d30,0x7d42,0x7d50,0x7d55,0x7d71,0x7d93,0x7da0,0x7dca,0x7dda,0x7de8,0x7def,0x7df4,0x7e2e,0x7e3d,0x7e8c,0x7f6e,0x7f8e,0x7fa9,0x8005,0x8017,0x806f,0x8072,0x80cc,0x80fd,0x8108,0x8173,0x81ea,0x81f3,0x8207,0x8235,0x8272,0x82f1,0x84cb,0x85cd,0x865f,0x8702,0x87ba,0x884c,0x885d,0x8868,0x8870,0x88ab,0x88dc,0x88dd,0x88fd,0x8907,0x8981,0x8986,0x8996,0x89d2,0x89e3,0x89f8,0x8a00,0x8a08,0x8a18,0x8a2a,0x8a2d,0x8a31,0x8a3b,0x8a62,0x8a66,0x8a73,0x8a8c,0x8a8d,0x8a9e,0x8aa4,0x8aaa,0x8abf,0x8acb,0x8b49,0x8b58,0x8b5c,0x8b66,0x8b70,0x8b77,0x8b8a,0x8cbc,0x8d77,0x8d85,0x8db3,0x8ddd,0x8def,0x8df3,0x8f03,0x8f09,0x8f2a,0x8f2f,0x8f38,0x8f49,0x8f91,0x8ff0,0x9000,0x901a,0x901f,0x9023,0x9032,0x903b,0x904a,0x904b,0x904e,0x9053,0x9072,0x9078,0x9084,0x908a,0x908f,0x90e8,0x91cd,0x91cf,0x91dd,0x9215,0x9304,0x932f,0x9375,0x9396,0x93e1,0x9418,0x9451,0x9577,0x9580,0x9589,0x958b,0x9592,0x9593,0x95dc,0x9640,0x9644,0x9650,0x9664,0x9670,0x969c,0x96a8,0x96d9,0x96e2,0x96fb,0x9700,0x9707,0x975c,0x9762,0x97cc,0x97f3,0x97ff,0x9801,0x9802,0x9805,0x9806,0x9810,0x983b,0x984c,0x984f,0x985e,0x986f,0x98db,0x9a45,0x9a57,0x9ad4,0x9ad8,0x9cf4,0x9ed8,0x9ede"

CN_SYMBOLS="0x4e00,0x4e0a,0x4e0b,0x4e0d,0x4e0e,0x4e2a,0x4e2d,0x4e32,0x4e3a,0x4e3b,0x4e49,0x4e4b,0x4e50,0x4e58,0x4e8c,0x4e8e,0x4eab,0x4eae,0x4ecb,0x4ece,0x4eea,0x4ef0,0x4ef6,0x4efb,0x4efd,0x4f20,0x4f3a,0x4f4d,0x4f4e,0x4f4f,0x4f53,0x4f5c,0x4f7f,0x4f8b,0x4fa7,0x4fdd,0x4fe1,0x4fee,0x4fef,0x500d,0x5012,0x503c,0x504f,0x505c,0x507f,0x50a8,0x50cf,0x5141,0x5145,0x5149,0x5165,0x5168,0x516c,0x5173,0x5176,0x5177,0x517c,0x5185,0x518c,0x5199,0x51b2,0x51c6,0x51cf,0x51fa,0x51fb,0x5206,0x5217,0x521b,0x521d,0x5220,0x522b,0x5230,0x5236,0x5237,0x524d,0x529f,0x52a0,0x52a8,0x5305,0x5316,0x533a,0x5347,0x534f,0x5355,0x5361,0x5382,0x538b,0x53c2,0x53ca,0x53cc,0x53cd,0x53d1,0x53d6,0x53d8,0x53e0,0x53e3,0x53ea,0x53ef,0x53f7,0x540c,0x540d,0x540e,0x5411,0x5417,0x5426,0x542b,0x542f,0x544a,0x547d,0x548c,0x54cd,0x5668,0x56de,0x56f4,0x56fa,0x56fd,0x56fe,0x5728,0x5730,0x5740,0x5747,0x5757,0x578b,0x57fa,0x586b,0x589e,0x58f0,0x5907,0x590d,0x5916,0x591a,0x5927,0x5929,0x592a,0x5931,0x5939,0x597d,0x59cb,0x5b50,0x5b54,0x5b58,0x5b66,0x5b83,0x5b89,0x5b8c,0x5b9a,0x5bb9,0x5bbd,0x5bf8,0x5bf9,0x5bfc,0x5c04,0x5c06,0x5c0f,0x5c3a,0x5c40,0x5c45,0x5c4f,0x5c55,0x5de5,0x5dee,0x5df2,0x5e03,0x5e26,0x5e27,0x5e38,0x5e45,0x5e55,0x5e73,0x5e74,0x5e8f,0x5e94,0x5ea6,0x5ef6,0x5efa,0x5f00,0x5f0f,0x5f15,0x5f31,0x5f39,0x5f3a,0x5f53,0x5f55,0x5f62,0x5f71,0x5f84,0x5f85,0x5f88,0x5faa,0x5fae,0x5fd7,0x5ffd,0x6001,0x6020,0x6025,0x603b,0x6062,0x606f,0x60c5,0x610f,0x611f,0x6162,0x620f,0x6210,0x6216,0x622a,0x6237,0x6240,0x6247,0x624b,0x6253,0x6267,0x6269,0x626b,0x626c,0x627e,0x62a4,0x62a5,0x62c9,0x62d2,0x62e9,0x62fe,0x6301,0x6307,0x6309,0x632f,0x6362,0x636e,0x63a5,0x63a7,0x63cf,0x63d0,0x63d2,0x6447,0x6478,0x64ad,0x64cd,0x64e6,0x652f,0x6536,0x6539,0x653e,0x6545,0x6548,0x6559,0x6570,0x6574,0x6587,0x659c,0x65ad,0x65b0,0x65b9,0x65cb,0x65e0,0x65e5,0x65f6,0x660e,0x6620,0x662f,0x663e,0x666f,0x6682,0x66f2,0x66f4,0x66ff,0x6700,0x6708,0x6709,0x670d,0x671f,0x672a,0x672c,0x673a,0x6746,0x675f,0x6761,0x6765,0x677f,0x6781,0x67c4,0x67e5,0x6807,0x680f,0x6821,0x6837,0x683c,0x68c0,0x6a21,0x6a2a,0x6b27,0x6b62,0x6b63,0x6b64,0x6b65,0x6b8a,0x6bb5,0x6bd4,0x6c60,0x6ca1,0x6cb9,0x6cbf,0x6cd5,0x6ce2,0x6ce8,0x6d32,0x6d41,0x6d4b,0x6d88,0x6df7,0x6dfb,0x6e05,0x6e10,0x6e29,0x6e38,0x6e90,0x6ed1,0x6eda,0x6ede,0x6ee1,0x6ee4,0x70b9,0x70ed,0x7247,0x7248,0x7259,0x7279,0x72b6,0x7387,0x73af,0x73b0,0x751f,0x7528,0x7535,0x754c,0x7559,0x7565,0x767d,0x7684,0x76d1,0x76d6,0x76d8,0x76ee,0x76f4,0x76f8,0x770b,0x771f,0x77e5,0x7801,0x786c,0x786e,0x793a,0x7981,0x79bb,0x79d2,0x79f0,0x79fb,0x7a0b,0x7a7a,0x7a97,0x7ade,0x7aef,0x7b2c,0x7b49,0x7b7e,0x7b97,0x7c7b,0x7c98,0x7cbe,0x7cfb,0x7d27,0x7ea2,0x7ea7,0x7eac,0x7ebf,0x7ec3,0x7ec6,0x7ec8,0x7ecf,0x7ed3,0x7edd,0x7edf,0x7eed,0x7eff,0x7f16,0x7f29,0x7f6e,0x7f8e,0x8005,0x8017,0x8054,0x80cc,0x80fd,0x8109,0x811a,0x81ea,0x81f3,0x8272,0x8282,0x82f1,0x8303,0x84dd,0x8702,0x87ba,0x884c,0x8865,0x8868,0x8870,0x88ab,0x88c5,0x8981,0x8986,0x89c6,0x89d2,0x89e3,0x89e6,0x8a00,0x8b66,0x8ba1,0x8ba4,0x8bae,0x8bb0,0x8bb8,0x8bbe,0x8bbf,0x8bc1,0x8bc6,0x8bd5,0x8be2,0x8be6,0x8bed,0x8bef,0x8bf4,0x8bf7,0x8c03,0x8c31,0x8d25,0x8d34,0x8d77,0x8d85,0x8db3,0x8ddd,0x8def,0x8df3,0x8f6c,0x8f6e,0x8f7d,0x8f83,0x8f91,0x8f93,0x8fb9,0x8fc7,0x8fd0,0x8fd8,0x8fdb,0x8fde,0x8fdf,0x8ff0,0x9000,0x9009,0x901a,0x901f,0x903b,0x9053,0x90e8,0x91c7,0x91cd,0x91cf,0x9274,0x9488,0x949f,0x94ae,0x9501,0x9519,0x952e,0x955c,0x957f,0x95e8,0x95ed,0x95ee,0x95f2,0x95f4,0x9634,0x9640,0x9644,0x9650,0x9664,0x968f,0x969c,0x9700,0x9707,0x9759,0x9762,0x97f3,0x9875,0x9876,0x9879,0x987a,0x9884,0x9891,0x9898,0x989c,0x98de,0x9a71,0x9a8c,0x9ad8,0x9e23,0x9ed8"

# https://yeun.github.io/open-arrow/
ARROWS_FONT="EdgeTX/OpenArrow-Regular.woff"
# 0x80: right, 0x81: left, 0x82: up, 0x83: down
ARROWS="0x21E8=>0x80,0x21E6=>0x81,0x21E7=>0x82,0x21E9=>0x83"

function make_font() {
  local name=$1
  local ttf=$2
  local size=$3
  local chars=$4
  local arg=$5

  lv_font_conv --no-prefilter --bpp 4 --size ${size} \
               --font ${TTF_DIR}${ttf} -r ${ASCII},${DEGREE},${BULLET},${chars} \
               --font EdgeTX/extra.ttf -r ${EXTRA_SYM} \
               --font ${ARROWS_FONT} -r ${ARROWS} \
               --font ${SYMBOLS_FONT} -r ${SYMBOLS} \
               --format lvgl -o lv_font_${name}_${size}.c --force-fast-kern-format ${arg}
}

function make_font_no_sym() {
  local name=$1
  local ttf=$2
  local size=$3
  local chars=$4
  local arg=$5
  lv_font_conv --no-prefilter --bpp 4 --size ${size} \
               --font ${TTF_DIR}${ttf} -r ${ASCII},${chars} \
               --format lvgl -o lv_font_${name}_${size}.c --force-fast-kern-format ${arg}
}

# LV_SYMBOL_CHARGE, LV_SYMBOL_NEW_LINE, LV_SYMBOL_SD_CARD, LV_SYMBOL_CLOSE
# LV_SYMBOL_FILE, LV_SYMBOL_OK
BL_SYMBOLS="61671,63650,63426,61453,61787,61452"

function make_bootloader_font() {
  local name=$1
  local ttf=$2
  local size=$3
  lv_font_conv --no-prefilter --bpp 2 --size ${size} \
               --font ${TTF_DIR}${ttf} -r ${ASCII} \
               --font ${SYMBOLS_FONT} -r ${BL_SYMBOLS} \
               --format lvgl -o lv_font_${name}_${size}.c --force-fast-kern-format
}

function make_font_set() {
  local name=$1
  local ttf_normal=$2
  local ttf_bold=$3
  local chars=$4
  
  make_font "${name}" "${ttf_normal}" 9 ${chars} --no-compress
  make_font "${name}" "${ttf_normal}" 13 ${chars} --no-compress
  make_font "${name}" "${ttf_normal}" 16 ${chars} --no-compress
  make_font "${name}" "${ttf_normal}" 17 ${chars} --no-compress
  make_font "${name}_bold" "${ttf_bold}" 16 ${chars}
  make_font "${name}_bold" "${ttf_bold}" 17 ${chars}
  make_font_no_sym "${name}" "${ttf_normal}" 24 ${chars}
  make_font_no_sym "${name}_bold" "${ttf_bold}" 32 ${chars}
}

# Regular fonts
make_font_set "roboto" "Roboto/Roboto-Regular.ttf" "Roboto/Roboto-Bold.ttf" "${LATIN1}"

# Bootloader font
make_bootloader_font "roboto_bl" "Roboto/Roboto-Regular.ttf" 16

# CJK fonts
make_font_set "noto_tw" "Noto/NotoSansCJKsc-Regular.otf" "Noto/NotoSansCJKsc-Bold.otf" "${TW_SYMBOLS}"
make_font_set "noto_cn" "Noto/NotoSansCJKsc-Regular.otf" "Noto/NotoSansCJKsc-Bold.otf" "${CN_SYMBOLS}"

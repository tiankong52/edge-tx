#include "definitions.h"
#include "lz4_fonts.h"

static const uint8_t lz4FontData[] ={
0x15,0x00,0x01,0x00,0x22,0x10,0x03,0x08,0x00,0xf0,0x08,0xb0,0x03,0x02,0x08,0x01,
0x00,0x08,0x00,0x30,0x05,0x05,0x03,0x00,0x05,0x10,0x00,0x20,0x06,0x06,0x08,0x00,
0x00,0x28,0x08,0x00,0xf3,0x15,0x0a,0x00,0xfe,0x46,0x00,0xc0,0x09,0x0a,0x08,0x00,
0x00,0x6e,0x00,0xf0,0x07,0x08,0x08,0x00,0x00,0x8e,0x00,0xa0,0x02,0x03,0x03,0x00,
0x05,0x93,0x00,0xb0,0x03,0x04,0x0a,0x00,0xfe,0xa7,0x08,0x00,0xf0,0x0a,0xbb,0x00,
0x40,0x04,0x05,0x05,0x00,0x03,0xc8,0x00,0x70,0x06,0x06,0x06,0x00,0x01,0xda,0x00,
0x10,0x03,0x03,0x04,0x00,0xfe,0xe0,0x20,0x00,0x40,0x03,0x00,0x01,0xe6,0x10,0x00,
0x40,0x02,0x00,0x00,0xe9,0x08,0x00,0x43,0x08,0x00,0x00,0xf5,0x68,0x00,0x22,0x0d,
0x01,0x08,0x00,0x13,0x25,0x08,0x00,0x13,0x3d,0x08,0x00,0x93,0x55,0x01,0x20,0x06,
0x07,0x08,0x00,0x00,0x71,0x10,0x00,0x13,0x89,0x08,0x00,0x13,0xa1,0x08,0x00,0x13,
0xb9,0x08,0x00,0x13,0xd1,0x08,0x00,0xa1,0xe9,0x01,0xb0,0x03,0x02,0x06,0x01,0x00,
0xef,0x01,0xd0,0x00,0xf2,0x04,0xfe,0xf7,0x01,0x70,0x06,0x06,0x07,0x00,0x00,0x0c,
0x02,0x70,0x06,0x06,0x05,0x00,0x01,0x1b,0x02,0x10,0x00,0x31,0x30,0x02,0xc0,0x58,
0x00,0xa2,0x4c,0x02,0xc0,0x0a,0x0b,0x0a,0x00,0xfe,0x83,0x02,0xd8,0x00,0x13,0xa3,
0x08,0x00,0x13,0xc3,0x08,0x00,0x13,0xe3,0x08,0x00,0x40,0x03,0x03,0x50,0x07,0x30,
0x00,0x22,0x1f,0x03,0x38,0x00,0x40,0x3b,0x03,0x90,0x08,0x18,0x00,0x22,0x5b,0x03,
0x20,0x00,0x22,0x7b,0x03,0xd0,0x00,0x22,0x87,0x03,0x88,0x00,0x13,0x9f,0x18,0x00,
0x13,0xbf,0x30,0x00,0x93,0xdb,0x03,0x30,0x09,0x09,0x08,0x00,0x00,0xff,0x18,0x00,
0x40,0x1f,0x04,0x90,0x08,0x10,0x00,0x22,0x43,0x04,0x58,0x00,0x10,0x5f,0x10,0x00,
0x52,0x0a,0x00,0xfe,0x8c,0x04,0x20,0x00,0x13,0xac,0x18,0x00,0x22,0xc8,0x04,0x40,
0x00,0x13,0xe4,0x18,0x00,0x31,0x04,0x05,0x50,0x08,0x00,0x93,0x24,0x05,0x60,0x0a,
0x0b,0x08,0x00,0x00,0x50,0x10,0x00,0x13,0x70,0x08,0x00,0x22,0x90,0x05,0x30,0x00,
0x22,0xac,0x05,0x90,0x01,0x22,0xc0,0x05,0x98,0x00,0x13,0xcc,0x10,0x00,0xf0,0x02,
0xe0,0x05,0x70,0x06,0x07,0x05,0x00,0x03,0xf2,0x05,0x20,0x06,0x08,0x01,0xff,0xfe,
0xf6,0x18,0x00,0xd2,0x02,0x00,0x06,0xfa,0x05,0x20,0x06,0x07,0x06,0x00,0x00,0x0f,
0x06,0x40,0x00,0x30,0x2b,0x06,0x20,0xc0,0x01,0x42,0x00,0x3d,0x06,0xc0,0x88,0x01,
0x03,0x10,0x00,0x92,0x67,0x06,0xb0,0x03,0x04,0x08,0x00,0x00,0x77,0x18,0x00,0x23,
0xfe,0x8f,0x30,0x00,0x22,0xab,0x06,0x68,0x00,0xa2,0xb7,0x06,0x10,0x03,0x04,0x0a,
0xff,0xfe,0xcb,0x06,0xb8,0x01,0x13,0xe7,0x18,0x00,0xb1,0xf3,0x06,0xc0,0x09,0x0a,
0x06,0x00,0x00,0x11,0x07,0xc0,0x68,0x00,0x13,0x26,0x08,0x00,0x21,0x3b,0x07,0x40,
0x00,0x32,0xfe,0x57,0x07,0x50,0x00,0xa2,0x6f,0x07,0x40,0x04,0x05,0x07,0x00,0x00,
0x81,0x07,0x70,0x00,0x22,0x93,0x07,0x70,0x00,0x31,0xa3,0x07,0xc0,0x10,0x00,0x22,
0xb5,0x07,0xa8,0x00,0x93,0xca,0x07,0x90,0x08,0x0a,0x06,0xff,0x00,0xe8,0x10,0x00,
0x31,0xfd,0x07,0x20,0x48,0x00,0x40,0x19,0x08,0x80,0x05,0x28,0x00,0xf3,0x02,0x2b,
0x08,0x40,0x04,0x05,0x0a,0x00,0xfe,0x44,0x08,0x10,0x03,0x03,0x0a,0x00,0xfe,0x53,
0x10,0x00,0xf1,0x13,0x6c,0x08,0x70,0x06,0x07,0x03,0x00,0x02,0x77,0x08,0x00,0x0b,
0x0a,0x09,0x01,0x00,0xa4,0x08,0x00,0x0b,0x0b,0x09,0x00,0x00,0xd6,0x08,0x00,0x0b,
0x09,0x0a,0x01,0x00,0x03,0x09,0x08,0x00,0xa0,0xff,0x30,0x09,0x00,0x0b,0x0b,0x0a,
0x00,0x00,0x67,0x10,0x00,0x40,0x0b,0x01,0xff,0x99,0x08,0x00,0x43,0x09,0x01,0x00,
0xc2,0x08,0x00,0x13,0xeb,0x18,0x00,0xa2,0x1d,0x0a,0x00,0x0b,0x07,0x0b,0x02,0xfe,
0x44,0x0a,0x18,0x00,0x50,0x6d,0x0a,0x00,0x0b,0x08,0x30,0x00,0x31,0x0a,0x50,0x0a,
0x30,0x00,0x13,0x0a,0x30,0x00,0x03,0x08,0x00,0x22,0x14,0x0b,0x08,0x00,0xf0,0x06,
0x3d,0x0b,0x00,0x0b,0x07,0x09,0x02,0x00,0x5d,0x0b,0x60,0x04,0x04,0x04,0x00,0x04,
0x65,0x0b,0x80,0x07,0x08,0xf8,0x00,0xb0,0x0b,0x10,0x07,0x07,0x07,0x00,0x00,0x9a,
0x0b,0x40,0x05,0x08,0x01,0x40,0xac,0x0b,0x60,0x06,0x10,0x00,0x31,0xc5,0x0b,0x70,
0x18,0x00,0xf1,0x04,0xde,0x0b,0x50,0x03,0x03,0x07,0x00,0x00,0xe9,0x0b,0x00,0x04,
0x04,0x07,0x00,0x00,0xf7,0x0b,0xb0,0x18,0x00,0x31,0x10,0x0c,0x90,0x08,0x00,0x30,
0x29,0x0c,0x50,0x70,0x03,0xc1,0x03,0x2f,0x0c,0x50,0x06,0x06,0x09,0x00,0xfe,0x4a,
0x0c,0x10,0xf0,0x02,0x30,0x5f,0x0c,0x50,0xc8,0x03,0x41,0x00,0x7d,0x0c,0xf0,0x68,
0x00,0x40,0x99,0x0c,0x00,0x08,0x08,0x00,0x10,0xb5,0x30,0x00,0x61,0x09,0x00,0xfe,
0xc3,0x0c,0xc0,0x50,0x00,0x31,0xd1,0x0c,0xb0,0x20,0x00,0x31,0xed,0x0c,0xd0,0x78,
0x00,0xb1,0x06,0x0d,0x70,0x07,0x07,0x09,0x00,0xfe,0x26,0x0d,0x30,0x60,0x00,0x31,
0x3f,0x0d,0x10,0x58,0x00,0x31,0x5a,0x0d,0xb0,0x20,0x00,0x31,0x73,0x0d,0x30,0x20,
0x00,0x31,0x93,0x0d,0x50,0x68,0x00,0xb1,0xa8,0x0d,0xe0,0x08,0x09,0x07,0x00,0x00,
0xc8,0x0d,0xe0,0x48,0x00,0xf2,0x03,0xe4,0x0d,0xe0,0x06,0x05,0x04,0x01,0x06,0xee,
0x0d,0xe0,0x03,0x04,0x04,0x00,0x02,0xf6,0x0d,0x90,0x00,0xa2,0x0b,0x0e,0x00,0x0b,
0x0b,0x0c,0x00,0xfe,0x4d,0x0e,0x80,0x01,0x21,0x7f,0x0e,0x70,0x01,0x23,0xff,0xb6,
0x10,0x00,0x31,0xe8,0x0e,0x90,0xd0,0x02,0xa2,0x08,0x0f,0x00,0x0b,0x0c,0x0c,0x00,
0xfe,0x50,0x0f,0x30,0x00,0x91,0x92,0x0f,0x60,0x0c,0x0d,0x0a,0x00,0xff,0xd3,0x18,
0x00,0xc2,0xff,0xfe,0x1b,0x10,0x60,0x0c,0x0d,0x09,0x00,0x00,0x56,0x10,0x20,0x00,
0x50,0x98,0x10,0x80,0x05,0x06,0x48,0x00,0x20,0x10,0x40,0x50,0x03,0x20,0xff,0xe3,
0x20,0x00,0x52,0x0c,0x00,0xfe,0x31,0x11,0x58,0x00,0xc0,0x63,0x11,0x90,0x07,0x08,
0x0c,0x00,0xfe,0x93,0x11,0xa0,0x09,0xa8,0x01,0x90,0xbf,0x11,0xa0,0x09,0x0a,0x0c,
0x00,0xfe,0xfb,0x08,0x00,0x52,0x0a,0x00,0xff,0x2d,0x12,0x08,0x00,0x22,0x5f,0x12,
0x20,0x00,0xf3,0x02,0x8b,0x12,0xa0,0x09,0x0b,0x0a,0xff,0xff,0xc2,0x12,0xe0,0x06,
0x07,0x0a,0x00,0xff,0xe5,0x08,0x00,0x22,0x08,0x13,0x28,0x00,0x10,0x3a,0x08,0x00,
0x52,0x03,0x00,0x03,0x49,0x13,0x88,0x00,0xf0,0x0c,0x84,0x13,0xc0,0x0d,0x0e,0x0c,
0x00,0xfe,0xd8,0x13,0x60,0x0c,0x0e,0x0c,0xff,0xfe,0x2c,0x14,0x00,0x0b,0x0b,0x0b,
0x00,0xff,0x69,0x14,0xa0,0x00,0x03,0x23,0x01,0x87,0x08,0x00,0xa2,0xa5,0x14,0xc0,
0x0d,0x0e,0x0a,0x00,0xff,0xeb,0x14,0x98,0x00,0x22,0x1d,0x15,0xc0,0x00,0x22,0x5f,
0x15,0xd8,0x00,0x22,0xa7,0x15,0x60,0x00,0x22,0xd9,0x15,0xa0,0x00,0x22,0x15,0x16,
0x10,0x00,0x13,0x47,0x08,0x00,0x22,0x79,0x16,0x38,0x00,0xa2,0xab,0x16,0xe0,0x06,
0x08,0x0c,0xff,0xfe,0xdb,0x16,0x28,0x00,0x22,0x17,0x17,0x08,0x00,0x22,0x53,0x17,
0x90,0x00,0xf0,0x0a,0x8e,0x17,0x00,0x0b,0x0d,0x0c,0xff,0xfe,0xdc,0x17,0x40,0x08,
0x09,0x0c,0x00,0xfe,0x12,0x18,0xc0,0x0d,0x0e,0x0b,0x00,0xff,0x5f,0x08,0x00,0x43,
0x08,0x00,0x00,0x97,0x08,0x00,0x13,0xcf,0x08,0x00,0x22,0x07,0x19,0x08,0x00,0x13,
0x3f,0x08,0x00,0x22,0x77,0x19,0xa8,0x00,0x22,0xbd,0x19,0x58,0x00,0x13,0xf9,0x08,
0x00,0x22,0x35,0x1a,0xa8,0x00,0xa2,0x7d,0x1a,0xc0,0x0d,0x0e,0x09,0x00,0x00,0xbc,
0x1a,0x60,0x00,0x60,0xf2,0x1a,0x10,0x0b,0x0c,0x08,0x50,0x06,0xf0,0xaf,0x2e,0x1a,
0x71,0x1c,0x0d,0xea,0x14,0xea,0x17,0xea,0x18,0xea,0x19,0xea,0x1d,0xea,0x1f,0xea,
0x21,0xea,0x25,0xea,0x28,0xea,0x2d,0xea,0x32,0xea,0x33,0xea,0x34,0xea,0x4a,0xea,
0x4f,0xea,0x54,0xea,0x57,0xea,0x58,0xea,0x59,0xea,0x5d,0xea,0x5e,0xea,0x5f,0xea,
0x60,0xea,0x73,0xea,0x74,0xea,0x7a,0xea,0x7c,0xea,0x7d,0xea,0x80,0xea,0x83,0xea,
0x84,0xea,0x85,0xea,0x87,0xea,0x9f,0xea,0xa1,0xea,0xd0,0xea,0xd1,0xea,0xd3,0xea,
0xd5,0xea,0xec,0xea,0xf3,0xea,0xf6,0xea,0xff,0xea,0x28,0xeb,0x30,0xeb,0x67,0xeb,
0xf7,0xeb,0x4c,0xec,0x4d,0xec,0x4e,0xec,0x4f,0xec,0x50,0xec,0x93,0xec,0x9f,0xec,
0xf9,0xec,0x10,0xed,0x66,0xef,0xce,0xf1,0xae,0xf2,0xf9,0xe8,0xe8,0xd7,0xd7,0x42,
0x74,0xf9,0x4f,0x2f,0x73,0xf1,0xe6,0x1c,0x0a,0x40,0x00,0xd0,0x76,0x02,0xb0,0xa3,
0x6e,0xed,0xfc,0x08,0x40,0xc0,0x0b,0x23,0x90,0xaf,0xde,0xe8,0x1b,0x0a,0x30,0x48,
0x0d,0x00,0x1b,0xff,0xb1,0x8e,0x58,0xe9,0x8e,0x56,0x10,0x2e,0xfd,0x70,0x00,0x7d,
0xfa,0x55,0x36,0x8e,0x9e,0x88,0xcc,0x1b,0xff,0xc3,0x00,0x36,0xc2,0x00,0xf0,0x70,
0x2d,0xd6,0x00,0x89,0x00,0x98,0x3f,0x02,0xe1,0x00,0xb6,0x1f,0x0b,0x50,0x00,0x99,
0x3e,0x5c,0x8d,0xa0,0x1c,0xd6,0xe5,0xf0,0xc5,0x00,0x09,0x84,0xd0,0xa7,0x00,0x3d,
0x02,0xf0,0xc5,0x00,0xd4,0x00,0x9c,0xb0,0x00,0x7e,0xe5,0x00,0x00,0xf3,0x7d,0x00,
0x00,0xf6,0xc8,0x00,0x02,0xef,0x70,0x10,0x2f,0xbf,0x35,0xe0,0x7e,0x08,0xdc,0x80,
0x5f,0x53,0xff,0x51,0x09,0xef,0xa9,0xe8,0x6f,0x05,0xf0,0x3b,0x00,0x02,0xf5,0x0b,
0xc0,0x1f,0x60,0x5f,0x20,0x6f,0x10,0x6f,0x10,0x5f,0x20,0x1f,0x60,0x0b,0xc0,0x02,
0xf5,0xac,0x00,0x2f,0x50,0x0b,0xb0,0x08,0xf0,0x06,0xf0,0x06,0xf0,0x08,0xf0,0x0c,
0xb0,0x2f,0x50,0xbc,0x00,0x06,0xb0,0x0c,0xcd,0xd1,0x2e,0xf5,0x05,0xb7,0xa0,0x83,
0x00,0x40,0x48,0x00,0x00,0x6d,0x03,0x00,0xf4,0x37,0x8f,0xff,0xff,0x13,0x8d,0x33,
0x00,0x6d,0x00,0x2a,0x33,0xf5,0x0a,0x20,0x60,0x01,0x10,0x9f,0xf3,0x24,0x40,0x2a,
0x34,0xf4,0x06,0xd0,0x9a,0x0d,0x70,0xf4,0x3f,0x16,0xe0,0x9b,0x0c,0x80,0x06,0xee,
0x70,0x2f,0x76,0xf3,0x7f,0x00,0xe8,0x8f,0x00,0xda,0x8f,0x00,0xd9,0x6f,0x00,0xf8,
0x2f,0x77,0xf3,0x06,0xee,0x70,0x03,0xdf,0x10,0x3e,0xbf,0x10,0x11,0x7f,0x10,0x00,
0x03,0x00,0xf2,0xc1,0x02,0x8f,0x31,0x5f,0xff,0xfd,0x08,0xee,0xa0,0x5f,0x76,0xf6,
0x13,0x00,0xf7,0x00,0x0a,0xf2,0x00,0xaf,0x60,0x0a,0xf4,0x00,0x6f,0x94,0x42,0xaf,
0xff,0xfa,0x09,0xef,0xa0,0x7f,0x66,0xf7,0x00,0x03,0xf5,0x00,0xcf,0x90,0x00,0x26,
0xf6,0x46,0x00,0xda,0x7f,0x66,0xf8,0x09,0xee,0xa0,0x00,0x0e,0xf0,0x00,0x09,0xef,
0x00,0x03,0xe7,0xf0,0x00,0xd6,0x6f,0x00,0x8b,0x06,0xf0,0x0d,0xff,0xff,0xf0,0x22,
0x27,0xf3,0x00,0x00,0x6f,0x00,0x3f,0xff,0xf6,0x4f,0x42,0x20,0x5f,0x10,0x00,0x5f,
0xcf,0xc1,0x4a,0x65,0xfa,0x01,0x00,0xcc,0x7f,0x65,0xf8,0x0a,0xfe,0xa0,0x05,0xef,
0xa0,0x1f,0x95,0xf5,0x6f,0x00,0x00,0x8e,0xae,0xb1,0x8f,0x64,0xf8,0x7f,0x00,0xda,
0x2f,0x85,0xf7,0x05,0xdf,0xa0,0x8f,0xff,0xfa,0x24,0x44,0xf7,0x00,0x08,0xd0,0x00,
0x2f,0x50,0x00,0x9e,0x00,0x00,0xf8,0x00,0x04,0xf4,0x00,0x05,0xf3,0x00,0x09,0xef,
0xb1,0x5f,0x54,0xf7,0x5f,0x31,0xf7,0x0a,0xff,0xb0,0x5f,0x54,0xf7,0x9e,0x00,0xcb,
0x7f,0x43,0xf9,0x09,0xef,0xa1,0x09,0xee,0x70,0x6f,0x67,0xf4,0x9e,0x00,0xe9,0x7f,
0x33,0xfa,0x1d,0xfd,0xea,0x00,0x10,0xe8,0x4f,0x68,0xf3,0x09,0xfe,0x60,0xf9,0x75,
0x00,0x00,0x75,0xf9,0x06,0x00,0xf0,0x08,0x67,0x61,0x00,0x00,0x17,0x00,0x5b,0xfb,
0x5e,0xe8,0x20,0x8e,0x40,0x00,0x29,0xee,0x71,0x00,0x05,0xbf,0x00,0x00,0x02,0x3b,
0x01,0x51,0x33,0x33,0x00,0x00,0x00,0x09,0x00,0xf0,0xa9,0x32,0x44,0x00,0x00,0x5e,
0xe8,0x20,0x00,0x5c,0xfb,0x00,0x01,0xaf,0x05,0xbf,0xc5,0x8e,0x82,0x00,0x10,0x00,
0x00,0x05,0xdf,0xc3,0x03,0xf9,0x4c,0xe0,0x26,0x00,0x8f,0x00,0x00,0x3f,0xa0,0x00,
0x3f,0x90,0x00,0x05,0x90,0x00,0x00,0x46,0x00,0x00,0x0a,0xe0,0x00,0x00,0x06,0xcc,
0xcb,0x30,0x00,0x0b,0x70,0x00,0x2c,0x30,0x08,0x61,0xab,0x8d,0x2c,0x00,0xd0,0xa4,
0x08,0xb0,0xc0,0x49,0x0d,0x00,0x77,0x0c,0x05,0x82,0xc0,0x0a,0x40,0xd0,0x4a,0x0d,
0x04,0xe3,0x77,0x00,0xd1,0x6b,0x84,0xb8,0x00,0x05,0xc2,0x00,0x16,0x20,0x00,0x03,
0xac,0xca,0x60,0x00,0x00,0x2f,0xf1,0x00,0x00,0x7f,0xf6,0x00,0x00,0xdb,0xcc,0x00,
0x02,0xf6,0x7f,0x10,0x08,0xf1,0x2f,0x70,0x0d,0xff,0xff,0xc0,0x3f,0x83,0x38,0xf2,
0x8f,0x10,0x01,0xf7,0x4f,0xff,0xfd,0x40,0x4f,0x73,0x4d,0xe0,0x4f,0x50,0x0b,0xd0,
0x4f,0xff,0xff,0x40,0x4f,0x73,0x3a,0xf2,0x4f,0x50,0x02,0xf6,0x4f,0x73,0x39,0xf3,
0x4f,0xff,0xfd,0x60,0x01,0xae,0xfc,0x40,0x0d,0xe6,0x4b,0xf3,0x5f,0x50,0x00,0x61,
0x8f,0x10,0x00,0xb9,0x01,0x50,0x00,0x5f,0x50,0x00,0x93,0x14,0x00,0x00,0x1c,0x00,
0xf1,0x01,0x4f,0xff,0xe9,0x10,0x4f,0x74,0x7f,0xc0,0x4f,0x50,0x07,0xf4,0x4f,0x50,
0x02,0xf7,0x3c,0x00,0xf0,0x09,0x50,0x07,0xf3,0x4f,0x73,0x6f,0xb0,0x4f,0xff,0xe9,
0x00,0x4f,0xff,0xff,0xb4,0xf7,0x44,0x42,0x4f,0x50,0x00,0x04,0xf5,0x00,0x0e,0x00,
0xb1,0x54,0xf7,0x33,0x31,0x4f,0x73,0x33,0x34,0xff,0xff,0xfe,0x0e,0x00,0x26,0x44,
0x41,0x1c,0x00,0x43,0x34,0xf7,0x33,0x30,0x0e,0x00,0xd1,0x01,0xae,0xfd,0x60,0x0d,
0xe7,0x4a,0xf6,0x5f,0x50,0x00,0x62,0x7f,0x78,0x00,0xf1,0x03,0x6f,0xfe,0x5f,0x60,
0x13,0xae,0x0d,0xf7,0x47,0xed,0x01,0xae,0xfd,0x81,0x4f,0x50,0x06,0xf3,0x04,0x00,
0xa2,0x51,0x16,0xf3,0x4f,0xff,0xff,0xf3,0x4f,0x74,0x48,0x10,0x00,0x04,0x04,0x00,
0x25,0x54,0xf5,0x03,0x00,0x83,0x00,0xbf,0xf5,0x00,0x36,0xf5,0x00,0x03,0x03,0x00,
0xf4,0x1a,0x35,0x03,0xf5,0x9f,0x5a,0xf2,0x1b,0xfe,0x60,0x4f,0x50,0x0b,0xe2,0x4f,
0x50,0xaf,0x30,0x4f,0x59,0xf3,0x00,0x4f,0xdf,0x80,0x00,0x4f,0xdb,0xf3,0x00,0x4f,
0x50,0xdd,0x10,0x4f,0x50,0x2f,0xb0,0x4f,0x50,0x06,0xf7,0x99,0x00,0x0a,0x07,0x00,
0xf7,0x74,0x73,0x33,0x14,0xff,0xff,0xf6,0x4f,0xf0,0x00,0xdf,0x64,0xff,0x50,0x2f,
0xf6,0x4f,0xb9,0x06,0xcf,0x64,0xf7,0xe0,0xb8,0xf6,0x4f,0x3f,0x4f,0x3f,0x64,0xf2,
0xbc,0xe0,0xf6,0x4f,0x27,0xf9,0x0f,0x64,0xf2,0x2f,0x40,0xf6,0x4f,0xc0,0x03,0xf3,
0x4f,0xf5,0x03,0xf3,0x4f,0xbd,0x03,0xf3,0x4f,0x3f,0x63,0xf3,0x4f,0x28,0xe4,0xf3,
0x4f,0x21,0xea,0xf3,0x4f,0x20,0x7f,0xf3,0x4f,0x20,0x0e,0xf3,0x01,0x9e,0xfd,0x50,
0x00,0xdf,0x75,0xbf,0x60,0x5f,0x50,0x00,0xdd,0x08,0xf1,0x00,0x09,0xf0,0x7f,0x10,
0x00,0x9f,0x04,0xf5,0x00,0x0d,0xd0,0x0c,0xf6,0x5a,0xf5,0x00,0x19,0xef,0xc5,0x00,
0x4f,0xff,0xfb,0x24,0xf7,0x45,0xfb,0x4f,0x50,0x0a,0xe4,0xf5,0x02,0xec,0x4f,0xff,
0xfe,0x34,0xf7,0x32,0x00,0x24,0x01,0x4b,0x00,0xde,0x75,0xaf,0x40,0x00,0x10,0xf6,
0x40,0x00,0xf0,0x1d,0xf8,0x6b,0xf4,0x00,0x08,0xdf,0xc4,0x00,0x00,0x01,0xfb,0x31,
0x00,0x00,0x05,0xef,0x40,0x4f,0xff,0xfd,0x50,0x4f,0x74,0x4b,0xf2,0x4f,0x50,0x04,
0xf4,0x4f,0x50,0x09,0xf2,0x4f,0xff,0xff,0x60,0x4f,0x73,0xaf,0x10,0x4f,0x50,0x1e,
0xed,0x00,0xfa,0x1c,0xf6,0x06,0xdf,0xea,0x02,0xf8,0x26,0xf8,0x4f,0x70,0x01,0x00,
0xcf,0xea,0x50,0x00,0x48,0xdf,0x81,0x40,0x00,0xcd,0x6f,0x83,0x5e,0xb0,0x7d,0xfe,
0xa1,0xef,0xff,0xff,0x93,0x49,0xf5,0x42,0x00,0x7f,0x20,0x00,0x07,0xf2,0x00,0x07,
0x00,0x4c,0x5f,0x40,0x05,0xf4,0x04,0x00,0xf4,0x80,0x4f,0x50,0x07,0xf2,0x0e,0xd5,
0x5e,0xd0,0x03,0xcf,0xfb,0x20,0xbe,0x00,0x08,0xf1,0x6f,0x20,0x0d,0xb0,0x1f,0x70,
0x2f,0x60,0x0b,0xc0,0x6f,0x10,0x05,0xf1,0xbb,0x00,0x00,0xf6,0xf5,0x00,0x00,0xae,
0xf0,0x00,0x00,0x4f,0xa0,0x00,0xdb,0x00,0xcf,0x30,0x5f,0x49,0xe0,0x0f,0xf6,0x08,
0xf0,0x6f,0x23,0xfb,0xa0,0xbc,0x02,0xf5,0x7d,0x7e,0x0f,0x80,0x0e,0x9a,0x93,0xf4,
0xf4,0x00,0xac,0xd6,0x0f,0xaf,0x00,0x06,0xff,0x20,0xcf,0xc0,0x00,0x2f,0xf0,0x09,
0xf8,0x00,0x5f,0x40,0x0e,0xb0,0x0b,0xd0,0x8f,0x20,0x02,0xf9,0xf8,0x00,0x00,0x7f,
0xe0,0x00,0x00,0xbf,0xf2,0x00,0x05,0xf6,0xeb,0x00,0x1e,0xb0,0x5f,0x50,0x9f,0x10,
0x0b,0xe0,0x8f,0x20,0x0c,0xd0,0x0e,0xa0,0x5f,0x40,0x06,0xf3,0xdb,0x00,0x00,0xce,
0xf2,0x00,0x00,0x4f,0x90,0x00,0x00,0x1f,0x70,0x04,0x00,0x00,0x63,0x02,0xf7,0x10,
0x31,0x44,0x4e,0xd0,0x00,0x07,0xf3,0x00,0x03,0xf7,0x00,0x01,0xeb,0x00,0x00,0xae,
0x10,0x00,0x6f,0x84,0x44,0x1a,0xff,0xff,0xf6,0x6f,0xf8,0x6f,0x10,0x6f,0x00,0x02,
0x00,0xfb,0x03,0x10,0x6f,0xf8,0xc7,0x09,0xa0,0x6e,0x03,0xf1,0x0f,0x40,0xd7,0x0a,
0xa0,0x7d,0xdf,0xf0,0x06,0x02,0x00,0xf4,0x82,0xdf,0xf0,0x00,0xdf,0x40,0x00,0x4e,
0x8b,0x00,0x0b,0x71,0xf2,0x02,0xf1,0x0a,0x80,0x8a,0x00,0x4e,0x00,0x06,0x66,0x66,
0x61,0x47,0x00,0x08,0xb0,0x09,0xef,0x90,0x03,0xc4,0x4f,0x40,0x1b,0xdd,0xf5,0x08,
0xf1,0x2f,0x60,0x9f,0x19,0xf7,0x03,0xde,0x6a,0xf2,0x3f,0x40,0x00,0x03,0xf4,0x00,
0x00,0x3f,0x8e,0xe6,0x03,0xfa,0x1b,0xf0,0x3f,0x40,0x5f,0x33,0xf4,0x05,0xf3,0x3f,
0xa1,0xbf,0x04,0xf7,0xee,0x50,0x06,0xef,0xa0,0x3f,0x62,0xe8,0x7f,0x00,0x00,0x7f,
0x00,0x00,0x3f,0x72,0xe9,0x07,0xee,0xa0,0x00,0x00,0x9f,0x00,0x00,0x9f,0x09,0xfc,
0xaf,0x4f,0x72,0xef,0x7f,0x10,0x9f,0x7f,0x10,0x9f,0x4f,0x72,0xef,0x09,0xfc,0xaf,
0x07,0xee,0xa0,0x4f,0x31,0xe7,0x7f,0xff,0xfa,0x7f,0x10,0x00,0x4f,0x72,0xc5,0x07,
0xef,0xa0,0x08,0xfa,0x0f,0xa0,0xdf,0xfb,0x0f,0x80,0x02,0x00,0x38,0x09,0xfd,0x9f,
0x34,0x00,0x94,0x0a,0xfc,0xae,0x17,0x40,0xcc,0x09,0xef,0xc2,0x80,0x00,0xf3,0x00,
0x7d,0xe5,0x03,0xfb,0x3c,0xe0,0x3f,0x50,0x7f,0x03,0xf4,0x07,0xf0,0x3f,0x40,0x07,
0x00,0x42,0x20,0x3f,0x43,0xf4,0x03,0x00,0x66,0x03,0xf4,0x00,0x20,0x03,0xf4,0x02,
0x00,0x44,0x06,0xf4,0x2f,0xc0,0x3c,0x00,0xf4,0x05,0x42,0xe8,0x03,0xf5,0xda,0x00,
0x3f,0xef,0x10,0x03,0xfa,0xea,0x00,0x3f,0x46,0xf3,0x03,0xf4,0x0c,0xc0,0x39,0x00,
0x00,0x03,0x00,0xfb,0x00,0x4f,0x7e,0xe4,0xcf,0x70,0x3f,0xa2,0xfe,0x2a,0xf0,0x3f,
0x40,0xdb,0x06,0xf1,0x05,0x00,0x6b,0x4f,0x7e,0xe5,0x03,0xfa,0x1c,0x7b,0x00,0xf7,
0x0c,0x06,0xdf,0xc3,0x03,0xf7,0x1b,0xe0,0x7f,0x10,0x5f,0x37,0xf1,0x05,0xf3,0x3f,
0x71,0xbe,0x00,0x6d,0xfc,0x30,0x4f,0x8d,0xe6,0x03,0xf9,0x0a,0x25,0x01,0x43,0x03,
0xf9,0xee,0x50,0x85,0x00,0x2c,0x09,0xfd,0x14,0x01,0x31,0x00,0x00,0x8f,0x03,0x00,
0xf2,0x26,0x04,0xf8,0xf1,0x3f,0xb3,0x03,0xf5,0x00,0x3f,0x40,0x03,0xf4,0x00,0x3f,
0x40,0x00,0x09,0xef,0xa0,0x4f,0x31,0xa4,0x2f,0xe9,0x40,0x01,0x7b,0xf6,0x4a,0x11,
0xd9,0x1b,0xff,0xb1,0x05,0x20,0x0e,0x50,0xdf,0xf7,0x2f,0x60,0x2f,0x50,0x2f,0x50,
0x1f,0x80,0x0c,0xf7,0x5f,0x30,0x9f,0x03,0x00,0xf8,0x8c,0x4f,0x30,0x9f,0x3f,0x93,
0xef,0x0a,0xfc,0x8f,0xcc,0x00,0xae,0x06,0xf1,0x0f,0x80,0x1f,0x64,0xf2,0x00,0xbb,
0x9d,0x00,0x06,0xfe,0x70,0x00,0x1f,0xf1,0x00,0x0e,0x70,0xaf,0x30,0xe7,0x0a,0xb0,
0xed,0x72,0xf3,0x06,0xe2,0xf7,0xb5,0xe0,0x02,0xf8,0xb2,0xf9,0xa0,0x00,0xee,0x70,
0xee,0x60,0x00,0xaf,0x30,0xaf,0x20,0x7f,0x21,0xe9,0x00,0xcb,0xad,0x00,0x02,0xff,
0x30,0x00,0x3f,0xf4,0x00,0x0d,0xa8,0xe1,0x09,0xe1,0x0d,0xa0,0xbd,0x00,0xad,0x04,
0xf3,0x0f,0x70,0x0e,0x84,0xf1,0x00,0x7d,0x9b,0x00,0x01,0xff,0x50,0x00,0x0b,0xe0,
0x00,0x03,0xf8,0x00,0x06,0xfb,0x00,0x00,0x5f,0xff,0xd0,0x01,0x4f,0x80,0x00,0xcc,
0x00,0x08,0xf2,0x00,0x4f,0x81,0x10,0x9f,0xff,0xf1,0x04,0xef,0x00,0x9f,0x10,0x09,
0xd0,0x00,0xcc,0x00,0xcf,0x30,0x02,0xda,0x00,0x09,0xc0,0x00,0x9d,0x00,0x08,0xe1,
0x00,0x3e,0xf0,0x2f,0x42,0xf4,0x03,0x00,0xf0,0x12,0xcf,0x70,0x00,0xbd,0x00,0x08,
0xe0,0x00,0x7f,0x10,0x01,0xdf,0x10,0x6f,0x40,0x08,0xe0,0x00,0x8e,0x00,0x0b,0xd0,
0x0c,0xf6,0x00,0x4d,0xd6,0x05,0x06,0x35,0xdf,0xd0,0x00,0x48,0x06,0x20,0x00,0x2b,
0xb5,0x07,0xf0,0x0e,0x3e,0xb0,0x00,0xcd,0xdd,0xea,0x89,0x00,0xe1,0x11,0x10,0x0a,
0x80,0xe0,0x00,0x00,0x01,0xf1,0xe3,0x33,0x31,0x0c,0x60,0xab,0xbb,0xcb,0xa7,0x00,
0x00,0x5d,0x06,0x30,0x00,0x00,0x19,0x28,0x00,0x10,0x79,0x05,0x00,0xf0,0x14,0x6e,
0xb0,0x00,0x00,0x00,0x6d,0x4f,0xdd,0xdd,0x00,0x6d,0x10,0x00,0x00,0xd1,0x0f,0x50,
0x00,0x00,0x0d,0x10,0x4e,0x30,0x33,0x33,0xd1,0x00,0x4e,0x5e,0xbb,0xba,0x00,0x00,
0x4f,0xb0,0x27,0x00,0x15,0x47,0xb0,0x0f,0xf1,0x0f,0xad,0x20,0x00,0x00,0xb6,0x2d,
0x20,0x00,0xb7,0x00,0x2d,0x20,0xaf,0xb0,0x08,0xde,0x12,0x3d,0x20,0xc4,0x30,0x00,
0xc2,0x0c,0x20,0x00,0x0c,0x20,0xc2,0x00,0x09,0x00,0x86,0x0b,0xee,0xf1,0x00,0x00,
0xbe,0xef,0x10,0x12,0x00,0x00,0x09,0x00,0xf9,0x07,0x9c,0xf1,0x0c,0xdc,0x15,0xf3,
0x00,0x0c,0xa0,0x07,0xd1,0x08,0xc0,0x00,0x08,0xb7,0xd0,0x00,0x00,0x09,0xd1,0x00,
0x01,0x00,0x10,0xc1,0x05,0x00,0xd0,0x68,0x80,0x00,0x00,0x00,0x0b,0x0a,0x10,0x00,
0x00,0x06,0x50,0x28,0x19,0x10,0xf4,0x09,0x00,0xa1,0x00,0x00,0x65,0x00,0x02,0x90,
0x00,0x0b,0x00,0x00,0x09,0x10,0x06,0x50,0x00,0x00,0x29,0x00,0xda,0xaa,0xaa,0xaa,
0x3d,0x00,0xf0,0x0f,0x69,0xa1,0x00,0x39,0x5f,0x01,0x80,0x78,0x04,0xf1,0x66,0x38,
0x00,0x93,0xff,0x18,0x10,0x0b,0xa4,0x17,0x90,0x02,0xc2,0x00,0x98,0x20,0x20,0x00,
0x27,0x29,0x34,0x00,0xf3,0x4b,0x49,0x20,0x39,0x40,0x00,0x16,0x86,0x10,0x00,0x00,
0x46,0x66,0x00,0x00,0xa6,0xef,0x8b,0x50,0x69,0x24,0xc0,0x4d,0x24,0x50,0x00,0x00,
0x72,0xc5,0x00,0x00,0x0b,0x6a,0x80,0x00,0x00,0xa6,0x0e,0x40,0x00,0x7d,0x00,0x2e,
0x98,0xad,0x00,0x00,0x15,0x44,0x00,0x00,0x04,0x87,0x97,0x10,0x03,0x48,0xa0,0x29,
0x40,0x89,0x05,0x80,0x0a,0x16,0x96,0x89,0x00,0x27,0x80,0x59,0x00,0x00,0x97,0x20,
0x00,0x00,0x27,0x19,0x00,0x00,0x09,0x20,0x58,0x10,0x18,0x50,0x00,0x28,0x98,0x20,
0x83,0x00,0xf0,0x3d,0xb9,0x99,0xc3,0x00,0x37,0x00,0x0a,0x00,0x09,0x10,0x03,0x70,
0x00,0xd1,0x02,0xa1,0x00,0x99,0x93,0xf0,0x00,0x55,0x0a,0x95,0x60,0x08,0x03,0x89,
0x09,0x00,0x63,0x31,0x03,0x70,0x00,0xa3,0x03,0xb0,0x00,0x00,0x68,0x60,0x00,0x00,
0x00,0x87,0xa0,0x00,0x07,0x07,0x00,0x67,0xde,0xe7,0x67,0x00,0x00,0x07,0x70,0x77,
0x70,0x77,0x07,0x77,0x07,0x70,0x00,0x00,0x77,0x7d,0xff,0x76,0x00,0x70,0x70,0x00,
0xd7,0x0c,0xf1,0x1c,0x57,0x60,0x00,0x00,0x01,0x9d,0xeb,0x19,0x81,0xed,0x65,0x70,
0x93,0xff,0x00,0x00,0x09,0x00,0x88,0x00,0x00,0x90,0x01,0xb2,0x00,0x09,0x07,0xc1,
0x00,0x00,0x97,0xfd,0x00,0x00,0x08,0x41,0xdd,0x76,0x80,0x00,0x01,0x8c,0xda,0x80,
0x00,0xf0,0x49,0x97,0xfe,0x66,0x6c,0x90,0x94,0x2a,0xff,0x90,0xb6,0x7e,0xff,0x90,
0xf8,0x00,0x4b,0x90,0x00,0x00,0x09,0x90,0xf9,0x00,0x09,0x90,0x84,0x00,0x09,0x90,
0xe8,0x00,0x09,0x97,0xfd,0x77,0x7c,0x01,0x11,0x11,0x11,0x00,0x4e,0xf4,0x00,0x00,
0x86,0xaa,0x5a,0x00,0x56,0x09,0x80,0x47,0x0a,0x00,0x89,0x00,0xa0,0x90,0x56,0x2b,
0x3a,0x0a,0x79,0xb4,0x9a,0xf0,0x8f,0xa1,0x01,0xdf,0x00,0xc7,0x10,0x59,0x00,0x00,
0x38,0x84,0x00,0x00,0x06,0xca,0x20,0x00,0x04,0xff,0xfd,0xb6,0x08,0xf0,0x11,0xf5,
0xdd,0x35,0xff,0xfe,0xcf,0xfb,0x08,0xff,0x9c,0xff,0xa0,0xc5,0x8f,0xff,0xf1,0x67,
0x4f,0xff,0xff,0x79,0x3c,0xff,0xff,0xfb,0x7c,0xb9,0x99,0x99,0x70,0x00,0x04,0x04,
0x01,0x11,0x1c,0x05,0x00,0xf0,0x02,0x30,0x08,0xff,0xff,0xff,0x40,0x28,0x88,0x88,
0x88,0x10,0x6f,0xff,0xff,0xf6,0x00,0x5a,0x9b,0x00,0x10,0x4b,0x05,0x00,0xf0,0x28,
0x32,0x00,0x00,0x00,0x01,0xaa,0x71,0x00,0x00,0x19,0x64,0xa5,0x00,0x00,0x44,0xa6,
0x20,0x00,0x08,0xb5,0x10,0x02,0x95,0x69,0x20,0x01,0xe5,0x56,0x4e,0x10,0x6f,0x2e,
0xf0,0xf5,0x00,0xc8,0x33,0x6c,0x00,0x00,0x77,0x76,0x00,0x00,0xc9,0x99,0xc3,0x09,
0x00,0x90,0xa3,0x90,0x08,0x95,0xa9,0xc6,0x00,0x36,0x00,0x00,0x99,0x07,0x00,0xf7,
0x52,0xd9,0x99,0x99,0xc0,0x0a,0xc3,0x67,0x1c,0x67,0x1c,0x0a,0xc3,0x1e,0xc0,0x08,
0xe0,0x04,0xf7,0x0a,0xc0,0x04,0xff,0x3e,0x80,0x0e,0x9d,0xfd,0x10,0x2f,0x43,0xf9,
0x00,0x5f,0x10,0x7f,0x40,0x8f,0x00,0x0c,0xe1,0x5f,0xfe,0xb1,0x01,0x55,0x6f,0xa0,
0x00,0x00,0x9d,0x00,0x00,0x08,0xf0,0x00,0x00,0x8f,0x02,0x44,0x4a,0xf3,0x9f,0xff,
0xff,0xa0,0x2f,0xe3,0x00,0x5d,0xb0,0x00,0x6f,0x00,0x2a,0xf3,0x0e,0xcf,0x75,0xf2,
0xca,0x8e,0x08,0xe0,0xcf,0xff,0xff,0x13,0x55,0x6f,0x80,0x00,0x02,0xf4,0x00,0x00,
0x2f,0x40,0x07,0x00,0xf2,0x03,0x3f,0xff,0xe8,0x00,0x55,0x59,0xf5,0x00,0x00,0x0f,
0x81,0xf6,0x00,0xe9,0x1f,0x60,0x0e,0x91,0x07,0x00,0x43,0x90,0x1f,0x61,0xf6,0x03,
0x00,0xb0,0x60,0x86,0x10,0x7f,0xfa,0x05,0xf9,0x0c,0xa0,0x0d,0x90,0x02,0x00,0xf2,
0x03,0x1f,0xff,0xea,0x01,0xf9,0x57,0xf8,0x1f,0x60,0x0b,0xc1,0xf6,0x00,0xad,0x1f,
0x60,0x0a,0xd1,0x07,0x00,0xf1,0x0b,0xd0,0x2f,0x55,0xfd,0x32,0xf5,0x24,0xdb,0x2f,
0x50,0x09,0xe2,0xf5,0x00,0x8f,0x1f,0x60,0x0b,0xd0,0xdd,0x58,0xf8,0x03,0xcf,0xe9,
0x00,0x45,0x00,0xdb,0x83,0xcf,0xfe,0x70,0x35,0x5a,0xf3,0x00,0x00,0xf6,0x00,0x00,
0xf7,0x03,0x00,0x90,0x9f,0xfc,0x40,0x25,0x5c,0xf1,0x00,0x02,0xf5,0x0f,0x00,0xc1,
0x02,0xf5,0x24,0x5c,0xf1,0x9f,0xfc,0x40,0x12,0x00,0x00,0xad,0x03,0x00,0xf2,0x15,
0xaf,0xff,0xc2,0x35,0x56,0xea,0x00,0x00,0xbb,0x00,0x02,0xf7,0x00,0x3e,0xe0,0x0b,
0xfd,0x20,0x0c,0x60,0x00,0x1f,0xff,0xfb,0x20,0x1f,0x95,0x6e,0xc0,0x1f,0x60,0x07,
0xf0,0x1f,0x60,0x06,0x04,0x00,0xf6,0x14,0x94,0x49,0xf0,0x1f,0xff,0xff,0xf0,0x7f,
0x4c,0xfc,0x20,0x0e,0xfc,0x6d,0xc0,0x08,0xf2,0x07,0xf0,0x0c,0xc0,0x05,0xf1,0x0f,
0x80,0x05,0xf1,0x4f,0x41,0x48,0xf1,0x8f,0x05,0xff,0xf1,0xd7,0x00,0x00,0x95,0x00,
0x60,0x5f,0xe3,0x15,0xeb,0x00,0x9d,0x02,0x00,0xf0,0x28,0x24,0xbd,0x9f,0xfd,0xbf,
0xff,0xeb,0x20,0x3e,0x95,0x6e,0xc0,0x2f,0x40,0x08,0xf0,0x4f,0x30,0x07,0xf0,0x2f,
0x50,0x09,0xe0,0x0d,0xd5,0x7f,0x90,0x02,0xbf,0xe9,0x00,0x5f,0x30,0x4f,0x30,0xf8,
0x04,0xf2,0x0a,0xe0,0x6f,0x10,0x4f,0x3a,0xd0,0x00,0xec,0xf7,0x05,0x7e,0xfb,0x00,
0xce,0xb6,0xd9,0x09,0xf5,0x06,0xe8,0x04,0xf6,0x59,0xf5,0x4f,0x30,0x0f,0x84,0xff,
0x70,0xe8,0x13,0x31,0x0e,0x80,0x00,0x00,0xe8,0x00,0x00,0x07,0x00,0xf0,0x18,0x3f,
0xff,0xd6,0x03,0xf7,0x5a,0xf3,0x3f,0x40,0x0f,0x73,0xff,0x80,0xe8,0x03,0x32,0x0f,
0x70,0x44,0x5b,0xf2,0x2f,0xff,0xc4,0x00,0xae,0x10,0xcb,0x1e,0x90,0xda,0x07,0xf2,
0xf7,0x03,0xfe,0xd1,0x03,0xf7,0xfb,0x05,0x05,0x03,0x00,0xff,0x2a,0x9f,0x20,0x5f,
0x20,0xdc,0x07,0xf0,0x03,0xf8,0xcc,0x00,0x07,0xfd,0x20,0x00,0x0c,0xe1,0x02,0x44,
0x6f,0xb0,0x8f,0xff,0xff,0x10,0x5f,0xff,0xfa,0x01,0x55,0x57,0xf7,0x02,0x00,0x0e,
0x81,0xf6,0x01,0xf6,0x1f,0x60,0xaf,0x11,0xf6,0xbf,0x50,0x1f,0x6d,0x40,0x01,0xf6,
0x00,0x00,0x1f,0x60,0x00,0x00,0x64,0x01,0x02,0xf4,0x1d,0x9e,0x03,0xf4,0x1f,0x66,
0xf1,0x4f,0x33,0xf4,0x3f,0x46,0xf1,0x5f,0x21,0xfc,0xfb,0x07,0xf0,0x0e,0xd5,0x00,
0xcc,0x00,0xbd,0x46,0xcf,0x50,0x08,0xff,0xda,0x40,0x00,0x9f,0xff,0xfc,0x20,0x3b,
0xe5,0x6e,0xc0,0x09,0xd0,0x07,0xf0,0x04,0x00,0xf0,0x20,0x3e,0xb0,0x07,0xf0,0xae,
0x30,0x07,0xf0,0x16,0x14,0x44,0xf1,0xe6,0x8a,0x1f,0x1b,0x45,0xb0,0x01,0x00,0x4f,
0xf2,0x9f,0xf6,0x3e,0xc1,0x89,0x40,0x00,0x39,0xee,0x93,0x00,0x04,0xbe,0x01,0x7c,
0xfb,0x8f,0xc6,0x10,0x54,0x33,0x32,0x9f,0xff,0xfe,0xfe,0x02,0xf0,0x0b,0x59,0xb0,
0x00,0x02,0x7b,0xff,0xff,0x00,0x1d,0xff,0xff,0xff,0xf0,0x04,0xff,0xff,0xc7,0x8f,
0x00,0x4f,0xa5,0x10,0x06,0xf0,0x04,0xf2,0xbc,0x0c,0x31,0x4f,0x20,0x00,0x0b,0x00,
0xf0,0x00,0x8e,0xff,0x28,0xaf,0x20,0x0f,0xff,0xfe,0xff,0xf1,0x00,0x5b,0xb4,0x9f,
0xfb,0x39,0x00,0x11,0x11,0x21,0x15,0xf0,0x3b,0x34,0x44,0x44,0x30,0x1d,0x9f,0xdc,
0xcc,0xdf,0x9d,0xb2,0xf1,0x00,0x01,0xf2,0xcd,0x8f,0x10,0x00,0x1f,0x8d,0xc3,0xfb,
0xaa,0xab,0xf3,0xcd,0x7f,0x76,0x66,0x7f,0x7d,0xc4,0xf1,0x00,0x01,0xf4,0xcd,0x6f,
0x20,0x00,0x2f,0x6d,0xb5,0xff,0xff,0xff,0xf5,0xb0,0xef,0xe3,0xef,0xff,0xff,0xdf,
0xff,0x5f,0xff,0xff,0xff,0xbc,0xc2,0xcc,0xcc,0xcc,0xb7,0x87,0x07,0x88,0x88,0x86,
0xff,0xf5,0xff,0x01,0x00,0xc0,0x4f,0xff,0xff,0xff,0x35,0x40,0x45,0x55,0x55,0x3f,
0xff,0x3f,0x10,0x00,0x00,0x16,0x00,0x70,0xfa,0xba,0x1a,0xbb,0xbb,0xba,0x00,0xa5,
0x03,0x00,0x05,0x00,0x20,0x04,0xf9,0x05,0x00,0xf0,0x0a,0xff,0xc1,0x50,0x00,0x04,
0xff,0xc0,0xcf,0x80,0x04,0xff,0xc0,0x08,0xff,0x84,0xff,0xc0,0x00,0x09,0xff,0xff,
0xc0,0x00,0x00,0x09,0x05,0x00,0x20,0x00,0x08,0x17,0x06,0xf0,0x14,0x7b,0x00,0x04,
0xc2,0xdf,0xc0,0x4f,0xf6,0x2e,0xfd,0xff,0x90,0x02,0xef,0xf9,0x00,0x04,0xff,0xfc,
0x00,0x5f,0xfa,0xef,0xc0,0xef,0x90,0x2e,0xf7,0x47,0x00,0x02,0x81,0x00,0x00,0x1d,
0xf1,0x04,0xf0,0x2b,0x71,0x2f,0x90,0x62,0x00,0x09,0xf7,0x2f,0x90,0xfe,0x20,0x3f,
0xb0,0x2f,0x90,0x5f,0xb0,0xaf,0x20,0x2f,0x90,0x0b,0xf1,0xce,0x00,0x2f,0x90,0x07,
0xf3,0xbf,0x00,0x05,0x20,0x08,0xf3,0x8f,0x50,0x00,0x00,0x0e,0xf0,0x1e,0xf4,0x00,
0x01,0xbf,0x70,0x04,0xff,0xc9,0xaf,0xfa,0x00,0x00,0x2a,0xff,0xfd,0x60,0x92,0x00,
0x10,0x10,0x93,0x00,0xf0,0x00,0x46,0x40,0x00,0x00,0x00,0x0e,0xfe,0x00,0x00,0x08,
0x7a,0xff,0xfa,0x78,0x03,0xb9,0x00,0xf0,0x09,0xf3,0x5f,0xff,0x83,0x9f,0xff,0x50,
0x9f,0xd0,0x00,0xdf,0x90,0x0a,0xfe,0x00,0x0e,0xfa,0x07,0xff,0xfc,0x7c,0xff,0xf7,
0x2f,0x1c,0x00,0xa0,0x20,0x43,0x6f,0xff,0x63,0x40,0x00,0x00,0xdf,0xd0,0x42,0x00,
0x10,0x21,0x42,0x00,0xf0,0x35,0x0a,0xd3,0x3f,0x70,0x00,0x00,0x2d,0xec,0xf9,0xf7,
0x00,0x00,0x4e,0xd4,0x59,0xff,0x70,0x00,0x6f,0xb4,0xef,0x86,0xfb,0x00,0x9f,0x96,
0xff,0xff,0xa5,0xed,0x19,0x68,0xff,0xff,0xff,0xd3,0xb1,0x00,0xff,0xff,0xef,0xff,
0x50,0x00,0x0f,0xff,0x20,0xcf,0xf5,0x00,0x00,0xff,0xf2,0x0c,0xff,0x50,0x00,0x09,
0xaa,0x10,0x7a,0xa2,0x00,0x00,0x00,0x07,0x96,0x00,0x84,0x00,0x1b,0xfd,0x06,0x00,
0xe1,0x17,0x7f,0xfe,0x77,0x00,0x00,0x0c,0xff,0xff,0xfb,0x00,0x00,0x01,0xdf,0x1c,
0x01,0xf0,0x22,0x1d,0xfc,0x10,0x00,0x0f,0xff,0xe4,0x94,0xff,0xfe,0x0f,0xff,0xfe,
0x8e,0xff,0xff,0x0f,0xff,0xff,0xff,0x8b,0x7f,0x08,0x99,0x99,0x99,0x99,0x97,0x00,
0x03,0x44,0x44,0x41,0x00,0x00,0x0b,0xff,0xff,0xff,0xf2,0x00,0x06,0xf4,0x22,0x22,
0x2d,0xc0,0x02,0xf9,0x97,0x07,0xc0,0x70,0xbe,0x22,0x00,0x00,0x12,0xaf,0x2f,0xff,
0xf9,0x00,0x3f,0x95,0x01,0x61,0xfc,0xce,0xff,0xff,0x6f,0xff,0xa2,0x01,0x11,0xcf,
0x07,0x00,0xf0,0x30,0x30,0x00,0x01,0x56,0x40,0x04,0x90,0x08,0xff,0xff,0xe6,0x7f,
0x09,0xfc,0x42,0x4c,0xfe,0xf3,0xfa,0x00,0x04,0x4c,0xff,0xaf,0x10,0x00,0xcf,0xff,
0xf1,0x20,0x00,0x02,0x33,0x32,0x67,0x77,0x50,0x00,0x05,0x4f,0xff,0xfc,0x00,0x02,
0xf8,0xff,0xc2,0x00,0x01,0xdf,0x2f,0xcf,0xf9,0x79,0xff,0x50,0xf7,0x2a,0xff,0xfb,
0x30,0x05,0x20,0x20,0x08,0x00,0x25,0x08,0x73,0x01,0xd7,0x12,0x3d,0xf8,0xff,0xff,
0x03,0x00,0x92,0xef,0xff,0xf8,0x00,0x0b,0xf8,0x00,0x00,0xb7,0x8c,0x17,0x00,0xbd,
0x00,0xf0,0x0c,0x70,0x00,0x12,0x3d,0xf8,0x00,0x0f,0xff,0xff,0x85,0x80,0xff,0xff,
0xf8,0x1e,0x2f,0xff,0xff,0x82,0xe1,0xef,0xff,0xf8,0x34,0x00,0x00,0xbf,0x9a,0x07,
0x16,0xb7,0xaf,0x07,0x11,0x02,0x31,0x02,0xf1,0x28,0x02,0xe5,0x00,0x00,0x01,0xd7,
0x02,0x52,0xe3,0x01,0x23,0xdf,0x80,0x1d,0x76,0xb0,0xff,0xff,0xf8,0x58,0x2f,0x1f,
0x1f,0xff,0xff,0x80,0xe2,0xd3,0xd3,0xff,0xff,0xf8,0x2e,0x1e,0x2d,0x3e,0xff,0xff,
0x83,0x45,0xe1,0xf0,0x00,0x0b,0xf8,0x03,0xe4,0x9a,0x00,0x00,0x0b,0x70,0x02,0x6e,
0x10,0xe2,0x10,0x04,0x40,0x07,0x60,0x13,0x44,0x44,0x44,0x43,0x1e,0xe6,0x00,0x40,
0xfe,0xf7,0x0a,0xff,0x46,0x06,0xf1,0x0b,0x7f,0xff,0x6e,0xff,0xfe,0xbf,0xff,0x40,
0x2e,0xff,0xf7,0x4e,0x40,0x00,0x6f,0xf8,0x00,0x10,0x00,0x06,0xff,0x96,0x66,0x66,
0x66,0x9f,0x0e,0x01,0xf0,0x01,0xc0,0x00,0x06,0x20,0x00,0x00,0x2f,0xb0,0x00,0x00,
0x8f,0xf2,0x00,0x01,0xff,0xfa,0x51,0x01,0xf0,0x0c,0x40,0x5f,0xff,0xff,0xe0,0xdf,
0xff,0xff,0xf6,0xf9,0xff,0xff,0xf8,0xd9,0x9f,0xff,0xf6,0x7f,0x65,0xff,0xe1,0x09,
0xff,0xfe,0x30,0x00,0x25,0x3e,0x02,0x00,0x0d,0x06,0xf2,0x01,0x03,0xd2,0xae,0x00,
0x4f,0xf4,0xae,0x06,0xff,0xf4,0xae,0x7f,0xff,0xf4,0xaf,0xff,0x04,0x00,0xf0,0x02,
0xae,0x3e,0xff,0xf4,0xae,0x02,0xef,0xf4,0xae,0x00,0x1d,0xf3,0x69,0x00,0x01,0x91,
0x67,0x2d,0x00,0x20,0xff,0xd5,0x05,0x00,0x20,0xff,0xb2,0x05,0x00,0x30,0xff,0x80,
0x00,0x9b,0x00,0x10,0x50,0x7a,0x00,0x14,0xf7,0x35,0x03,0xf0,0x03,0xfb,0x20,0xff,
0xff,0xfd,0x40,0x00,0xff,0xff,0x70,0x00,0x00,0xff,0xa1,0x00,0x00,0x00,0x23,0x37,
0x00,0xdf,0xbf,0xfc,0x01,0xdf,0xf9,0xff,0xff,0x14,0xff,0xfd,0xff,0xff,0x24,0x05,
0x00,0x09,0x00,0x23,0x00,0x63,0x7a,0xa8,0x00,0x9a,0xa5,0xbf,0x50,0x00,0x30,0xff,
0xf9,0xff,0x8b,0x03,0x0f,0x05,0x00,0x0a,0x60,0xf9,0x7a,0xaa,0xaa,0xaa,0xa3,0x68,
0x00,0xf0,0x1d,0xa9,0x00,0x06,0xf0,0xcf,0xb0,0x07,0xf1,0xcf,0xfc,0x17,0xf1,0xcf,
0xff,0xd9,0xf1,0xcf,0xff,0xff,0xf1,0xcf,0xff,0xfe,0xf1,0xcf,0xff,0x97,0xf1,0xcf,
0xf8,0x07,0xf1,0xcf,0x60,0x07,0xf1,0x65,0x00,0x04,0xa0,0x00,0x00,0x1c,0x90,0xd6,
0x01,0x21,0xff,0x80,0xa5,0x02,0x11,0x70,0x7a,0x02,0x12,0x60,0x64,0x01,0xb1,0xef,
0xff,0xff,0xff,0xf8,0x01,0x45,0x55,0x55,0x54,0x00,0x0b,0x00,0x10,0x0f,0x16,0x00,
0x61,0xa0,0x9b,0xbb,0xbb,0xbb,0xb4,0xb8,0x07,0x50,0x4f,0xe1,0x00,0x4f,0xe3,0x03,
0x00,0x67,0x3f,0xf3,0x00,0x01,0xdf,0x70,0x04,0x00,0xc5,0x20,0x00,0x01,0x50,0x1b,
0x30,0x00,0x03,0xff,0x30,0x00,0x04,0x04,0x00,0x43,0x20,0x00,0x9f,0xc0,0x03,0x00,
0x41,0x4f,0xc0,0x00,0x00,0xbd,0x03,0x63,0xea,0x00,0x00,0x00,0x03,0xfd,0x05,0x00,
0x51,0x12,0x25,0xfd,0x22,0x20,0xc7,0x00,0x56,0xce,0xee,0xff,0xee,0xe6,0x19,0x00,
0x02,0x05,0x00,0x40,0x00,0xa7,0x00,0x00,0xa5,0x08,0x11,0x10,0x8d,0x00,0x10,0xdf,
0x6c,0x01,0x40,0x00,0x00,0x01,0x20,0x47,0x00,0xf2,0x25,0x9f,0xfe,0xfb,0x40,0x00,
0x04,0xef,0x60,0x13,0xdf,0x80,0x03,0xff,0x70,0x3f,0xa2,0xff,0x70,0xdf,0xf2,0x7c,
0xff,0x2d,0xff,0x2c,0xff,0x3b,0xff,0xf1,0xef,0xf1,0x2e,0xf9,0x2c,0xd6,0x4f,0xf5,
0x00,0x2d,0xf9,0x21,0x6e,0xf5,0x00,0x00,0x06,0xcf,0xfd,0x92,0x00,0x00,0x52,0x5a,
0x02,0x40,0xce,0x40,0x00,0x21,0xfe,0x03,0xf1,0x28,0xf9,0xaf,0xef,0xf9,0x20,0x00,
0x00,0x6f,0xf5,0x11,0x5f,0xf4,0x00,0x05,0x03,0xee,0xcf,0x56,0xff,0x30,0x2f,0xd2,
0x1b,0xff,0xd1,0xff,0xe0,0x1e,0xfd,0x00,0x7f,0xe3,0xff,0xc0,0x05,0xff,0x40,0x04,
0xef,0xfe,0x20,0x00,0x5f,0xe6,0x10,0x1c,0xf8,0x00,0x00,0x01,0x8d,0xfd,0x20,0x9f,
0xa0,0x44,0x00,0x22,0x05,0xf9,0x4c,0x00,0x10,0x21,0x6d,0x0a,0x02,0xfa,0x02,0x00,
0x4f,0x01,0x00,0xc6,0x03,0x30,0xf1,0x00,0x00,0xe9,0x06,0x10,0xfa,0x07,0x00,0xf1,
0x1a,0xdf,0x50,0xef,0x30,0x00,0x00,0x06,0xff,0x50,0xef,0xc0,0x00,0x00,0x1e,0xff,
0x50,0xff,0xf5,0x00,0x00,0x9f,0xff,0xa6,0xff,0xfe,0x00,0x02,0xff,0xff,0x61,0xff,
0xff,0x80,0x0b,0xff,0xff,0x72,0xff,0xff,0xf1,0x0e,0xcf,0x03,0x30,0xf4,0x02,0x55,
0x01,0x00,0x15,0x40,0x4e,0x03,0xa0,0x0b,0x80,0xaa,0xa1,0x00,0x4a,0xef,0x8f,0xff,
0xc0,0xc3,0x03,0xf1,0x10,0x8d,0x4f,0xe3,0xcd,0x10,0x00,0x4f,0xf3,0x03,0x10,0x00,
0x2e,0xf5,0x80,0xa7,0x09,0xae,0xf4,0x7f,0xce,0xf7,0xff,0xf5,0x00,0xaf,0xff,0xd1,
0x11,0x00,0x00,0x1c,0xfc,0x0a,0x50,0x41,0x00,0x00,0x01,0xc7,0x79,0x09,0xf0,0x1b,
0xff,0x70,0x00,0x01,0xcf,0x9d,0xf7,0x00,0x1c,0xf8,0x01,0xdf,0x70,0xbf,0x80,0x00,
0x1d,0xf5,0x47,0x00,0x00,0x01,0x91,0x8b,0x00,0x00,0x03,0xd3,0x9f,0xc0,0x00,0x3f,
0xf3,0x09,0xfc,0x03,0xff,0x40,0x00,0x9f,0xcf,0xf4,0xbf,0x05,0x00,0x73,0x00,0x42,
0x84,0x00,0x00,0x00,0x7d,0x03,0xa0,0x04,0xfb,0x04,0x66,0x66,0x61,0x00,0x4f,0xff,
0xb8,0x70,0x01,0xa0,0xdb,0xfb,0xf5,0x00,0x00,0xe7,0x00,0x10,0xf7,0x10,0x07,0x00,
0x00,0x25,0x07,0xa0,0x20,0xe7,0x20,0x00,0xf7,0x11,0x10,0xcc,0xec,0xf5,0x25,0x02,
0xa3,0x5e,0xff,0xa0,0x00,0x35,0x55,0x54,0x03,0xea,0x00,0x31,0x04,0x91,0x13,0x44,
0x20,0x00,0x00,0x0e,0xff,0xff,0x40,0x28,0x03,0x4f,0xee,0xed,0xaf,0xff,0x01,0x00,
0x07,0x03,0xba,0x03,0x21,0x00,0x07,0xef,0x00,0x11,0xfb,0x41,0x01,0x10,0xfb,0x0c,
0x05,0x00,0x06,0x00,0x42,0x88,0xff,0xf8,0x80,0xe3,0x05,0x43,0x00,0x00,0xef,0xe0,
0xee,0x05,0x40,0xff,0xf8,0x9b,0x98,0x0d,0x02,0x21,0x78,0xff,0x37,0x02,0x20,0xb6,
0xf8,0x44,0x05,0x10,0x98,0x23,0x00,0x40,0x18,0x51,0x00,0x00,0x5f,0x01,0x01,0xab,
0x03,0x11,0xfe,0x93,0x01,0x20,0xfc,0x00,0x48,0x05,0x11,0xf7,0x06,0x00,0x10,0xf2,
0x36,0x02,0xd1,0xef,0x90,0x00,0x5c,0x70,0x2d,0xfd,0x00,0x0d,0xff,0xfa,0xff,0xd1,
0xa3,0x05,0xa0,0x10,0x00,0x09,0xff,0xfb,0x40,0x00,0x00,0x01,0x53,0x80,0x04,0xf0,
0x37,0x3c,0xd4,0x00,0x05,0x82,0xdc,0xbf,0x00,0x9f,0xf5,0xea,0x8f,0x09,0xff,0x60,
0x6f,0xff,0xdf,0xf6,0x00,0x01,0x6f,0xff,0x60,0x00,0x04,0xaf,0xff,0x70,0x00,0x9f,
0xff,0x9f,0xf7,0x00,0xf8,0x6f,0x16,0xff,0x70,0xcd,0xce,0x00,0x6f,0xf6,0x2b,0xc3,
0x00,0x04,0x71,0x00,0x1d,0xdd,0xd3,0x70,0x00,0x3f,0xff,0xf4,0xf7,0x79,0x4f,0xff,
0xf2,0x32,0xff,0x4f,0xff,0xfe,0xeb,0x52,0x07,0x1f,0xfd,0x05,0x00,0x02,0x40,0x64,
0x55,0x55,0x53,0xf3,0x07,0xf0,0x01,0x00,0x46,0x66,0x66,0x50,0x00,0xbf,0xff,0xff,
0xfa,0x00,0xfa,0x66,0x66,0x8f,0xa0,0x93,0x08,0x10,0xf8,0x05,0x00,0x04,0xd9,0x03,
0xf1,0x0d,0x8a,0xff,0xfa,0xff,0xf8,0x00,0xdf,0xfa,0xff,0xf9,0x00,0xef,0xfa,0xff,
0xff,0x9b,0xff,0xfa,0xae,0xee,0xee,0xee,0xe6,0x78,0x88,0x88,0x88,0x84,0xf9,0x00,
0x06,0x74,0x05,0x01,0x1c,0x03,0x51,0x89,0x99,0x99,0x99,0x95,0x0f,0x00,0x0b,0x23,
0x00,0x07,0x48,0x05,0x01,0x6d,0x01,0xf9,0x06,0xc5,0x9f,0xff,0xff,0xff,0x95,0xf9,
0x5e,0xff,0xfe,0x58,0xff,0xfc,0x4c,0xfc,0x4c,0xff,0xff,0xff,0x64,0x6f,0x8e,0x01,
0xf2,0x1b,0x03,0xdd,0xd9,0x00,0x06,0xff,0xf9,0x00,0x09,0xff,0xf3,0x00,0x0b,0xff,
0xf6,0x64,0x0d,0xff,0xff,0xfb,0x0f,0xff,0xff,0xf2,0x04,0x55,0xff,0x90,0x00,0x03,
0xfe,0x10,0x00,0x07,0xf6,0x00,0x00,0x0a,0xd0,0x00,0x00,0x0d,0xaa,0x02,0x90,0x01,
0x5b,0x41,0x00,0x00,0xff,0xf4,0xff,0xf0,0xef,0x01,0xf0,0x09,0xf1,0x00,0xff,0xe4,
0x55,0x51,0x10,0xff,0xc8,0xff,0xf4,0xd1,0xff,0xc8,0xff,0xf3,0xa7,0xff,0xc8,0xff,
0xfb,0xa8,0xff,0xc8,0xfd,0x00,0x00,0x05,0x00,0x80,0x01,0x18,0xff,0xff,0xfd,0x00,
0x08,0xff,0x49,0x0c,0x60,0x22,0x22,0x21,0x00,0x00,0x62,0x71,0x02,0x20,0xeb,0x20,
0xb9,0x01,0x80,0xf4,0x00,0x05,0xff,0xff,0xfe,0x00,0x09,0xda,0x06,0x00,0x94,0x04,
0x60,0x50,0x0d,0xff,0xff,0xff,0x70,0x9e,0x08,0x11,0xd0,0xe4,0x00,0x80,0x35,0x55,
0x55,0x55,0x41,0x00,0x06,0xff,0xa9,0x01,0x12,0x42,0xda,0x00,0x23,0x44,0x43,0x3b,
0x03,0xf5,0x17,0xf7,0x2b,0x2c,0x2c,0x2c,0x2f,0x6f,0xdb,0xeb,0xeb,0xeb,0xeb,0xf6,
0xff,0x60,0xb0,0xa0,0xb0,0xff,0x6f,0xfd,0xae,0xae,0xae,0xaf,0xf6,0xf6,0x1a,0x00,
0x00,0x0b,0x0f,0x6f,0xa6,0xc6,0x66,0x66,0xd6,0x38,0x07,0x00,0xb7,0x00,0x10,0x75,
0x06,0x00,0x70,0x29,0xff,0xe0,0x00,0x00,0x03,0xaf,0x2d,0x01,0x10,0x4c,0x26,0x08,
0x20,0x05,0xdf,0xf1,0x04,0x11,0x00,0x4e,0x08,0x43,0x00,0x05,0x89,0x9a,0x43,0x02,
0x01,0x22,0x03,0x31,0x03,0xff,0xd0,0x0d,0x00,0x11,0xf6,0x3f,0x00,0x11,0xfe,0xfd,
0x00,0xf4,0x07,0x03,0x20,0x00,0x00,0x67,0x77,0x63,0x00,0x0f,0xff,0xfd,0x8c,0x00,
0xff,0xff,0xd8,0xfc,0x0f,0xff,0xfd,0x35,0x51,0x56,0x09,0x1f,0xf4,0x09,0x00,0x03,
0x54,0x47,0x88,0x88,0x88,0x81,0xbf,0x01,0xf1,0x0f,0x06,0xbe,0xff,0xea,0x50,0x00,
0x06,0xff,0xfd,0xbc,0xef,0xfd,0x40,0xaf,0xe6,0x10,0x00,0x02,0x8f,0xf6,0x7b,0x10,
0x26,0x88,0x51,0x02,0xc4,0x00,0x1a,0xff,0x4c,0x06,0xc5,0x6f,0xc5,0x23,0x6e,0xf2,
0x00,0x00,0x04,0x00,0x00,0x00,0x30,0x1b,0x05,0x23,0x00,0x07,0xc8,0x00,0x60,0x97,
0x00,0x00,0x00,0x36,0x66,0x01,0x00,0x12,0x40,0xc7,0x01,0xa0,0xf2,0xf6,0x67,0x77,
0x77,0x77,0x73,0xfe,0xf6,0xef,0xc6,0x00,0x12,0xae,0x07,0x00,0x91,0xbe,0xf6,0x45,
0x55,0x55,0x55,0x53,0xfc,0xef,0x23,0x00,0x21,0xf0,0x24,0x6b,0x04,0x1e,0x20,0x38,
0x00,0x21,0x70,0x02,0x38,0x00,0x32,0xf1,0x00,0xae,0x07,0x00,0x01,0x38,0x00,0x2f,
0x51,0x13,0x38,0x00,0x0d,0x21,0x60,0x00,0x38,0x00,0x42,0xf0,0x00,0x00,0xae,0x07,
0x00,0x00,0x38,0x00,0x2f,0x41,0x11,0x38,0x00,0x0d,0x21,0x60,0x00,0x38,0x00,0x00,
0xdd,0x03,0x11,0xae,0x07,0x00,0x00,0x38,0x00,0x2f,0x41,0x11,0x38,0x00,0x0b,0x21,
0xf0,0xf6,0x71,0x05,0x21,0xfd,0xf6,0x07,0x01,0x12,0xae,0x07,0x00,0x4e,0xbe,0xf6,
0x11,0x11,0x38,0x00,0x00,0x28,0x00,0x11,0x20,0xa8,0x01,0x11,0x8f,0x98,0x05,0xf1,
0x10,0x1c,0x3b,0xc0,0x00,0x00,0x6d,0x70,0x93,0x00,0x00,0x05,0x30,0xff,0xfb,0xfb,
0xbb,0xbb,0xbe,0xf7,0xaf,0xb0,0x05,0x90,0x00,0x08,0x80,0x02,0x00,0x00,0xc0,0x13,
0x2b,0x00,0x31,0x4a,0xcf,0xb0,0x32,0x00,0x34,0xbf,0xb0,0x00,0x00,0x0b,0xf0,0x2a,
0x19,0xcd,0xa3,0x00,0x01,0xef,0xca,0xff,0x30,0x09,0xff,0xc0,0xbf,0xb0,0x0e,0xd8,
0xc5,0x4d,0xf0,0x0f,0xf6,0x43,0x4f,0xf1,0x1f,0xff,0x40,0xef,0xf2,0x0f,0xfc,0x10,
0x8f,0xf1,0x0f,0xd2,0xa6,0x3b,0xf0,0x0b,0xfe,0xc2,0x5f,0xd0,0x04,0xff,0xc5,0xff,
0x60,0x00,0x6e,0xff,0xf8,0x00,0x00,0x00,0x12,0x17,0x0b,0x21,0xaa,0x40,0xa3,0x03,
0x60,0xf9,0x56,0x66,0x66,0x66,0x63,0x04,0x02,0xad,0xe0,0x5f,0xbf,0xbe,0xce,0xf0,
0x5f,0x6e,0x7d,0x8c,0x05,0x00,0x41,0x7e,0x8d,0x9c,0xf0,0x23,0x00,0x51,0x04,0x66,
0x66,0x65,0x20,0xd6,0x04,0x01,0xe5,0x01,0x00,0xa7,0x05,0xa0,0x00,0x15,0xaf,0xfe,
0x00,0x00,0x01,0xcf,0x6a,0xf9,0xe0,0x05,0x61,0xf6,0x60,0x00,0x01,0xcf,0xff,0x0b,
0x00,0x23,0xff,0x90,0x0b,0x00,0x10,0x0a,0x0b,0x00,0x21,0x00,0x0d,0xfa,0x03,0x30,
0x0f,0xff,0x90,0x5a,0x03,0x12,0x42,0x65,0x02,0x50,0x34,0x44,0x44,0x44,0x30,0x6e,
0x0c,0x00,0xdf,0x07,0xf1,0x1c,0xdf,0xff,0xaf,0xfb,0xef,0xfb,0x1d,0xff,0xff,0x13,
0x90,0x8f,0xfc,0xcf,0xff,0xff,0xd1,0x06,0xff,0xfc,0xaf,0xff,0xff,0xa0,0x03,0xff,
0xfc,0x0a,0xff,0xff,0x06,0xd1,0x7f,0xfc,0x00,0xaf,0xff,0xdf,0xfe,0xff,0xfb,0x00,
0x09,0xda,0x08,0xff,0x03,0x00,0x36,0x66,0x63,0x00,0x4e,0xff,0xff,0xf2,0x4f,0x6b,
0x0b,0x2f,0x4f,0xf6,0xb0,0xb2,0xf4,0xe0,0x02,0x08,0x00,0xeb,0x00,0x42,0x22,0x88,
0x88,0x88,0x1c,0x04,0x02,0x7c,0x01,0xe1,0xf0,0x00,0xb6,0x00,0x00,0x0a,0xf0,0x0c,
0xf8,0x11,0x11,0x1b,0xf0,0xcf,0xa0,0x01,0x81,0x6f,0xfd,0xaa,0xaa,0xaa,0x90,0x05,
0xf7,0x26,0x00,0x15,0x43,0xcc,0x04,0x01,0xb4,0x04,0x1a,0xfd,0x03,0x12,0x00,0xa1,
0x0d,0x0d,0x01,0x00,0x03,0x00,0x05,0x46,0xf3,0xf3,0xf6,0xf0,0x14,0x00,0x4f,0xfd,
0xf9,0x00,0xec,0x30,0x00,0x02,0x1e,0xfd,0x2e,0x00,0x01,0x30,0x00,0x10,0xe9,0x15,
0x00,0x0e,0x5e,0x00,0x04,0x36,0x00,0x29,0xfd,0xf9,0x10,0x00,0x62,0xec,0xf6,0x00,
0xec,0xf3,0xfd,0x49,0x00,0x20,0xf3,0xfd,0x3a,0x0e,0x70,0xf3,0x00,0xf3,0xf3,0x00,
0xf0,0xf6,0x09,0x00,0x02,0xa9,0x00,0x11,0xf6,0x17,0x00,0x10,0xf9,0xa0,0x00,0x53,
0xf6,0xfc,0x00,0xfd,0xf6,0xac,0x00,0x30,0xfd,0xfe,0xfd,0x4f,0x00,0x00,0x04,0x00,
0x54,0xec,0xf6,0x00,0xf3,0xf0,0x2e,0x00,0x7f,0xf9,0xf3,0xf6,0xf3,0x00,0xf6,0xf6,
0xe4,0x00,0x04,0x0e,0x9d,0x00,0x0b,0xfe,0x00,0x0c,0x01,0x00,0x1c,0x01,0x11,0x00,
0x1b,0x02,0x10,0x00,0x11,0x03,0xdf,0x07,0x02,0xc2,0x08,0x00,0x7b,0x04,0x9f,0x00,
0x07,0x00,0x08,0x00,0x09,0x0a,0x00,0x0b,0x03,0x01,0x05,0x9f,0x0c,0x00,0x00,0x00,
0x0d,0x0e,0x00,0x0d,0x00,0x01,0x00,0x5e,0x18,0x01,0xc7,0x00,0x24,0x03,0x02,0xb7,
0x00,0x00,0xba,0x00,0x12,0x05,0x38,0x05,0x09,0x2f,0x00,0x01,0x41,0x08,0x09,0xcc,
0x00,0x50,0x0c,0x00,0x0d,0x00,0x0e,0x09,0x03,0x02,0x97,0x08,0xaf,0x11,0x12,0x13,
0x0d,0x00,0x14,0x15,0x16,0x00,0x17,0xc6,0x00,0x59,0x50,0x00,0x00,0x00,0x00,0x00,
};

static const etxFontCmap cmaps[] = {
{ .range_start = 32, .range_length = 95, .glyph_id_start = 1, .list_length = 0, .type = 2, .unicode_list = 0, .glyph_id_ofs_list = 0 },
{ .range_start = 128, .range_length = 4, .glyph_id_start = 96, .list_length = 0, .type = 2, .unicode_list = 0, .glyph_id_ofs_list = 0 },
{ .range_start = 136, .range_length = 13, .glyph_id_start = 100, .list_length = 0, .type = 2, .unicode_list = 0, .glyph_id_ofs_list = 0 },
{ .range_start = 176, .range_length = 1, .glyph_id_start = 113, .list_length = 0, .type = 2, .unicode_list = 0, .glyph_id_ofs_list = 0 },
{ .range_start = 1488, .range_length = 27, .glyph_id_start = 114, .list_length = 0, .type = 2, .unicode_list = 0, .glyph_id_ofs_list = 0 },
{ .range_start = 1524, .range_length = 62127, .glyph_id_start = 141, .list_length = 63, .type = 3, .unicode_list = 1632, .glyph_id_ofs_list = 0 },
};

static uint8_t etxUncompBuf[9762] __SDRAMFONTS;

const etxLz4Font lv_font_arimo_he_bold_STD_s = {
.uncomp_size = 9434,
.comp_size = 7552,
.line_height = 12,
.base_line = 2,
.subpx = 0,
.underline_position = -1,
.underline_thickness = 1,
.kern_scale = 16,
.cmap_num = 6,
.bpp = 4,
.kern_classes = 1,
.bitmap_format = 0,
.left_class_cnt = 14,
.right_class_cnt = 23,
.glyph_bitmap = 1758,
.class_pair_values = 8704,
.left_class_mapping = 9026,
.right_class_mapping = 9230,
.cmaps = cmaps,
.compressed = lz4FontData,
.lvglFontBuf = etxUncompBuf,
.lvglFontBufSize = 9762,
};

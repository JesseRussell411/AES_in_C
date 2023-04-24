#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

#include "Buffer.h"

uint8_t E[256] = {
    0x01, 0x03, 0x05, 0x0F, 0x11, 0x33, 0x55, 0xFF, 0x1A, 0x2E, 0x72, 0x96, 0xA1, 0xF8, 0x13, 0x35,
    0x5F, 0xE1, 0x38, 0x48, 0xD8, 0x73, 0x95, 0xA4, 0xF7, 0x02, 0x06, 0x0A, 0x1E, 0x22, 0x66, 0xAA,
    0xE5, 0x34, 0x5C, 0xE4, 0x37, 0x59, 0xEB, 0x26, 0x6A, 0xBE, 0xD9, 0x70, 0x90, 0xAB, 0xE6, 0x31,
    0x53, 0xF5, 0x04, 0x0C, 0x14, 0x3C, 0x44, 0xCC, 0x4F, 0xD1, 0x68, 0xB8, 0xD3, 0x6E, 0xB2, 0xCD,
    0x4C, 0xD4, 0x67, 0xA9, 0xE0, 0x3B, 0x4D, 0xD7, 0x62, 0xA6, 0xF1, 0x08, 0x18, 0x28, 0x78, 0x88,
    0x83, 0x9E, 0xB9, 0xD0, 0x6B, 0xBD, 0xDC, 0x7F, 0x81, 0x98, 0xB3, 0xCE, 0x49, 0xDB, 0x76, 0x9A,
    0xB5, 0xC4, 0x57, 0xF9, 0x10, 0x30, 0x50, 0xF0, 0x0B, 0x1D, 0x27, 0x69, 0xBB, 0xD6, 0x61, 0xA3,
    0xFE, 0x19, 0x2B, 0x7D, 0x87, 0x92, 0xAD, 0xEC, 0x2F, 0x71, 0x93, 0xAE, 0xE9, 0x20, 0x60, 0xA0,
    0xFB, 0x16, 0x3A, 0x4E, 0xD2, 0x6D, 0xB7, 0xC2, 0x5D, 0xE7, 0x32, 0x56, 0xFA, 0x15, 0x3F, 0x41,
    0xC3, 0x5E, 0xE2, 0x3D, 0x47, 0xC9, 0x40, 0xC0, 0x5B, 0xED, 0x2C, 0x74, 0x9C, 0xBF, 0xDA, 0x75,
    0x9F, 0xBA, 0xD5, 0x64, 0xAC, 0xEF, 0x2A, 0x7E, 0x82, 0x9D, 0xBC, 0xDF, 0x7A, 0x8E, 0x89, 0x80,
    0x9B, 0xB6, 0xC1, 0x58, 0xE8, 0x23, 0x65, 0xAF, 0xEA, 0x25, 0x6F, 0xB1, 0xC8, 0x43, 0xC5, 0x54,
    0xFC, 0x1F, 0x21, 0x63, 0xA5, 0xF4, 0x07, 0x09, 0x1B, 0x2D, 0x77, 0x99, 0xB0, 0xCB, 0x46, 0xCA,
    0x45, 0xCF, 0x4A, 0xDE, 0x79, 0x8B, 0x86, 0x91, 0xA8, 0xE3, 0x3E, 0x42, 0xC6, 0x51, 0xF3, 0x0E,
    0x12, 0x36, 0x5A, 0xEE, 0x29, 0x7B, 0x8D, 0x8C, 0x8F, 0x8A, 0x85, 0x94, 0xA7, 0xF2, 0x0D, 0x17,
    0x39, 0x4B, 0xDD, 0x7C, 0x84, 0x97, 0xA2, 0xFD, 0x1C, 0x24, 0x6C, 0xB4, 0xC7, 0x52, 0xF6, 0x01};

uint8_t L[256] = {
    0x00, 0x00, 0x19, 0x01, 0x32, 0x02, 0x1A, 0xC6, 0x4B, 0xC7, 0x1B, 0x68, 0x33, 0xEE, 0xDF, 0x03,
    0x64, 0x04, 0xE0, 0x0E, 0x34, 0x8D, 0x81, 0xEF, 0x4C, 0x71, 0x08, 0xC8, 0xF8, 0x69, 0x1C, 0xC1,
    0x7D, 0xC2, 0x1D, 0xB5, 0xF9, 0xB9, 0x27, 0x6A, 0x4D, 0xE4, 0xA6, 0x72, 0x9A, 0xC9, 0x09, 0x78,
    0x65, 0x2F, 0x8A, 0x05, 0x21, 0x0F, 0xE1, 0x24, 0x12, 0xF0, 0x82, 0x45, 0x35, 0x93, 0xDA, 0x8E,
    0x96, 0x8F, 0xDB, 0xBD, 0x36, 0xD0, 0xCE, 0x94, 0x13, 0x5C, 0xD2, 0xF1, 0x40, 0x46, 0x83, 0x38,
    0x66, 0xDD, 0xFD, 0x30, 0xBF, 0x06, 0x8B, 0x62, 0xB3, 0x25, 0xE2, 0x98, 0x22, 0x88, 0x91, 0x10,
    0x7E, 0x6E, 0x48, 0xC3, 0xA3, 0xB6, 0x1E, 0x42, 0x3A, 0x6B, 0x28, 0x54, 0xFA, 0x85, 0x3D, 0xBA,
    0x2B, 0x79, 0x0A, 0x15, 0x9B, 0x9F, 0x5E, 0xCA, 0x4E, 0xD4, 0xAC, 0xE5, 0xF3, 0x73, 0xA7, 0x57,
    0xAF, 0x58, 0xA8, 0x50, 0xF4, 0xEA, 0xD6, 0x74, 0x4F, 0xAE, 0xE9, 0xD5, 0xE7, 0xE6, 0xAD, 0xE8,
    0x2C, 0xD7, 0x75, 0x7A, 0xEB, 0x16, 0x0B, 0xF5, 0x59, 0xCB, 0x5F, 0xB0, 0x9C, 0xA9, 0x51, 0xA0,
    0x7F, 0x0C, 0xF6, 0x6F, 0x17, 0xC4, 0x49, 0xEC, 0xD8, 0x43, 0x1F, 0x2D, 0xA4, 0x76, 0x7B, 0xB7,
    0xCC, 0xBB, 0x3E, 0x5A, 0xFB, 0x60, 0xB1, 0x86, 0x3B, 0x52, 0xA1, 0x6C, 0xAA, 0x55, 0x29, 0x9D,
    0x97, 0xB2, 0x87, 0x90, 0x61, 0xBE, 0xDC, 0xFC, 0xBC, 0x95, 0xCF, 0xCD, 0x37, 0x3F, 0x5B, 0xD1,
    0x53, 0x39, 0x84, 0x3C, 0x41, 0xA2, 0x6D, 0x47, 0x14, 0x2A, 0x9E, 0x5D, 0x56, 0xF2, 0xD3, 0xAB,
    0x44, 0x11, 0x92, 0xD9, 0x23, 0x20, 0x2E, 0x89, 0xB4, 0x7C, 0xB8, 0x26, 0x77, 0x99, 0xE3, 0xA5,
    0x67, 0x4A, 0xED, 0xDE, 0xC5, 0x31, 0xFE, 0x18, 0x0D, 0x63, 0x8C, 0x80, 0xC0, 0xF7, 0x70, 0x07};

uint8_t s_box[256] = {
    0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
    0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
    0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
    0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
    0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
    0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
    0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
    0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
    0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
    0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
    0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
    0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
    0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
    0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
    0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16};

uint8_t s_box_inverse[256] = {
    0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB, 
    0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB, 
    0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E, 
    0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25, 
    0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92, 
    0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84, 
    0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06, 
    0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B, 
    0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73, 
    0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E, 
    0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B, 
    0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4, 
    0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F, 
    0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF, 
    0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61, 
    0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D};

uint8_t mul2[256] = {
    0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
    0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
    0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
    0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
    0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
    0x1b, 0x19, 0x1f, 0x1d, 0x13, 0x11, 0x17, 0x15, 0x0b, 0x09, 0x0f, 0x0d, 0x03, 0x01, 0x07, 0x05,
    0x3b, 0x39, 0x3f, 0x3d, 0x33, 0x31, 0x37, 0x35, 0x2b, 0x29, 0x2f, 0x2d, 0x23, 0x21, 0x27, 0x25,
    0x5b, 0x59, 0x5f, 0x5d, 0x53, 0x51, 0x57, 0x55, 0x4b, 0x49, 0x4f, 0x4d, 0x43, 0x41, 0x47, 0x45,
    0x7b, 0x79, 0x7f, 0x7d, 0x73, 0x71, 0x77, 0x75, 0x6b, 0x69, 0x6f, 0x6d, 0x63, 0x61, 0x67, 0x65,
    0x9b, 0x99, 0x9f, 0x9d, 0x93, 0x91, 0x97, 0x95, 0x8b, 0x89, 0x8f, 0x8d, 0x83, 0x81, 0x87, 0x85,
    0xbb, 0xb9, 0xbf, 0xbd, 0xb3, 0xb1, 0xb7, 0xb5, 0xab, 0xa9, 0xaf, 0xad, 0xa3, 0xa1, 0xa7, 0xa5,
    0xdb, 0xd9, 0xdf, 0xdd, 0xd3, 0xd1, 0xd7, 0xd5, 0xcb, 0xc9, 0xcf, 0xcd, 0xc3, 0xc1, 0xc7, 0xc5,
    0xfb, 0xf9, 0xff, 0xfd, 0xf3, 0xf1, 0xf7, 0xf5, 0xeb, 0xe9, 0xef, 0xed, 0xe3, 0xe1, 0xe7, 0xe5};

uint8_t mul3[256] = {
    0x00, 0x03, 0x06, 0x05, 0x0c, 0x0f, 0x0a, 0x09, 0x18, 0x1b, 0x1e, 0x1d, 0x14, 0x17, 0x12, 0x11,
    0x30, 0x33, 0x36, 0x35, 0x3c, 0x3f, 0x3a, 0x39, 0x28, 0x2b, 0x2e, 0x2d, 0x24, 0x27, 0x22, 0x21,
    0x60, 0x63, 0x66, 0x65, 0x6c, 0x6f, 0x6a, 0x69, 0x78, 0x7b, 0x7e, 0x7d, 0x74, 0x77, 0x72, 0x71,
    0x50, 0x53, 0x56, 0x55, 0x5c, 0x5f, 0x5a, 0x59, 0x48, 0x4b, 0x4e, 0x4d, 0x44, 0x47, 0x42, 0x41,
    0xc0, 0xc3, 0xc6, 0xc5, 0xcc, 0xcf, 0xca, 0xc9, 0xd8, 0xdb, 0xde, 0xdd, 0xd4, 0xd7, 0xd2, 0xd1,
    0xf0, 0xf3, 0xf6, 0xf5, 0xfc, 0xff, 0xfa, 0xf9, 0xe8, 0xeb, 0xee, 0xed, 0xe4, 0xe7, 0xe2, 0xe1,
    0xa0, 0xa3, 0xa6, 0xa5, 0xac, 0xaf, 0xaa, 0xa9, 0xb8, 0xbb, 0xbe, 0xbd, 0xb4, 0xb7, 0xb2, 0xb1,
    0x90, 0x93, 0x96, 0x95, 0x9c, 0x9f, 0x9a, 0x99, 0x88, 0x8b, 0x8e, 0x8d, 0x84, 0x87, 0x82, 0x81,
    0x9b, 0x98, 0x9d, 0x9e, 0x97, 0x94, 0x91, 0x92, 0x83, 0x80, 0x85, 0x86, 0x8f, 0x8c, 0x89, 0x8a,
    0xab, 0xa8, 0xad, 0xae, 0xa7, 0xa4, 0xa1, 0xa2, 0xb3, 0xb0, 0xb5, 0xb6, 0xbf, 0xbc, 0xb9, 0xba,
    0xfb, 0xf8, 0xfd, 0xfe, 0xf7, 0xf4, 0xf1, 0xf2, 0xe3, 0xe0, 0xe5, 0xe6, 0xef, 0xec, 0xe9, 0xea,
    0xcb, 0xc8, 0xcd, 0xce, 0xc7, 0xc4, 0xc1, 0xc2, 0xd3, 0xd0, 0xd5, 0xd6, 0xdf, 0xdc, 0xd9, 0xda,
    0x5b, 0x58, 0x5d, 0x5e, 0x57, 0x54, 0x51, 0x52, 0x43, 0x40, 0x45, 0x46, 0x4f, 0x4c, 0x49, 0x4a,
    0x6b, 0x68, 0x6d, 0x6e, 0x67, 0x64, 0x61, 0x62, 0x73, 0x70, 0x75, 0x76, 0x7f, 0x7c, 0x79, 0x7a,
    0x3b, 0x38, 0x3d, 0x3e, 0x37, 0x34, 0x31, 0x32, 0x23, 0x20, 0x25, 0x26, 0x2f, 0x2c, 0x29, 0x2a,
    0x0b, 0x08, 0x0d, 0x0e, 0x07, 0x04, 0x01, 0x02, 0x13, 0x10, 0x15, 0x16, 0x1f, 0x1c, 0x19, 0x1a};

uint8_t rcon[256] = {
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
    0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
    0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
    0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
    0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
    0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
    0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
    0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
    0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d};



// galois field multiplication
static inline uint8_t finiteFieldMultiply(uint8_t a, uint8_t b){
    if (a == 0x00) return 0x00;
    if (b == 0x00) return 0x00;
    if (a == 0x01) return b;
    if (b == 0x01) return a;

    int ra = L[a];
    int ba = L[b];
    int r = ra + ba;
    if (r > 255) r -= 255;
    return E[r];
}

// alias for finiteFieldMultiply
static inline uint8_t mul(uint8_t a, uint8_t b){
    return finiteFieldMultiply(a, b);
}



// =====================
//    key expansion
// =====================
static void rotWord(uint8_t *word){
    // rotate 4 bytes to the left: 1234 -> 2341
    uint32_t *q = (uint32_t *)word;
    *q = (*q >> 8) | ((*q & 0xff) << 24);
}

static void subWord(uint8_t *word) {
    for(int i = 0; i < 4; i++){
        word[i] = s_box[word[i]];
    }
}


void keyExpansionCore(uint8_t *in, uint8_t i)
{
    // // rotate
    // uint32_t *q = (uint32_t *)in;
    // *q = (*q >> 8) | ((*q & 0xff) << 24);
    rotWord(in);

    // s box
    subWord(in);

    // Rcon
    in[0] ^= rcon[i];
}

void KeyExpansion(uint8_t *inputKey, uint8_t *expandedKeys)
{
    // first 16 bytes are the original key
    memcpy(expandedKeys, inputKey, 16);

    size_t bytesGenerated = 16; // we've generated 16 bytes so far
    size_t rconIteration = 1;   // RCon iteration begins at 1
    uint8_t temp[4];            // temporary storage for core

    while (bytesGenerated < 176)
    {
        memcpy(temp, expandedKeys + bytesGenerated - 4, 4);

        if (bytesGenerated % 16 == 0)
        {
            keyExpansionCore(temp, rconIteration);
            rconIteration++;
        }

        for (int a = 0; a < 4; a++)
        {
            expandedKeys[bytesGenerated] = expandedKeys[bytesGenerated - 16] ^ temp[a];
            bytesGenerated++;
        }
    }
}

void subBytes(uint8_t *state) {
    for(int i = 0; i < 16; i++){
        state[i] = s_box[state[i]];
    }
}

void subBytes_inverse(uint8_t *state) {
    for( int i = 0; i < 16; i++){
        state[i] = s_box_inverse[state[i]];
    }
}

void shiftRows(uint8_t *state)
{

    // 00 04 08 12              \     00 04 08 12
    // 01 05 09 13    ___________\    05 09 13 01
    // 02 06 10 14               /    10 14 02 06
    // 03 07 11 15              /     15 03 07 11

    uint8_t tmp[16];

    tmp[0] = state[0];
    tmp[1] = state[5];
    tmp[2] = state[10];
    tmp[3] = state[15];

    tmp[4] = state[4];
    tmp[5] = state[9];
    tmp[6] = state[14];
    tmp[7] = state[3];

    tmp[8] = state[8];
    tmp[9] = state[13];
    tmp[10] = state[2];
    tmp[11] = state[7];

    tmp[12] = state[12];
    tmp[13] = state[1];
    tmp[14] = state[6];
    tmp[15] = state[11];

    memcpy(state, tmp, 16);
}

void shiftRows_inverse(uint8_t *state)
{
    // 00 04 08 12              \     00 04 08 12
    // 01 05 09 13    ___________\    13 01 05 09
    // 02 06 10 14               /    10 14 02 06
    // 03 07 11 15              /     07 11 15 03

    uint8_t tmp[16];

    tmp[0] = state[0];
    tmp[1] = state[13];
    tmp[2] = state[10];
    tmp[3] = state[7];

    tmp[4] = state[4];
    tmp[5] = state[1];
    tmp[6] = state[14];
    tmp[7] = state[11];

    tmp[8] = state[8];
    tmp[9] = state[5];
    tmp[10] = state[2];
    tmp[11] = state[15];

    tmp[12] = state[12];
    tmp[13] = state[9];
    tmp[14] = state[6];
    tmp[15] = state[3];

    memcpy(state, tmp, 16);
}

void mixColumns(uint8_t *state)
{
    //Galois field multiplication by this matrix of the matrix made up by the state's columns
    // |2 3 1 1| |00 05 09 13|
    // |1 2 3 1| |01 04 08 12|
    // |1 1 2 3| |02 06 10 14|
    // |3 1 1 2| |03 07 11 15|
    //  special  state columns
    //  matrix      matrix

    uint8_t result[16];

    result[0]  = mul(0x02, state[ 0]) ^ mul(0x03, state[ 1]) ^ mul(0x01, state[ 2]) ^ mul(0x01, state[ 3]);
    result[1]  = mul(0x01, state[ 0]) ^ mul(0x02, state[ 1]) ^ mul(0x03, state[ 2]) ^ mul(0x01, state[ 3]);
    result[2]  = mul(0x01, state[ 0]) ^ mul(0x01, state[ 1]) ^ mul(0x02, state[ 2]) ^ mul(0x03, state[ 3]);
    result[3]  = mul(0x03, state[ 0]) ^ mul(0x01, state[ 1]) ^ mul(0x01, state[ 2]) ^ mul(0x02, state[ 3]);

    result[4]  = mul(0x02, state[ 4]) ^ mul(0x03, state[ 5]) ^ mul(0x01, state[ 6]) ^ mul(0x01, state[ 7]);
    result[5]  = mul(0x01, state[ 4]) ^ mul(0x02, state[ 5]) ^ mul(0x03, state[ 6]) ^ mul(0x01, state[ 7]);
    result[6]  = mul(0x01, state[ 4]) ^ mul(0x01, state[ 5]) ^ mul(0x02, state[ 6]) ^ mul(0x03, state[ 7]);
    result[7]  = mul(0x03, state[ 4]) ^ mul(0x01, state[ 5]) ^ mul(0x01, state[ 6]) ^ mul(0x02, state[ 7]);

    result[8]  = mul(0x02, state[ 8]) ^ mul(0x03, state[ 9]) ^ mul(0x01, state[10]) ^ mul(0x01, state[11]);
    result[9]  = mul(0x01, state[ 8]) ^ mul(0x02, state[ 9]) ^ mul(0x03, state[10]) ^ mul(0x01, state[11]);
    result[10] = mul(0x01, state[ 8]) ^ mul(0x01, state[ 9]) ^ mul(0x02, state[10]) ^ mul(0x03, state[11]);
    result[11] = mul(0x03, state[ 8]) ^ mul(0x01, state[ 9]) ^ mul(0x01, state[10]) ^ mul(0x02, state[11]);

    result[12] = mul(0x02, state[12]) ^ mul(0x03, state[13]) ^ mul(0x01, state[14]) ^ mul(0x01, state[15]);
    result[13] = mul(0x01, state[12]) ^ mul(0x02, state[13]) ^ mul(0x03, state[14]) ^ mul(0x01, state[15]);
    result[14] = mul(0x01, state[12]) ^ mul(0x01, state[13]) ^ mul(0x02, state[14]) ^ mul(0x03, state[15]);
    result[15] = mul(0x03, state[12]) ^ mul(0x01, state[13]) ^ mul(0x01, state[14]) ^ mul(0x02, state[15]);

    memcpy(state, result, 16);
}

void mixColumns_inverse(uint8_t *state) {
    //Galois field multiplication by this matrix (inverse of the one used for the non-reverse mixColumns) of the matrix made up by the state's columns
    // |0E 0B 0D 09| |00 05 09 13|
    // |09 0E 0B 0D| |01 04 08 12|
    // |0D 09 0E 0B| |02 06 10 14|
    // |0B 0D 09 0E| |03 07 11 15|
    //  special      state columns
    //  matrix          matrix

    uint8_t result[16];

    result[0]  = mul(0x0E, state[ 0]) ^ mul(0x0B, state[ 1]) ^ mul(0x0D, state[ 2]) ^ mul(0x09, state[ 3]);
    result[1]  = mul(0x09, state[ 0]) ^ mul(0x0E, state[ 1]) ^ mul(0x0B, state[ 2]) ^ mul(0x0D, state[ 3]);
    result[2]  = mul(0x0D, state[ 0]) ^ mul(0x09, state[ 1]) ^ mul(0x0E, state[ 2]) ^ mul(0x0B, state[ 3]);
    result[3]  = mul(0x0B, state[ 0]) ^ mul(0x0D, state[ 1]) ^ mul(0x09, state[ 2]) ^ mul(0x0E, state[ 3]);

    result[4]  = mul(0x0E, state[ 4]) ^ mul(0x0B, state[ 5]) ^ mul(0x0D, state[ 6]) ^ mul(0x09, state[ 7]);
    result[5]  = mul(0x09, state[ 4]) ^ mul(0x0E, state[ 5]) ^ mul(0x0B, state[ 6]) ^ mul(0x0D, state[ 7]);
    result[6]  = mul(0x0D, state[ 4]) ^ mul(0x09, state[ 5]) ^ mul(0x0E, state[ 6]) ^ mul(0x0B, state[ 7]);
    result[7]  = mul(0x0B, state[ 4]) ^ mul(0x0D, state[ 5]) ^ mul(0x09, state[ 6]) ^ mul(0x0E, state[ 7]);

    result[8]  = mul(0x0E, state[ 8]) ^ mul(0x0B, state[ 9]) ^ mul(0x0D, state[10]) ^ mul(0x09, state[11]);
    result[9]  = mul(0x09, state[ 8]) ^ mul(0x0E, state[ 9]) ^ mul(0x0B, state[10]) ^ mul(0x0D, state[11]);
    result[10] = mul(0x0D, state[ 8]) ^ mul(0x09, state[ 9]) ^ mul(0x0E, state[10]) ^ mul(0x0B, state[11]);
    result[11] = mul(0x0B, state[ 8]) ^ mul(0x0D, state[ 9]) ^ mul(0x09, state[10]) ^ mul(0x0E, state[11]);

    result[12] = mul(0x0E, state[12]) ^ mul(0x0B, state[13]) ^ mul(0x0D, state[14]) ^ mul(0x09, state[15]);
    result[13] = mul(0x09, state[12]) ^ mul(0x0E, state[13]) ^ mul(0x0B, state[14]) ^ mul(0x0D, state[15]);
    result[14] = mul(0x0D, state[12]) ^ mul(0x09, state[13]) ^ mul(0x0E, state[14]) ^ mul(0x0B, state[15]);
    result[15] = mul(0x0B, state[12]) ^ mul(0x0D, state[13]) ^ mul(0x09, state[14]) ^ mul(0x0E, state[15]);

    memcpy(state, result, 16);
}

void addRoundKey(uint8_t *state, uint8_t *roundKey)
{
    for (int i = 0; i < 16; i++)
    {
        state[i] ^= roundKey[i];
    }
}

void encrypt_128(uint8_t *block, uint8_t *key)
{
    uint8_t state[16];
    memcpy(state, block, 16);

    int numberOfRounds = 10;

    uint8_t expandedKey[176];
    KeyExpansion(key, expandedKey);

    addRoundKey(state, key);

    for (int i = 1; i <= numberOfRounds - 1; i++)
    {
        subBytes(state);
        shiftRows(state);
        mixColumns(state);
        addRoundKey(state, expandedKey + 16 * i);
    }

    // final round
    subBytes(state);
    shiftRows(state);
    addRoundKey(state, expandedKey + 16 * (numberOfRounds));

    memcpy(block, state, 16);
}

void decrypt_128(uint8_t *block, uint8_t *key)
{
    uint8_t state[16];
    memcpy(state, block, 16);

    int numberOfRounds = 10;

    uint8_t expandedKey[176];
    KeyExpansion(key, expandedKey);

    // final round
    addRoundKey(state, expandedKey + 16 * (numberOfRounds));
    shiftRows_inverse(state);
    subBytes_inverse(state);

    for(int i = numberOfRounds - 1; i >= 1; i--){
        addRoundKey(state, expandedKey + 16 * i);
        mixColumns_inverse(state);
        shiftRows_inverse(state);
        subBytes_inverse(state);
    }

    addRoundKey(state, key);

    memcpy(block, state, 16);  
}

/**
 * @brief pads the message by adding bytes.
 * @param blockSize The size to pad to.
 * @returns The message's new length. If this is greater than capacity,
 * Nothing has been done, increase the capacity and run again
 * 
 */
size_t bytePad(uint8_t blockSize, uint8_t *message, size_t length, size_t capacity) {
    // get amount of padding
    // this will return the blocksize if the length
    // is a multiple of the blocksize, which is desired
    uint8_t padSize = blockSize - (length % blockSize);
    size_t newLength = length + padSize;

    // check capacity
    if (newLength > capacity) {
        // return needed capacity
        return newLength;
    }

    // pad with zeros and then the number of padded bytes
    // ie: fb 8c 0a 00 00 00 04
    for(int i = 0; i < padSize - 1; i++){
        message[length + i] = 0x00;
    }
    message[newLength - 1] = (uint8_t)padSize;

    // return new length
    return newLength;
}

/**
 * @brief Removes the padding added by bytePad.
 * @returns The new length of the message.
 * 
 * @param blockSize 
 * @param message 
 * @param length 
 * @return size_t 
 */
size_t byteUnPad(uint8_t *message, size_t length) {
    uint8_t padSize = message[length - 1];
    return length - padSize;
    // that was simple
}

/**
 * @brief 
 * 
 * @param key 16 byte key (must be 16 bytes of known data). Will not pad if not long enough. Must be padded already.
 * @param message 
 * @param length 
 * @param capacity 
 * @return The new length of the, now encrypted message, if greater than capacity, nothing has been done.
 * increase capacity and run again.
 */
size_t encrypt_128_ecb(uint8_t *key, uint8_t *message, size_t length, size_t capacity) {
    // pad message
    size_t newLength = bytePad(16, message, length, capacity);
    // check capacity;
    if (newLength > capacity){
        // return needed capacity
        return newLength;
    }

    // encrypt the message in blocks
    for(size_t i = 0; i < newLength; i += 16){
        encrypt_128(message + i, key);
    }
}

/**
 * @brief decrypts the message using the ecb mode of operation. Assumes that the message's length is a multiple of 16.
 * 
 * @param key 
 * @param message 
 * @param length 
 * @return size_t 
 */
size_t decrypt_128_ecb(uint8_t *key, uint8_t *message, size_t length) {
    // decrypt the message in bocks
    for(size_t i = 0; i < length; i += 16) {
        decrypt_128(message + i, key);
    }

    // un-pad and return new length
    return byteUnPad(message, length);
}

int main(size_t argc, char **args) {
    if (argc != 3){
        fputs("invalid number of arguments, 2 expected", stderr);
        return 1;
    }

    char mode = args[1][0];
    if (mode != 'e' && mode != 'd'){
        fputs("invalid mode expected 'e' (ecrypt) or 'd' (decrypt)", stderr);
        return 1;
    }

    size_t keyLength = strlen(args[2]);
    char key[16];
    for(int i = 0; i < 16; i++) {
        key[i] = 0x00;
    }

    memcpy(key, args[2], keyLength);

    if (keyLength < 16){
        fputs("key too short. padding with zeros\n", stderr);
    } else if (keyLength > 16) {
        fputs("key too long. extra bytes will be ignored\n", stderr);
    }

    Buffer input = createBuffer();

    size_t messageLength = 0;

    // read stdin
    int c;
    while((c = getchar()) != EOF) {
        bufferAppendByte(&input, (char)c);
        messageLength++;
    }


    // trim buffer or add capacity for padding and null terminator
    BufferError err = bufferSetSize(&input, messageLength + 17);
    if (err) {
        destroyBuffer(&input);
        return err;
    };

    int newLength;

    if (mode == 'e'){
        // can ignore output as the capacity is definitely enough
        newLength = encrypt_128_ecb(key, input.data, messageLength, input.size);
    } else {
        newLength = decrypt_128_ecb(key, input.data, messageLength);
    }

    // printf("%.*s", newLength, input.data);
    for(size_t i = 0; i < newLength; i++){
        char tmp[2];
        tmp[0] = input.data[i];
        tmp[1] = '\0';
        printf("%c", input.data[i]);
    }

    destroyBuffer(&input);
    return 0;
}


void scratch()
{
    // uint8_t *message = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog! The quick brown fox jumps over the lazy dog?";

    // message that is 32 bytes long(including null terminator)
    uint8_t *message = "0123456789abcdef0123456789abcd";

    uint8_t *key = "aes rules!!!!!!"; /* key padded with exclamation points to be 16 bytes, including null terminator.*/

    size_t messageLength = strlen(message) + 1 /* for null terminator */;
    size_t messageCapacity = messageLength + 16 /* for potential extra block from padding */ + 1 /* for post encryption null terminator to print message, since I'm encrypting the null terminator as well. */;
    uint8_t *messageBuffer = malloc(messageCapacity);
    memcpy(messageBuffer, message, messageLength);

    // print message pre-encryption
    printf("pre encryption:  %s\n", messageBuffer);

    // encrypt
    size_t encryptedLength = encrypt_128_ecb(key, messageBuffer, messageLength, messageCapacity);
    // add null terminator so message can be printed
    messageBuffer[encryptedLength] = '\0';

    // print message post-encryption
    printf("post encryption: %s\n", messageBuffer);


    //decrypt
    decrypt_128_ecb(key, messageBuffer, encryptedLength);

    // print message post decryption
    printf("post decryption: %s\n", messageBuffer);
    printf("pre encryption length:  %d\n", messageLength /* null term */);
    printf("post encryption length: %d\n", encryptedLength);

    free(messageBuffer);
}
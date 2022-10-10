// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "iw7.hpp"

namespace xsk::gsc::iw7
{

extern const std::array<std::pair<std::uint16_t, const char*>, func_count> func_list
{{
    { 0x001, "_func_001" },
    { 0x002, "_func_002" },
    { 0x003, "_func_003" },
    { 0x004, "_func_004" },
    { 0x005, "_func_005" },
    { 0x006, "_func_006" },
    { 0x007, "_func_007" },
    { 0x008, "_func_008" },
    { 0x009, "_func_009" },
    { 0x00A, "_func_00A" },
    { 0x00B, "_func_00B" },
    { 0x00C, "_func_00C" },
    { 0x00D, "_func_00D" },
    { 0x00E, "_func_00E" },
    { 0x00F, "_func_00F" },
    { 0x010, "_func_010" },
    { 0x011, "_func_011" },
    { 0x012, "_func_012" },
    { 0x013, "_func_013" },
    { 0x014, "_func_014" },
    { 0x015, "_func_015" },
    { 0x016, "_func_016" },
    { 0x017, "_func_017" },
    { 0x018, "_func_018" },
    { 0x019, "_func_019" },
    { 0x01A, "_func_01A" },
    { 0x01B, "_func_01B" },
    { 0x01C, "_func_01C" },
    { 0x01D, "_func_01D" },
    { 0x01E, "_func_01E" },
    { 0x01F, "_func_01F" },
    { 0x020, "_func_020" },
    { 0x021, "_func_021" },
    { 0x022, "_func_022" },
    { 0x023, "_func_023" },
    { 0x024, "_func_024" },
    { 0x025, "_func_025" },
    { 0x026, "_func_026" },
    { 0x027, "_func_027" },
    { 0x028, "_func_028" },
    { 0x029, "_func_029" },
    { 0x02A, "_func_02A" },
    { 0x02B, "_func_02B" },
    { 0x02C, "_func_02C" },
    { 0x02D, "_func_02D" },
    { 0x02E, "_func_02E" },
    { 0x02F, "_func_02F" },
    { 0x030, "_func_030" },
    { 0x031, "_func_031" },
    { 0x032, "_func_032" },
    { 0x033, "_func_033" },
    { 0x034, "_func_034" },
    { 0x035, "_func_035" },
    { 0x036, "_func_036" },
    { 0x037, "_func_037" },
    { 0x038, "_func_038" },
    { 0x039, "_func_039" },
    { 0x03A, "_func_03A" },
    { 0x03B, "_func_03B" },
    { 0x03C, "_func_03C" },
    { 0x03D, "_func_03D" },
    { 0x03E, "_func_03E" },
    { 0x03F, "_func_03F" },
    { 0x040, "_func_040" },
    { 0x041, "_func_041" },
    { 0x042, "_func_042" },
    { 0x043, "_func_043" },
    { 0x044, "_func_044" },
    { 0x045, "_func_045" },
    { 0x046, "_func_046" },
    { 0x047, "_func_047" },
    { 0x048, "_func_048" },
    { 0x049, "_func_049" },
    { 0x04A, "_func_04A" },
    { 0x04B, "_func_04B" },
    { 0x04C, "_func_04C" },
    { 0x04D, "_func_04D" },
    { 0x04E, "_func_04E" },
    { 0x04F, "_func_04F" },
    { 0x050, "_func_050" },
    { 0x051, "_func_051" },
    { 0x052, "_func_052" },
    { 0x053, "_func_053" },
    { 0x054, "_func_054" },
    { 0x055, "_func_055" },
    { 0x056, "_func_056" },
    { 0x057, "_func_057" },
    { 0x058, "_func_058" },
    { 0x059, "_func_059" },
    { 0x05A, "_func_05A" },
    { 0x05B, "_func_05B" },
    { 0x05C, "_func_05C" },
    { 0x05D, "_func_05D" },
    { 0x05E, "_func_05E" },
    { 0x05F, "_func_05F" },
    { 0x060, "_func_060" },
    { 0x061, "_func_061" },
    { 0x062, "_func_062" },
    { 0x063, "_func_063" },
    { 0x064, "_func_064" },
    { 0x065, "_func_065" },
    { 0x066, "_func_066" },
    { 0x067, "_func_067" },
    { 0x068, "_func_068" },
    { 0x069, "_func_069" },
    { 0x06A, "_func_06A" },
    { 0x06B, "_func_06B" },
    { 0x06C, "_func_06C" },
    { 0x06D, "_func_06D" },
    { 0x06E, "_func_06E" },
    { 0x06F, "_func_06F" },
    { 0x070, "_func_070" },
    { 0x071, "_func_071" },
    { 0x072, "_func_072" },
    { 0x073, "_func_073" },
    { 0x074, "_func_074" },
    { 0x075, "_func_075" },
    { 0x076, "_func_076" },
    { 0x077, "_func_077" },
    { 0x078, "_func_078" },
    { 0x079, "_func_079" },
    { 0x07A, "_func_07A" },
    { 0x07B, "_func_07B" },
    { 0x07C, "_func_07C" },
    { 0x07D, "_func_07D" },
    { 0x07E, "_func_07E" },
    { 0x07F, "_func_07F" },
    { 0x080, "_func_080" },
    { 0x081, "_func_081" },
    { 0x082, "_func_082" },
    { 0x083, "_func_083" },
    { 0x084, "_func_084" },
    { 0x085, "_func_085" },
    { 0x086, "_func_086" },
    { 0x087, "_func_087" },
    { 0x088, "_func_088" },
    { 0x089, "_func_089" },
    { 0x08A, "_func_08A" },
    { 0x08B, "_func_08B" },
    { 0x08C, "_func_08C" },
    { 0x08D, "_func_08D" },
    { 0x08E, "_func_08E" },
    { 0x08F, "_func_08F" },
    { 0x090, "_func_090" },
    { 0x091, "_func_091" },
    { 0x092, "_func_092" },
    { 0x093, "_func_093" },
    { 0x094, "_func_094" },
    { 0x095, "_func_095" },
    { 0x096, "_func_096" },
    { 0x097, "_func_097" },
    { 0x098, "_func_098" },
    { 0x099, "_func_099" },
    { 0x09A, "_func_09A" },
    { 0x09B, "_func_09B" },
    { 0x09C, "getfirstarraykey" },
    { 0x09D, "_func_09D" },
    { 0x09E, "_func_09E" },
    { 0x09F, "_func_09F" },
    { 0x0A0, "_func_0A0" },
    { 0x0A1, "_func_0A1" },
    { 0x0A2, "_func_0A2" },
    { 0x0A3, "_func_0A3" },
    { 0x0A4, "_func_0A4" },
    { 0x0A5, "_func_0A5" },
    { 0x0A6, "_func_0A6" },
    { 0x0A7, "_func_0A7" },
    { 0x0A8, "_func_0A8" },
    { 0x0A9, "_func_0A9" },
    { 0x0AA, "_func_0AA" },
    { 0x0AB, "_func_0AB" },
    { 0x0AC, "_func_0AC" },
    { 0x0AD, "_func_0AD" },
    { 0x0AE, "_func_0AE" },
    { 0x0AF, "_func_0AF" },
    { 0x0B0, "_func_0B0" },
    { 0x0B1, "_func_0B1" },
    { 0x0B2, "getnextarraykey" },
    { 0x0B3, "_func_0B3" },
    { 0x0B4, "_func_0B4" },
    { 0x0B5, "_func_0B5" },
    { 0x0B6, "_func_0B6" },
    { 0x0B7, "_func_0B7" },
    { 0x0B8, "_func_0B8" },
    { 0x0B9, "_func_0B9" },
    { 0x0BA, "_func_0BA" },
    { 0x0BB, "_func_0BB" },
    { 0x0BC, "_func_0BC" },
    { 0x0BD, "_func_0BD" },
    { 0x0BE, "_func_0BE" },
    { 0x0BF, "_func_0BF" },
    { 0x0C0, "_func_0C0" },
    { 0x0C1, "_func_0C1" },
    { 0x0C2, "_func_0C2" },
    { 0x0C3, "_func_0C3" },
    { 0x0C4, "_func_0C4" },
    { 0x0C5, "_func_0C5" },
    { 0x0C6, "_func_0C6" },
    { 0x0C7, "_func_0C7" },
    { 0x0C8, "_func_0C8" },
    { 0x0C9, "_func_0C9" },
    { 0x0CA, "_func_0CA" },
    { 0x0CB, "_func_0CB" },
    { 0x0CC, "_func_0CC" },
    { 0x0CD, "_func_0CD" },
    { 0x0CE, "_func_0CE" },
    { 0x0CF, "_func_0CF" },
    { 0x0D0, "_func_0D0" },
    { 0x0D1, "_func_0D1" },
    { 0x0D2, "_func_0D2" },
    { 0x0D3, "_func_0D3" },
    { 0x0D4, "_func_0D4" },
    { 0x0D5, "_func_0D5" },
    { 0x0D6, "_func_0D6" },
    { 0x0D7, "_func_0D7" },
    { 0x0D8, "_func_0D8" },
    { 0x0D9, "_func_0D9" },
    { 0x0DA, "_func_0DA" },
    { 0x0DB, "_func_0DB" },
    { 0x0DC, "_func_0DC" },
    { 0x0DD, "_func_0DD" },
    { 0x0DE, "_func_0DE" },
    { 0x0DF, "_func_0DF" },
    { 0x0E0, "_func_0E0" },
    { 0x0E1, "_func_0E1" },
    { 0x0E2, "_func_0E2" },
    { 0x0E3, "_func_0E3" },
    { 0x0E4, "_func_0E4" },
    { 0x0E5, "_func_0E5" },
    { 0x0E6, "_func_0E6" },
    { 0x0E7, "_func_0E7" },
    { 0x0E8, "_func_0E8" },
    { 0x0E9, "_func_0E9" },
    { 0x0EA, "_func_0EA" },
    { 0x0EB, "_func_0EB" },
    { 0x0EC, "_func_0EC" },
    { 0x0ED, "_func_0ED" },
    { 0x0EE, "_func_0EE" },
    { 0x0EF, "_func_0EF" },
    { 0x0F0, "_func_0F0" },
    { 0x0F1, "_func_0F1" },
    { 0x0F2, "_func_0F2" },
    { 0x0F3, "_func_0F3" },
    { 0x0F4, "_func_0F4" },
    { 0x0F5, "_func_0F5" },
    { 0x0F6, "_func_0F6" },
    { 0x0F7, "_func_0F7" },
    { 0x0F8, "_func_0F8" },
    { 0x0F9, "_func_0F9" },
    { 0x0FA, "_func_0FA" },
    { 0x0FB, "_func_0FB" },
    { 0x0FC, "_func_0FC" },
    { 0x0FD, "_func_0FD" },
    { 0x0FE, "_func_0FE" },
    { 0x0FF, "_func_0FF" },
    { 0x100, "_func_100" },
    { 0x101, "_func_101" },
    { 0x102, "_func_102" },
    { 0x103, "_func_103" },
    { 0x104, "isdefined" },
    { 0x105, "_func_105" },
    { 0x106, "_func_106" },
    { 0x107, "_func_107" },
    { 0x108, "_func_108" },
    { 0x109, "_func_109" },
    { 0x10A, "_func_10A" },
    { 0x10B, "_func_10B" },
    { 0x10C, "_func_10C" },
    { 0x10D, "_func_10D" },
    { 0x10E, "_func_10E" },
    { 0x10F, "_func_10F" },
    { 0x110, "_func_110" },
    { 0x111, "_func_111" },
    { 0x112, "_func_112" },
    { 0x113, "_func_113" },
    { 0x114, "_func_114" },
    { 0x115, "_func_115" },
    { 0x116, "_func_116" },
    { 0x117, "_func_117" },
    { 0x118, "_func_118" },
    { 0x119, "_func_119" },
    { 0x11A, "_func_11A" },
    { 0x11B, "_func_11B" },
    { 0x11C, "_func_11C" },
    { 0x11D, "_func_11D" },
    { 0x11E, "_func_11E" },
    { 0x11F, "_func_11F" },
    { 0x120, "_func_120" },
    { 0x121, "_func_121" },
    { 0x122, "_func_122" },
    { 0x123, "_func_123" },
    { 0x124, "_func_124" },
    { 0x125, "_func_125" },
    { 0x126, "_func_126" },
    { 0x127, "_func_127" },
    { 0x128, "_func_128" },
    { 0x129, "_func_129" },
    { 0x12A, "_func_12A" },
    { 0x12B, "_func_12B" },
    { 0x12C, "_func_12C" },
    { 0x12D, "_func_12D" },
    { 0x12E, "_func_12E" },
    { 0x12F, "_func_12F" },
    { 0x130, "_func_130" },
    { 0x131, "_func_131" },
    { 0x132, "_func_132" },
    { 0x133, "_func_133" },
    { 0x134, "_func_134" },
    { 0x135, "_func_135" },
    { 0x136, "_func_136" },
    { 0x137, "_func_137" },
    { 0x138, "_func_138" },
    { 0x139, "_func_139" },
    { 0x13A, "_func_13A" },
    { 0x13B, "_func_13B" },
    { 0x13C, "_func_13C" },
    { 0x13D, "_func_13D" },
    { 0x13E, "_func_13E" },
    { 0x13F, "_func_13F" },
    { 0x140, "_func_140" },
    { 0x141, "_func_141" },
    { 0x142, "_func_142" },
    { 0x143, "_func_143" },
    { 0x144, "_func_144" },
    { 0x145, "_func_145" },
    { 0x146, "_func_146" },
    { 0x147, "_func_147" },
    { 0x148, "_func_148" },
    { 0x149, "_func_149" },
    { 0x14A, "_func_14A" },
    { 0x14B, "_func_14B" },
    { 0x14C, "_func_14C" },
    { 0x14D, "_func_14D" },
    { 0x14E, "_func_14E" },
    { 0x14F, "_func_14F" },
    { 0x150, "_func_150" },
    { 0x151, "_func_151" },
    { 0x152, "_func_152" },
    { 0x153, "_func_153" },
    { 0x154, "_func_154" },
    { 0x155, "_func_155" },
    { 0x156, "_func_156" },
    { 0x157, "_func_157" },
    { 0x158, "_func_158" },
    { 0x159, "_func_159" },
    { 0x15A, "_func_15A" },
    { 0x15B, "_func_15B" },
    { 0x15C, "_func_15C" },
    { 0x15D, "_func_15D" },
    { 0x15E, "_func_15E" },
    { 0x15F, "_func_15F" },
    { 0x160, "_func_160" },
    { 0x161, "_func_161" },
    { 0x162, "_func_162" },
    { 0x163, "_func_163" },
    { 0x164, "_func_164" },
    { 0x165, "_func_165" },
    { 0x166, "_func_166" },
    { 0x167, "_func_167" },
    { 0x168, "_func_168" },
    { 0x169, "_func_169" },
    { 0x16A, "_func_16A" },
    { 0x16B, "_func_16B" },
    { 0x16C, "_func_16C" },
    { 0x16D, "_func_16D" },
    { 0x16E, "_func_16E" },
    { 0x16F, "_func_16F" },
    { 0x170, "_func_170" },
    { 0x171, "_func_171" },
    { 0x172, "_func_172" },
    { 0x173, "_func_173" },
    { 0x174, "_func_174" },
    { 0x175, "_func_175" },
    { 0x176, "_func_176" },
    { 0x177, "_func_177" },
    { 0x178, "_func_178" },
    { 0x179, "_func_179" },
    { 0x17A, "_func_17A" },
    { 0x17B, "_func_17B" },
    { 0x17C, "_func_17C" },
    { 0x17D, "_func_17D" },
    { 0x17E, "_func_17E" },
    { 0x17F, "_func_17F" },
    { 0x180, "_func_180" },
    { 0x181, "_func_181" },
    { 0x182, "_func_182" },
    { 0x183, "_func_183" },
    { 0x184, "_func_184" },
    { 0x185, "_func_185" },
    { 0x186, "_func_186" },
    { 0x187, "_func_187" },
    { 0x188, "_func_188" },
    { 0x189, "_func_189" },
    { 0x18A, "_func_18A" },
    { 0x18B, "_func_18B" },
    { 0x18C, "_func_18C" },
    { 0x18D, "_func_18D" },
    { 0x18E, "_func_18E" },
    { 0x18F, "_func_18F" },
    { 0x190, "_func_190" },
    { 0x191, "_func_191" },
    { 0x192, "_func_192" },
    { 0x193, "_func_193" },
    { 0x194, "_func_194" },
    { 0x195, "_func_195" },
    { 0x196, "_func_196" },
    { 0x197, "_func_197" },
    { 0x198, "_func_198" },
    { 0x199, "_func_199" },
    { 0x19A, "_func_19A" },
    { 0x19B, "_func_19B" },
    { 0x19C, "_func_19C" },
    { 0x19D, "_func_19D" },
    { 0x19E, "_func_19E" },
    { 0x19F, "_func_19F" },
    { 0x1A0, "_func_1A0" },
    { 0x1A1, "_func_1A1" },
    { 0x1A2, "_func_1A2" },
    { 0x1A3, "_func_1A3" },
    { 0x1A4, "_func_1A4" },
    { 0x1A5, "_func_1A5" },
    { 0x1A6, "_func_1A6" },
    { 0x1A7, "_func_1A7" },
    { 0x1A8, "_func_1A8" },
    { 0x1A9, "_func_1A9" },
    { 0x1AA, "_func_1AA" },
    { 0x1AB, "_func_1AB" },
    { 0x1AC, "_func_1AC" },
    { 0x1AD, "_func_1AD" },
    { 0x1AE, "_func_1AE" },
    { 0x1AF, "_func_1AF" },
    { 0x1B0, "_func_1B0" },
    { 0x1B1, "_func_1B1" },
    { 0x1B2, "_func_1B2" },
    { 0x1B3, "_func_1B3" },
    { 0x1B4, "_func_1B4" },
    { 0x1B5, "_func_1B5" },
    { 0x1B6, "_func_1B6" },
    { 0x1B7, "_func_1B7" },
    { 0x1B8, "_func_1B8" },
    { 0x1B9, "_func_1B9" },
    { 0x1BA, "_func_1BA" },
    { 0x1BB, "_func_1BB" },
    { 0x1BC, "_func_1BC" },
    { 0x1BD, "_func_1BD" },
    { 0x1BE, "_func_1BE" },
    { 0x1BF, "_func_1BF" },
    { 0x1C0, "_func_1C0" },
    { 0x1C1, "_func_1C1" },
    { 0x1C2, "_func_1C2" },
    { 0x1C3, "_func_1C3" },
    { 0x1C4, "_func_1C4" },
    { 0x1C5, "_func_1C5" },
    { 0x1C6, "_func_1C6" },
    { 0x1C7, "_func_1C7" },
    { 0x1C8, "_func_1C8" },
    { 0x1C9, "_func_1C9" },
    { 0x1CA, "_func_1CA" },
    { 0x1CB, "_func_1CB" },
    { 0x1CC, "_func_1CC" },
    { 0x1CD, "_func_1CD" },
    { 0x1CE, "_func_1CE" },
    { 0x1CF, "_func_1CF" },
    { 0x1D0, "_func_1D0" },
    { 0x1D1, "_func_1D1" },
    { 0x1D2, "_func_1D2" },
    { 0x1D3, "_func_1D3" },
    { 0x1D4, "_func_1D4" },
    { 0x1D5, "_func_1D5" },
    { 0x1D6, "_func_1D6" },
    { 0x1D7, "_func_1D7" },
    { 0x1D8, "_func_1D8" },
    { 0x1D9, "_func_1D9" },
    { 0x1DA, "_func_1DA" },
    { 0x1DB, "_func_1DB" },
    { 0x1DC, "_func_1DC" },
    { 0x1DD, "_func_1DD" },
    { 0x1DE, "_func_1DE" },
    { 0x1DF, "_func_1DF" },
    { 0x1E0, "_func_1E0" },
    { 0x1E1, "_func_1E1" },
    { 0x1E2, "_func_1E2" },
    { 0x1E3, "_func_1E3" },
    { 0x1E4, "_func_1E4" },
    { 0x1E5, "_func_1E5" },
    { 0x1E6, "_func_1E6" },
    { 0x1E7, "_func_1E7" },
    { 0x1E8, "_func_1E8" },
    { 0x1E9, "_func_1E9" },
    { 0x1EA, "_func_1EA" },
    { 0x1EB, "_func_1EB" },
    { 0x1EC, "_func_1EC" },
    { 0x1ED, "_func_1ED" },
    { 0x1EE, "_func_1EE" },
    { 0x1EF, "_func_1EF" },
    { 0x1F0, "_func_1F0" },
    { 0x1F1, "_func_1F1" },
    { 0x1F2, "_func_1F2" },
    { 0x1F3, "_func_1F3" },
    { 0x1F4, "_func_1F4" },
    { 0x1F5, "_func_1F5" },
    { 0x1F6, "_func_1F6" },
    { 0x1F7, "_func_1F7" },
    { 0x1F8, "_func_1F8" },
    { 0x1F9, "_func_1F9" },
    { 0x1FA, "_func_1FA" },
    { 0x1FB, "_func_1FB" },
    { 0x1FC, "_func_1FC" },
    { 0x1FD, "_func_1FD" },
    { 0x1FE, "_func_1FE" },
    { 0x1FF, "_func_1FF" },
    { 0x200, "_func_200" },
    { 0x201, "_func_201" },
    { 0x202, "_func_202" },
    { 0x203, "_func_203" },
    { 0x204, "_func_204" },
    { 0x205, "_func_205" },
    { 0x206, "_func_206" },
    { 0x207, "_func_207" },
    { 0x208, "_func_208" },
    { 0x209, "_func_209" },
    { 0x20A, "_func_20A" },
    { 0x20B, "_func_20B" },
    { 0x20C, "_func_20C" },
    { 0x20D, "_func_20D" },
    { 0x20E, "_func_20E" },
    { 0x20F, "_func_20F" },
    { 0x210, "_func_210" },
    { 0x211, "_func_211" },
    { 0x212, "_func_212" },
    { 0x213, "_func_213" },
    { 0x214, "_func_214" },
    { 0x215, "_func_215" },
    { 0x216, "_func_216" },
    { 0x217, "_func_217" },
    { 0x218, "_func_218" },
    { 0x219, "_func_219" },
    { 0x21A, "_func_21A" },
    { 0x21B, "_func_21B" },
    { 0x21C, "_func_21C" },
    { 0x21D, "_func_21D" },
    { 0x21E, "_func_21E" },
    { 0x21F, "_func_21F" },
    { 0x220, "_func_220" },
    { 0x221, "_func_221" },
    { 0x222, "_func_222" },
    { 0x223, "_func_223" },
    { 0x224, "_func_224" },
    { 0x225, "_func_225" },
    { 0x226, "_func_226" },
    { 0x227, "_func_227" },
    { 0x228, "_func_228" },
    { 0x229, "_func_229" },
    { 0x22A, "_func_22A" },
    { 0x22B, "_func_22B" },
    { 0x22C, "_func_22C" },
    { 0x22D, "_func_22D" },
    { 0x22E, "_func_22E" },
    { 0x22F, "_func_22F" },
    { 0x230, "_func_230" },
    { 0x231, "_func_231" },
    { 0x232, "_func_232" },
    { 0x233, "_func_233" },
    { 0x234, "_func_234" },
    { 0x235, "_func_235" },
    { 0x236, "_func_236" },
    { 0x237, "_func_237" },
    { 0x238, "_func_238" },
    { 0x239, "_func_239" },
    { 0x23A, "_func_23A" },
    { 0x23B, "_func_23B" },
    { 0x23C, "_func_23C" },
    { 0x23D, "_func_23D" },
    { 0x23E, "_func_23E" },
    { 0x23F, "_func_23F" },
    { 0x240, "_func_240" },
    { 0x241, "_func_241" },
    { 0x242, "_func_242" },
    { 0x243, "_func_243" },
    { 0x244, "_func_244" },
    { 0x245, "_func_245" },
    { 0x246, "_func_246" },
    { 0x247, "_func_247" },
    { 0x248, "_func_248" },
    { 0x249, "_func_249" },
    { 0x24A, "_func_24A" },
    { 0x24B, "_func_24B" },
    { 0x24C, "_func_24C" },
    { 0x24D, "_func_24D" },
    { 0x24E, "_func_24E" },
    { 0x24F, "_func_24F" },
    { 0x250, "_func_250" },
    { 0x251, "_func_251" },
    { 0x252, "_func_252" },
    { 0x253, "_func_253" },
    { 0x254, "_func_254" },
    { 0x255, "_func_255" },
    { 0x256, "_func_256" },
    { 0x257, "_func_257" },
    { 0x258, "_func_258" },
    { 0x259, "_func_259" },
    { 0x25A, "_func_25A" },
    { 0x25B, "_func_25B" },
    { 0x25C, "_func_25C" },
    { 0x25D, "_func_25D" },
    { 0x25E, "_func_25E" },
    { 0x25F, "_func_25F" },
    { 0x260, "_func_260" },
    { 0x261, "_func_261" },
    { 0x262, "_func_262" },
    { 0x263, "_func_263" },
    { 0x264, "_func_264" },
    { 0x265, "_func_265" },
    { 0x266, "_func_266" },
    { 0x267, "_func_267" },
    { 0x268, "_func_268" },
    { 0x269, "_func_269" },
    { 0x26A, "_func_26A" },
    { 0x26B, "_func_26B" },
    { 0x26C, "_func_26C" },
    { 0x26D, "_func_26D" },
    { 0x26E, "_func_26E" },
    { 0x26F, "_func_26F" },
    { 0x270, "_func_270" },
    { 0x271, "_func_271" },
    { 0x272, "_func_272" },
    { 0x273, "_func_273" },
    { 0x274, "_func_274" },
    { 0x275, "_func_275" },
    { 0x276, "_func_276" },
    { 0x277, "_func_277" },
    { 0x278, "_func_278" },
    { 0x279, "_func_279" },
    { 0x27A, "_func_27A" },
    { 0x27B, "_func_27B" },
    { 0x27C, "_func_27C" },
    { 0x27D, "_func_27D" },
    { 0x27E, "_func_27E" },
    { 0x27F, "_func_27F" },
    { 0x280, "_func_280" },
    { 0x281, "_func_281" },
    { 0x282, "_func_282" },
    { 0x283, "_func_283" },
    { 0x284, "_func_284" },
    { 0x285, "_func_285" },
    { 0x286, "_func_286" },
    { 0x287, "_func_287" },
    { 0x288, "_func_288" },
    { 0x289, "_func_289" },
    { 0x28A, "_func_28A" },
    { 0x28B, "_func_28B" },
    { 0x28C, "_func_28C" },
    { 0x28D, "_func_28D" },
    { 0x28E, "_func_28E" },
    { 0x28F, "_func_28F" },
    { 0x290, "_func_290" },
    { 0x291, "_func_291" },
    { 0x292, "_func_292" },
    { 0x293, "_func_293" },
    { 0x294, "_func_294" },
    { 0x295, "_func_295" },
    { 0x296, "_func_296" },
    { 0x297, "_func_297" },
    { 0x298, "_func_298" },
    { 0x299, "_func_299" },
    { 0x29A, "_func_29A" },
    { 0x29B, "_func_29B" },
    { 0x29C, "_func_29C" },
    { 0x29D, "_func_29D" },
    { 0x29E, "_func_29E" },
    { 0x29F, "_func_29F" },
    { 0x2A0, "_func_2A0" },
    { 0x2A1, "_func_2A1" },
    { 0x2A2, "_func_2A2" },
    { 0x2A3, "_func_2A3" },
    { 0x2A4, "_func_2A4" },
    { 0x2A5, "_func_2A5" },
    { 0x2A6, "_func_2A6" },
    { 0x2A7, "_func_2A7" },
    { 0x2A8, "_func_2A8" },
    { 0x2A9, "_func_2A9" },
    { 0x2AA, "_func_2AA" },
    { 0x2AB, "_func_2AB" },
    { 0x2AC, "_func_2AC" },
    { 0x2AD, "_func_2AD" },
    { 0x2AE, "_func_2AE" },
    { 0x2AF, "_func_2AF" },
    { 0x2B0, "_func_2B0" },
    { 0x2B1, "_func_2B1" },
    { 0x2B2, "_func_2B2" },
    { 0x2B3, "_func_2B3" },
    { 0x2B4, "_func_2B4" },
    { 0x2B5, "_func_2B5" },
    { 0x2B6, "_func_2B6" },
    { 0x2B7, "_func_2B7" },
    { 0x2B8, "_func_2B8" },
    { 0x2B9, "_func_2B9" },
    { 0x2BA, "_func_2BA" },
    { 0x2BB, "_func_2BB" },
    { 0x2BC, "_func_2BC" },
    { 0x2BD, "_func_2BD" },
    { 0x2BE, "_func_2BE" },
    { 0x2BF, "_func_2BF" },
    { 0x2C0, "_func_2C0" },
    { 0x2C1, "_func_2C1" },
    { 0x2C2, "_func_2C2" },
    { 0x2C3, "_func_2C3" },
    { 0x2C4, "_func_2C4" },
    { 0x2C5, "_func_2C5" },
    { 0x2C6, "_func_2C6" },
    { 0x2C7, "_func_2C7" },
    { 0x2C8, "_func_2C8" },
    { 0x2C9, "_func_2C9" },
    { 0x2CA, "_func_2CA" },
    { 0x2CB, "_func_2CB" },
    { 0x2CC, "_func_2CC" },
    { 0x2CD, "_func_2CD" },
    { 0x2CE, "_func_2CE" },
    { 0x2CF, "_func_2CF" },
    { 0x2D0, "_func_2D0" },
    { 0x2D1, "_func_2D1" },
    { 0x2D2, "_func_2D2" },
    { 0x2D3, "_func_2D3" },
    { 0x2D4, "_func_2D4" },
    { 0x2D5, "_func_2D5" },
    { 0x2D6, "_func_2D6" },
    { 0x2D7, "_func_2D7" },
    { 0x2D8, "_func_2D8" },
    { 0x2D9, "_func_2D9" },
    { 0x2DA, "_func_2DA" },
    { 0x2DB, "_func_2DB" },
    { 0x2DC, "_func_2DC" },
    { 0x2DD, "_func_2DD" },
    { 0x2DE, "_func_2DE" },
    { 0x2DF, "_func_2DF" },
    { 0x2E0, "_func_2E0" },
    { 0x2E1, "_func_2E1" },
    { 0x2E2, "_func_2E2" },
    { 0x2E3, "_func_2E3" },
    { 0x2E4, "_func_2E4" },
    { 0x2E5, "_func_2E5" },
    { 0x2E6, "_func_2E6" },
    { 0x2E7, "_func_2E7" },
    { 0x2E8, "_func_2E8" },
    { 0x2E9, "_func_2E9" },
    { 0x2EA, "_func_2EA" },
    { 0x2EB, "_func_2EB" },
    { 0x2EC, "_func_2EC" },
    { 0x2ED, "_func_2ED" },
    { 0x2EE, "_func_2EE" },
    { 0x2EF, "_func_2EF" },
    { 0x2F0, "_func_2F0" },
    { 0x2F1, "_func_2F1" },
    { 0x2F2, "_func_2F2" },
    { 0x2F3, "_func_2F3" },
    { 0x2F4, "_func_2F4" },
    { 0x2F5, "_func_2F5" },
    { 0x2F6, "_func_2F6" },
    { 0x2F7, "_func_2F7" },
    { 0x2F8, "_func_2F8" },
    { 0x2F9, "_func_2F9" },
    { 0x2FA, "_func_2FA" },
    { 0x2FB, "_func_2FB" },
    { 0x2FC, "_func_2FC" },
    { 0x2FD, "_func_2FD" },
    { 0x2FE, "_func_2FE" },
    { 0x2FF, "_func_2FF" },
    { 0x300, "_func_300" },
    { 0x301, "_func_301" },
    { 0x302, "_func_302" },
    { 0x303, "_func_303" },
    { 0x304, "_func_304" },
    { 0x305, "_func_305" },
    { 0x306, "_func_306" },
    { 0x307, "_func_307" },
    { 0x308, "_func_308" },
    { 0x309, "_func_309" },
    { 0x30A, "_func_30A" },
    { 0x30B, "_func_30B" },
    { 0x30C, "_func_30C" },
    { 0x30D, "_func_30D" },
    { 0x30E, "_func_30E" },
    { 0x30F, "_func_30F" },
    { 0x310, "_func_310" },
    { 0x311, "_func_311" },
    { 0x312, "_func_312" },
    { 0x313, "_func_313" },
    { 0x314, "_func_314" },
    { 0x315, "_func_315" },
    { 0x316, "_func_316" },
    { 0x317, "_func_317" },
    { 0x318, "_func_318" },
    { 0x319, "_func_319" },
    { 0x31A, "_func_31A" },
    { 0x31B, "_func_31B" },
    { 0x31C, "_func_31C" },
    { 0x31D, "_func_31D" },
    { 0x31E, "_func_31E" },
    { 0x31F, "_func_31F" },
    { 0x320, "_func_320" },
    { 0x321, "_func_321" },
    { 0x322, "_func_322" },
    { 0x323, "_func_323" },
    { 0x324, "_func_324" },
    { 0x325, "_func_325" },
    { 0x326, "_func_326" },
    { 0x327, "_func_327" },
}};

} // namespace xsk::gsc::iw7

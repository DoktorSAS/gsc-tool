// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "s1_ps.hpp"

namespace xsk::gsc::s1_ps
{

extern const std::array<std::pair<std::uint16_t, const char*>, func_count> func_list
{{
    { 0x12, "isdefined" },
    { 0xC0, "getfirstarraykey" },
    { 0xC1, "getnextarraykey" },
}};

} // namespace xsk::gsc::s1_ps

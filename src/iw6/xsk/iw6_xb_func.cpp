// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "iw6_xb.hpp"

namespace xsk::gsc::iw6_xb
{

extern const std::array<std::pair<std::uint16_t, const char*>, func_count> func_list
{{
    { 0x12, "isdefined" },
    { 0xB7, "getfirstarraykey" },
    { 0xB8, "getnextarraykey" },
}};

} // namespace xsk::gsc::iw6_xb

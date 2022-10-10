// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "gsc/xsk/context.hpp"

namespace xsk::gsc::iw6_pc
{

constexpr size_t code_count = 153;
constexpr size_t func_count = 605;
constexpr size_t meth_count = 1066;
constexpr size_t token_count = 17508;
constexpr std::uint32_t max_string_id = 0x95A1;

class context : public gsc::context
{
public:
    context();
};

} // namespace xsk::gsc::iw6_pc

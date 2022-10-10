// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "gsc/xsk/context.hpp"

namespace xsk::gsc::s1_ps
{

constexpr size_t code_count = 154;
constexpr size_t func_count = 3;
constexpr size_t meth_count = 0;
constexpr size_t token_count = 0;
constexpr std::uint32_t max_string_id = 0xA51D; // TODO

class context : public gsc::context
{
public:
    context();
};

} // namespace xsk::gsc::s1_ps

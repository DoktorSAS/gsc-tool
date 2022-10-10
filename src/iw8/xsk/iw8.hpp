// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "gsc/xsk/context.hpp"

namespace xsk::gsc::iw8
{

constexpr size_t code_count = 190;
constexpr size_t func_count = 1065;
constexpr size_t meth_count = 2032;
constexpr size_t token_count = 72014;
constexpr std::uint32_t max_string_id = 0x1472F;

class context : public gsc::context
{
public:
    context();
};

} // namespace xsk::gsc::iw8

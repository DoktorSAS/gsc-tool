// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "gsc/xsk/context.hpp"

namespace xsk::gsc::s2
{

constexpr size_t code_count = 155;
constexpr size_t func_count = 1000;
constexpr size_t meth_count = 1700;
constexpr size_t token_count = 5;
constexpr std::uint32_t max_string_id = 0xACEE;

class context : public gsc::context
{
public:
    context();
};

} // namespace xsk::gsc::s2

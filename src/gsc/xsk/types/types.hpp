// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "utils/xsk/string.hpp"

#include "asset.hpp"
#include "opcode.hpp"
#include "instruction.hpp"
#include "function.hpp"
#include "location.hpp"
#include "exception.hpp"
#include "block.hpp"
#include "ast.hpp"

namespace xsk::gsc
{

using read_cb_type = std::function<std::vector<std::uint8_t>(const std::string&)>;

enum class build : std::uint8_t
{
    dev,
    prod,
};

enum class endian : std::uint8_t
{
    little,
    big,
};

enum class system : std::uint8_t
{
    pc,
    ps3,
    xb2,
};

enum class engine : std::uint8_t
{
    iw5,
    iw6,
    iw7,
    iw8,
    iw9,
    s1,
    s2,
    s4,
    h1,
    h2,
};

struct props
{
    enum values : std::uint32_t
    {
        none = 0,
        string_size = 1,
        token_size = 2,
        waitframe = 4,
        formal_params = 8,
        is_defined_is_true = 16,
        bool_not_after_and = 32,
        offset_8 = 64,
        offset_9 = 128,
    };

    props(values value) : value_(value) {}
    operator values() { return value_; }
    operator bool() { return value_ != values::none; }
    props::values operator|(props::values rhs) const { return static_cast<props::values>(value_ | rhs); }
    props::values operator&(props::values rhs) const { return static_cast<props::values>(value_ & rhs); }

    friend props::values operator|(props::values lhs, props::values rhs)
    {
        return static_cast<props::values>(static_cast<std::underlying_type<props::values>::type>(lhs) | static_cast<std::underlying_type<props::values>::type>(rhs));
    }

    friend props::values operator&(props::values lhs, props::values rhs)
    {
        return static_cast<props::values>(static_cast<std::underlying_type<props::values>::type>(lhs) & static_cast<std::underlying_type<props::values>::type>(rhs));
    }

private:
    values value_;
};

struct include_t
{
    std::string name;
    std::vector<std::string> funcs;

    include_t(const std::string& name, const std::vector<std::string>& funcs) : name(name), funcs(funcs) {}
};

struct animtree_t
{
    std::string name;
    bool loaded;
};

} // namespace xsk::gsc

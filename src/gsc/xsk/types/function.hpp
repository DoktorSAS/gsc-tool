// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc
{

struct function
{
    using ptr = std::unique_ptr<function>;

    std::uint32_t index;
    std::uint32_t size;
    std::uint32_t id;
    std::string name;
    std::vector<instruction::ptr> instructions;
    std::unordered_map<std::uint32_t, std::string> labels;
};

} // namespace xsk::gsc

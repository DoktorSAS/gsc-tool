// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc
{

struct instruction
{
    using ptr = std::unique_ptr<instruction>;

    std::uint32_t index;
    std::uint32_t size;
    opcode opcode;
    std::vector<std::string> data;
};

} // namespace xsk::gsc

// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc
{

class disassembler
{
public:
    using ptr = std::unique_ptr<disassembler>;

    virtual ~disassembler() = default;
    virtual auto output() -> std::vector<gsc::function::ptr> = 0;
    virtual auto output_data() -> std::vector<std::uint8_t> = 0;
    virtual void disassemble(const std::string& file, std::vector<std::uint8_t>& script, std::vector<std::uint8_t>& stack) = 0;
};

} // namespace xsk::gsc

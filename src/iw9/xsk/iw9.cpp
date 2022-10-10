// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "iw9.hpp"

namespace xsk::gsc::iw9
{

extern std::array<std::pair<std::uint8_t, opcode>, code_count> code_list;
extern std::array<std::pair<std::uint16_t, const char*>, func_count> func_list;
extern std::array<std::pair<std::uint16_t, const char*>, meth_count> meth_list;
extern std::array<std::pair<std::uint32_t, const char*>, token_count> token_list;

context::context() : gsc::context(props::string_size | props::token_size | props::waitframe | props::formal_params | props::is_defined_is_true | props::bool_not_after_and | props::offset_8,
    engine::iw9, endian::little, system::pc, max_string_id)
{
    code_map_.reserve(code_list.size());
    code_map_rev_.reserve(code_list.size());
    func_map_.reserve(func_list.size());
    func_map_rev_.reserve(func_list.size());
    meth_map_.reserve(meth_list.size());
    meth_map_rev_.reserve(meth_list.size());
    token_map_.reserve(token_list.size());
    token_map_rev_.reserve(token_list.size());

    for (const auto& entry : code_list)
    {
        code_map_.insert({ entry.first, entry.second });
        code_map_rev_.insert({ entry.second, entry.first });
    }

    for (const auto& entry : func_list)
    {
        func_map_.insert({ entry.first, entry.second });
        func_map_rev_.insert({ entry.second, entry.first });
    }

    for (const auto& entry : meth_list)
    {
        meth_map_.insert({ entry.first, entry.second });
        meth_map_rev_.insert({ entry.second, entry.first });
    }

    for (const auto& entry : token_list)
    {
        token_map_.insert({ entry.first, entry.second });
        token_map_rev_.insert({ entry.second, entry.first });
    }
}

} // namespace xsk::gsc::iw9

// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::gsc
{

class decompiler
{
public:
    using ptr = std::unique_ptr<decompiler>;

    virtual ~decompiler() = default;
    virtual auto output() -> std::vector<std::uint8_t> = 0;
    virtual void decompile(const std::string& file, std::vector<gsc::function::ptr>& funcs) = 0;
};

} // namespace xsk::gsc

// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::utils
{

class reader
{
public:
    using ptr = std::unique_ptr<reader>;

private:
    const std::uint8_t* data_;
    std::uint32_t size_;
    std::uint32_t pos_;
    bool own_;
    bool swap_;

public:
    reader(const std::vector<std::uint8_t>& data, bool swap = false);
    reader(const std::uint8_t* data, std::uint32_t size, bool swap = false);
    template <typename T> auto read() -> T;
    auto read_c_string() -> std::string;
    auto read_bytes(std::uint32_t pos, std::uint32_t count) -> std::string;
    auto is_avail() -> bool;
    void seek(std::uint32_t size);
    void seek_neg(std::uint32_t size);
    auto align(std::uint32_t size) -> std::uint32_t;
    auto data() -> const std::uint8_t*;
    auto size() -> std::uint32_t;
    auto pos() -> std::uint32_t;
    void pos(std::uint32_t pos);
};

} // namespace xsk::utils

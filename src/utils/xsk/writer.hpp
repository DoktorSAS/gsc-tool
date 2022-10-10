// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

namespace xsk::utils
{

class writer
{
public:
    using ptr = std::unique_ptr<writer>;

private:
    std::uint8_t* data_;
    std::uint32_t size_;
    std::uint32_t pos_;
    bool swap_;

public:
    writer(bool swap = false);
    writer(std::uint32_t size, bool swap = false);
    ~writer();
    void clear();
    template <typename T> void write(T data);
    void write_string(const std::string& data);
    void write_c_string(const std::string& data);
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

// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "reader.hpp"
#include "string.hpp"

namespace xsk::utils
{

reader::reader(const std::vector<std::uint8_t>& data, bool swap) : data_(data.data()), size_(static_cast<std::uint32_t>(data.size())), pos_(0), own_(false), swap_(swap)
{

}

reader::reader(const std::uint8_t* data, std::uint32_t size, bool swap) : data_(data), size_(size), pos_(0), own_(false), swap_(swap)
{

}

template<> auto reader::read() -> std::int8_t
{
    if (pos_ + sizeof(std::int8_t) > size_) return std::int8_t{};

    auto value = *reinterpret_cast<const std::int8_t*>(data_ + pos_);
    pos_ += sizeof(std::int8_t);
    return value;
}

template<> auto reader::read() -> std::uint8_t
{
    if (pos_ + sizeof(std::uint8_t) > size_) return std::uint8_t{};

    auto value = *reinterpret_cast<const std::uint8_t*>(data_ + pos_);
    pos_ += sizeof(std::uint8_t);
    return value;
}

template<> auto reader::read() -> std::int16_t
{
    if (pos_ + 2 > size_) return std::int16_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::int16_t*>(data_ + pos_);
        pos_ += 2;
        return value;
    }

    std::array<std::uint8_t, 2> bytes{};
    bytes[0] = (data_ + pos_)[1];
    bytes[1] = (data_ + pos_)[0];
    pos_ += 2;
    return *reinterpret_cast<std::int16_t*>(bytes.data());    
}

template<> auto reader::read() -> std::uint16_t
{
    if (pos_ + 2 > size_) return std::uint16_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::uint16_t*>(data_ + pos_);
        pos_ += 2;
        return value;
    }

    std::array<std::uint8_t, 2> bytes{};
    bytes[0] = (data_ + pos_)[1];
    bytes[1] = (data_ + pos_)[0];
    pos_ += 2;
    return *reinterpret_cast<std::uint16_t*>(bytes.data());    
}

template<> auto reader::read() -> std::int32_t
{
    if (pos_ + 4 > size_) return std::int32_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::int32_t*>(data_ + pos_);
        pos_ += 4;
        return value;
    }

    std::array<std::uint8_t, 4> bytes{};
    bytes[0] = (data_ + pos_)[3];
    bytes[1] = (data_ + pos_)[2];
    bytes[2] = (data_ + pos_)[1];
    bytes[3] = (data_ + pos_)[0];
    pos_ += 4;
    return *reinterpret_cast<std::int32_t*>(bytes.data());    
}

template<> auto reader::read() -> std::uint32_t
{
    if (pos_ + 4 > size_) return std::uint32_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::uint32_t*>(data_ + pos_);
        pos_ += 4;
        return value;
    }

    std::array<std::uint8_t, 4> bytes{};
    bytes[0] = (data_ + pos_)[3];
    bytes[1] = (data_ + pos_)[2];
    bytes[2] = (data_ + pos_)[1];
    bytes[3] = (data_ + pos_)[0];
    pos_ += 4;
    return *reinterpret_cast<std::uint32_t*>(bytes.data());    
}

template<> auto reader::read() -> std::int64_t
{
    if (pos_ + 8 > size_) return std::int64_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::int64_t*>(data_ + pos_);
        pos_ += 8;
        return value;
    }

    std::array<std::uint8_t, 8> bytes{};
    bytes[0] = (data_ + pos_)[7];
    bytes[1] = (data_ + pos_)[6];
    bytes[2] = (data_ + pos_)[5];
    bytes[3] = (data_ + pos_)[4];
    bytes[4] = (data_ + pos_)[3];
    bytes[5] = (data_ + pos_)[2];
    bytes[6] = (data_ + pos_)[1];
    bytes[7] = (data_ + pos_)[0];
    pos_ += 8;
    return *reinterpret_cast<std::int64_t*>(bytes.data());    
}

template<> auto reader::read() -> std::uint64_t
{
    if (pos_ + 8 > size_) return std::uint64_t{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const std::uint64_t*>(data_ + pos_);
        pos_ += 8;
        return value;
    }

    std::array<std::uint8_t, 8> bytes{};
    bytes[0] = (data_ + pos_)[7];
    bytes[1] = (data_ + pos_)[6];
    bytes[2] = (data_ + pos_)[5];
    bytes[3] = (data_ + pos_)[4];
    bytes[4] = (data_ + pos_)[3];
    bytes[5] = (data_ + pos_)[2];
    bytes[6] = (data_ + pos_)[1];
    bytes[7] = (data_ + pos_)[0];
    pos_ += 8;
    return *reinterpret_cast<std::uint64_t*>(bytes.data());    
}

template<> auto reader::read() -> float
{
    if (pos_ + 4 > size_) return float{};

    if (!swap_)
    {
        auto value = *reinterpret_cast<const float*>(data_ + pos_);
        pos_ += 4;
        return value;
    }

    std::array<std::uint8_t, 4> bytes{};
    bytes[0] = (data_ + pos_)[3];
    bytes[1] = (data_ + pos_)[2];
    bytes[2] = (data_ + pos_)[1];
    bytes[3] = (data_ + pos_)[0];
    pos_ += 4;
    return *reinterpret_cast<float*>(bytes.data());    
}

auto reader::read_c_string() -> std::string
{
    auto ret = std::string(reinterpret_cast<const char*>(data_ + pos_));
    pos_ += static_cast<std::uint32_t>(ret.size() + 1);
    return ret;
}

auto reader::read_bytes(std::uint32_t pos, std::uint32_t count) -> std::string
{
    std::string data{};

    data.reserve(count * 3);

    for (auto i = pos; i < pos + count; i++)
    {
        data += fmt::format("{:02X} ", *reinterpret_cast<const std::uint8_t*>(data_ + i));
    }

    data.pop_back();

    return data;
}

auto reader::is_avail() -> bool
{
    return (pos_ < size_) ? true : false;
}

void reader::seek(std::uint32_t size)
{
    if (pos_ + size <= size_) pos_ += size;
}

void reader::seek_neg(std::uint32_t size)
{
    if (pos_ - size >= 0) pos_ -= size;
}

auto reader::align(std::uint32_t size) -> std::uint32_t
{
    auto pos = pos_;

    pos_ = (pos_ + (size - 1)) & ~(size - 1);

    return pos_ - pos;
}

auto reader::data() -> const std::uint8_t*
{
    return data_;
}

auto reader::size() -> std::uint32_t
{
    return size_;
}

auto reader::pos() -> std::uint32_t
{
    return pos_;
}

void reader::pos(std::uint32_t pos)
{
    if (pos >= 0 && pos <= size_)
    {
        pos_ = pos;
    }
}

} // namespace xsk::utils

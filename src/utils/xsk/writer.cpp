// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "writer.hpp"
#include "string.hpp"

namespace xsk::utils
{

writer::writer(bool swap) : size_(0x100000), pos_(0), swap_(swap)
{
    data_ = reinterpret_cast<std::uint8_t*>(std::malloc(size_));
    std::memset(data_, 0, size_);
}

writer::writer(std::uint32_t size, bool swap) : size_(size), pos_(0), swap_(swap)
{
    data_ = reinterpret_cast<std::uint8_t*>(std::malloc(size_));
    std::memset(data_, 0, size_);
}

writer::~writer()
{
    std::free(reinterpret_cast<void*>(data_));
}

void writer::clear()
{
    std::memset(data_, 0, size_);
}

template<> void writer::write(std::int8_t data)
{
    if (pos_ + 1 > size_) return;

    *reinterpret_cast<std::int8_t*>(data_ + pos_) = data;
    pos_ += 1;
}

template<> void writer::write(std::uint8_t data)
{
    if (pos_ + 1 > size_) return;

    *reinterpret_cast<std::uint8_t*>(data_ + pos_) = data;
    pos_ += 1;
}

template<> void writer::write(std::int16_t data)
{
    if (pos_ + 2 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::int16_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 2;
}

template<> void writer::write(std::uint16_t data)
{
    if (pos_ + 2 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::uint16_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 2;
}

template<> void writer::write(std::int32_t data)
{
    if (pos_ + 4 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::int32_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[3];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[2];
        (data_ + pos_)[2] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[3] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 4;
}

template<> void writer::write(std::uint32_t data)
{
    if (pos_ + 4 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::uint32_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[3];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[2];
        (data_ + pos_)[2] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[3] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 4;
}

template<> void writer::write(std::int64_t data)
{
    if (pos_ + 8 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::int64_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[7];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[6];
        (data_ + pos_)[2] = reinterpret_cast<std::uint8_t*>(&data)[5];
        (data_ + pos_)[3] = reinterpret_cast<std::uint8_t*>(&data)[4];
        (data_ + pos_)[4] = reinterpret_cast<std::uint8_t*>(&data)[3];
        (data_ + pos_)[5] = reinterpret_cast<std::uint8_t*>(&data)[2];
        (data_ + pos_)[6] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[7] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 8;
}

template<> void writer::write(std::uint64_t data)
{
    if (pos_ + 8 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<std::uint64_t*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[7];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[6];
        (data_ + pos_)[2] = reinterpret_cast<std::uint8_t*>(&data)[5];
        (data_ + pos_)[3] = reinterpret_cast<std::uint8_t*>(&data)[4];
        (data_ + pos_)[4] = reinterpret_cast<std::uint8_t*>(&data)[3];
        (data_ + pos_)[5] = reinterpret_cast<std::uint8_t*>(&data)[2];
        (data_ + pos_)[6] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[7] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 8;
}

template<> void writer::write(float data)
{
    if (pos_ + 4 > size_) return;

    if (!swap_)
    {
        *reinterpret_cast<float*>(data_ + pos_) = data;
    }
    else
    {
        (data_ + pos_)[0] = reinterpret_cast<std::uint8_t*>(&data)[3];
        (data_ + pos_)[1] = reinterpret_cast<std::uint8_t*>(&data)[2];
        (data_ + pos_)[2] = reinterpret_cast<std::uint8_t*>(&data)[1];
        (data_ + pos_)[3] = reinterpret_cast<std::uint8_t*>(&data)[0];
    }

    pos_ += 4;
}

void writer::write_string(const std::string& data)
{
    if (pos_ + data.size() > size_) return;

    std::memcpy(reinterpret_cast<void*>(data_ + pos_), data.data(), data.size());
    pos_ += static_cast<std::uint32_t>(data.size());
}

void writer::write_c_string(const std::string& data)
{
    if (pos_ + data.size() >= size_) return;

    std::memcpy(reinterpret_cast<void*>(data_ + pos_), data.data(), data.size());
    pos_ += static_cast<std::uint32_t>(data.size() + 1);
}

auto writer::read_bytes(std::uint32_t pos, std::uint32_t count) -> std::string
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

auto writer::is_avail() -> bool
{
    return (pos_ < size_) ? true : false;
}

void writer::seek(std::uint32_t size)
{
    if (pos_ + size <= size_) pos_ += size;
}

void writer::seek_neg(std::uint32_t size)
{
    if (pos_ - size >= 0) pos_ -= size;
}

auto writer::align(std::uint32_t size) -> std::uint32_t
{
    auto pos = pos_;

    pos_ = (pos_ + (size - 1)) & ~(size - 1);

    return pos_ - pos;
}

auto writer::data() -> const std::uint8_t*
{
    return data_;
}

auto writer::size() -> std::uint32_t
{
    return size_;
}

auto writer::pos() -> std::uint32_t
{
    return pos_;
}

void writer::pos(std::uint32_t pos)
{
    if (pos >= 0 && pos <= size_)
    {
        pos_ = pos;
    }
}
} // namespace xsk::utils

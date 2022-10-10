// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "utils/xsk/reader.hpp"
#include "utils/xsk/writer.hpp"
#include "utils/xsk/string.hpp"

#include "types/types.hpp"

namespace xsk::gsc { class context; }

#include "assembler.hpp"
#include "disassembler.hpp"
#include "compiler.hpp"
#include "decompiler.hpp"

namespace xsk::gsc
{

class context
{
public:
    using ref = const context* const; 
    using ptr = std::unique_ptr<context>;

protected:
    props props_;
    build build_;
    engine engine_;
    endian endian_;
    system system_;
    std::uint32_t str_count_;
    assembler assembler_;
    disassembler disassembler_;
    compiler compiler_;
    decompiler decompiler_;
    std::unordered_map<std::uint8_t, opcode> code_map_;
    std::unordered_map<opcode, std::uint8_t> code_map_rev_;
    std::unordered_map<std::string_view, opcode> opcode_map;
    std::unordered_map<opcode, std::string_view> opcode_map_rev;
    std::unordered_map<std::uint16_t, std::string_view> func_map_;
    std::unordered_map<std::string_view, std::uint16_t> func_map_rev_;
    std::unordered_map<std::uint16_t, std::string_view> meth_map_;
    std::unordered_map<std::string_view, std::uint16_t> meth_map_rev_;
    std::unordered_map<std::uint32_t, std::string_view> token_map_;
    std::unordered_map<std::string_view, std::uint32_t> token_map_rev_;

public:
    context(props props, engine engine, endian endian, system system, std::uint32_t str_count);
    auto props() const -> props { return props_; }
    auto build() const -> build { return build_; }
    auto engine() const -> engine { return engine_; }
    auto endian() const -> endian { return endian_; }
    auto system() const -> system { return system_; }
    auto str_count() const -> std::uint32_t { return str_count_; }
    auto assembler() -> assembler& { return assembler_; }
    auto disassembler() -> disassembler& { return disassembler_; }
    auto compiler() -> compiler& { return compiler_; }
    auto decompiler() -> decompiler& { return decompiler_; }
    void init(gsc::build build, read_cb_type callback);
    void cleanup();
    auto opcode_size(opcode op) const -> std::uint32_t;
    auto opcode_id(opcode op) const -> std::uint8_t;
    auto opcode_enum(std::uint8_t id) const -> opcode;
    auto opcode_enum(const std::string& name) const -> opcode;
    auto opcode_name(opcode op) const -> std::string;
    auto func_id(const std::string& name) const -> std::uint16_t;
    auto func_name(std::uint16_t id) const -> std::string;
    auto meth_id(const std::string& name) const -> std::uint16_t;
    auto meth_name(std::uint16_t id) const -> std::string;
    auto token_id(const std::string& name) const -> std::uint32_t;
    auto token_name(std::uint32_t id) const -> std::string;
    auto func_exists(const std::string& name) const -> bool;
    auto meth_exists(const std::string& name) const -> bool;
    void func_add(const std::string& name, std::uint16_t id);
    void meth_add(const std::string& name, std::uint16_t id);
    auto make_token(std::string_view str) const -> std::string;
    auto file_data(const std::string& name) const -> std::tuple<const std::string*, const char*, size_t>;
    auto fs_to_game_path(const std::filesystem::path& file) const -> std::filesystem::path;
};

} // namespace xsk::gsc

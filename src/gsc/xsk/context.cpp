// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "context.hpp"

namespace xsk::gsc
{

read_cb_type read_callback = nullptr;
std::unordered_map<std::string, std::vector<std::uint8_t>> files;
std::set<std::string> string_map;
std::set<std::string> new_func_map;
std::set<std::string> new_meth_map;

extern std::array<std::pair<opcode, std::string_view>, opcode_count> opcode_list;

context::context(gsc::props props, gsc::engine engine, gsc::endian endian, gsc::system system, std::uint32_t str_count)
    : props_(props), engine_(engine), endian_(endian), system_(system), str_count_(str_count), assembler_(this), disassembler_(this), compiler_(this), decompiler_(this)
{
    opcode_map.reserve(opcode_list.size());
    opcode_map_rev.reserve(opcode_list.size());

    for (const auto& entry : opcode_list)
    {
        opcode_map.insert({ entry.second, entry.first });
        opcode_map_rev.insert({ entry.first, entry.second });
    }
}

void context::init(gsc::build build, read_cb_type callback)
{
    build_ = build;
    read_callback = callback;
}

void context::cleanup()
{
    files.clear();
}

auto context::opcode_size(opcode op) const -> std::uint32_t
{
    switch (op)
    {
        case opcode::OP_CastFieldObject:
        case opcode::OP_plus:
        case opcode::OP_GetGameRef:
        case opcode::OP_GetThisthread:
        case opcode::OP_greater:
        case opcode::OP_shift_right:
        case opcode::OP_dec:
        case opcode::OP_bit_or:
        case opcode::OP_equality:
        case opcode::OP_ClearLocalVariableFieldCached0:
        case opcode::OP_notify:
        case opcode::OP_PreScriptCall:
        case opcode::OP_GetUndefined:
        case opcode::OP_SetLocalVariableFieldCached0:
        case opcode::OP_GetLevel:
        case opcode::OP_size:
        case opcode::OP_AddArray:
        case opcode::OP_endon:
        case opcode::OP_shift_left:
        case opcode::OP_EvalLocalArrayRefCached0:
        case opcode::OP_Return:
        case opcode::OP_SafeSetVariableFieldCached0:
        case opcode::OP_GetSelfObject:
        case opcode::OP_GetGame:
        case opcode::OP_EvalArray:
        case opcode::OP_GetSelf:
        case opcode::OP_End:
        case opcode::OP_less_equal:
        case opcode::OP_EvalLocalVariableCached0:
        case opcode::OP_EvalLocalVariableCached1:
        case opcode::OP_EvalLocalVariableCached2:
        case opcode::OP_EvalLocalVariableCached3:
        case opcode::OP_EvalLocalVariableCached4:
        case opcode::OP_EvalLocalVariableCached5:
        case opcode::OP_ScriptMethodCallPointer:
        case opcode::OP_checkclearparams:
        case opcode::OP_waittillmatch2:
        case opcode::OP_minus:
        case opcode::OP_greater_equal:
        case opcode::OP_vector:
        case opcode::OP_ClearArray:
        case opcode::OP_DecTop:
        case opcode::OP_CastBool:
        case opcode::OP_EvalArrayRef:
        case opcode::OP_GetZero:
        case opcode::OP_wait:
        case opcode::OP_waittill:
        case opcode::OP_GetAnimObject:
        case opcode::OP_mod:
        case opcode::OP_clearparams:
        case opcode::OP_ScriptFunctionCallPointer:
        case opcode::OP_EmptyArray:
        case opcode::OP_ClearVariableField:
        case opcode::OP_EvalNewLocalVariableRefCached0:
        case opcode::OP_BoolComplement:
        case opcode::OP_less:
        case opcode::OP_BoolNot:
        case opcode::OP_waittillFrameEnd:
        case opcode::OP_waitframe:
        case opcode::OP_GetLevelObject:
        case opcode::OP_inc:
        case opcode::OP_GetAnim:
        case opcode::OP_SetVariableField:
        case opcode::OP_divide:
        case opcode::OP_multiply:
        case opcode::OP_EvalLocalVariableRefCached0:
        case opcode::OP_bit_and:
        case opcode::OP_voidCodepos:
        case opcode::OP_inequality:
        case opcode::OP_bit_ex_or:
/*      case opcode::OP_NOP:
        case opcode::OP_abort:
        case opcode::OP_object:
        case opcode::OP_thread_object:
        case opcode::OP_EvalLocalVariable:
        case opcode::OP_EvalLocalVariableRef:
        case opcode::OP_breakpoint:
        case opcode::OP_assignmentBreakpoint:
        case opcode::OP_manualAndAssignmentBreakpoint:*/
        case opcode::OP_BoolNotAfterAnd:
        case opcode::OP_IsDefined:
        case opcode::OP_IsTrue:
            return 1;
        case opcode::OP_SetLocalVariableFieldCached:
        case opcode::OP_RemoveLocalVariables:
        case opcode::OP_waittillmatch:
        case opcode::OP_ScriptMethodChildThreadCallPointer:
        case opcode::OP_GetByte:
        case opcode::OP_SafeSetWaittillVariableFieldCached:
        case opcode::OP_CreateLocalVariable:
        case opcode::OP_CallBuiltinMethodPointer:
        case opcode::OP_EvalLocalVariableCached:
        case opcode::OP_EvalNewLocalArrayRefCached0:
        case opcode::OP_ScriptChildThreadCallPointer:
        case opcode::OP_EvalLocalVariableObjectCached:
        case opcode::OP_GetNegByte:
        case opcode::OP_SafeCreateVariableFieldCached:
        case opcode::OP_SetNewLocalVariableFieldCached0:
        case opcode::OP_GetAnimTree:
        case opcode::OP_EvalLocalArrayCached:
        case opcode::OP_ScriptMethodThreadCallPointer:
        case opcode::OP_SafeSetVariableFieldCached:
        case opcode::OP_EvalLocalVariableRefCached:
        case opcode::OP_ScriptThreadCallPointer:
        case opcode::OP_ClearLocalVariableFieldCached:
        case opcode::OP_EvalLocalArrayRefCached:
        case opcode::OP_CallBuiltinPointer:
//      case opcode::OP_prof_end:
        case opcode::OP_FormalParams:
/*      case opcode::OP_EvalNewLocalArrayRefCached0_Precompiled:
        case opcode::OP_SetNewLocalVariableFieldCached0_Precompiled:
        case opcode::OP_CreateLocalVariable_Precompiled:
        case opcode::OP_SafeCreateVariableFieldCached_Precompiled:
        case opcode::OP_FormalParams_Precompiled:*/
            return 2;
        case opcode::OP_JumpOnTrue:
        case opcode::OP_JumpOnFalseExpr:
        case opcode::OP_jumpback:
        case opcode::OP_JumpOnTrueExpr:
        case opcode::OP_CallBuiltin0:
        case opcode::OP_CallBuiltin1:
        case opcode::OP_CallBuiltin2:
        case opcode::OP_CallBuiltin3:
        case opcode::OP_CallBuiltin4:
        case opcode::OP_CallBuiltin5:
        case opcode::OP_GetBuiltinFunction:
        case opcode::OP_GetNegUnsignedShort:
        case opcode::OP_GetBuiltinMethod:
        case opcode::OP_endswitch:
        case opcode::OP_GetUnsignedShort:
        case opcode::OP_JumpOnFalse:
        case opcode::OP_CallBuiltinMethod0:
        case opcode::OP_CallBuiltinMethod1:
        case opcode::OP_CallBuiltinMethod2:
        case opcode::OP_CallBuiltinMethod3:
        case opcode::OP_CallBuiltinMethod4:
        case opcode::OP_CallBuiltinMethod5:
            return 3;
        case opcode::OP_CallBuiltin:
        case opcode::OP_ScriptLocalMethodCall:
        case opcode::OP_ScriptLocalFunctionCall2:
        case opcode::OP_ScriptFarFunctionCall:
        case opcode::OP_ScriptFarFunctionCall2:
        case opcode::OP_CallBuiltinMethod:
        case opcode::OP_GetLocalFunction:
        case opcode::OP_GetFarFunction:
        case opcode::OP_ScriptFarMethodCall:
        case opcode::OP_ScriptLocalFunctionCall:
/*      case opcode::OP_NativeGetLocalFunction:
        case opcode::OP_NativeLocalFunctionCall:
        case opcode::OP_NativeLocalFunctionCall2:
        case opcode::OP_NativeLocalMethodCall:
        case opcode::OP_NativeGetFarFunction:
        case opcode::OP_NativeFarFunctionCall:
        case opcode::OP_NativeFarFunctionCall2:
        case opcode::OP_NativeFarMethodCall:*/
            return 4;
        case opcode::OP_ScriptFarMethodChildThreadCall:
        case opcode::OP_ScriptFarThreadCall:
        case opcode::OP_ScriptLocalMethodThreadCall:
        case opcode::OP_ScriptLocalChildThreadCall:
        case opcode::OP_ScriptLocalThreadCall:
        case opcode::OP_GetInteger:
        case opcode::OP_ScriptFarMethodThreadCall:
        case opcode::OP_ScriptLocalMethodChildThreadCall:
        case opcode::OP_GetFloat:
        case opcode::OP_switch:
        case opcode::OP_ScriptFarChildThreadCall:
        case opcode::OP_jump:
/*      case opcode::OP_NativeLocalFunctionThreadCall:
        case opcode::OP_NativeLocalMethodThreadCall:
        case opcode::OP_NativeLocalFunctionChildThreadCall:
        case opcode::OP_NativeLocalMethodChildThreadCall:
        case opcode::OP_NativeFarFunctionThreadCall:
        case opcode::OP_NativeFarMethodThreadCall:
        case opcode::OP_NativeFarFunctionChildThreadCall:
        case opcode::OP_NativeFarMethodChildThreadCall:*/
            return 5;
        case opcode::OP_EvalSelfFieldVariableRef:
        case opcode::OP_EvalAnimFieldVariable:
        case opcode::OP_EvalLevelFieldVariableRef:
        case opcode::OP_SetSelfFieldVariableField:
        case opcode::OP_ClearFieldVariable:
        case opcode::OP_EvalFieldVariable:
        case opcode::OP_SetAnimFieldVariableField:
        case opcode::OP_SetLevelFieldVariableField:
        case opcode::OP_EvalSelfFieldVariable:
        case opcode::OP_EvalFieldVariableRef:
        case opcode::OP_EvalLevelFieldVariable:
        case opcode::OP_EvalAnimFieldVariableRef:
            return (props_ & props::token_size) ? 5 : 3;
        case opcode::OP_GetString:
        case opcode::OP_GetIString:
            return (props_ & props::string_size) ? 5 : 3;
/*      case opcode::OP_prof_begin:
            return 6;*/
        case opcode::OP_GetAnimation:
            return (props_ & props::string_size) ? 9 : 5;
        case opcode::OP_GetVector:
            return 13;
        default:
            throw error("couldn't resolve instruction size for " + opcode_name(op));
    }
}

auto context::opcode_id(opcode op) const -> std::uint8_t
{
    const auto itr = code_map_rev_.find(op);

    if (itr != code_map_rev_.end())
    {
        return itr->second;
    }

    throw error(utils::string::va("couldn't resolve opcode id for name '%s'!", opcode_name(op).data()));
}

auto context::opcode_enum(std::uint8_t id) const -> opcode
{
    const auto itr = code_map_.find(id);

    if (itr != code_map_.end())
    {
        return itr->second;
    }

    throw error(utils::string::va("couldn't resolve opcode enum for id '0x%hhX'!", id));
}

auto context::opcode_enum(const std::string& name) const -> opcode
{
    const auto itr = opcode_map.find(name);

    if (itr != opcode_map.end())
    {
        return itr->second;
    }

    throw error(utils::string::va("couldn't resolve opcode id for name '%s'!", name.data()));
}

auto context::opcode_name(opcode op) const -> std::string
{
    const auto itr = opcode_map_rev.find(op);

    if (itr != opcode_map_rev.end())
    {
        return std::string(itr->second);
    }

    throw error(utils::string::va("couldn't resolve opcode string for index '0x%hhX'!", static_cast<std::uint8_t>(op)));
}

auto context::func_id(const std::string& name) const -> std::uint16_t
{
    if (name.starts_with("_func_"))
    {
        return static_cast<std::uint16_t>(std::stoul(name.substr(6), nullptr, 16));
    }

    const auto itr = func_map_rev_.find(name);

    if (itr != func_map_rev_.end())
    {
        return itr->second;
    }

    throw error(utils::string::va("couldn't resolve builtin function id for name '%s'!", name.data()));
}

auto context::func_name(std::uint16_t id) const -> std::string
{
    const auto itr = func_map_.find(id);

    if (itr != func_map_.end())
    {
        return std::string(itr->second);
    }

    return utils::string::va("_func_%04X", id);
}

auto context::func_exists(const std::string& name) const -> bool
{
    if (name.starts_with("_func_")) return true;

    const auto itr = func_map_rev_.find(name);

    if (itr != func_map_rev_.end())
    {
        return true;
    }

    return false;
}

void context::func_add(const std::string& name, std::uint16_t id)
{
    const auto itr = func_map_rev_.find(name);

    if (itr != func_map_rev_.end())
    {
        throw error(utils::string::va("builtin function '%s' already defined.", name.data()));
    }

    const auto str = new_func_map.find(name);

    if (str != new_func_map.end())
    {
        func_map_.insert({ id, *str });
        func_map_rev_.insert({ *str, id });
    }
    else
    {
        auto ins = new_func_map.insert(name);

        if (ins.second)
        {
            func_map_.insert({ id, *ins.first });
            func_map_rev_.insert({ *ins.first, id });
        }
    }
}

auto context::meth_id(const std::string& name) const -> std::uint16_t
{
    if (name.starts_with("_meth_"))
    {
        return static_cast<std::uint16_t>(std::stoul(name.substr(6), nullptr, 16));
    }

    const auto itr = meth_map_rev_.find(name);

    if (itr != meth_map_rev_.end())
    {
        return itr->second;
    }

    throw error(utils::string::va("couldn't resolve builtin method id for name '%s'!", name.data()));
}

auto context::meth_name(std::uint16_t id) const -> std::string
{
    const auto itr = meth_map_.find(id);

    if (itr != meth_map_.end())
    {
        return std::string(itr->second);
    }

    return utils::string::va("_meth_%04X", id);
}

auto context::meth_exists(const std::string& name) const -> bool
{
    if (name.starts_with("_meth_")) return true;

    const auto itr = meth_map_rev_.find(name);

    if (itr != meth_map_rev_.end())
    {
        return true;
    }

    return false;
}

void context::meth_add(const std::string& name, std::uint16_t id)
{
    const auto itr = meth_map_rev_.find(name);

    if (itr != meth_map_rev_.end())
    {
        throw error(utils::string::va("builtin method '%s' already defined.", name.data()));
    }

    const auto str = new_meth_map.find(name);

    if (str != new_meth_map.end())
    {
        meth_map_.insert({ id, *str });
        meth_map_rev_.insert({ *str, id });
    }
    else
    {
        auto ins = new_meth_map.insert(name);

        if (ins.second)
        {
            meth_map_.insert({ id, *ins.first });
            meth_map_rev_.insert({ *ins.first, id });
        }
    }
}

auto context::token_id(const std::string& name) const -> std::uint32_t
{
    if (name.starts_with("_id_"))
    {
        return static_cast<std::uint32_t>(std::stoul(name.substr(4), nullptr, 16));
    }

    const auto itr = token_map_rev_.find(name);

    if (itr != token_map_rev_.end())
    {
        return itr->second;
    }

    return 0;
}

auto context::token_name(std::uint32_t id) const -> std::string
{
    const auto itr = token_map_.find(id);

    if (itr != token_map_.end())
    {
        return std::string(itr->second);
    }

    return utils::string::va("_id_%04X", id);
}

auto context::make_token(std::string_view str) const -> std::string
{
    if (str.starts_with("_id_") || str.starts_with("_func_") || str.starts_with("_meth_"))
    {
        return std::string(str);
    }

    auto data = std::string(str.begin(), str.end());

    for (std::size_t i = 0; i < data.size(); i++)
    {
        data[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
        if (data[i] == '\\') data[i] = '/';
    }

    return data;
}

auto context::file_data(const std::string& name) const -> std::tuple<const std::string*, const char*, size_t>
{
    const auto itr = files.find(name);

    if (itr != files.end())
    {
        return { &itr->first, reinterpret_cast<const char*>(itr->second.data()), itr->second.size() };
    }

    auto data = read_callback(name);

    const auto res = files.insert({ name, std::move(data)});

    if (res.second)
    {
        return { &res.first->first, reinterpret_cast<const char*>(res.first->second.data()), res.first->second.size() };
    }

    throw error("couldn't open gsc file '" + name + "'");
}

std::set<std::string_view> paths
{
};

auto context::fs_to_game_path(const std::filesystem::path& file) const -> std::filesystem::path
{
    auto result = std::filesystem::path();
    auto root = false;

    for (auto& entry : file)
    {
        if (!root && paths.contains(entry.string()))
        {
            result = entry;
            root = true;
        }
        else if (paths.contains(result.string()))
        {
            result /= entry;
        }
    }

    return result.empty() ? file : result;
}

} // namespace xsk::gsc

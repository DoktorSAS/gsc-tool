// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#include "stdafx.hpp"
#include "context.hpp"

namespace xsk::gsc
{

assembler::assembler(context::ref ctx) : ctx_(ctx) {}

auto assembler::output_script() -> std::vector<std::uint8_t>
{
    std::vector<std::uint8_t> script;

    if (script_ == nullptr) return script;

    script.resize(script_->pos());
    std::memcpy(script.data(), script_->data(), script.size());

    return script;
}

auto assembler::output_stack() -> std::vector<std::uint8_t>
{
    std::vector<std::uint8_t> stack;

    if (stack_ == nullptr) return stack;

    stack.resize(stack_->pos());
    std::memcpy(stack.data(), stack_->data(), stack.size());

    return stack;
}

void assembler::assemble(const std::string& file, std::vector<std::uint8_t>& data)
{
    std::vector<std::string> assembly = utils::string::clean_buffer_lines(data);
    std::vector<function::ptr> functions;
    function::ptr func = nullptr;
    std::uint32_t index = 1;
    std::uint16_t switchnum = 0;

    for (auto& line : assembly)
    {
        if (line == "" || line.substr(0, 2) == "//")
        {
            continue;
        }
        else if (line.substr(0, 4) == "sub_")
        {
            func = std::make_unique<function>();
            func->index = index;
            func->name = line.substr(4);
        }
        else if (line.substr(0, 4) == "end_")
        {
            if (func != nullptr)
            {
                func->size = index - func->index;
                functions.push_back(std::move(func));
            }
        }
        else if (line.substr(0, 4) == "loc_")
        {
            func->labels[index] = line;
        }
        else
        {
            auto opdata = utils::string::parse_code(line);

            if (switchnum)
            {
                if (opdata[0] == "case" || opdata[0] == "default")
                {
                    for (auto& entry : opdata)
                    {
                        func->instructions.back()->data.push_back(entry);
                    }
                    switchnum--;
                    continue;
                }

                throw asm_error("invalid instruction inside endswitch \""s + line + "\"!");
            }
            else
            {
                auto inst = std::make_unique<instruction>();
                inst->index = index;
                inst->opcode = ctx_->opcode_enum(opdata[0]);
                inst->size = ctx_->opcode_size(inst->opcode);
                opdata.erase(opdata.begin());
                inst->data = std::move(opdata);

                switch (inst->opcode)
                {
                    case opcode::OP_GetLocalFunction:
                    case opcode::OP_ScriptLocalFunctionCall:
                    case opcode::OP_ScriptLocalFunctionCall2:
                    case opcode::OP_ScriptLocalMethodCall:
                    case opcode::OP_ScriptLocalThreadCall:
                    case opcode::OP_ScriptLocalChildThreadCall:
                    case opcode::OP_ScriptLocalMethodThreadCall:
                    case opcode::OP_ScriptLocalMethodChildThreadCall:
                        inst->data[0] = inst->data[0].substr(4);
                        break;
                    case opcode::OP_endswitch:
                        switchnum = static_cast<std::uint16_t>(std::stoi(inst->data[0]));
                        inst->size += 7 * switchnum;
                        break;
                    default:
                        break;
                }

                index += inst->size;
                func->instructions.push_back(std::move(inst));
            }
        }
    }

    assemble(file, functions);
}

void assembler::assemble(const std::string& file, std::vector<function::ptr>& funcs)
{
    script_ = std::make_unique<utils::writer>(ctx_->endian() == endian::big);
    stack_ = std::make_unique<utils::writer>(ctx_->endian() == endian::big);
    filename_ = file;
    functions_ = std::move(funcs);

    script_->write<std::uint8_t>(ctx_->opcode_id(opcode::OP_End));

    for (const auto& func : functions_)
    {
        assemble_function(func);
    }
}

void assembler::assemble_function(const function::ptr& func)
{
    labels_ = func->labels;

    func->id = ctx_->token_id(func->name);

    stack_->write<std::uint32_t>(func->size);

    if (ctx_->props() & props::token_size)
        stack_->write<std::uint32_t>(func->id);
    else
        stack_->write<std::uint16_t>(static_cast<std::uint16_t>(func->id));

    if (func->id == 0)
    {
        stack_->write_c_string(encrypt_string(func->name));
    }

    for (const auto& inst : func->instructions)
    {
        assemble_instruction(inst);
    }
}

void assembler::assemble_instruction(const instruction::ptr& inst)
{
    script_->write<std::uint8_t>(ctx_->opcode_id(inst->opcode));

    switch (inst->opcode)
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
            break;
        case opcode::OP_GetByte:
        case opcode::OP_GetNegByte:
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[0])));
            break;
        case opcode::OP_GetUnsignedShort:
        case opcode::OP_GetNegUnsignedShort:
            script_->write<std::uint16_t>(static_cast<std::uint16_t>(std::stoi(inst->data[0])));
            break;
        case opcode::OP_GetInteger:
            script_->write<std::int32_t>(std::stoi(inst->data[0]));
            break;
        case opcode::OP_GetFloat:
            script_->write<float>(std::stof(inst->data[0]));
            break;
        case opcode::OP_GetVector:
            inst->size += script_->align((ctx_->endian() == endian::little) ? 1 : 4);
            script_->write<float>(std::stof(inst->data[0]));
            script_->write<float>(std::stof(inst->data[1]));
            script_->write<float>(std::stof(inst->data[2]));
            break;
        case opcode::OP_GetString:
        case opcode::OP_GetIString:
            if (ctx_->props() & props::string_size)
                script_->write<std::uint32_t>(0);
            else
                script_->write<std::uint16_t>(0);
            stack_->write_c_string(encrypt_string(inst->data[0]));
            break;
        case opcode::OP_GetAnimation:
            if (ctx_->props() & props::string_size)
                script_->write<std::uint64_t>(0);
            else
                script_->write<std::uint32_t>(0);
            stack_->write_c_string(encrypt_string(inst->data[0]));
            stack_->write_c_string(encrypt_string(inst->data[1]));
            break;
        case opcode::OP_GetAnimTree:
            script_->write<std::uint8_t>(0);
            stack_->write_c_string(encrypt_string(inst->data[0]));
            break;
        case opcode::OP_waittillmatch:
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[0])));
            break;
        case opcode::OP_SetNewLocalVariableFieldCached0:
        case opcode::OP_EvalNewLocalArrayRefCached0:
        case opcode::OP_SafeCreateVariableFieldCached:
        case opcode::OP_ClearLocalVariableFieldCached:
        case opcode::OP_SetLocalVariableFieldCached:
        case opcode::OP_RemoveLocalVariables:
        case opcode::OP_EvalLocalVariableRefCached:
        case opcode::OP_EvalLocalArrayRefCached:
        case opcode::OP_SafeSetVariableFieldCached:
        case opcode::OP_EvalLocalVariableCached:
        case opcode::OP_SafeSetWaittillVariableFieldCached:
        case opcode::OP_CreateLocalVariable:
        case opcode::OP_EvalLocalVariableObjectCached:
        case opcode::OP_EvalLocalArrayCached:
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[0])));
            break;
        case opcode::OP_EvalSelfFieldVariable:
        case opcode::OP_SetLevelFieldVariableField:
        case opcode::OP_ClearFieldVariable:
        case opcode::OP_EvalFieldVariable:
        case opcode::OP_EvalFieldVariableRef:
        case opcode::OP_EvalLevelFieldVariable:
        case opcode::OP_SetAnimFieldVariableField:
        case opcode::OP_SetSelfFieldVariableField:
        case opcode::OP_EvalAnimFieldVariableRef:
        case opcode::OP_EvalLevelFieldVariableRef:
        case opcode::OP_EvalAnimFieldVariable:
        case opcode::OP_EvalSelfFieldVariableRef:
            assemble_field_variable(inst);
            break;
        case opcode::OP_CallBuiltinPointer:
        case opcode::OP_CallBuiltinMethodPointer:
        case opcode::OP_ScriptThreadCallPointer:
        case opcode::OP_ScriptChildThreadCallPointer:
        case opcode::OP_ScriptMethodThreadCallPointer:
        case opcode::OP_ScriptMethodChildThreadCallPointer:
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[0])));
            break;
        case opcode::OP_GetLocalFunction:
        case opcode::OP_ScriptLocalFunctionCall2:
        case opcode::OP_ScriptLocalFunctionCall:
        case opcode::OP_ScriptLocalMethodCall:
            assemble_local_call(inst, false);
            break;
        case opcode::OP_ScriptLocalThreadCall:
        case opcode::OP_ScriptLocalChildThreadCall:
        case opcode::OP_ScriptLocalMethodThreadCall:
        case opcode::OP_ScriptLocalMethodChildThreadCall:
            assemble_local_call(inst, true);
            break;
        case opcode::OP_GetFarFunction:
        case opcode::OP_ScriptFarFunctionCall2:
        case opcode::OP_ScriptFarFunctionCall:
        case opcode::OP_ScriptFarMethodCall:
            assemble_far_call(inst, false);
            break;
        case opcode::OP_ScriptFarThreadCall:
        case opcode::OP_ScriptFarChildThreadCall:
        case opcode::OP_ScriptFarMethodThreadCall:
        case opcode::OP_ScriptFarMethodChildThreadCall:
            assemble_far_call(inst, true);
            break;
        case opcode::OP_CallBuiltin:
            assemble_builtin_call(inst, false, true);
            break;
        case opcode::OP_CallBuiltinMethod:
            assemble_builtin_call(inst, true, true);
            break;
        case opcode::OP_GetBuiltinFunction:
        case opcode::OP_CallBuiltin0:
        case opcode::OP_CallBuiltin1:
        case opcode::OP_CallBuiltin2:
        case opcode::OP_CallBuiltin3:
        case opcode::OP_CallBuiltin4:
        case opcode::OP_CallBuiltin5:
            assemble_builtin_call(inst, false, false);
            break;
        case opcode::OP_GetBuiltinMethod:
        case opcode::OP_CallBuiltinMethod0:
        case opcode::OP_CallBuiltinMethod1:
        case opcode::OP_CallBuiltinMethod2:
        case opcode::OP_CallBuiltinMethod3:
        case opcode::OP_CallBuiltinMethod4:
        case opcode::OP_CallBuiltinMethod5:
            assemble_builtin_call(inst, true, false);
            break;
        case opcode::OP_JumpOnFalseExpr:
        case opcode::OP_JumpOnTrueExpr:
        case opcode::OP_JumpOnFalse:
        case opcode::OP_JumpOnTrue:
            assemble_jump(inst, true, false);
            break;
        case opcode::OP_jumpback:
            assemble_jump(inst, false, true);
            break;
        case opcode::OP_jump:
            assemble_jump(inst, false, false);
            break;
        case opcode::OP_switch:
            assemble_switch(inst);
            break;
        case opcode::OP_endswitch:
            assemble_end_switch(inst);
            break;
/*      case opcode::OP_prof_begin:
            script_->write<std::uint32_t>(0); // TODO: skipped data
            script_->write<std::uint8_t>(0);
            break;
        case opcode::OP_prof_end:
            script_->write<std::uint8_t>(0); // TODO: skipped data
            break;
        case opcode::OP_EvalNewLocalArrayRefCached0_Precompiled:
        case opcode::OP_SetNewLocalVariableFieldCached0_Precompiled:
        case opcode::OP_CreateLocalVariable_Precompiled:
        case opcode::OP_SafeCreateVariableFieldCached_Precompiled:
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(inst->opcode));
            script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[0])));
            break;*/
        case opcode::OP_FormalParams:
//      case opcode::OP_FormalParams_Precompiled:
            assemble_formal_params(inst);
            break;
/*      case opcode::OP_NativeGetLocalFunction:
        case opcode::OP_NativeLocalFunctionCall:
        case opcode::OP_NativeLocalFunctionCall2:
        case opcode::OP_NativeLocalMethodCall:
            assemble_local_call(inst, false);
            break;
        case opcode::OP_NativeGetFarFunction:
        case opcode::OP_NativeFarFunctionCall:
        case opcode::OP_NativeFarFunctionCall2:
        case opcode::OP_NativeFarMethodCall:
            assemble_far_call(inst, false);
            break;
        case opcode::OP_NativeLocalFunctionThreadCall:
        case opcode::OP_NativeLocalMethodThreadCall:
        case opcode::OP_NativeLocalFunctionChildThreadCall:
        case opcode::OP_NativeLocalMethodChildThreadCall:
            assemble_local_call(inst, true);
            break;
        case opcode::OP_NativeFarFunctionThreadCall:
        case opcode::OP_NativeFarMethodThreadCall:
        case opcode::OP_NativeFarFunctionChildThreadCall:
        case opcode::OP_NativeFarMethodChildThreadCall:
            assemble_far_call(inst, true);
            break;*/
        default:
            throw asm_error(utils::string::va("unhandled opcode 0x%X at index '%04X'!", inst->opcode, inst->index));
    }
}

void assembler::assemble_builtin_call(const instruction::ptr& inst, bool method, bool args)
{
    if (args)
    {
        script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[1])));
    }

    const auto id = method ? ctx_->meth_id(inst->data[0]) : ctx_->func_id(inst->data[0]);

    script_->write<std::uint16_t>(id);
}

void assembler::assemble_local_call(const instruction::ptr& inst, bool thread)
{
    const auto addr = resolve_function(inst->data[0]);
    const auto offset = static_cast<std::int32_t>(addr - inst->index - 1);

    assemble_offset(offset);

    if (thread)
    {
        script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[1])));
    }
}

void assembler::assemble_far_call(const instruction::ptr& inst, bool thread)
{
    script_->write<std::uint8_t>(0);
    script_->write<std::uint16_t>(0);

    if (thread)
    {
        script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[2])));
    }

    const auto file_id = ctx_->token_id(inst->data[0]);
    const auto func_id = ctx_->token_id(inst->data[1]);

    if (ctx_->props() & props::token_size)
        stack_->write<std::uint32_t>(file_id);
    else
        stack_->write<std::uint16_t>(static_cast<std::uint16_t>(file_id));

    if (file_id == 0)
        stack_->write_c_string(encrypt_string(inst->data[0]));

    if (ctx_->props() & props::token_size)
        stack_->write<std::uint32_t>(func_id);
    else
        stack_->write<std::uint16_t>(static_cast<std::uint16_t>(func_id));

    if (func_id == 0)
        stack_->write_c_string(encrypt_string(inst->data[1]));
}

void assembler::assemble_switch(const instruction::ptr& inst)
{
    const auto addr = resolve_label(inst->data[0]);

    script_->write<std::int32_t>(addr - inst->index - 4);
}

void assembler::assemble_end_switch(const instruction::ptr& inst)
{
    const auto count = std::stoul(inst->data[0]);

    script_->write<std::uint16_t>(static_cast<std::uint16_t>(count));

    std::uint32_t index = inst->index + 3;

    for (auto i = 0u; i < count; i++)
    {
        if (inst->data[1 + (3 * i)] == "case")
        {
            if (utils::string::is_number(inst->data[1 + (3 * i) + 1]))
            {
                script_->write<uint32_t>((std::stoi(inst->data[1 + (3 * i) + 1]) & 0xFFFFFF) + 0x800000);
            }
            else
            {
                script_->write<uint32_t>(i + 1);
                stack_->write_c_string(encrypt_string(inst->data[1 + (3 * i) + 1]));
            }

            index += 4;

            const auto addr = resolve_label(inst->data[1 + (3 * i) + 2]);

            assemble_offset(addr - index);

            index += 3;
        }
        else if (inst->data[1 + (3 * i)] == "default")
        {
            script_->write<uint32_t>(0);
            stack_->write_c_string("\x01");

            index += 4;

            const auto addr = resolve_label(inst->data[1 + (3 * i) + 1]);

            assemble_offset(addr - index);

            index += 3;
        }
        else
        {
            throw asm_error("invalid switch case '" + inst->data[1 + (3 * i)] + "'!");
        }
    }
}

void assembler::assemble_field_variable(const instruction::ptr& inst)
{
    auto id = ctx_->token_id(inst->data[0]);

    if (id == 0) id = 0xFFFFFFFF;

    if (ctx_->props() & props::token_size)
        script_->write<std::uint32_t>(id);
    else
        script_->write<std::uint16_t>(static_cast<std::uint16_t>(id));

    if (id > ctx_->str_count())
    {
        if (ctx_->props() & props::token_size)
            stack_->write<std::uint32_t>(0);
        else
            stack_->write<std::uint16_t>(0);

        stack_->write_c_string(encrypt_string(inst->data[0]));
    }
}

void assembler::assemble_formal_params(const instruction::ptr& inst)
{
    const auto count = std::stoi(inst->data[0]);

    script_->write<std::uint8_t>(static_cast<std::uint8_t>(count));

    for (auto i = 1; i <= count; i++)
    {
        script_->write<std::uint8_t>(static_cast<std::uint8_t>(std::stoi(inst->data[i])));
    }
}

void assembler::assemble_jump(const instruction::ptr& inst, bool expr, bool back)
{
    const auto addr = resolve_label(inst->data[0]);

    if (expr)
    {
        script_->write<std::int16_t>(static_cast<std::int16_t>(addr - inst->index - 3));
    }
    else if (back)
    {
        script_->write<std::int16_t>(static_cast<std::int16_t>((inst->index + 3) - addr));
    }
    else
    {
        script_->write<std::int32_t>(static_cast<std::int32_t>(addr - inst->index - 5));
    }
}

void assembler::assemble_offset(std::int32_t offset)
{
    std::array<std::uint8_t, 4> bytes = {};

    auto shift = (ctx_->props() & props::offset_8) ? 8 : (ctx_->props() & props::offset_9) ? 9 : 10;

    offset = (offset << shift) >> 8;

    *reinterpret_cast<std::int32_t*>(bytes.data()) = offset;

    if (ctx_->endian() == endian::little)
    {
        script_->write<std::uint8_t>(bytes[0]);
        script_->write<std::uint8_t>(bytes[1]);
        script_->write<std::uint8_t>(bytes[2]);
    }
    else
    {
        script_->write<std::uint8_t>(bytes[2]);
        script_->write<std::uint8_t>(bytes[1]);
        script_->write<std::uint8_t>(bytes[0]);
    }
}

auto assembler::resolve_function(const std::string& name) -> std::int32_t
{
    for (const auto& entry : functions_)
    {
        if (entry->name == name)
        {
            return entry->index;
        }
    }

    throw asm_error("couldn't resolve local function address of '" + name + "'!");
}

auto assembler::resolve_label(const std::string& name) -> std::int32_t
{
    for (const auto& entry : labels_)
    {
        if (entry.second == name)
        {
            return entry.first;
        }
    }

    throw asm_error("couldn't resolve label address of '" + name + "'!");
}

auto assembler::encrypt_string(std::string& str) -> std::string&
{
    if (str.starts_with("_encstr_") && str.size() % 2 == 0)
    {
        std::string data{};
        data.reserve(str.size() / 2);

        for (auto i = 8u; i < str.size(); i += 2)
        {
            data += static_cast<char>(std::stoul(str.substr(i, 2), 0, 16));
        }

        str = std::move(data);
    }

    return str;
}

} // namespace xsk::gsc

// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "utils/xsk/utils.hpp"

#include "assembler.hpp"
#include "disassembler.hpp"
#include "compiler.hpp"
#include "decompiler.hpp"
#include "resolver.hpp"
#include "context.hpp"

namespace xsk::gsc::iw5c
{

constexpr std::uint16_t max_string_id = 0x8250;

enum class opcode : std::uint8_t
{
    OP_End = 0,
    OP_Return = 1,
    OP_GetUndefined = 2,
    OP_GetZero = 3,
    OP_GetByte = 4,
    OP_GetAnimTree = 5,
    OP_GetNegByte = 6,
    OP_GetUnsignedShort = 7,
    OP_GetNegUnsignedShort = 8,
    OP_GetInteger = 9,
    OP_GetBuiltinFunction = 0xA,
    OP_GetBuiltinMethod = 0xB,
    OP_GetFloat = 0xC,
    OP_GetString = 0xD,
    OP_GetIString = 0xE,
    OP_GetVector = 0xF,
    OP_GetLevelObject = 0x10,
    OP_GetAnimObject = 0x11,
    OP_GetSelf = 0x12,
    OP_GetThisthread = 0x13,
    OP_GetLevel = 0x14,
    OP_GetGame = 0x15,
    OP_GetAnim = 0x16,
    OP_GetAnimation = 0x17,
    OP_GetGameRef = 0x18,
    OP_GetLocalFunction = 0x19,
    OP_GetFarFunction = 0x1A,
    OP_CreateLocalVariable = 0x1B,
    OP_RemoveLocalVariables = 0x1C,
    OP_EvalLocalVariableCached0 = 0x1D,
    OP_EvalLocalVariableCached1 = 0x1E,
    OP_EvalLocalVariableCached2 = 0x1F,
    OP_EvalLocalVariableCached3 = 0x20,
    OP_EvalLocalVariableCached4 = 0x21,
    OP_EvalLocalVariableCached5 = 0x22,
    OP_EvalLocalVariableCached = 0x23,
    OP_EvalLocalArrayCached = 0x24,
    OP_EvalArray = 0x25,
    OP_EvalLocalArrayRefCached0 = 0x26,
    OP_EvalNewLocalArrayRefCached0 = 0x27,
    OP_EvalLocalArrayRefCached = 0x28,
    OP_EvalArrayRef = 0x29,
    OP_ClearArray = 0x2A,
    OP_EmptyArray = 0x2B,
    OP_AddArray = 0x2C,
    OP_GetSelfObject = 0x2D,
    OP_EvalLevelFieldVariable = 0x2E,
    OP_EvalAnimFieldVariable = 0x2F,
    OP_EvalSelfFieldVariable = 0x30,
    OP_EvalFieldVariable = 0x31,
    OP_EvalLevelFieldVariableRef  = 0x32,
    OP_EvalAnimFieldVariableRef = 0x33,
    OP_EvalSelfFieldVariableRef = 0x34,
    OP_EvalFieldVariableRef = 0x35,
    OP_ClearFieldVariable = 0x36,
    OP_SafeCreateVariableFieldCached = 0x37,
    OP_SafeSetVariableFieldCached0 = 0x38,
    OP_SafeSetVariableFieldCached = 0x39,
    OP_SafeSetWaittillVariableFieldCached = 0x3A,
    OP_clearparams = 0x3B,
    OP_checkclearparams = 0x3C,
    OP_EvalLocalVariableRefCached0 = 0x3D,
    OP_EvalNewLocalVariableRefCached0 = 0x3E,
    OP_EvalLocalVariableRefCached = 0x3F,
    OP_SetLevelFieldVariableField = 0x40,
    OP_SetVariableField = 0x41,
    OP_ClearVariableField = 0x42,
    OP_SetAnimFieldVariableField = 0x43,
    OP_SetSelfFieldVariableField = 0x44,
    OP_SetLocalVariableFieldCached0 = 0x45,
    OP_SetNewLocalVariableFieldCached0 = 0x46,
    OP_SetLocalVariableFieldCached = 0x47,
    OP_ClearLocalVariableFieldCached = 0x48,
    OP_ClearLocalVariableFieldCached0 = 0x49,
    OP_CallBuiltin0 = 0x4A,
    OP_CallBuiltin1 = 0x4B,
    OP_CallBuiltin2 = 0x4C,
    OP_CallBuiltin3 = 0x4D,
    OP_CallBuiltin4 = 0x4E,
    OP_CallBuiltin5 = 0x4F,
    OP_CallBuiltin = 0x50,
    OP_CallBuiltinMethod0 = 0x51,
    OP_CallBuiltinMethod1 = 0x52,
    OP_CallBuiltinMethod2 = 0x53,
    OP_CallBuiltinMethod3 = 0x54,
    OP_CallBuiltinMethod4 = 0x55,
    OP_CallBuiltinMethod5 = 0x56,
    OP_CallBuiltinMethod = 0x57,
    OP_wait = 0x58,
    OP_waittillFrameEnd = 0x59,
    OP_PreScriptCall = 0x5A,
    OP_ScriptLocalFunctionCall2 = 0x5B,
    OP_ScriptLocalFunctionCall = 0x5C,
    OP_ScriptLocalMethodCall = 0x5D,
    OP_ScriptLocalThreadCall = 0x5E,
    OP_ScriptLocalChildThreadCall = 0x5F,
    OP_ScriptLocalMethodThreadCall = 0x60,
    OP_ScriptLocalMethodChildThreadCall = 0x61,
    OP_ScriptFarFunctionCall2 = 0x62,
    OP_ScriptFarFunctionCall = 0x63,
    OP_ScriptFarMethodCall = 0x64,
    OP_ScriptFarThreadCall = 0x65,
    OP_ScriptFarChildThreadCall = 0x66,
    OP_ScriptFarMethodThreadCall = 0x67,
    OP_ScriptFarMethodChildThreadCall = 0x68,
    OP_ScriptFunctionCallPointer = 0x69,
    OP_ScriptMethodCallPointer = 0x6A,
    OP_ScriptThreadCallPointer = 0x6B,
    OP_ScriptChildThreadCallPointer = 0x6C,
    OP_ScriptMethodThreadCallPointer = 0x6D,
    OP_ScriptMethodChildThreadCallPointer = 0x6E,
    OP_CallBuiltinPointer = 0x6F,
    OP_CallBuiltinMethodPointer = 0x70,
    OP_DecTop = 0x71,
    OP_CastFieldObject = 0x72,
    OP_EvalLocalVariableObjectCached = 0x73,
    OP_CastBool = 0x74,
    OP_BoolNot = 0x75,
    OP_BoolComplement = 0x76,
    OP_JumpOnFalse = 0x77,
    OP_JumpOnTrue = 0x78,
    OP_JumpOnFalseExpr = 0x79,
    OP_JumpOnTrueExpr = 0x7A,
    OP_jump = 0x7B,
    OP_jumpback = 0x7C,
    OP_inc = 0x7D,
    OP_dec = 0x7E,
    OP_bit_or = 0x7F,
    OP_bit_ex_or = 0x80,
    OP_bit_and = 0x81,
    OP_equality = 0x82,
    OP_inequality = 0x83,
    OP_less = 0x84,
    OP_greater = 0x85,
    OP_less_equal = 0x86,
    OP_greater_equal = 0x87,
    OP_shift_left = 0x88,
    OP_shift_right = 0x89,
    OP_plus = 0x8A,
    OP_minus = 0x8B,
    OP_multiply = 0x8C,
    OP_divide = 0x8D,
    OP_mod = 0x8E,
    OP_size = 0x8F,
    OP_waittillmatch = 0x90,
    OP_waittillmatch2 = 0x91,
    OP_waittill = 0x92,
    OP_notify = 0x93,
    OP_endon = 0x94,
    OP_voidCodepos = 0x95,
    OP_switch = 0x96,
    OP_endswitch = 0x97,
    OP_vector = 0x98,
    OP_Count = 0x99,
};

auto opcode_size(std::uint8_t id) -> std::uint32_t;

} // namespace xsk::gsc::iw5c

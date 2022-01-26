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

namespace xsk::gsc::iw8
{

constexpr std::uint32_t max_string_id = 0x13E43;

enum class opcode : std::uint8_t
{
    OP_CastFieldObject = 0x0,
    OP_SetLocalVariableFieldCached = 0x1,
    OP_plus = 0x2,
    OP_RemoveLocalVariables = 0x3,
    OP_EvalSelfFieldVariableRef = 0x4,
    OP_ScriptFarMethodChildThreadCall = 0x5,
    OP_GetGameRef = 0x6,
    OP_EvalAnimFieldVariable = 0x7,
    OP_EvalLevelFieldVariableRef = 0x8,
    OP_GetThisthread = 0x9,
    OP_greater = 0xA,
    OP_waittillmatch = 0xB,
    OP_shift_right = 0xC,
    OP_dec = 0xD,
    OP_JumpOnTrue = 0xE,
    OP_bit_or = 0xF,
    OP_equality = 0x10,
    OP_ClearLocalVariableFieldCached0 = 0x11,
    OP_notify = 0x12,
    OP_GetVector = 0x13,
    OP_ScriptMethodChildThreadCallPointer = 0x14,
    OP_PreScriptCall = 0x15,
    OP_GetByte = 0x16,
    OP_ScriptFarThreadCall = 0x17,
    OP_SetSelfFieldVariableField = 0x18,
    OP_JumpOnFalseExpr = 0x19,
    OP_GetUndefined = 0x1A,
    OP_jumpback = 0x1B,
    OP_JumpOnTrueExpr = 0x1C,
    OP_CallBuiltin0 = 0x1D,
    OP_CallBuiltin1 = 0x1E,
    OP_CallBuiltin2 = 0x1F,
    OP_CallBuiltin3 = 0x20,
    OP_CallBuiltin4 = 0x21,
    OP_CallBuiltin5 = 0x22,
    OP_CallBuiltin = 0x23,
    OP_SetLocalVariableFieldCached0 = 0x24,
    OP_ClearFieldVariable = 0x25,
    OP_GetLevel = 0x26,
    OP_size = 0x27,
    OP_SafeSetWaittillVariableFieldCached = 0x28,
    OP_ScriptLocalMethodThreadCall = 0x29,
    OP_AddArray = 0x2A,
    OP_endon = 0x2B,
    OP_EvalFieldVariable = 0x2C,
    OP_shift_left = 0x2D,
    OP_EvalLocalArrayRefCached0 = 0x2E,
    OP_Return = 0x2F,
    OP_CreateLocalVariable = 0x30,
    OP_SafeSetVariableFieldCached0 = 0x31,
    OP_GetBuiltinFunction = 0x32,
    OP_ScriptLocalMethodCall = 0x33,
    OP_CallBuiltinMethodPointer = 0x34,
    OP_ScriptLocalChildThreadCall = 0x35,
    OP_GetSelfObject = 0x36,
    OP_GetGame = 0x37,
    OP_SetLevelFieldVariableField = 0x38,
    OP_EvalArray = 0x39,
    OP_GetSelf = 0x3A,
    OP_End = 0x3B,
    OP_EvalSelfFieldVariable = 0x3C,
    OP_less_equal = 0x3D,
    OP_EvalLocalVariableCached0 = 0x3E,
    OP_EvalLocalVariableCached1 = 0x3F,
    OP_EvalLocalVariableCached2 = 0x40,
    OP_EvalLocalVariableCached3 = 0x41,
    OP_EvalLocalVariableCached4 = 0x42,
    OP_EvalLocalVariableCached5 = 0x43,
    OP_EvalLocalVariableCached = 0x44,
    OP_EvalNewLocalArrayRefCached0 = 0x45,
    OP_ScriptChildThreadCallPointer = 0x46,
    OP_EvalLocalVariableObjectCached = 0x47,
    OP_ScriptLocalThreadCall = 0x48,
    OP_GetInteger = 0x49,
    OP_ScriptMethodCallPointer = 0x4A,
    OP_checkclearparams = 0x4B,
    OP_SetAnimFieldVariableField = 0x4C,
    OP_waittillmatch2 = 0x4D,
    OP_minus = 0x4E,
    OP_ScriptLocalFunctionCall2 = 0x4F,
    OP_GetNegUnsignedShort = 0x50,
    OP_GetNegByte = 0x51,
    OP_SafeCreateVariableFieldCached = 0x52,
    OP_greater_equal = 0x53,
    OP_vector = 0x54,
    OP_GetBuiltinMethod = 0x55,
    OP_endswitch = 0x56,
    OP_ClearArray = 0x57,
    OP_DecTop = 0x58,
    OP_CastBool = 0x59,
    OP_EvalArrayRef = 0x5A,
    OP_SetNewLocalVariableFieldCached0 = 0x5B,
    OP_GetZero = 0x5C,
    OP_wait = 0x5D,
    OP_waittill = 0x5E,
    OP_GetIString = 0x5F,
    OP_ScriptFarFunctionCall = 0x60,
    OP_GetAnimObject = 0x61,
    OP_GetAnimTree = 0x62,
    OP_EvalLocalArrayCached = 0x63,
    OP_mod = 0x64,
    OP_ScriptFarMethodThreadCall = 0x65,
    OP_GetUnsignedShort = 0x66,
    OP_clearparams = 0x67,
    OP_ScriptMethodThreadCallPointer = 0x68,
    OP_ScriptFunctionCallPointer = 0x69,
    OP_EmptyArray = 0x6A,
    OP_SafeSetVariableFieldCached = 0x6B,
    OP_ClearVariableField = 0x6C,
    OP_EvalFieldVariableRef = 0x6D,
    OP_ScriptLocalMethodChildThreadCall = 0x6E,
    OP_EvalNewLocalVariableRefCached0 = 0x6F,
    OP_GetFloat = 0x70,
    OP_EvalLocalVariableRefCached = 0x71,
    OP_JumpOnFalse = 0x72,
    OP_BoolComplement = 0x73,
    OP_ScriptThreadCallPointer = 0x74,
    OP_ScriptFarFunctionCall2 = 0x75,
    OP_less = 0x76,
    OP_BoolNot = 0x77,
    OP_waittillFrameEnd = 0x78,
    OP_waitframe = 0x79,
    OP_GetString = 0x7A,
    OP_EvalLevelFieldVariable = 0x7B,
    OP_GetLevelObject = 0x7C,
    OP_inc = 0x7D,
    OP_CallBuiltinMethod0 = 0x7E,
    OP_CallBuiltinMethod1 = 0x7F,
    OP_CallBuiltinMethod2 = 0x80,
    OP_CallBuiltinMethod3 = 0x81,
    OP_CallBuiltinMethod4 = 0x82,
    OP_CallBuiltinMethod5 = 0x83,
    OP_CallBuiltinMethod = 0x84,
    OP_GetAnim = 0x85,
    OP_switch = 0x86,
    OP_SetVariableField = 0x87,
    OP_divide = 0x88,
    OP_GetLocalFunction = 0x89,
    OP_ScriptFarChildThreadCall = 0x8A,
    OP_multiply = 0x8B,
    OP_ClearLocalVariableFieldCached = 0x8C,
    OP_EvalAnimFieldVariableRef = 0x8D,
    OP_EvalLocalArrayRefCached = 0x8E,
    OP_EvalLocalVariableRefCached0 = 0x8F,
    OP_bit_and = 0x90,
    OP_GetAnimation = 0x91,
    OP_GetFarFunction = 0x92,
    OP_CallBuiltinPointer = 0x93,
    OP_jump = 0x94,
    OP_voidCodepos = 0x95,
    OP_ScriptFarMethodCall = 0x96,
    OP_inequality = 0x97,
    OP_ScriptLocalFunctionCall = 0x98,
    OP_bit_ex_or = 0x99,
    OP_NOP = 0x9A,
    OP_abort = 0x9B,
    OP_object = 0x9C,
    OP_thread_object = 0x9D,
    OP_EvalLocalVariable = 0x9E,
    OP_EvalLocalVariableRef = 0x9F,
    OP_prof_begin = 0xA0,
    OP_prof_end = 0xA1,
    OP_breakpoint = 0xA2,
    OP_assignmentBreakpoint = 0xA3,
    OP_manualAndAssignmentBreakpoint = 0xA4,
    OP_BoolNotAfterAnd = 0xA5,
    OP_FormalParams = 0xA6,
    OP_IsDefined = 0xA7,
    OP_IsTrue = 0xA8,
    OP_NativeGetLocalFunction = 0xA9,
    OP_NativeLocalFunctionCall = 0xAA,
    OP_NativeLocalFunctionCall2 = 0xAB,
    OP_NativeLocalMethodCall = 0xAC,
    OP_NativeLocalFunctionThreadCall = 0xAD,
    OP_NativeLocalMethodThreadCall = 0xAE,
    OP_NativeLocalFunctionChildThreadCall = 0xAF,
    OP_NativeLocalMethodChildThreadCall = 0xB0,
    OP_NativeGetFarFunction = 0xB1,
    OP_NativeFarFunctionCall = 0xB2,
    OP_NativeFarFunctionCall2 = 0xB3,
    OP_NativeFarMethodCall = 0xB4,
    OP_NativeFarFunctionThreadCall = 0xB5,
    OP_NativeFarMethodThreadCall = 0xB6,
    OP_NativeFarFunctionChildThreadCall = 0xB7,
    OP_NativeFarMethodChildThreadCall = 0xB8,
    OP_EvalNewLocalArrayRefCached0_Precompiled = 0xB9,
    OP_SetNewLocalVariableFieldCached0_Precompiled = 0xBA,
    OP_CreateLocalVariable_Precompiled = 0xBB,
    OP_SafeCreateVariableFieldCached_Precompiled = 0xBC,
    OP_FormalParams_Precompiled = 0xBD,
    OP_count = 0xBE,
};

auto opcode_size(std::uint8_t op) -> std::uint32_t;

} // namespace xsk::gsc::iw8

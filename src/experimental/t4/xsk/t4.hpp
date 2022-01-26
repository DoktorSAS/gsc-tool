// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "utils/xsk/utils.hpp"

namespace xsk::gsc::t4
{

enum class opcode : std::uint8_t
{
    OP_End = 0x0,
    OP_Return = 0x1,
    OP_GetUndefined = 0x2,
    OP_GetZero = 0x3,
    OP_GetByte = 0x4,
    OP_GetNegByte = 0x5,
    OP_GetUnsignedShort = 0x6,
    OP_GetNegUnsignedShort = 0x7,
    OP_GetInteger = 0x8,
    OP_GetFloat = 0x9,
    OP_GetString = 0xA,
    OP_GetIString = 0xB,
    OP_GetVector = 0xC,
    OP_GetLevelObject = 0xD,
    OP_GetAnimObject = 0xE,
    OP_GetSelf = 0xF,
    OP_GetLevel = 0x10,
    OP_GetGame = 0x11,
    OP_GetAnim = 0x12,
    OP_GetAnimation = 0x13,
    OP_GetGameRef = 0x14,
    OP_GetFunction = 0x15,
    OP_CreateLocalVariable = 0x16,
    OP_RemoveLocalVariables = 0x17,
    OP_EvalLocalVariableCached0 = 0x18,
    OP_EvalLocalVariableCached1 = 0x19,
    OP_EvalLocalVariableCached2 = 0x1A,
    OP_EvalLocalVariableCached3 = 0x1B,
    OP_EvalLocalVariableCached4 = 0x1C,
    OP_EvalLocalVariableCached5 = 0x1D,
    OP_EvalLocalVariableCached = 0x1E,
    OP_EvalLocalArrayCached = 0x1F,
    OP_EvalArray = 0x20,
    OP_EvalLocalArrayRefCached0 = 0x21,
    OP_EvalLocalArrayRefCached = 0x22,
    OP_EvalArrayRef = 0x23,
    OP_ClearArray = 0x24,
    OP_EmptyArray = 0x25,
    OP_GetSelfObject = 0x26,
    OP_EvalLevelFieldVariable = 0x27,
    OP_EvalAnimFieldVariable = 0x28,
    OP_EvalSelfFieldVariable = 0x29,
    OP_EvalFieldVariable = 0x2A,
    OP_EvalLevelFieldVariableRef = 0x2B,
    OP_EvalAnimFieldVariableRef = 0x2C,
    OP_EvalSelfFieldVariableRef = 0x2D,
    OP_EvalFieldVariableRef = 0x2E,
    OP_ClearFieldVariable = 0x2F,
    OP_SafeCreateVariableFieldCached = 0x30,
    OP_SafeSetVariableFieldCached0 = 0x31,
    OP_SafeSetVariableFieldCached = 0x32,
    OP_SafeSetWaittillVariableFieldCached = 0x33,
    OP_clearparams = 0x34,
    OP_checkclearparams = 0x35,
    OP_EvalLocalVariableRefCached0 = 0x36,
    OP_EvalLocalVariableRefCached = 0x37,
    OP_SetLevelFieldVariableField = 0x38,
    OP_SetVariableField = 0x39,
    OP_SetAnimFieldVariableField = 0x3A,
    OP_SetSelfFieldVariableField = 0x3B,
    OP_SetLocalVariableFieldCached0 = 0x3C,
    OP_SetLocalVariableFieldCached = 0x3D,
    OP_CallBuiltin0 = 0x3E,
    OP_CallBuiltin1 = 0x3F,
    OP_CallBuiltin2 = 0x40,
    OP_CallBuiltin3 = 0x41,
    OP_CallBuiltin4 = 0x42,
    OP_CallBuiltin5 = 0x43,
    OP_CallBuiltin = 0x44,
    OP_CallBuiltinMethod0 = 0x45,
    OP_CallBuiltinMethod1 = 0x46,
    OP_CallBuiltinMethod2 = 0x47,
    OP_CallBuiltinMethod3 = 0x48,
    OP_CallBuiltinMethod4 = 0x49,
    OP_CallBuiltinMethod5 = 0x4A,
    OP_CallBuiltinMethod = 0x4B,
    OP_wait = 0x4C,
    OP_waittillFrameEnd = 0x4D,
    OP_PreScriptCall = 0x4E,
    OP_ScriptFunctionCall2 = 0x4F,
    OP_ScriptFunctionCall = 0x50,
    OP_ScriptFunctionCallPointer = 0x51,
    OP_ScriptMethodCall = 0x52,
    OP_ScriptMethodCallPointer = 0x53,
    OP_ScriptThreadCall = 0x54,
    OP_ScriptThreadCallPointer = 0x55,
    OP_ScriptMethodThreadCall = 0x56,
    OP_ScriptMethodThreadCallPointer = 0x57,
    OP_DecTop = 0x58,
    OP_CastFieldObject = 0x59,
    OP_EvalLocalVariableObjectCached = 0x5A,
    OP_CastBool = 0x5B,
    OP_BoolNot = 0x5C,
    OP_BoolComplement = 0x5D,
    OP_JumpOnFalse = 0x5E,
    OP_JumpOnTrue = 0x5F,
    OP_JumpOnFalseExpr = 0x60,
    OP_JumpOnTrueExpr = 0x61,
    OP_jump = 0x62,
    OP_jumpback = 0x63,
    OP_inc = 0x64,
    OP_dec = 0x65,
    OP_bit_or = 0x66,
    OP_bit_ex_or = 0x67,
    OP_bit_and = 0x68,
    OP_equality = 0x69,
    OP_inequality = 0x6A,
    OP_less = 0x6B,
    OP_greater = 0x6C,
    OP_less_equal = 0x6D,
    OP_greater_equal = 0x6E,
    OP_shift_left = 0x6F,
    OP_shift_right = 0x70,
    OP_plus = 0x71,
    OP_minus = 0x72,
    OP_multiply = 0x73,
    OP_divide = 0x74,
    OP_mod = 0x75,
    OP_size = 0x76,
    OP_waittillmatch = 0x77,
    OP_waittill = 0x78,
    OP_notify = 0x79,
    OP_endon = 0x7A,
    OP_voidCodepos = 0x7B,
    OP_switch = 0x7C,
    OP_endswitch = 0x7D,
    OP_vector = 0x7E,
    OP_NOP = 0x7F,
    OP_abort = 0x80,
    OP_object = 0x81,
    OP_thread_object = 0x82,
    OP_EvalLocalVariable = 0x83,
    OP_EvalLocalVariableRef = 0x84,
    OP_prof_begin = 0x85,
    OP_prof_end = 0x86,
    OP_breakpoint = 0x87,
    OP_assignmentBreakpoint = 0x88,
    OP_manualAndAssignmentBreakpoint = 0x89,
    OP_count = 0x8A,
};

auto opcode_size(std::uint8_t id) -> std::uint32_t;

} // namespace xsk::gsc::t4

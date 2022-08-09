//
// Created by xgladius on 8/7/22.
//
#pragma once
#include <iostream>
#include <Luau/Transpiler.h>
#include "BlockGen/include/BlockGen.h"
#include "Common.h"

namespace Luau::Decompiler {
    void dumpInstructionX(const uint32_t* code, std::string& result, int targetLabel);

    void dumpProto(lua_State* L, Proto* p);

    std::string decompile(lua_State* L, std::string& bytecode);
}
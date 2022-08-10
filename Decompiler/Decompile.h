//
// Created by xgladius on 8/7/22.
//
#pragma once
#include <iostream>
#include <Luau/Transpiler.h>
#include "BlockGen/include/BlockGen.h"
#include "Common.h"

namespace Luau::Decompiler {
    std::string decompile(lua_State* L, std::string& bytecode);
}
//
// Created by Braeden Weaver on 8/7/22.
//
#include <iostream>
#include <Luau/Transpiler.h>
#include "BlockGen/include/BlockGen.h"
#include "Common.h"

namespace Luau::Decompiler {
    void dumpProto(lua_State* L, Proto* p);

    std::string decompile(lua_State* L, std::string& bytecode);
}
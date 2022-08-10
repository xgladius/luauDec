//
// Created by xgladius on 8/7/22.
//
#include <Luau/JsonEncoder.h>
#include "Decompile.h"

namespace Luau::Decompiler {
    std::string decompile(lua_State* L, std::string& bytecode) {
        if (luau_load(L, "=", bytecode.c_str(), bytecode.size(), 0) != 0)
            return lua_tostring(L, -1);
        Proto* p = ((Closure *)lua_topointer(L, -1))->l.p;
        std::vector<AstExpr*> subFuncs;
        for (auto i = 0; i < p->sizep; i++) {
            BlockGen::BlockGen<false> block(p->p[i]);
            subFuncs.push_back(block.generate());
        }

        BlockGen::BlockGen<true> main(p, subFuncs);
        auto* block = main.generate();
        std::cout << "our json: " << std::endl << toJson(block) << std::endl;
        return transpile(*block);
    }
}
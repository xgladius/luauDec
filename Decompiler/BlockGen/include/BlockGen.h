//
// Created by xgladius on 8/6/22.
//
#pragma once
#include <unordered_map>
#include <utility>
#include "../include/Lifter.h"
#include "../../AstGen/include/VirtualAstStack.h"
#include "../../AstGen/include/Handlers.h"
#include "../../AstGen/include/Common.h"
#include "../../Common.h"
#include "BodyHandler.h"

namespace Luau::Decompiler::BlockGen {
    template <bool isMain>
    class BlockGen {
        Proto* proto;
        std::vector<int> blockInfo;

        BodyHandler bodyHandler;

        Luau::Decompiler::AstGen::VirtualAstStack virtualStack;
        std::vector<AstExprFunction*> subFuncs;
        std::vector<AstLocal*>* functionArgs;
        std::unordered_map<int, AstLocal*> locVars;

        void handleInstruction(unsigned int *insn, int pc);

        AstStatBlock* handleAllInstructions();

        void generateFunctionArgs();
    public:
#ifndef _MSC_VER
        explicit BlockGen<true>(Proto* p, std::vector<AstExprFunction*> subFuncs);
        explicit BlockGen<false>(Proto* p);
#else
        BlockGen(Proto* p, std::vector<AstExprFunction*> subFuncs);
        BlockGen(Proto* p);
#endif

        auto generate() -> typename std::conditional<isMain,
                AstStatBlock*,
                AstExprFunction*>::type;
    };
}
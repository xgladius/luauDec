//
// Created by Braeden Weaver on 8/6/22.
//
#pragma once
#include <vector>
#include "../../Common.h"

namespace Luau::Decompiler::BlockGen::Lifter {
    enum BlockType : int8_t {
        START = 1,
        END = 2,
        STARTEND = 3
    };

    std::vector<int> liftBodyInfo(Proto* p);
}
//
// Created by xgladius on 8/6/22.
//
#include "../include/Lifter.h"

namespace Luau::Decompiler::BlockGen::Lifter {
    std::vector<int> liftBodyInfo(Proto* p) {
        std::vector<int> bodies;
        bodies.resize(p->sizecode, -1);
        for (size_t i = 0; i < p->sizecode;) {
            int target = getJumpTarget(p->code[i], uint32_t(i));
            if (target >= 0) {
                if (LUAU_INSN_OP(p->code[i]) == LOP_JUMP || LUAU_INSN_OP(p->code[i]) == LOP_JUMPBACK) {
                    bodies[i + getOpLength(
                            LuauOpcode(LUAU_INSN_OP(p->code[i]))) - 1] = STARTEND; // next instr is start of block
                    p->code[i- 1] = LOP_NOP;
                    bodies[target- 1] = END; // end of block
                } else if (LUAU_INSN_OP(p->code[i]) == LOP_FORNLOOP || LUAU_INSN_OP(p->code[i]) == LOP_FORGLOOP) {
                    // do nothing, else will handle this, we do nothing with this instr in decomp
                    p->code[i] = LOP_NOP;
                } else {
                    bodies[i + getOpLength(LuauOpcode(LUAU_INSN_OP(p->code[i])))- 1] = 1; // next instr is start of block
                    bodies[target- 1] = END; // end of block
                }
            }
            i += getOpLength(LuauOpcode(LUAU_INSN_OP(p->code[i])));
        }
        return bodies;
    }
}
#include <iostream>
#include <string>
#include "Decompiler/Decompile.h"
#include "lualib.h"
#include "Luau/Compiler.h"

namespace luau {
    struct rbx_lua_bytecode_encoder : public Luau::BytecodeEncoder
    {
        uint8_t encodeOp(uint8_t op) override
        {
            return static_cast<std::uint8_t>(op);
        };
    };

    std::string rbx_compile(const std::string &script) {
        return Luau::compile(script, {0, 1, 0}, {}, {});
    }
}

static void setupState(lua_State* L)
{
    luaL_openlibs(L);
    luaL_sandbox(L);
}

int main() {
    auto bytecode = luau::rbx_compile("x = 1 while true do for i=1, 19 do print(x) end end");
    std::unique_ptr<lua_State, void (*)(lua_State*)> globalState(luaL_newstate(), lua_close);
    lua_State* L = globalState.get();
    setupState(L);
    luaL_sandboxthread(L);
    std::cout << Luau::Decompiler::decompile(L, bytecode) << std::endl;
    return 0;
}

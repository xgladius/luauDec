cmake_minimum_required(VERSION 3.20)
project(luauDec)
set(CMAKE_CXX_STANDARD 17)

add_executable(luauDec main.cpp Decompiler/AstGen/src/Common.cpp Decompiler/BlockGen/include/Lifter.h Decompiler/BlockGen/src/Lifter.cpp Decompiler/Common.h Decompiler/BlockGen/src/BlockGen.cpp Decompiler/BlockGen/include/BlockGen.h Decompiler/AstGen/include/VirtualAstStack.h Decompiler/AstGen/src/VirtualAstStack.cpp Decompiler/BlockGen/include/BodyHandler.h Decompiler/BlockGen/src/BodyHandler.cpp Decompiler/AstGen/include/Generator.h Decompiler/AstGen/src/Generator.cpp Decompiler/AstGen/include/Handlers.h Decompiler/AstGen/src/Handlers.cpp Decompiler/Decompile.h Decompiler/Decompile.cpp)

include(CTest)
enable_testing()

target_include_directories(luauDec PRIVATE include)

add_subdirectory(luau)
target_link_libraries(luauDec Luau.Compiler)
target_link_libraries(luauDec Luau.Analysis)
target_link_libraries(luauDec Luau.VM)
target_link_libraries(luauDec Luau.Ast)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
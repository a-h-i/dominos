cmake_minimum_required(VERSION 3.4)
project(Dominos)
set(EXECUTABLE_NAME "dominos")
set(TEST_EXEC_NAME "dominos-tests")
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" )
    ADD_DEFINITIONS(
        -std=c++14
        -Wall
        -Wextra
        -DwxUSE_GUI=1
        -fPIC
        )
    # Yes discard default values
    set(CMAKE_CXX_FLAGS_RELEASE "-flto -O3 -march=native -fmerge-all-constants -fgcse-sm -fgcse-las")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-flto -s")
elseif ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
    add_definitions(
        /Wall
        /WX
        )
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox /Oi /arch:SSE2")
endif()
add_subdirectory(src)

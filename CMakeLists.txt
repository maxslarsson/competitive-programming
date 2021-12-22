# https://codeforces.com/blog/entry/15547

cmake_minimum_required(VERSION 3.21)
project(usaco)

set(CMAKE_CXX_STANDARD 17)

set(OPTIONS "-fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fno-sanitize-recover")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${OPTIONS}")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} ${OPTIONS}")

include_directories($ENV{HOME}/include)

add_executable(template template.cpp)
target_precompile_headers(template PUBLIC <bits/stdc++.h>)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "Bronze/*.cpp" "Silver/*.cpp" "Gold/*.cpp" "Platinum/*.cpp")
foreach (sourcefile ${SRC_FILES})
    string(REPLACE "/" "_" EXECNAME ${sourcefile})
    string(REPLACE ".cpp" "" EXECNAME ${EXECNAME})
    add_executable(${EXECNAME} ${sourcefile})
    target_precompile_headers(${EXECNAME} REUSE_FROM template)
endforeach (sourcefile ${SRC_FILES})

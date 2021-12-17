cmake_minimum_required(VERSION 3.21)
project(usaco)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

include_directories($ENV{HOME}/include)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS RELATIVE "${CMAKE_CURRENT_LIST_DIR}" "Bronze/*.cpp" "Silver/*.cpp" "Gold/*.cpp" "Platinum/*.cpp")

foreach (sourcefile ${SRC_FILES})
    string(REPLACE "/" "_" EXECNAME ${sourcefile})
    string(REPLACE ".cpp" "" EXECNAME ${EXECNAME})
    add_executable(${EXECNAME} ${sourcefile})
endforeach (sourcefile ${SRC_FILES})

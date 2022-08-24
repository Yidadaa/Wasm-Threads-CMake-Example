cmake_minimum_required(VERSION 3.5)

project(hello_cmake)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-pthread)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

if(EMSCRIPTEN)
  add_compile_options(
    -sALLOW_MEMORY_GROWTH=1 -sPTHREAD_POOL_SIZE=10 -sPTHREAD_POOL_SIZE_STRICT=0
    -sUSE_PTHREADS=1 -sEXIT_RUNTIME=1)
endif()

add_executable(hello_cmake main.cpp)

message(CMAKE_CURRENT_BINARY_DIR)

execute_process(
  COMMAND ln -sf ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
          ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)

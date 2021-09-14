cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_C_COMPILER gcc)
add_compile_options(-Wall -Wextra)

project(HackAssembler)

file(GLOB_RECURSE source_files ${PROJECT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(HackAssembler ${source_files})

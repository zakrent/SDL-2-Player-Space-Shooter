cmake_minimum_required(VERSION 3.6)
project(ORBIT-SIM)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

file(GLOB_RECURSE SOURCE_FILES
    "src/*.cpp"
    "src/*.h"
)

add_executable(ORBIT-SIM ${SOURCE_FILES} ${SOURCE_FILES})
target_link_libraries(ORBIT-SIM ${SDL2_LIBRARY})

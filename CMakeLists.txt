cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(GetProcAddressEx)

add_library(GetProcAddressEx STATIC src/GetProcAddressEx.cpp)

target_include_directories(GetProcAddressEx PUBLIC include)

add_executable(Test src/Main.cpp)

target_link_libraries(Test PRIVATE GetProcAddressEx)
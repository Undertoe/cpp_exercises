
cmake_minimum_required(VERSION 3.20.0)


project(cpp_exercises VERSION 0.1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
find_package(Catch2)

if(Catch2_FOUND)
    message(STATUS "Catch2 found")
else()
    message(STATUS "Catch2 not found")
endif()

include_directories(Catch2_INCLUDE_DIRS)

add_subdirectory(ModernCPPChallenge)
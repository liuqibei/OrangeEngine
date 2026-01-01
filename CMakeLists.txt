cmake_minimum_required(VERSION 3.16)

project(OrangeEngine VERSION 1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Vulkan REQUIRED)

add_subdirectory(thirdparty)
add_subdirectory(modules)
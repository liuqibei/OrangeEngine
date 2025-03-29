file(GLOB_RECURSE BASE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Base ${BASE_SOURCES})

target_include_directories(Orange.Base
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)
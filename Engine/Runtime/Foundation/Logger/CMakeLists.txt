file(GLOB_RECURSE FOUNDATION_LOGGER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Foundation.Logger ${FOUNDATION_LOGGER_SOURCES})

target_link_libraries(Orange.Foundation.Logger PUBLIC spdlog)
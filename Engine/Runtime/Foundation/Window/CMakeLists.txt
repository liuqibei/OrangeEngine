file(GLOB_RECURSE FOUNDATION_WINDOW_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Foundation.Window ${FOUNDATION_WINDOW_SOURCES})

target_link_libraries(Orange.Foundation.Window PRIVATE SDL3::SDL3)

target_link_libraries(Orange.Foundation.Window PUBLIC Orange.Base.Math)
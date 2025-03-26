file(GLOB_RECURSE FOUNDATION_APPLICATION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Foundation.Application ${FOUNDATION_APPLICATION_SOURCES})

target_link_libraries(
    Orange.Foundation.Application 
    PUBLIC 
    Orange.Foundation.Logger
    Orange.Foundation.Window
)
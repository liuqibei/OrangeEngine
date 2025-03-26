file(GLOB_RECURSE ENTRY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_executable(Orange.Entry ${ENTRY_SOURCES})

target_link_libraries(
    Orange.Entry
    PRIVATE 
    SDL3::SDL3
    Orange.Foundation.Application
)
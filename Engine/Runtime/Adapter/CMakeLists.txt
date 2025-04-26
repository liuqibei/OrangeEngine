file(GLOB_RECURSE ADAPTER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Adapter STATIC ${ADAPTER_SOURCES})

target_include_directories(Orange.Adapter
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)

target_include_directories(Orange.Adapter
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Foundation/Interface
)

target_link_libraries(Orange.Adapter
    PUBLIC
    Orange.Base
)

target_link_libraries(Orange.Adapter
    PRIVATE
    SDL3::SDL3
)
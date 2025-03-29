file(GLOB_RECURSE PLATFROM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Platfrom ${PLATFROM_SOURCES})

target_include_directories(Orange.Platfrom
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)

target_include_directories(Orange.Platfrom
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Foundation/Interface
)

target_link_libraries(Orange.Platfrom
    PUBLIC
    Orange.Base
)

target_link_libraries(Orange.Platfrom
    PRIVATE
    SDL3::SDL3
)
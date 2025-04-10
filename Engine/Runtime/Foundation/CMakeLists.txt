file(GLOB_RECURSE FOUNDATION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Foundation ${FOUNDATION_SOURCES})

target_include_directories(Orange.Foundation
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)

target_include_directories(Orange.Foundation
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Orange.Foundation
    PUBLIC
    spdlog
)

target_link_libraries(Orange.Foundation
    PUBLIC
    Orange.Platfrom
)
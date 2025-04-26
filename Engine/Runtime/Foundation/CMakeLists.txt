file(GLOB_RECURSE FOUNDATION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(Orange.Foundation ${FOUNDATION_SOURCES})

# public include directories
target_include_directories(Orange.Foundation
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)

# private include directories
target_include_directories(Orange.Foundation
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# public dependencies
target_link_libraries(Orange.Foundation
    PUBLIC
    Orange.Adapter
    spdlog
    Vulkan::Vulkan
)

# private dependencies
target_link_libraries(Orange.Foundation
    PRIVATE
    tinyxml2::tinyxml2
    RapidJSON
)
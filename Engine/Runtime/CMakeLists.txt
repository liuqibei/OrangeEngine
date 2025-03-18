file(GLOB_RECURSE RUNTIME_SOURCES "*.cpp" "*.hpp")

add_executable(OrangeEngine ${RUNTIME_SOURCES})

set(ORANGE_ENGINE_DENPENDENCIES
    SDL3::SDL3-shared
    spdlog::spdlog
)

target_link_libraries(OrangeEngine PRIVATE ${ORANGE_ENGINE_DENPENDENCIES})

target_include_directories(OrangeEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
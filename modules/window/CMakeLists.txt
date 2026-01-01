set(ORANGE_ENGINE_MODULE_WINDOW_BACKEND "GLFW" CACHE STRING "Orange Engine Module Window Backend")

message(STATUS "Orange Engine Module Window Backend: ${ORANGE_ENGINE_MODULE_WINDOW_BACKEND}")

file(GLOB_RECURSE ORANGE_ENGINE_MODULE_WINDOW_SOURCES "*.h" "*.cpp")

add_library("orange.window" SHARED ${ORANGE_ENGINE_MODULE_WINDOW_SOURCES})

target_link_libraries("orange.window" PRIVATE
	glfw
)

target_include_directories("orange.window" PUBLIC
	"${CMAKE_CURRENT_LIST_DIR}/include"
)

if (ORANGE_ENGINE_MODULE_WINDOW_BACKEND STREQUAL "GLFW")
	target_compile_definitions("orange.window" PRIVATE ORANGE_ENGINE_MODULE_WINDOW_BACKEND_GLFW)
else()
	message(FATAL_ERROR "Unsupported window backend: ${ORANGE_ENGINE_MODULE_WINDOW_BACKEND}")
endif()
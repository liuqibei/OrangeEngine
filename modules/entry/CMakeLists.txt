file(GLOB_RECURSE ORANGE_ENGINE_MODULE_ENTRY_SOURCES "*.h" "*.cpp")

add_executable("orange.entry" ${ORANGE_ENGINE_MODULE_ENTRY_SOURCES})

target_link_libraries("orange.entry" PRIVATE 
	"orange.window"
	glm::glm
	Vulkan::Vulkan
)
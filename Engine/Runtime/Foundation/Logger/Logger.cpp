#include "Logger.hpp"

namespace Orange {

static bool _ = Orange::SetupLogger();

bool SetupLogger()
{
    spdlog::set_pattern("[%H:%M:%S %z] [%^%l%$] [thread %t] %v");
    spdlog::set_level(spdlog::level::debug);
    return true;
}

} // namespace Orange
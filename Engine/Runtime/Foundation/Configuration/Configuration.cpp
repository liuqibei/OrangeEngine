#include "Configuration/IConfiguration.hpp"

namespace Orange {

std::shared_ptr<IConfiguration> IConfiguration::Create(ConfigurationBackend backend)
{
    return nullptr;
}

std::shared_ptr<IConfiguration> IConfiguration::Create(const Uri& uri)
{
    return nullptr;
}

} // namespace Orange
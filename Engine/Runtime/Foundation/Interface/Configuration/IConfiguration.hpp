#pragma once

#include <any>
#include <memory>

#include "Common/Uri.hpp"

namespace Orange {

enum class ConfigurationBackend {
    Json, // Json
    Xml   // Xml
};

class IConfiguration {
public:
    static std::shared_ptr<IConfiguration> Create(ConfigurationBackend backend);
    static std::shared_ptr<IConfiguration> Create(const Uri& uri);

    template<typename T>
    T Get(const std::string& path, const T& defaultValue = T()) const
    {
        auto value = Get(path);
        if (value.has_value() && value.type() == typeid(T)) {
            return std::any_cast<T>(value);
        }
        return defaultValue;
    }

    template<typename T>
    void Set(const std::string& path, const T& value)
    {
        Set(path, std::any(value));
    }

protected:
    virtual std::any Get(const std::string& path) const              = 0;
    virtual void Set(const std::string& path, const std::any& value) = 0;
};

} // namespace Orange
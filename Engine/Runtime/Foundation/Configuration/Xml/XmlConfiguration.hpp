#pragma once

#include <tinyxml2.h>

#include "Configuration/IConfiguration.hpp"

namespace Orange {

class XmlConfiguration : public IConfiguration {
protected:
    virtual std::any Get(const std::string& path) const override;
    virtual void Set(const std::string& path, const std::any& value) override;
};

} // namespace Orange
#pragma once

#include "SchemeType.hpp"

namespace Orange {

class Uri {
public:
    Uri() = default;
    Uri(const std::string& uri);

    bool IsValid() const
    {
        return !_uri.empty();
    }

    SchemeType GetScheme() const
    {
        return _scheme;
    }

    std::string GetUri() const
    {
        return _uri;
    }

private:
    std::string _uri;
    SchemeType _scheme;
};

} // namespace Orange
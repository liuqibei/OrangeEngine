#include "Common/Uri.hpp"

namespace Orange {

Uri::Uri(const std::string& uri)
{
    // Parse the URI to extract scheme and other components
    size_t schemeEnd = uri.find("://");
    if (schemeEnd != std::string::npos) {
        _scheme = String2SchemeType(uri.substr(0, schemeEnd));
        _uri    = uri.substr(schemeEnd + 3); // Skip "://"
    }
}

} // namespace Orange
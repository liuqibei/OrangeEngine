#include "Common/SchemeType.hpp"

#include <algorithm>
#include <unordered_map>

namespace Orange {

static const std::unordered_map<SchemeType, std::string> s_scheme2StringMap = {
    { SchemeType::Asset, "asset" }, // Asset
    { SchemeType::File, "file" },   // File
    { SchemeType::Http, "http" },   // Http
    { SchemeType::Https, "https" }, // Https
};

static const std::unordered_map<std::string, SchemeType> s_string2SchemeMap = {
    { "asset", SchemeType::Asset }, // Asset
    { "file", SchemeType::File },   // File
    { "http", SchemeType::Http },   // Http
    { "https", SchemeType::Https }, // Https
};

SchemeType String2SchemeType(const std::string& scheme)
{
    // ignore case
    std::string lowerScheme = scheme;
    std::transform(lowerScheme.begin(), lowerScheme.end(), lowerScheme.begin(), ::tolower);

    // find in map
    auto it = s_string2SchemeMap.find(lowerScheme);
    if (it != s_string2SchemeMap.end()) {
        return it->second;
    }
    return SchemeType::Unknown;
}

std::string SchemeType2String(SchemeType scheme)
{
    auto it = s_scheme2StringMap.find(scheme);
    if (it != s_scheme2StringMap.end()) {
        return it->second;
    }
    return "unknown";
}

} // namespace Orange
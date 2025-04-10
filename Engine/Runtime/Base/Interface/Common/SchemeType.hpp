#pragma once

#include <string>

namespace Orange {

enum class SchemeType {
    Unknown,
    Asset,
    File,
    Http,
    Https,
};

SchemeType String2SchemeType(const std::string& scheme);

std::string SchemeType2String(SchemeType scheme);

} // namespace Orange
#pragma once

#include <cstdint>

namespace Orange {

class Timestamp {
public:
    Timestamp(uint64_t start, uint64_t delta) : _start(start), _delta(delta) {}

    uint64_t GetStart() const
    {
        return _start;
    }

    uint64_t GetDelta() const
    {
        return _delta;
    }

private:
    uint64_t _start;
    uint64_t _delta;
};

} // namespace Orange
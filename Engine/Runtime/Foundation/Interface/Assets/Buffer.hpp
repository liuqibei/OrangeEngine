#pragma once

#include <cstdint>

namespace Orange {

class Buffer {
public:
    Buffer() = default;
    Buffer(uint8_t* data, uint64_t size) : _data(data), _size(size) {}

    Buffer(const Buffer&)            = delete;
    Buffer& operator=(const Buffer&) = delete;

    Buffer(Buffer&& other) noexcept : _data(other._data), _size(other._size)
    {
        other._data = nullptr;
        other._size = 0;
    }

    Buffer& operator=(Buffer&& other) noexcept
    {
        if (this != &other) {
            delete[] _data;
            _data       = other._data;
            _size       = other._size;
            other._data = nullptr;
            other._size = 0;
        }
        return *this;
    }

    uint8_t* GetData() const
    {
        return _data;
    }

    uint64_t GetSize() const
    {
        return _size;
    }

private:
    uint8_t* _data = nullptr;
    uint64_t _size = 0;
};

} // namespace Orange
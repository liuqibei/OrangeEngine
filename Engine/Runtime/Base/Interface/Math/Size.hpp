#pragma once

#include <cstdint>

namespace Orange {

template<typename T>
class Size {
public:
    static Size<T> Zero()
    {
        return Size<T>(0, 0);
    }

    Size() : _width(0), _height(0) {}
    Size(T width, T height) : _width(width), _height(height) {}

    T GetWidth() const
    {
        return _width;
    }

    T GetHeight() const
    {
        return _height;
    }

    void SetWidth(T width)
    {
        _width = width;
    }

    void SetHeight(T height)
    {
        _height = height;
    }

    void SetSize(T width, T height)
    {
        _width  = width;
        _height = height;
    }

    bool operator==(const Size<T>& other) const
    {
        return _width == other._width && _height == other._height;
    }

    bool operator!=(const Size<T>& other) const
    {
        return !(*this == other);
    }

    Size<T> operator+(const Size<T>& other) const
    {
        return Size<T>(_width + other._width, _height + other._height);
    }

    Size<T> operator-(const Size<T>& other) const
    {
        return Size<T>(_width - other._width, _height - other._height);
    }

private:
    T _width;
    T _height;
};

using SizeI = Size<int32_t>;
using SizeF = Size<float>;
using SizeD = Size<double>;

} // namespace Orange
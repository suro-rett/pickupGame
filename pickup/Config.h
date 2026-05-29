#pragma once
#define DEBUG false

namespace Config
{
    constexpr int ScreenWidth = 960;
    constexpr int ScreenHeight = 540;

    constexpr int ScreenFPS = 60;
}

namespace Math
{
    template<typename T>
    constexpr T Clamp(T v, T min, T max)
    {
        return (v < min) ? min : (v > max) ? max : v;
    }
}
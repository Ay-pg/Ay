/*
    @file Concepts.hpp
    @author Ay
    @date 2024/10/30
*/
#pragma once
#include <concepts>

namespace Ay {
    // @brief ®”Œ^§–ñ
    template <typename T>
    concept Integral = std::is_integral_v<T>;
    // @brief •‚“®¬”“_Œ^§–ñ
    template <typename T>
    concept Floating = std::is_floating_point_v<T>;
}

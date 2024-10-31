/*
    @file Concepts.hpp
    @author Ay
    @date 2024/10/31
*/
#pragma once
#include <concepts>

namespace Ay {
    // @brief �����^����
    template <typename T>
    concept Integral = std::is_integral_v<T>;
    // @brief ���������_�^����
    template <typename T>
    concept Floating = std::is_floating_point_v<T>;
    // @brief �Z�p�^����
    template <typename T>
    concept Arithmetic = Integral<T> || Floating<T>;
}

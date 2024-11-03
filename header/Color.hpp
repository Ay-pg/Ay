/*
    @file Color.hpp
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include <array>
#include "Utility.hpp"

namespace Ay {
    struct Color {
        uInt r; // 赤
        uInt g; // 緑
        uInt b; // 青
        uInt a; // 透明度

        static constexpr uInt MIN = 0u;   // 最小値
        static constexpr uInt MAX = 255u; // 最大値

        NODISCARD_CPP20 Color() noexcept = default;
        NODISCARD_CPP20 Color(const Color&) noexcept = default;

        NODISCARD_CPP20 constexpr Color(uInt r = 255u, uInt g = 255u, uInt b = 255u, uInt a = 255u)
            : r(std::clamp(r, MIN, MAX)), g(std::clamp(g, MIN, MAX)), b(std::clamp(b, MIN, MAX)), a(std::clamp(a, MIN, MAX)) {
        }
        // @return 16進数値にして返す
        NODISCARD constexpr uInt ToUInt() const noexcept {
            return (r << 16) | (g << 8) | b;
        }
        // @return color red
        NODISCARD static constexpr Color red() noexcept {
            return Color(255, 0, 0);
        }
        // @return color green
        NODISCARD static constexpr Color green() noexcept {
            return Color(0, 255, 0);
        }
        // @return color blue
        NODISCARD static constexpr Color blue() noexcept {
            return Color(0, 0, 255);
        }
        // @return color yellow
        NODISCARD static constexpr Color yellow() noexcept {
            return Color(255, 255, 0);
        }
        // @return color magenta
        NODISCARD static constexpr Color magenta() noexcept {
            return Color(255, 0, 255);
        }
        // @return color cyan
        NODISCARD static constexpr Color cyan() noexcept {
            return Color(0, 255, 255);
        }
        // @return color orange
        NODISCARD static constexpr Color orange() noexcept {
            return Color(255, 165, 0);
        }
        // @return color purple
        NODISCARD static constexpr Color purple() noexcept {
            return Color(128, 0, 128);
        }
        // @return color gray
        NODISCARD static constexpr Color gray() noexcept {
            return Color(125, 125, 125);
        }
        // @return color black
        NODISCARD static constexpr Color black() noexcept {
            return Color(0, 0, 0);
        }
        // @return color white
        NODISCARD static constexpr Color white() noexcept {
            return Color(255, 255, 255);
        }
    };
}

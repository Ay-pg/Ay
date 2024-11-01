/*
    @file Color.hpp
    @author Ay
    @date 2024/11/01
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

        NODISCARD_CPP20 constexpr Color(uInt r = 255u, uInt g = 255u, uInt b = 255u, uInt a = 255u) : r(r), g(g), b(b), a(a) {
            std::array<uInt, 4> rgba = { r,g,b,a };
            for (auto& col : rgba) {
                if (col < MIN || col > MAX) {
                    col = std::clamp(col, MIN, MAX);
                }
            }
        }
        // @return 16進数値にして返す
        NODISCARD constexpr uInt ToUInt() const noexcept {
            return (r << 16) | (g << 8) | b;
        }
        // @return 赤のカラーコード
        NODISCARD static constexpr uInt red() noexcept {
            return 0xff0000;
        }
        // @return 緑のカラーコード
        NODISCARD static constexpr uInt green() noexcept {
            return 0x00ff00;
        }
        // @return 青のカラーコード
        NODISCARD static constexpr uInt blue() noexcept {
            return 0x0000ff;
        }
        // @return 黄のカラーコード
        NODISCARD static constexpr uInt yellow() noexcept {
            return 0xffff00;
        }
        // @return マゼンタのカラーコード
        NODISCARD static constexpr uInt magenta() noexcept {
            return 0xff00ff;
        }
        // @return シアンのカラーコード
        NODISCARD static constexpr uInt cyan() noexcept {
            return 0x00ffff;
        }
        // @return オレンジのカラーコード
        NODISCARD static constexpr uInt orange() noexcept {
            0xffa500;
        }
        // @return パープルのカラーコード
        NODISCARD static constexpr uInt purple() noexcept {
            return 0x800080;
        }
        // @return グレーのカラーコード
        NODISCARD static constexpr uInt gray() noexcept {
            return 0x7d7d7d;
        }
        // @return 黒のカラーコード
        NODISCARD static constexpr uInt black() noexcept {
            return 0x000000;
        }
        // @return 白のカラーコード
        NODISCARD static constexpr uInt white() noexcept {
            return 0xffffff;
        }
    };
}

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
        uInt r; // ��
        uInt g; // ��
        uInt b; // ��
        uInt a; // �����x

        static constexpr uInt MIN = 0u;   // �ŏ��l
        static constexpr uInt MAX = 255u; // �ő�l

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
        // @return 16�i���l�ɂ��ĕԂ�
        NODISCARD constexpr uInt ToUInt() const noexcept {
            return (r << 16) | (g << 8) | b;
        }
        // @return �Ԃ̃J���[�R�[�h
        NODISCARD static constexpr uInt red() noexcept {
            return 0xff0000;
        }
        // @return �΂̃J���[�R�[�h
        NODISCARD static constexpr uInt green() noexcept {
            return 0x00ff00;
        }
        // @return �̃J���[�R�[�h
        NODISCARD static constexpr uInt blue() noexcept {
            return 0x0000ff;
        }
        // @return ���̃J���[�R�[�h
        NODISCARD static constexpr uInt yellow() noexcept {
            return 0xffff00;
        }
        // @return �}�[���^�̃J���[�R�[�h
        NODISCARD static constexpr uInt magenta() noexcept {
            return 0xff00ff;
        }
        // @return �V�A���̃J���[�R�[�h
        NODISCARD static constexpr uInt cyan() noexcept {
            return 0x00ffff;
        }
        // @return �I�����W�̃J���[�R�[�h
        NODISCARD static constexpr uInt orange() noexcept {
            0xffa500;
        }
        // @return �p�[�v���̃J���[�R�[�h
        NODISCARD static constexpr uInt purple() noexcept {
            return 0x800080;
        }
        // @return �O���[�̃J���[�R�[�h
        NODISCARD static constexpr uInt gray() noexcept {
            return 0x7d7d7d;
        }
        // @return ���̃J���[�R�[�h
        NODISCARD static constexpr uInt black() noexcept {
            return 0x000000;
        }
        // @return ���̃J���[�R�[�h
        NODISCARD static constexpr uInt white() noexcept {
            return 0xffffff;
        }
    };
}

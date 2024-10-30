/*
    @file Vector2.hpp
    @author Ay
    @date 2024/10/30
*/
#pragma once
#include <cmath>
#include <ostream>
#include <sstream>
#include <compare>
#include <string>
#include "Config.hpp"

namespace Ay {

    // @brief 2 �����̃x�N�g��
    struct Vector2 {
        float x; // �x�N�g���� x
        float y; // �x�N�g���� y

        NODISCARD_CPP20 Vector2() noexcept = default;

        NODISCARD_CPP20 Vector2(const Vector2&) noexcept = default;

        NODISCARD_CPP20 constexpr Vector2(float x, float y) : x(x), y(y) {
        }

        constexpr Vector2& operator = (const Vector2&) = default;

        NODISCARD constexpr Vector2 operator +() const noexcept {
            return *this;
        }

        NODISCARD constexpr Vector2 operator -() const noexcept {
            return Vector2(-x, -y);
        }

        NODISCARD constexpr Vector2 operator +(const Vector2& other) const noexcept {
            return Vector2(x + other.x, y + other.y);
        }

        NODISCARD constexpr Vector2 operator -(const Vector2& other) const noexcept {
            return Vector2(x - other.x, y - other.y);
        }

        NODISCARD constexpr Vector2 operator *(const Vector2& other) const noexcept {
            return Vector2(x * other.x, y * other.y);
        }

        NODISCARD constexpr Vector2 operator /(const Vector2& other) const noexcept {
            return Vector2(x / other.x, y / other.y);
        }

        NODISCARD constexpr Vector2 operator *(float other) const noexcept {
            return Vector2(x * other, y * other);
        }

        NODISCARD constexpr Vector2 operator /(float other) const noexcept {
            return Vector2(x / other, y / other);
        }

        Vector2& operator +=(const Vector2& other) noexcept {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2& operator -=(const Vector2& other) noexcept {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vector2& operator *=(const Vector2& other) noexcept {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        Vector2& operator /=(const Vector2& other) noexcept {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        Vector2& operator *=(float other) noexcept {
            x *= other;
            y *= other;
            return *this;
        }

        Vector2& operator /=(float other) noexcept {
            x /= other;
            y /= other;
            return *this;
        }

#if (__cplusplus >= CPP20)
        NODISCARD std::partial_ordering operator <=>(const Vector2& other) const noexcept {
            return Magnitude() <=> other.Magnitude();
        }
#else 
        NODISCARD bool operator <(const Vector2& other) const noexcept {
            return Magnitude() < other.Magnitude();
        }

        NODISCARD bool operator <=(const Vector2& other) const noexcept {
            return Magnitude() <= other.Magnitude();
        }

        NODISCARD bool operator >(const Vector2& other) const noexcept {
            return Magnitude() > other.Magnitude();
        }

        NODISCARD bool operator >=(const Vector2& other) const noexcept {
            return Magnitude() >= other.Magnitude();
        }
#endif
        NODISCARD bool operator !=(const Vector2& other) const noexcept {
            return Magnitude() != other.Magnitude();
        }

        NODISCARD bool operator ==(const Vector2& other) const noexcept {
            return Magnitude() == other.Magnitude();
        }

        Vector2& operator ++() noexcept {
            ++x;
            ++y;
            return *this;
        }

        Vector2& operator --() noexcept {
            --x;
            --y;
            return *this;
        }
        // @return x �� y �̗������[���ł���� true ��Ԃ�
        NODISCARD constexpr bool IsZero()const noexcept {
            return x == 0.f && y == 0.f;
        }
        // @return ���ς�Ԃ�
        NODISCARD constexpr float Dot(const Vector2& other) const noexcept {
            return x * other.x + y * other.y;
        }
        // @return �O�ς�Ԃ�
        NODISCARD constexpr float Cross(const Vector2& other) const noexcept {
            return x * other.y - y * other.x;
        }
        // @return �p�x��Ԃ�
        NODISCARD float Angle() const noexcept {
            return atan2(y, x);
        }
        // @return ������Ԃ�
        NODISCARD float Distance() const noexcept {
            return std::sqrt(Dot(*this));
        }
        // @return ������Ԃ�
        NODISCARD float Magnitude() const noexcept {
            return std::sqrt(MagnitudeSquare());
        }
        // @return ������2���Ԃ�
        NODISCARD float MagnitudeSquare() const noexcept {
            return x * x + y * y;
        }
        // @return ���K�����ꂽ�x�N�g����Ԃ�
        NODISCARD Vector2 Normalized() const noexcept {
            auto mag = Magnitude();
            if (IsZero()) {
                return Vector2::zero();
            }
            return Vector2(x / mag, y / mag);
        }
        // @return ���g�𐳋K������
        NODISCARD Vector2& Normalize() noexcept {
            auto mag = Magnitude();
            if (IsZero()) {
                return *this;
            }
            x /= mag;
            y /= mag;
            return *this;
        }
        // @return �I�t�Z�b�g���K�����ꂽ�x�N�g����Ԃ�
        NODISCARD constexpr Vector2 OffSet(float dx, float dy) {
            return Vector2(x + dx, y + dy);
        }
        // @return {0.f, 0.f}
        NODISCARD static constexpr Vector2 zero() noexcept {
            return Vector2(0.0f, 0.0f);
        }
        // @return {1.f, 1.f}
        NODISCARD static constexpr Vector2 one() noexcept {
            return Vector2(1.0f, 1.0f);
        }
        // @return {0.f, -1.f}
        NODISCARD static constexpr Vector2 up() noexcept {
            return Vector2(0.0f, -1.0f);
        }
        // @return {0.f, 1.f}
        NODISCARD static constexpr Vector2 down() noexcept {
            return Vector2(0.0f, 1.0f);
        }
        // @return {1.f, 0.f}
        NODISCARD static constexpr Vector2 right() noexcept {
            return Vector2(1.0f, 0.0f);
        }
        // @return {-1.f, 0.f}
        NODISCARD static constexpr Vector2 left() noexcept {
            return Vector2(-1.0f, 0.0f);
        }
        // @return ������ɕϊ����ĕ������Ԃ�
        NODISCARD std::string ToString() const noexcept {
            std::ostringstream os;
            os << *this;
            return os.str();
        }

        friend std::ostream& operator <<(std::ostream& os, const Vector2& vec) {
            return os << "Vector2(" << vec.x << "," << vec.y << ")";
        }
    };
}

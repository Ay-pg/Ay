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

    // @brief 2 次元のベクトル
    struct Vector2 {
        float x; // ベクトルの x
        float y; // ベクトルの y

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
        // @return x と y の両方がゼロであれば true を返す
        NODISCARD constexpr bool IsZero()const noexcept {
            return x == 0.f && y == 0.f;
        }
        // @return 内積を返す
        NODISCARD constexpr float Dot(const Vector2& other) const noexcept {
            return x * other.x + y * other.y;
        }
        // @return 外積を返す
        NODISCARD constexpr float Cross(const Vector2& other) const noexcept {
            return x * other.y - y * other.x;
        }
        // @return 角度を返す
        NODISCARD float Angle() const noexcept {
            return atan2(y, x);
        }
        // @return 距離を返す
        NODISCARD float Distance() const noexcept {
            return std::sqrt(Dot(*this));
        }
        // @return 長さを返す
        NODISCARD float Magnitude() const noexcept {
            return std::sqrt(MagnitudeSquare());
        }
        // @return 長さの2乗を返す
        NODISCARD float MagnitudeSquare() const noexcept {
            return x * x + y * y;
        }
        // @return 正規化されたベクトルを返す
        NODISCARD Vector2 Normalized() const noexcept {
            auto mag = Magnitude();
            if (IsZero()) {
                return Vector2::zero();
            }
            return Vector2(x / mag, y / mag);
        }
        // @return 自身を正規化する
        NODISCARD Vector2& Normalize() noexcept {
            auto mag = Magnitude();
            if (IsZero()) {
                return *this;
            }
            x /= mag;
            y /= mag;
            return *this;
        }
        // @return オフセットが適応されたベクトルを返す
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
        // @return 文字列に変換して文字列を返す
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

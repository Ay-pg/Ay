/*
    @file Transform.hpp
    @brief 位置、スケール、角度の管理
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include <tuple>
#include <ostream>
#include "Component.hpp"
#include "Vector2.hpp"

namespace Ay {
    // @brief 位置、スケール、角度の管理
    class Transform final : public Component {
    private:
        Vector2 position; // 座標
        double scale;     // スケール
        double angle;     // 角度
    public:
        // @brief コンストラクタ
        NODISCARD_CPP20 Transform(std::shared_ptr<GameObject> owner)
            : Component(owner), position(Vector2::zero()), scale(0.f), angle(0.f) {
            Ready();
        }
        // @brief デフォルトデストラクタ
        virtual ~Transform() = default;
        // @brief 初期化処理
        virtual void Ready() noexcept override {
            SetOrder(OrderList::TRANSFORM);
        }
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) override {
        }
        // @brief 描画処理
        virtual void Draw() const override {
        }
        // @brief 座標をセットする
        // @brief other セットしたい座標
        void SetPosition(const Vector2& other) noexcept {
            position = other;
        }
        // @return 座標を返す
        NODISCARD Vector2 GetPosition() const noexcept {
            return position;
        }
        // @brief スケールをセットする
        // @brief other セットしたいスケール
        void SetScale(double other) noexcept {
            scale = other;
        }
        // @return スケールを返す
        NODISCARD double GetScale() const noexcept {
            return scale;
        }
        // @brief 角度をセットする
        // @param セットしたい角度
        void SetAngle(double other) noexcept {
            angle = other;
        }
        // @return  位置、スケール、角度を返す
        NODISCARD std::tuple<Vector2, double, double> GetInfo() const noexcept {
            return std::make_tuple(position, scale, angle);
        }
        // @return 文字列に変換して文字列を返す
        NODISCARD string ToString() const noexcept {
            std::ostringstream os;
            os << *this;
            return os.str();
        }

        friend std::ostream& operator <<(std::ostream& os, const Transform& transform) {
            return os << "Transform(" << transform.position.ToString() << "," << transform.scale << "," << transform.angle << ")";
        }
    };
}

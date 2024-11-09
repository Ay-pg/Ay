/*
    @file Component.hpp
    @brief コンポーネントの基底クラス
    @author Ay
    @date 2024/11/07
*/
#pragma once
#include "Object.hpp"
#include "Utility.hpp"

namespace Ay {
    namespace OrderList {
        constexpr int32 TRANSFORM = 1; // Transform (1)
        constexpr int32 TEXT = 2;      // Text (2)
    }
    class GameObject;
    // @class Component
    // @brief コンポーネントの基底クラス
    class Component : public Object {
    protected:
        std::shared_ptr<GameObject> owner; // オーナー
        int32 order = 0; // 優先度
    public:
        // @brief デフォルトコンストラクタ
        NODISCARD_CPP20 Component() noexcept = default;
        // @brief コンストラクタ
        NODISCARD_CPP20 Component(std::shared_ptr<GameObject> owner) noexcept
            : Object(typeid(Component).name()), owner(owner) {
        }
        // @brief デフォルトデストラクタ
        virtual ~Component() noexcept = default;
        // @brief 初期化処理
        virtual void Ready() = 0;
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) = 0;
        // @brief 描画処理
        virtual void Draw() const = 0;
        // @brief 優先度をセットする
        void SetOrder(int32 other) noexcept {
            order = other;
        }
        // @return 優先度を返す 
        NODISCARD int32 GetOrder() const noexcept {
            return order;
        }
    };
}

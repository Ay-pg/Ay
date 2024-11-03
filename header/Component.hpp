/*
    @file Component.hpp
    @brief コンポーネントの基底クラス
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include "Utility.hpp"

namespace Ay {
    namespace OrderList {
        constexpr int32 TRANSFORM = 1; // Transform (1)
        constexpr int32 TEXT = 2;      // Text (2)
    }
    class Object;
    // @class Component
    // @brief コンポーネントの基底クラス
    class Component {
    protected:
        Object* owner = nullptr; // オーナー
        int32 order = 0; // 優先度
    public:
        // @brief デフォルトデストラクタ
        virtual ~Component() noexcept = default;
        // @brief 初期化処理
        virtual void Ready() = 0;
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) = 0;
        // @brief 描画処理
        virtual void Draw() const = 0;
        // @brief オーナーをセットする
        void SetOwner(Object* other) noexcept {
            owner = other;
        }
        // @return オーナーを返す
        NODISCARD Object* GetOwner() const noexcept {
            return owner;
        }
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

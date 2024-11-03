/*
    @file GameObject.hpp
    @brief ゲームオブジェクトの基底クラス
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include "Object.hpp"

namespace Ay {
    // @brief ゲームオブジェクトの基底クラス
    class GameObject : public Object {
    private:
        static uInt createCount;
    protected:
        uInt id; // オブジェクトID
    public:
        // @brief コンストラクタ
        NODISCARD_CPP20 GameObject() noexcept = default;
        // @brief コンストラクタ
        // @param name ゲームオブジェクトの名前
        NODISCARD_CPP20 GameObject(stringView name) noexcept;
        // @brief デフォルトデストラクタ
        virtual ~GameObject() = default;
        // @brief 初期化処理
        virtual void Ready() override;
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) override;
        // @brief 描画処理
        virtual void Draw() const override;
        // @brief オブジェクトIDをセットする
        // @param other セットしたいゲームオブジェクトID
        void SetID(uInt other) noexcept {
            id = other;
        }
        // @return ゲームオブジェクトIDを返す
        NODISCARD uInt GetID() const noexcept {
            return id;
        }
    };
}

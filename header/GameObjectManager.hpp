/*
    @file GameObjectManager.hpp
    @brief ゲームオブジェクトを管理
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "GameObject.hpp"

namespace Ay {
    // @brief ゲームオブジェクトを管理
    class GameObjectManager final {
    protected:
        std::vector<std::shared_ptr<GameObject>> objects; // 所持しているオブジェクト
    public:
        // @brief コンストラクタ
        NODISCARD_CPP20 GameObjectManager() noexcept;
        // @brief デストラクタ
        ~GameObjectManager() noexcept = default;
        // @brief 初期化処理
        void Ready();
        // @brief 更新処理
        // @brief deltaTime 経過時間
        void Update(float deltaTime);
        // @brief 描画処理
        void Draw() const;
        // @brief オブジェクトを追加
        void AddObject(std::shared_ptr<GameObject> object) noexcept;
        // @brief 指定したオブジェクトを消す
        // @param name 消すオブジェクトの名前
        void DeleteObject(stringView name) noexcept;
        // @brief 指定したオブジェクトを探す
        // @brief name 探したいオブジェクトの名前
        NODISCARD std::shared_ptr<GameObject> FindObject(stringView name) noexcept;
        // @brief 指定したオブジェクトを探す
        // @brief id 探したいオブジェクトのID
        NODISCARD std::shared_ptr<GameObject> FindObject(uInt id) noexcept;
    };
}

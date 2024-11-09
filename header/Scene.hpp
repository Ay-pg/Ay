/*
    @file Scene.hpp
    @brief シーンの基底クラス
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "SceneManager.hpp"
#include "GameObjectManager.hpp"

namespace Ay {
    // @brief シーンの基底クラス
    class Scene {
    protected:
        string sceneName; // シーン名
        SceneManager& sceneManager; // シーンを管理
        std::unique_ptr<GameObjectManager> gameObjectManager; // ゲームオブジェクトを管理
    public:
        // @brief コンストラクタ
        // @brief sceneName シーン名(任意で指定。指定されていない場合は class 名)
        NODISCARD_CPP20 Scene(std::optional<stringView> sceneName = std::nullopt) noexcept 
            : sceneManager(SceneManager::GetInstance()){
            this->sceneName = sceneName.value_or(typeid(this).name());
        }
        // @brief デストラクタ
        virtual ~Scene() noexcept = default;
        // @brief 初期化処理
        virtual void Ready() = 0;
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) = 0;
        // @brief 描画処理
        virtual void Draw() const = 0;
    };
}

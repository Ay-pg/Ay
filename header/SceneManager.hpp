/*
    @file SceneManager.hpp
    @brief シーンを管理
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include <stack>
#include "Utility.hpp"

namespace Ay {
    class Scene;
    // @brief シーンを管理
    class SceneManager final {
    private:
        NODISCARD_CPP20 SceneManager() noexcept = default;
        ~SceneManager() noexcept = default;
        SceneManager(const SceneManager&) = delete;
        SceneManager(SceneManager&&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        SceneManager& operator=(SceneManager&&) = delete;
    public:
        NODISCARD static SceneManager& GetInstance() noexcept {
            static SceneManager instance;
            return instance;
        }
    private:
        std::stack<std::shared_ptr<Scene>> scene; // 現在のシーン
    public:
        // @brief 初期化処理
        void Ready();
        // @brief 更新処理
        // @param deltaTime 経過時間
        void Update(float deltaTime);
        // @brief 更新処理
        void Draw() const;
        // @brief シーン遷移
        // @param scene 遷移先のポインタ
        void LoadScene(std::shared_ptr<Scene> scene);
        // @brief シーンを追加
        // @param scene 追加するシーンのポインタ
        void AddScene(std::shared_ptr<Scene> scene);
        // @brief 現在のシーンを削除
        void DeleteScene();
    };
}

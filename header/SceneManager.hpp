/*
    @file SceneManager.hpp
    @brief �V�[�����Ǘ�
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include <stack>
#include "Utility.hpp"

namespace Ay {
    class Scene;
    // @brief �V�[�����Ǘ�
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
        std::stack<std::shared_ptr<Scene>> scene; // ���݂̃V�[��
    public:
        // @brief ����������
        void Ready();
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        void Update(float deltaTime);
        // @brief �X�V����
        void Draw() const;
        // @brief �V�[���J��
        // @param scene �J�ڐ�̃|�C���^
        void LoadScene(std::shared_ptr<Scene> scene);
        // @brief �V�[����ǉ�
        // @param scene �ǉ�����V�[���̃|�C���^
        void AddScene(std::shared_ptr<Scene> scene);
        // @brief ���݂̃V�[�����폜
        void DeleteScene();
    };
}

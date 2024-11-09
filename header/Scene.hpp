/*
    @file Scene.hpp
    @brief �V�[���̊��N���X
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "SceneManager.hpp"
#include "GameObjectManager.hpp"

namespace Ay {
    // @brief �V�[���̊��N���X
    class Scene {
    protected:
        string sceneName; // �V�[����
        SceneManager& sceneManager; // �V�[�����Ǘ�
        std::unique_ptr<GameObjectManager> gameObjectManager; // �Q�[���I�u�W�F�N�g���Ǘ�
    public:
        // @brief �R���X�g���N�^
        // @brief sceneName �V�[����(�C�ӂŎw��B�w�肳��Ă��Ȃ��ꍇ�� class ��)
        NODISCARD_CPP20 Scene(std::optional<stringView> sceneName = std::nullopt) noexcept 
            : sceneManager(SceneManager::GetInstance()){
            this->sceneName = sceneName.value_or(typeid(this).name());
        }
        // @brief �f�X�g���N�^
        virtual ~Scene() noexcept = default;
        // @brief ����������
        virtual void Ready() = 0;
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) = 0;
        // @brief �`�揈��
        virtual void Draw() const = 0;
    };
}

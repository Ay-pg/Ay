/*
    @file GameObjectManager.hpp
    @brief �Q�[���I�u�W�F�N�g���Ǘ�
    @author Ay
    @date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "GameObject.hpp"

namespace Ay {
    // @brief �Q�[���I�u�W�F�N�g���Ǘ�
    class GameObjectManager final {
    protected:
        std::vector<std::shared_ptr<GameObject>> objects; // �������Ă���I�u�W�F�N�g
    public:
        // @brief �R���X�g���N�^
        NODISCARD_CPP20 GameObjectManager() noexcept;
        // @brief �f�X�g���N�^
        ~GameObjectManager() noexcept = default;
        // @brief ����������
        void Ready();
        // @brief �X�V����
        // @brief deltaTime �o�ߎ���
        void Update(float deltaTime);
        // @brief �`�揈��
        void Draw() const;
        // @brief �I�u�W�F�N�g��ǉ�
        void AddObject(std::shared_ptr<GameObject> object) noexcept;
        // @brief �w�肵���I�u�W�F�N�g������
        // @param name �����I�u�W�F�N�g�̖��O
        void DeleteObject(stringView name) noexcept;
        // @brief �w�肵���I�u�W�F�N�g��T��
        // @brief name �T�������I�u�W�F�N�g�̖��O
        NODISCARD std::shared_ptr<GameObject> FindObject(stringView name) noexcept;
        // @brief �w�肵���I�u�W�F�N�g��T��
        // @brief id �T�������I�u�W�F�N�g��ID
        NODISCARD std::shared_ptr<GameObject> FindObject(uInt id) noexcept;
    };
}

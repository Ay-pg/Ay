/*
    @file GameObject.hpp
    @brief �Q�[���I�u�W�F�N�g�̊��N���X
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include "Object.hpp"

namespace Ay {
    // @brief �Q�[���I�u�W�F�N�g�̊��N���X
    class GameObject : public Object {
    private:
        static uInt createCount;
    protected:
        uInt id; // �I�u�W�F�N�gID
    public:
        // @brief �R���X�g���N�^
        NODISCARD_CPP20 GameObject() noexcept = default;
        // @brief �R���X�g���N�^
        // @param name �Q�[���I�u�W�F�N�g�̖��O
        NODISCARD_CPP20 GameObject(stringView name) noexcept;
        // @brief �f�t�H���g�f�X�g���N�^
        virtual ~GameObject() = default;
        // @brief ����������
        virtual void Ready() override;
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) override;
        // @brief �`�揈��
        virtual void Draw() const override;
        // @brief �I�u�W�F�N�gID���Z�b�g����
        // @param other �Z�b�g�������Q�[���I�u�W�F�N�gID
        void SetID(uInt other) noexcept {
            id = other;
        }
        // @return �Q�[���I�u�W�F�N�gID��Ԃ�
        NODISCARD uInt GetID() const noexcept {
            return id;
        }
    };
}

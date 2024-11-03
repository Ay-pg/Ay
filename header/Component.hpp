/*
    @file Component.hpp
    @brief �R���|�[�l���g�̊��N���X
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
    // @brief �R���|�[�l���g�̊��N���X
    class Component {
    protected:
        Object* owner = nullptr; // �I�[�i�[
        int32 order = 0; // �D��x
    public:
        // @brief �f�t�H���g�f�X�g���N�^
        virtual ~Component() noexcept = default;
        // @brief ����������
        virtual void Ready() = 0;
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) = 0;
        // @brief �`�揈��
        virtual void Draw() const = 0;
        // @brief �I�[�i�[���Z�b�g����
        void SetOwner(Object* other) noexcept {
            owner = other;
        }
        // @return �I�[�i�[��Ԃ�
        NODISCARD Object* GetOwner() const noexcept {
            return owner;
        }
        // @brief �D��x���Z�b�g����
        void SetOrder(int32 other) noexcept {
            order = other;
        }
        // @return �D��x��Ԃ� 
        NODISCARD int32 GetOrder() const noexcept {
            return order;
        }
    };
}

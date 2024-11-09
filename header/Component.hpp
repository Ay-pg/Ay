/*
    @file Component.hpp
    @brief �R���|�[�l���g�̊��N���X
    @author Ay
    @date 2024/11/07
*/
#pragma once
#include "Object.hpp"
#include "Utility.hpp"

namespace Ay {
    namespace OrderList {
        constexpr int32 TRANSFORM = 1; // Transform (1)
        constexpr int32 TEXT = 2;      // Text (2)
    }
    class GameObject;
    // @class Component
    // @brief �R���|�[�l���g�̊��N���X
    class Component : public Object {
    protected:
        std::shared_ptr<GameObject> owner; // �I�[�i�[
        int32 order = 0; // �D��x
    public:
        // @brief �f�t�H���g�R���X�g���N�^
        NODISCARD_CPP20 Component() noexcept = default;
        // @brief �R���X�g���N�^
        NODISCARD_CPP20 Component(std::shared_ptr<GameObject> owner) noexcept
            : Object(typeid(Component).name()), owner(owner) {
        }
        // @brief �f�t�H���g�f�X�g���N�^
        virtual ~Component() noexcept = default;
        // @brief ����������
        virtual void Ready() = 0;
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) = 0;
        // @brief �`�揈��
        virtual void Draw() const = 0;
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

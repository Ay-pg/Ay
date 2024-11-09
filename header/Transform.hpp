/*
    @file Transform.hpp
    @brief �ʒu�A�X�P�[���A�p�x�̊Ǘ�
    @author Ay
    @date 2024/11/03
*/
#pragma once
#include <tuple>
#include <ostream>
#include "Component.hpp"
#include "Vector2.hpp"

namespace Ay {
    // @brief �ʒu�A�X�P�[���A�p�x�̊Ǘ�
    class Transform final : public Component {
    private:
        Vector2 position; // ���W
        double scale;     // �X�P�[��
        double angle;     // �p�x
    public:
        // @brief �R���X�g���N�^
        NODISCARD_CPP20 Transform(std::shared_ptr<GameObject> owner)
            : Component(owner), position(Vector2::zero()), scale(0.f), angle(0.f) {
            Ready();
        }
        // @brief �f�t�H���g�f�X�g���N�^
        virtual ~Transform() = default;
        // @brief ����������
        virtual void Ready() noexcept override {
            SetOrder(OrderList::TRANSFORM);
        }
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) override {
        }
        // @brief �`�揈��
        virtual void Draw() const override {
        }
        // @brief ���W���Z�b�g����
        // @brief other �Z�b�g���������W
        void SetPosition(const Vector2& other) noexcept {
            position = other;
        }
        // @return ���W��Ԃ�
        NODISCARD Vector2 GetPosition() const noexcept {
            return position;
        }
        // @brief �X�P�[�����Z�b�g����
        // @brief other �Z�b�g�������X�P�[��
        void SetScale(double other) noexcept {
            scale = other;
        }
        // @return �X�P�[����Ԃ�
        NODISCARD double GetScale() const noexcept {
            return scale;
        }
        // @brief �p�x���Z�b�g����
        // @param �Z�b�g�������p�x
        void SetAngle(double other) noexcept {
            angle = other;
        }
        // @return  �ʒu�A�X�P�[���A�p�x��Ԃ�
        NODISCARD std::tuple<Vector2, double, double> GetInfo() const noexcept {
            return std::make_tuple(position, scale, angle);
        }
        // @return ������ɕϊ����ĕ������Ԃ�
        NODISCARD string ToString() const noexcept {
            std::ostringstream os;
            os << *this;
            return os.str();
        }

        friend std::ostream& operator <<(std::ostream& os, const Transform& transform) {
            return os << "Transform(" << transform.position.ToString() << "," << transform.scale << "," << transform.angle << ")";
        }
    };
}

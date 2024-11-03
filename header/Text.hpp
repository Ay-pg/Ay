/*
    @file Text.hpp
    @brief �e�L�X�g��\��
    @author Ay
    @date 2024/11/04
*/
#pragma once
#include "Component.hpp"
#include "Color.hpp"
#include "Vector2.hpp"

namespace Ay {
    // @brief �e�L�X�g��\��
    class Text final : public Component {
    private:
        Vector2 size; // �e�L�X�g�T�C�Y
        Vector2 pos;  // ���W
        string text;  // �\�����镶����
        string font;  // �t�H���g��
        Color color;  // �F
    public:
        // @brief �R���X�g���N�^
        NODISCARD_CPP20 constexpr Text() noexcept;
        // @brief �f�X�g���N�^
        virtual ~Text() = default;
        // @brief ����������
        virtual void Ready() override;
        // @brief �X�V����
        // @param deltaTime �o�ߎ���
        virtual void Update(float deltaTime) override {
        }
        // @brief �`�揈��
        virtual void Draw() const override;
        // @brief �e�L�X�g�̈ʒu�A���e�A�t�H���g�A�F��ݒ肷��
        // @param pos �e�L�X�g�̕\���ʒu���w�肷��x�N�g��
        // @param text �\������e�L�X�g�̓��e
        // @param font �t�H���g��
        // @param color �e�L�X�g�̐F���w�肷��I�u�W�F�N�g
        void SetInfo(const Vector2& pos, stringView text, stringView font, const Color& color);
    };
}

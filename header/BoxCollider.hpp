/*
  @file BoxCollider.hpp
  @brief �����蔻��̘g
  @author Ay
  @date 2024/11/08
*/
#pragma once
#include "Component.hpp"
#include "Vector2.hpp"

namespace Ay {
	// @brief �����蔻��̘g
	class BoxCollider final : public Component {
	private:
		bool collision; // �Փˏ��
		Vector2 pos;    // ���W
		Vector2 size;   // �T�C�Y 
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 BoxCollider() noexcept;
		// @brief �f�X�g���N�^
		virtual ~BoxCollider() = default;
		// @brief ����������
		virtual void Ready() noexcept override;
		// @brief �X�V����
		// @param deltaTime �o�ߎ���
		virtual void Update(float deltaTime) override {
		}
		// @brief �`�揈��
		virtual void Draw() const override {
		}
		// @brief �K�v�ȏ����Z�b�g
		// @param pos ���W
		// @param size �摜�̃T�C�Y
		void SetInfo(const Vector2& pos, const Vector2& size) {

		}
		// @brief �Փˏ�Ԃ��Z�b�g
		// @param other �Z�b�g������
		void SetCollision(bool other) noexcept {
			collision = other;
		}
		// @return �Փˏ�Ԃ�Ԃ�
		NODISCARD bool GetCollision() const noexcept {
			return collision;
		}
	};
#ifndef COLL_COMP
	#define COLL_COMP 
#endif 
}

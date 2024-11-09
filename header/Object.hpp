/*
	@file Object.hpp
	@brief �I�u�W�F�N�g�̊��N���X
	@author Ay
	@date 2024/11/07
*/
#pragma once
#include "Utility.hpp"

namespace Ay {
	// @brief �I�u�W�F�N�g�̊��N���X
	class Object {
	private:
		static int32 createCount; // �I�u�W�F�N�g���������ꂽ��
	protected:
		uInt id;     // �I�u�W�F�N�gid
		string name; // �I�u�W�F�N�g��
	public:
		// @brief �f�t�H���g�R���X�g���N�^
		NODISCARD_CPP20 Object() noexcept = default;
		// @brief �R���X�g���N�^
		// @param name �I�u�W�F�N�g�̖��O
		NODISCARD_CPP20 Object(stringView name) noexcept;
		// @brief �f�X�g���N�^
		virtual ~Object() noexcept = default;
		// @brief ����������
		virtual void Ready() = 0;
		// @brief �X�V����
		// @param deltaTime �o�ߎ���
		virtual void Update(float deltaTime) = 0;
		// @brief �`�揈��
		virtual void Draw() const = 0;
		// @brief �I�u�W�F�N�g�̖��O���Z�b�g����
		// @brief name �Z�b�g���閼�O
		void SetName(stringView name) noexcept {
			this->name = name;
		}
		// @return �I�u�W�F�N�g�̖��O��Ԃ�
		NODISCARD const string& GetName() const noexcept {
			return name;
		}
		// @brief �I�u�W�F�N�gID���Z�b�g����
		// @param other �Z�b�g�������I�u�W�F�N�gID
		void SetID(uInt other) noexcept {
			id = other;
		}
		// @return �I�u�W�F�N�gID��Ԃ�
		NODISCARD uInt GetID() const noexcept {
			return id;
		}
		// �I�u�W�F�N�g�𐶐�������
		static NODISCARD uInt GetCreateCount() noexcept {
			return createCount;
		}
	};
}

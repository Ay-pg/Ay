/*
	@file Object.hpp
	@brief �I�u�W�F�N�g�̊��N���X
	@author Ay
	@date 2024/11/03
*/
#pragma once
#include <typeindex>
#include "Utility.hpp"
#include "Component.hpp"
#include "Transform.hpp"

namespace Ay {
	class Object {
	protected:
		string name;   // �I�u�W�F�N�g��
		bool IsActive; // �A�N�e�B�u��?
		std::unordered_map<std::type_index, std::shared_ptr<Component>> components; // �I�u�W�F�N�g���������Ă��� Component
		std::vector<std::shared_ptr<Component>> ordered; // �\�[�g�ς݂�Component
		std::shared_ptr<Transform> transform; // Component Transform
		// TODO: �ǉ�Component-> Sprite
	public:
		// @brief �f�t�H���g�R���X�g���N�^
		NODISCARD_CPP20 Object() noexcept = default;
		// @brief �R���X�g���N�^
		// @param name �I�u�W�F�N�g�̖��O
		NODISCARD_CPP20 explicit constexpr Object(stringView name) noexcept;
		// @brief �f�X�g���N�^
		virtual ~Object() noexcept = default;
		// @brief ����������
		virtual void Ready();
		// @brief �X�V����
		// @param deltaTime �o�ߎ���
		virtual void Update(float deltaTime);
		// @brief �`�揈��
		virtual void Draw() const;
		// @brief �I�u�W�F�N�g�̃A�N�e�B�u��Ԃ��Z�b�g
		// @param value �Z�b�g������
		void SetActive(bool value) noexcept {
			IsActive = value;
		}
		// @return �I�u�W�F�N�g�̃A�N�e�B�u��Ԃ�Ԃ�
		NODISCARD bool GetActive() const noexcept {
			return IsActive;
		}
		// @brief �I�u�W�F�N�g�̖��O���Z�b�g����
		// @brief name �Z�b�g���閼�O
		void SetName(stringView name) noexcept {
			this->name = name;
		}
		// @return �I�u�W�F�N�g�̖��O��Ԃ�
		NODISCARD const string& GetName() const noexcept {
			return name;
		}
		// @brief �w�肵�� Component ��ǉ�����
		// @return �ǉ����� Component ��Ԃ�
		template <typename T>
		std::weak_ptr<T> AddComponent() noexcept {
			auto comp = std::make_shared<T>();
			components[typeid(T)] = comp;

			auto it = std::lower_bound(
				ordered.begin(),
				ordered.end(),
				comp,
				[](const std::shared_ptr<Component>& comp1, const std::shared_ptr<Component>& comp2) {
					return comp1->GetOrder() > comp2->GetOrder();
				}
			);
			return comp;
		}
		// @return �w�肵�� Component���擾
		template <typename T>
		NODISCARD std::shared_ptr<T> GetComponent() const noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				return std::static_pointer_cast<T>(it->second);
			}
			return nullptr;
		}
		// @brief �w�肵�� Component���폜
		template <typename T>
		void RemoveComponent() noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				components.erase(it);
			}
		}
	};
}
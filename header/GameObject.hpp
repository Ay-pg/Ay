/*
	@file GameObject.hpp
	@brief �Q�[���I�u�W�F�N�g�̊��N���X
	@author Ay
	@date 2024/11/07
*/
#pragma once
#include <typeindex>
#include "Object.hpp"
#include "Transform.hpp"

namespace Ay {
	// @brief �Q�[���I�u�W�F�N�g�̊��N���X
	class GameObject : public Object, public std::enable_shared_from_this<GameObject> {
	private:

	protected:
		std::unordered_map<std::type_index, std::shared_ptr<Component>> components; // �������Ă��� Component
		std::vector<std::shared_ptr<Component>> orderComponents; // �\�[�g�ς݂� Component
		bool IsActive; // �A�N�e�B�u���
		std::shared_ptr<Transform> transform; // Component Transform
		// TODO: Component Sprite��ǉ�
	public:
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 GameObject(stringView name) noexcept;
		// @brief �f�X�g���N�^
		virtual ~GameObject() = default;
		// @brief ����������
		virtual void Ready();
		// @brief �X�V����
		// @param deltaTime �o�ߎ���
		virtual void Update(float deltaTime);
		// @brief �`�揈��
		virtual void Draw() const;
		// @brief �I�u�W�F�N�g�̃A�N�e�B�u��Ԃ�ݒ�
		// @param other �Z�b�g������
		void SetActive(bool other) {
			IsActive = other;
		}
		// @return �I�u�W�F�N�g�̃A�N�e�B�u��Ԃ�Ԃ�
		bool GetActive()const {
			return IsActive;
		}
#ifdef COLL_COMP
		virtual void OnCollision(std::shared_ptr<GameObject> other) = 0;
#endif
		// @brief �w�肵�� Component ��ǉ�����
		// @return �ǉ����� Component ��Ԃ�
		template <typename T>
		std::shared_ptr<T> AddComponent() noexcept {
			auto comp = std::make_shared<T>(shared_from_this());
			components[typeid(T)] = comp;

			auto it = std::lower_bound(
				orderComponents.begin(),
				orderComponents.end(),
				comp,
				[](const std::shared_ptr<Component>& comp1, const std::shared_ptr<Component>& comp2) {
					return comp1->GetOrder() > comp2->GetOrder();
				}
			);
			orderComponents.insert(it, comp);
			return comp;
		}
		// @return �w�肵�� Component ���擾
		template <typename T>
		NODISCARD std::shared_ptr<T> GetComponent() const noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				return std::static_pointer_cast<T>(it->second);
			}
			return nullptr;
		}
		// @brief �w�肵�� Component ���폜
		template <typename T>
		void RemoveComponent() noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				components.erase(it);
			}
		}
	};
}

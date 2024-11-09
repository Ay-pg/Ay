/*
	@file GameObject.hpp
	@brief ゲームオブジェクトの基底クラス
	@author Ay
	@date 2024/11/07
*/
#pragma once
#include <typeindex>
#include "Object.hpp"
#include "Transform.hpp"

namespace Ay {
	// @brief ゲームオブジェクトの基底クラス
	class GameObject : public Object, public std::enable_shared_from_this<GameObject> {
	private:

	protected:
		std::unordered_map<std::type_index, std::shared_ptr<Component>> components; // 所持している Component
		std::vector<std::shared_ptr<Component>> orderComponents; // ソート済みの Component
		bool IsActive; // アクティブ状態
		std::shared_ptr<Transform> transform; // Component Transform
		// TODO: Component Spriteを追加
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 GameObject(stringView name) noexcept;
		// @brief デストラクタ
		virtual ~GameObject() = default;
		// @brief 初期化処理
		virtual void Ready();
		// @brief 更新処理
		// @param deltaTime 経過時間
		virtual void Update(float deltaTime);
		// @brief 描画処理
		virtual void Draw() const;
		// @brief オブジェクトのアクティブ状態を設定
		// @param other セットする状態
		void SetActive(bool other) {
			IsActive = other;
		}
		// @return オブジェクトのアクティブ状態を返す
		bool GetActive()const {
			return IsActive;
		}
#ifdef COLL_COMP
		virtual void OnCollision(std::shared_ptr<GameObject> other) = 0;
#endif
		// @brief 指定した Component を追加する
		// @return 追加した Component を返す
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
		// @return 指定した Component を取得
		template <typename T>
		NODISCARD std::shared_ptr<T> GetComponent() const noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				return std::static_pointer_cast<T>(it->second);
			}
			return nullptr;
		}
		// @brief 指定した Component を削除
		template <typename T>
		void RemoveComponent() noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				components.erase(it);
			}
		}
	};
}

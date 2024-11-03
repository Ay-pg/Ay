/*
	@file Object.hpp
	@brief オブジェクトの基底クラス
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
		string name;   // オブジェクト名
		bool IsActive; // アクティブか?
		std::unordered_map<std::type_index, std::shared_ptr<Component>> components; // オブジェクトが所持している Component
		std::vector<std::shared_ptr<Component>> ordered; // ソート済みのComponent
		std::shared_ptr<Transform> transform; // Component Transform
		// TODO: 追加Component-> Sprite
	public:
		// @brief デフォルトコンストラクタ
		NODISCARD_CPP20 Object() noexcept = default;
		// @brief コンストラクタ
		// @param name オブジェクトの名前
		NODISCARD_CPP20 explicit constexpr Object(stringView name) noexcept;
		// @brief デストラクタ
		virtual ~Object() noexcept = default;
		// @brief 初期化処理
		virtual void Ready();
		// @brief 更新処理
		// @param deltaTime 経過時間
		virtual void Update(float deltaTime);
		// @brief 描画処理
		virtual void Draw() const;
		// @brief オブジェクトのアクティブ状態をセット
		// @param value セットする状態
		void SetActive(bool value) noexcept {
			IsActive = value;
		}
		// @return オブジェクトのアクティブ状態を返す
		NODISCARD bool GetActive() const noexcept {
			return IsActive;
		}
		// @brief オブジェクトの名前をセットする
		// @brief name セットする名前
		void SetName(stringView name) noexcept {
			this->name = name;
		}
		// @return オブジェクトの名前を返す
		NODISCARD const string& GetName() const noexcept {
			return name;
		}
		// @brief 指定した Component を追加する
		// @return 追加した Component を返す
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
		// @return 指定した Componentを取得
		template <typename T>
		NODISCARD std::shared_ptr<T> GetComponent() const noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				return std::static_pointer_cast<T>(it->second);
			}
			return nullptr;
		}
		// @brief 指定した Componentを削除
		template <typename T>
		void RemoveComponent() noexcept {
			auto it = components.find(typeid(T));
			if (it != components.end()) {
				components.erase(it);
			}
		}
	};
}
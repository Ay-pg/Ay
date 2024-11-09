/*
  @file BoxCollider.hpp
  @brief 当たり判定の枠
  @author Ay
  @date 2024/11/08
*/
#pragma once
#include "Component.hpp"
#include "Vector2.hpp"

namespace Ay {
	// @brief 当たり判定の枠
	class BoxCollider final : public Component {
	private:
		bool collision; // 衝突状態
		Vector2 pos;    // 座標
		Vector2 size;   // サイズ 
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 BoxCollider() noexcept;
		// @brief デストラクタ
		virtual ~BoxCollider() = default;
		// @brief 初期化処理
		virtual void Ready() noexcept override;
		// @brief 更新処理
		// @param deltaTime 経過時間
		virtual void Update(float deltaTime) override {
		}
		// @brief 描画処理
		virtual void Draw() const override {
		}
		// @brief 必要な情報をセット
		// @param pos 座標
		// @param size 画像のサイズ
		void SetInfo(const Vector2& pos, const Vector2& size) {

		}
		// @brief 衝突状態をセット
		// @param other セットする状態
		void SetCollision(bool other) noexcept {
			collision = other;
		}
		// @return 衝突状態を返す
		NODISCARD bool GetCollision() const noexcept {
			return collision;
		}
	};
#ifndef COLL_COMP
	#define COLL_COMP 
#endif 
}

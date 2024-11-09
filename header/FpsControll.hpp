/*
 　@file FpsControll.hpp
 　@brief FPS制御
 　@author Ay
 　@date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace Ay {
	// @brief FPS制御
	class FpsControll final {
	private:
		std::chrono::steady_clock::time_point startTime; // 測定開始時刻
		int32 count; // カウント
		float fps; // fps 値
		const float targetFPS; // 設定する値
		Vector2 pos; // 座標
		Color color; // 色
	public:
		// @brief コンストラクタ
		// @param fps 値
		NODISCARD FpsControll(float fps, std::optional<Vector2> pos = std::nullopt, std::optional<Color> color = std::nullopt) noexcept;
		// @brief デストラクタ
		~FpsControll() noexcept = default;
		// @brief 初期化処理
		void Ready();
		// @brief 更新処理
		void Update();
		// @brief 描画処理
		void Draw() const;
		// @brief 待機
		void Wait();
	};
}
/*
	@file Time.hpp
	@brief 時間処理関係
	@author Ay
	@date 2024/10/30
*/
#pragma once
#include "Utility.hpp"
#include "Concepts.hpp"


namespace Ay {
	/*
	@class Time
	@brief 時間処理関係
*/
	class Time {
	private:
		float timeScale;   // タイムスケール
		std::chrono::steady_clock::time_point deltaTimer; // 時刻保存用
	public:
		/*
			@brief コンストラクタ
		*/
		Time();
		/*
			@brief デフォルトデストラクタ
		*/
		~Time() = default;
		/*
			@brief デルタタイムを取得
			@return 経過時間
		*/
		float DeltaTime();
		/*
			@brief 全体の時間スケールをセット
			@param scale セットする値
		*/
		void SetTimeScale(float scale) {
			timeScale = scale;
		}
		/*
			@brief 指定時間処理を止める
			@param sec 処理を止める秒数 (浮動小数点型のみ)
		*/
		template <Floating T>
		static void WaitForSeconds(T sec) {
			std::this_thread::sleep_for(duration<T>(sec));
		}
	};
}

/*
	@file Time.hpp
	@brief 乱数生成
	@author Ay
	@date 2024/11/01
*/
#pragma once
#include <random>
#include "Config.hpp"
#include "Concepts.hpp"
#include "Debug.hpp"

namespace Ay {
	class Random {
	private:
		std::random_device rnd;
		std::mt19937 mt;
	public:
		// @brief コンストラクタ
		NODISCARD_CPP20 Random() noexcept : mt(rnd()) {
		}
		// @brief デフォルトデストラクタ
		~Random() = default;
		/*
			@brief 乱数生成 [整数]
			@param min 最小値
			@param max 最大値
			@return 生成した値を返す
		*/
		template <Integral T>
		NODISCARD T GetRandomValue(T min, T max) {
#ifdef DEBUG
			if (min > max) {
				std::swap(min, max);
				Debug::LogError("最小値が最大値を超えています。");
			}
#endif
			std::uniform_int_distribution<T> dist(min, max);
			return dist(mt);
		}
		/*
			@brief 乱数生成 [浮動小数点]
			@param min 最小値
			@param max 最大値
			@return 生成した値を返す
		*/
		template <Floating T>
		NODISCARD T GetRandomValue(T min, T max) {
#ifdef DEBUG
			if (min > max) {
				std::swap(min, max);
				Debug::LogError("最小値が最大値を超えています。");
			}
#endif
			std::uniform_real_distribution<T> dist(min, max);
			return dist(mt);
		}
	};
}

/*
	@file Time.hpp
	@brief ��������
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
		// @brief �R���X�g���N�^
		NODISCARD_CPP20 Random() noexcept : mt(rnd()) {
		}
		// @brief �f�t�H���g�f�X�g���N�^
		~Random() = default;
		/*
			@brief �������� [����]
			@param min �ŏ��l
			@param max �ő�l
			@return ���������l��Ԃ�
		*/
		template <Integral T>
		NODISCARD T GetRandomValue(T min, T max) {
#ifdef DEBUG
			if (min > max) {
				std::swap(min, max);
				Debug::LogError("�ŏ��l���ő�l�𒴂��Ă��܂��B");
			}
#endif
			std::uniform_int_distribution<T> dist(min, max);
			return dist(mt);
		}
		/*
			@brief �������� [���������_]
			@param min �ŏ��l
			@param max �ő�l
			@return ���������l��Ԃ�
		*/
		template <Floating T>
		NODISCARD T GetRandomValue(T min, T max) {
#ifdef DEBUG
			if (min > max) {
				std::swap(min, max);
				Debug::LogError("�ŏ��l���ő�l�𒴂��Ă��܂��B");
			}
#endif
			std::uniform_real_distribution<T> dist(min, max);
			return dist(mt);
		}
	};
}

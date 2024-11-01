/*
	@file Debug.hpp
	@author Ay
	@date 2024/10/30
*/
#pragma once
#include "Utility.hpp"
#include <debugapi.h>

namespace Ay {
	/*
		@brief �f�o�b�O
	*/
	class Debug {
	public:
		// @brief �C���X�^���X�̐����͋֎~
		Debug() = delete;
		// @brief �R���\�[���Ƀ��b�Z�[�W��\������
		// @param msg �\�������郁�b�Z�[�W
		static void LogConsole(stringView msg) {
			std::cout << "[DEBUG] " << msg << "\n";
		}
		// @brief �R���\�[���Ƀ��b�Z�[�W��\������
		// @param msg �\�������郁�b�Z�[�W(format�w��\)
		// @param args �\������l
		template <typename... Args>
		static void LogConsole(stringView msg, Args&&... args) {
			std::cout << "[DEBUG] " + std::vformat(msg, std::make_format_args(std::forward<Args>(args)...)) + "\n";
		}
		// @brief �G���[���̃��b�Z�[�W��\������
		// @param file �t�@�C����
		// @param line �s��
		// @param msg �\�����郁�b�Z�[�W
		// @param args �\������l
		template <typename... Args>
		static void LogError(pcChar file, int32 line, stringView msg, Args&&... args) {
			auto formatMsg = std::vformat(msg, std::make_format_args(std::forward<Args>(args)...));
			auto outputMsg = "[ERROR] [" + std::string(file) + ":" + std::to_string(line) + "] " + formatMsg + "\n";

			OutputDebugString(outputMsg.c_str());
		}
	};
#define LogError(msg, ...) Debug::LogError(__FILE__, __LINE__, msg, ##__VA_ARGS__)
}

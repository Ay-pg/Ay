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
		@brief デバッグ
	*/
	class Debug {
	public:
		// @brief インスタンスの生成は禁止
		Debug() = delete;
		// @brief コンソールにメッセージを表示する
		// @param msg 表示させるメッセージ
		static void LogConsole(stringView msg) {
			std::cout << "[DEBUG] " << msg << "\n";
		}
		// @brief コンソールにメッセージを表示する
		// @param msg 表示させるメッセージ(format指定可能)
		// @param args 表示する値
		template <typename... Args>
		static void LogConsole(stringView msg, Args&&... args) {
			std::cout << "[DEBUG] " + std::vformat(msg, std::make_format_args(std::forward<Args>(args)...)) + "\n";
		}
		// @brief エラー時のメッセージを表示する
		// @param file ファイル名
		// @param line 行数
		// @param msg 表示するメッセージ
		// @param args 表示する値
		template <typename... Args>
		static void LogError(pcChar file, int32 line, stringView msg, Args&&... args) {
			auto formatMsg = std::vformat(msg, std::make_format_args(std::forward<Args>(args)...));
			auto outputMsg = "[ERROR] [" + std::string(file) + ":" + std::to_string(line) + "] " + formatMsg + "\n";

			OutputDebugString(outputMsg.c_str());
		}
	};
#define LogError(msg, ...) Debug::LogError(__FILE__, __LINE__, msg, ##__VA_ARGS__)
}

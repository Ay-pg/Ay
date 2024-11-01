#pragma once
#include <DxLib.h>
#include "Utility.hpp"
/*
	@file Window.hpp
	@brief ウィンドウ情報
	@author Ay
	@date 2024/11/01
*/
namespace Ay {
	namespace Window {
		int32 width = 1920;  // 横幅
		int32 height = 1080; // 縦幅
		int32 colorBit = 32; // カラービット
		int32 iconID = 0;    // アイコンID
		string title = "window-title"; // ウィンドウタイトル名

		// @brief @brief ウィンドウ情報を初期化
		// @param width 横幅
		// @param height 縦幅
		// @param bit カラービット
		// @param icon アイコンID
		// @param title ウィンドウタイトル名
		// @param mode true: ウィンドウ false: フルスクリーン
		void InitWindow(int32 width, int32 height, int32 bit = 32, int32 icon, const string& title = Window::title, bool mode = true) noexcept {
			Window::width = width;
			Window::height = height;
			Window::colorBit = bit;
			Window::iconID = icon;
			Window::title = title;
			SetGraphMode(width, height, bit);
			SetWindowIconID(icon);
			SetMainWindowText(title.data());
			ChangeWindowMode(mode);
		}
		// @brief 横幅
		// @brief 縦幅
		// @brief カラービット
		void Resize(int32 width, int32 height, int32 bit = 32) noexcept {
			Window::width = width;
			Window::height = height;
			SetGraphMode(width, height, bit);
		}
		// @brief フルスクリーンにする
		void SetFullScreen() noexcept {
			ChangeWindowMode(false);
		}
		// @brief ウィンドウにする
		void SetWindow() noexcept {
			ChangeWindowMode(true);
		}
		// @return 横幅
		NODISCARD constexpr uInt GetWidth() noexcept {
			return width;
		}
		// @return 横幅の半分
		NODISCARD constexpr uInt GetWidthHalf() noexcept {
			return width / 2;
		}
		// @return 縦幅
		NODISCARD constexpr uInt GetHeight() noexcept {
			return height;
		}
		// @return 縦幅の半分
		NODISCARD constexpr uInt GetHeightHalf() noexcept {
			return height / 2;
		}
		// @return 横幅(float 型)
		NODISCARD constexpr float GetWidthF() noexcept {
			return static_cast<float>(width);
		}
		// @return 横幅の半分(float 型)
		NODISCARD constexpr float GetWidthHalfF() noexcept {
			return static_cast<float>(width / 2);
		}
		// @return 縦幅(float 型)
		NODISCARD constexpr float GetHeightF() noexcept {
			return static_cast<float>(height);
		}
		// @return 縦幅半分(float 型)
		NODISCARD constexpr float GetHeightHalfF() noexcept {
			return static_cast<float>(height / 2);
		}
		// @return 縦幅と横幅
		NODISCARD constexpr std::pair<uInt, uInt> GetSize() noexcept {
			return std::make_pair(width, height);
		}
		// @return 縦幅と横幅の半分
		NODISCARD constexpr std::pair<uInt, uInt> GetSizeHalf() noexcept {
			return std::make_pair(width / 2, height / 2);
		}
		// @return 縦幅と横幅(float 型)
		NODISCARD constexpr std::pair<float, float> GetSizeF() noexcept {
			return std::make_pair(static_cast<float>(width), static_cast<float>(height));
		}
		// @return 縦幅と横幅の半分(float 型)
		NODISCARD constexpr std::pair<float, float> GetSizeHalfF() noexcept {
			return std::make_pair(static_cast<float>(width / 2), static_cast<float>(height / 2));
		}
		// @return カラービット
		NODISCARD constexpr uInt GetColorBit() noexcept {
			return colorBit;
		}
		// @return アイコンID
		NODISCARD constexpr uInt GetIconID() noexcept {
			return iconID;
		}
		// @return ウィンドウタイトル名
		void SetName(const string& title) {
			Window::title = title;
			SetMainWindowText(title.data());
		}
		// @return ウィンドウタイトル名
		NODISCARD constexpr const string& GetName() noexcept {
			return title;
		}
	}
}

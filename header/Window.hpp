#pragma once
#include <DxLib.h>
#include "Utility.hpp"
/*
	@file Window.hpp
	@brief �E�B���h�E���
	@author Ay
	@date 2024/11/01
*/
namespace Ay {
	namespace Window {
		int32 width = 1920;  // ����
		int32 height = 1080; // �c��
		int32 colorBit = 32; // �J���[�r�b�g
		int32 iconID = 0;    // �A�C�R��ID
		string title = "window-title"; // �E�B���h�E�^�C�g����

		// @brief @brief �E�B���h�E����������
		// @param width ����
		// @param height �c��
		// @param bit �J���[�r�b�g
		// @param icon �A�C�R��ID
		// @param title �E�B���h�E�^�C�g����
		// @param mode true: �E�B���h�E false: �t���X�N���[��
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
		// @brief ����
		// @brief �c��
		// @brief �J���[�r�b�g
		void Resize(int32 width, int32 height, int32 bit = 32) noexcept {
			Window::width = width;
			Window::height = height;
			SetGraphMode(width, height, bit);
		}
		// @brief �t���X�N���[���ɂ���
		void SetFullScreen() noexcept {
			ChangeWindowMode(false);
		}
		// @brief �E�B���h�E�ɂ���
		void SetWindow() noexcept {
			ChangeWindowMode(true);
		}
		// @return ����
		NODISCARD constexpr uInt GetWidth() noexcept {
			return width;
		}
		// @return �����̔���
		NODISCARD constexpr uInt GetWidthHalf() noexcept {
			return width / 2;
		}
		// @return �c��
		NODISCARD constexpr uInt GetHeight() noexcept {
			return height;
		}
		// @return �c���̔���
		NODISCARD constexpr uInt GetHeightHalf() noexcept {
			return height / 2;
		}
		// @return ����(float �^)
		NODISCARD constexpr float GetWidthF() noexcept {
			return static_cast<float>(width);
		}
		// @return �����̔���(float �^)
		NODISCARD constexpr float GetWidthHalfF() noexcept {
			return static_cast<float>(width / 2);
		}
		// @return �c��(float �^)
		NODISCARD constexpr float GetHeightF() noexcept {
			return static_cast<float>(height);
		}
		// @return �c������(float �^)
		NODISCARD constexpr float GetHeightHalfF() noexcept {
			return static_cast<float>(height / 2);
		}
		// @return �c���Ɖ���
		NODISCARD constexpr std::pair<uInt, uInt> GetSize() noexcept {
			return std::make_pair(width, height);
		}
		// @return �c���Ɖ����̔���
		NODISCARD constexpr std::pair<uInt, uInt> GetSizeHalf() noexcept {
			return std::make_pair(width / 2, height / 2);
		}
		// @return �c���Ɖ���(float �^)
		NODISCARD constexpr std::pair<float, float> GetSizeF() noexcept {
			return std::make_pair(static_cast<float>(width), static_cast<float>(height));
		}
		// @return �c���Ɖ����̔���(float �^)
		NODISCARD constexpr std::pair<float, float> GetSizeHalfF() noexcept {
			return std::make_pair(static_cast<float>(width / 2), static_cast<float>(height / 2));
		}
		// @return �J���[�r�b�g
		NODISCARD constexpr uInt GetColorBit() noexcept {
			return colorBit;
		}
		// @return �A�C�R��ID
		NODISCARD constexpr uInt GetIconID() noexcept {
			return iconID;
		}
		// @return �E�B���h�E�^�C�g����
		void SetName(const string& title) {
			Window::title = title;
			SetMainWindowText(title.data());
		}
		// @return �E�B���h�E�^�C�g����
		NODISCARD constexpr const string& GetName() noexcept {
			return title;
		}
	}
}

/*
    @file Window.hpp
    @brief �E�B���h�E���
    @author Ay
    @date 2024/11/02
*/
#pragma once
#include <DxLib.h>
#include "Utility.hpp"

namespace Ay {
    // @brief �E�B���h�E���
    class Window final {
    private:
        Window() = default;
        ~Window() = default;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;
    public:
        // @return �C���X�^���X���擾
        static Window& GetInstance() noexcept {
            static Window instance;
            return instance;
        }
    private:
        int32 width = 1920;  // ����
        int32 height = 1080; // �c��
        int32 colorBit = 32; // �J���[�r�b�g
        int32 iconID = 32;   // �A�C�R��ID
        string title = "";   // �E�B���h�E�^�C�g����
    public:
        // @brief �E�B���h�E����������
        // @param width ����
        // @param height �c��
        // @param bit �J���[�r�b�g
        // @param icon �A�C�R��ID
        // @param title �E�B���h�E�^�C�g����
        // @param mode true: �E�B���h�E false: �t���X�N���[��
        void InitWindow(int32 width, int32 height, int32 bit, int32 icon, const string& title = "window-title", bool mode = true) noexcept {
            Window::width = width;
            Window::height = height;
            Window::colorBit = bit;
            Window::iconID = icon;
            Window::title = title;
            SetGraphMode(width, height, bit);
            SetWindowIconID(icon);
            SetMainWindowText(title.c_str());
            ChangeWindowMode(mode);
        }
        // @brief �E�B���h�E�̃T�C�Y�ύX
        void Resize(int32 width, int32 height, int32 bit) noexcept {
            Window::width = width;
            Window::height = height;
            Window::colorBit = bit;
            SetGraphMode(width, height, bit);
        }
        // @brief �t���X�N���[�����[�h�ɐ؂�ւ���
        static void SetFullScreen() noexcept {
            ChangeWindowMode(false);
        }
        // @brief �E�B���h�E���[�h�ɐ؂�ւ���
        static void SetWindowed() noexcept {
            ChangeWindowMode(true);
        }
        // @return ����
        int32 GetWidth() noexcept {
            return width;
        }
        // @return �����̔���
        int32 GetWidthHalf() noexcept {
            return width / 2;
        }
        // @return �c��
        int32 GetHeight() noexcept {
            return height;
        }
        // @return �c���̔���
        int32 GetHeightHalf() noexcept {
            return height / 2;
        }
        // @return ����(float �^)
        float GetWidthF() noexcept {
            return static_cast<float>(width);
        }
        // @return �c��(float �^)
        float GetHeightF() noexcept {
            return static_cast<float>(height / 2);
        }
        // @return ����(float �^)�̔���
        float GetWidthHalfF() noexcept {
            return static_cast<float>(width / 2);
        }
        // @return �c��(float �^)�̔���
        float GetHeightHalfF() noexcept {
            return static_cast<float>(height);
        }
        // @return �����Əc���̃y�A
        std::pair<int32, int32> GetSize() noexcept {
            return { width, height };
        }
        // @return �����Əc���̃y�A(float �^)
        std::pair<float, float> GetSizeF() noexcept {
            return { static_cast<float>(width), static_cast<float>(height) };
        }
        // @return ���������Əc�������̃y�A
        std::pair<int32, int32> GetSizeHalf() noexcept {
            return { width / 2, height / 2 };
        }
        // @return ���������Əc�������̃y�A(float �^)
        std::pair<float, float> GetSizehalfF() noexcept {
            return { static_cast<float>(width / 2), static_cast<float>(height / 2) };
        }
        // @return �J���[�r�b�g
        int32 GetColorBit() noexcept {
            return colorBit;
        }
        // @return �A�C�R��ID
        int32 GetIconID() noexcept {
            return iconID;
        }
        // @return �E�B���h�E�^�C�g����
        const string& GetName() noexcept {
            return title;
        }
        // @brief �A�C�R��ID��ݒ肷��
        void SetIconID(int32 icon) noexcept {
            Window::iconID = icon;
            SetWindowIconID(icon);
        }
        // @brief �E�B���h�E�^�C�g������ݒ肷��
        void SetName(const string& title) noexcept {
            Window::title = title;
            SetMainWindowText(title.c_str());
        }
    };
#define window Window::GetInstance()
}

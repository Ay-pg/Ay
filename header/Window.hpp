/*
    @file Window.hpp
    @brief ウィンドウ情報
    @author Ay
    @date 2024/11/02
*/
#pragma once
#include <DxLib.h>
#include "Utility.hpp"

namespace Ay {
    // @brief ウィンドウ情報
    class Window final {
    private:
        Window() = default;
        ~Window() = default;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;
    public:
        // @return インスタンスを取得
        static Window& GetInstance() noexcept {
            static Window instance;
            return instance;
        }
    private:
        int32 width = 1920;  // 横幅
        int32 height = 1080; // 縦幅
        int32 colorBit = 32; // カラービット
        int32 iconID = 32;   // アイコンID
        string title = "";   // ウィンドウタイトル名
    public:
        // @brief ウィンドウ情報を初期化
        // @param width 横幅
        // @param height 縦幅
        // @param bit カラービット
        // @param icon アイコンID
        // @param title ウィンドウタイトル名
        // @param mode true: ウィンドウ false: フルスクリーン
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
        // @brief ウィンドウのサイズ変更
        void Resize(int32 width, int32 height, int32 bit) noexcept {
            Window::width = width;
            Window::height = height;
            Window::colorBit = bit;
            SetGraphMode(width, height, bit);
        }
        // @brief フルスクリーンモードに切り替える
        static void SetFullScreen() noexcept {
            ChangeWindowMode(false);
        }
        // @brief ウィンドウモードに切り替える
        static void SetWindowed() noexcept {
            ChangeWindowMode(true);
        }
        // @return 横幅
        int32 GetWidth() noexcept {
            return width;
        }
        // @return 横幅の半分
        int32 GetWidthHalf() noexcept {
            return width / 2;
        }
        // @return 縦幅
        int32 GetHeight() noexcept {
            return height;
        }
        // @return 縦幅の半分
        int32 GetHeightHalf() noexcept {
            return height / 2;
        }
        // @return 横幅(float 型)
        float GetWidthF() noexcept {
            return static_cast<float>(width);
        }
        // @return 縦幅(float 型)
        float GetHeightF() noexcept {
            return static_cast<float>(height / 2);
        }
        // @return 横幅(float 型)の半分
        float GetWidthHalfF() noexcept {
            return static_cast<float>(width / 2);
        }
        // @return 縦幅(float 型)の半分
        float GetHeightHalfF() noexcept {
            return static_cast<float>(height);
        }
        // @return 横幅と縦幅のペア
        std::pair<int32, int32> GetSize() noexcept {
            return { width, height };
        }
        // @return 横幅と縦幅のペア(float 型)
        std::pair<float, float> GetSizeF() noexcept {
            return { static_cast<float>(width), static_cast<float>(height) };
        }
        // @return 横幅半分と縦幅半分のペア
        std::pair<int32, int32> GetSizeHalf() noexcept {
            return { width / 2, height / 2 };
        }
        // @return 横幅半分と縦幅半分のペア(float 型)
        std::pair<float, float> GetSizehalfF() noexcept {
            return { static_cast<float>(width / 2), static_cast<float>(height / 2) };
        }
        // @return カラービット
        int32 GetColorBit() noexcept {
            return colorBit;
        }
        // @return アイコンID
        int32 GetIconID() noexcept {
            return iconID;
        }
        // @return ウィンドウタイトル名
        const string& GetName() noexcept {
            return title;
        }
        // @brief アイコンIDを設定する
        void SetIconID(int32 icon) noexcept {
            Window::iconID = icon;
            SetWindowIconID(icon);
        }
        // @brief ウィンドウタイトル名を設定する
        void SetName(const string& title) noexcept {
            Window::title = title;
            SetMainWindowText(title.c_str());
        }
    };
#define window Window::GetInstance()
}

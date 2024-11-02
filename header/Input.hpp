/*
    @file Input.hpp
    @brief キーボード、マウスの入力管理
    @author Ay
    @date 2024/11/02
*/
#pragma once
#include "Utility.hpp"
#include "Vector2.hpp"

namespace Ay {
	/*
	@enum Keys
	@brief  対応しているキー
*/
	enum Keys {
		A = 0x1e, // 'A' キー 
		B = 0x30, // 'B' キー
		C = 0x2e, // 'C' キー
		D = 0x20, // 'D' キー
		E = 0x12, // 'E' キー
		F = 0x21, // 'F' キー
		G = 0x22, // 'G' キー
		H = 0x23, // 'H' キー
		I = 0x17, // 'I' キー
		J = 0x24, // 'J' キー
		K = 0x25, // 'K' キー
		L = 0x26, // 'L' キー
		M = 0x32, // 'M' キー
		N = 0x31, // 'N' キー
		O = 0x18, // 'O' キー
		P = 0x19, // 'P' キー
		Q = 0x10, // 'Q' キー
		R = 0x13, // 'R' キー
		S = 0x1f, // 'S' キー
		T = 0x14, // 'T' キー
		U = 0x16, // 'U' キー
		V = 0x2f, // 'V' キー
		W = 0x11, // 'W' キー
		X = 0x2d, // 'X' キー
		Y = 0x15, // 'Y' キー
		Z = 0x2c, // 'Z' キー

		Alpha1 = 0x02, // '1' キー
		Alpha2 = 0x03, // '2' キー
		Alpha3 = 0x04, // '3' キー
		Alpha4 = 0x05, // '4' キー
		Alpha5 = 0x06, // '5' キー
		Alpha6 = 0x07, // '6' キー
		Alpha7 = 0x08, // '7' キー
		Alpha8 = 0x09, // '8' キー
		Alpha9 = 0x0a, // '9' キー
		Alpha0 = 0x0b, // '0' キー

		ESC   = 0x01, // 'ESC' キー
		SPACE = 0x39, // 'SPACE' キー
		LSHIT = 0x2a, // 'LSHIT' キー
		RSHIT = 0x36, // 'RSHIT' キー
		ENTER = 0x1c, // 'ENTER' キー

		UpArrow    = 0xc8, // '上矢印' キー
		DownArrow  = 0xd0, // '下矢印' キー
		RightArrow = 0xcd, // '右矢印' キー
		LeftArrow  = 0xcb, // '左矢印' キー
	};
	// @brief MouseButtons
	enum Mouse {
		Left = 0x0001,  // 左
		Mid  = 0x0004,  // 真ん中
		Right = 0x0002, // 右 
	};
    // @brief キーボード、マウスの入力管理
    class Input final {
    private:
        Input() = default;
        ~Input() = default;
        Input(const Input&) = delete;
        Input(Input&&) = delete;
        Input& operator=(const Input&) = delete;
        Input& operator=(Input&&) = delete;
    public:
        // @return インスタンスを取得
        static Input& GetInstance() noexcept {
            static Input instance;
            return instance;
        }
    private:
		Vector2 position = { 0.f,0.f }; // マウス座標
		Vector2 delta = { 0.f,0.f };    // マウス座標の変化量
		char key[256] = {};     // 現在の key 状態
		char keySave[256] = {}; // 前回の key 状態
		char keyDown[256] = {}; // KeyUp から KeyDown 検出情報保存用
		char keyUp[256] = {};   // KeyDown から KeyUp 検出情報保存用
		int mouse = 0;          // 現在の mouse 情報  bit_on: mouseButton Down  bit_off: mouseButton Up
		int mouseSave = 0;      // 前回の mouse 情報  bit_on: mouseButton Down  bit_off: mouseButton Up
		int mouseDown = 0;      // mouseButton Up -> Down 検出情報保存用
		int mouseUp = 0;        // mouseButton Down -> Up 検出情報保存用
    public:
		// @brief 更新処理
		void Update() noexcept;
	    // @param key 押されているか確認したいキー
		// @return キーを押している間、true を返す
		NODISCARD constexpr bool GetKey(Keys keyCode ) const noexcept {
			return key[keyCode] != 0;
		}
		// @param key 押されているか確認したいキー
		// @return キーを押したフレームの間だけ、true を返す
		NODISCARD constexpr bool GetKeyDown(Keys keyCode) const noexcept {
			return keyDown[keyCode] != 0;
		}
		// @param key 押されているか確認したいキー
		// @return キーを離したフレームの間だけ、true を返す
		NODISCARD constexpr bool GetKeyUp(Keys keyCode) const noexcept {
			return keyUp[keyCode] != 0;
		}
		// @param button 押されているか確認したいボタン
		// @return マウスボタンが押されているかどうかを返す
		NODISCARD constexpr bool GetMouseButton(Mouse button) const noexcept {
			return (mouse & button) != 0;
		}
		// @param button 押されているか確認したいボタン
		// @return マウスボタンを押したフレームの間だけ true を返す
		NODISCARD constexpr bool GetMouseButtonDown(Mouse button) const noexcept {
			return (mouseDown & button) != 0;
		}
		// @param button 押されているか確認したいボタン
		// @return マウスボタンを離したフレームの間だけ true を返す
		NODISCARD constexpr bool GetMouseButtonUp(Mouse button) const noexcept {
			return (mouseUp & button) != 0;
		}
		// @return 現在のマウスカーソル座標を Vector2 型で返す
		const Vector2& GetMousePosition() const noexcept {
			return Vector2(static_cast<float>(position.x), static_cast<float>(position.y));
		}
		// @return 現在のマウスカーソル座標を int 型で返す
		std::pair<int32, int32> GetMousePositionToInt() const noexcept {
			return { static_cast<int32>(position.x), static_cast<int32>(position.y) };
		}
		// @return マウスカーソル座標の移動量を Vector2 型で返す
		const Vector2& GetMouseDelta() const noexcept {
			return Vector2(static_cast<float>(delta.x), static_cast<float>(delta.y));
		}
		// @return マウスカーソル座標の移動量を int 型で返す
		std::pair<int32, int32> GetMouseDeltaToInt() const noexcept {
			return { static_cast<int32>(delta.x), static_cast<int32>(delta.y) };
		}
    };
#define input Input::GetInstance();
}

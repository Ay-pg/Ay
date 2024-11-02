/*
    @file Input.hpp
    @brief �L�[�{�[�h�A�}�E�X�̓��͊Ǘ�
    @author Ay
    @date 2024/11/02
*/
#pragma once
#include "Utility.hpp"
#include "Vector2.hpp"

namespace Ay {
	/*
	@enum Keys
	@brief  �Ή����Ă���L�[
*/
	enum Keys {
		A = 0x1e, // 'A' �L�[ 
		B = 0x30, // 'B' �L�[
		C = 0x2e, // 'C' �L�[
		D = 0x20, // 'D' �L�[
		E = 0x12, // 'E' �L�[
		F = 0x21, // 'F' �L�[
		G = 0x22, // 'G' �L�[
		H = 0x23, // 'H' �L�[
		I = 0x17, // 'I' �L�[
		J = 0x24, // 'J' �L�[
		K = 0x25, // 'K' �L�[
		L = 0x26, // 'L' �L�[
		M = 0x32, // 'M' �L�[
		N = 0x31, // 'N' �L�[
		O = 0x18, // 'O' �L�[
		P = 0x19, // 'P' �L�[
		Q = 0x10, // 'Q' �L�[
		R = 0x13, // 'R' �L�[
		S = 0x1f, // 'S' �L�[
		T = 0x14, // 'T' �L�[
		U = 0x16, // 'U' �L�[
		V = 0x2f, // 'V' �L�[
		W = 0x11, // 'W' �L�[
		X = 0x2d, // 'X' �L�[
		Y = 0x15, // 'Y' �L�[
		Z = 0x2c, // 'Z' �L�[

		Alpha1 = 0x02, // '1' �L�[
		Alpha2 = 0x03, // '2' �L�[
		Alpha3 = 0x04, // '3' �L�[
		Alpha4 = 0x05, // '4' �L�[
		Alpha5 = 0x06, // '5' �L�[
		Alpha6 = 0x07, // '6' �L�[
		Alpha7 = 0x08, // '7' �L�[
		Alpha8 = 0x09, // '8' �L�[
		Alpha9 = 0x0a, // '9' �L�[
		Alpha0 = 0x0b, // '0' �L�[

		ESC   = 0x01, // 'ESC' �L�[
		SPACE = 0x39, // 'SPACE' �L�[
		LSHIT = 0x2a, // 'LSHIT' �L�[
		RSHIT = 0x36, // 'RSHIT' �L�[
		ENTER = 0x1c, // 'ENTER' �L�[

		UpArrow    = 0xc8, // '����' �L�[
		DownArrow  = 0xd0, // '�����' �L�[
		RightArrow = 0xcd, // '�E���' �L�[
		LeftArrow  = 0xcb, // '�����' �L�[
	};
	// @brief MouseButtons
	enum Mouse {
		Left = 0x0001,  // ��
		Mid  = 0x0004,  // �^��
		Right = 0x0002, // �E 
	};
    // @brief �L�[�{�[�h�A�}�E�X�̓��͊Ǘ�
    class Input final {
    private:
        Input() = default;
        ~Input() = default;
        Input(const Input&) = delete;
        Input(Input&&) = delete;
        Input& operator=(const Input&) = delete;
        Input& operator=(Input&&) = delete;
    public:
        // @return �C���X�^���X���擾
        static Input& GetInstance() noexcept {
            static Input instance;
            return instance;
        }
    private:
		Vector2 position = { 0.f,0.f }; // �}�E�X���W
		Vector2 delta = { 0.f,0.f };    // �}�E�X���W�̕ω���
		char key[256] = {};     // ���݂� key ���
		char keySave[256] = {}; // �O��� key ���
		char keyDown[256] = {}; // KeyUp ���� KeyDown ���o���ۑ��p
		char keyUp[256] = {};   // KeyDown ���� KeyUp ���o���ۑ��p
		int mouse = 0;          // ���݂� mouse ���  bit_on: mouseButton Down  bit_off: mouseButton Up
		int mouseSave = 0;      // �O��� mouse ���  bit_on: mouseButton Down  bit_off: mouseButton Up
		int mouseDown = 0;      // mouseButton Up -> Down ���o���ۑ��p
		int mouseUp = 0;        // mouseButton Down -> Up ���o���ۑ��p
    public:
		// @brief �X�V����
		void Update() noexcept;
	    // @param key ������Ă��邩�m�F�������L�[
		// @return �L�[�������Ă���ԁAtrue ��Ԃ�
		NODISCARD constexpr bool GetKey(Keys keyCode ) const noexcept {
			return key[keyCode] != 0;
		}
		// @param key ������Ă��邩�m�F�������L�[
		// @return �L�[���������t���[���̊Ԃ����Atrue ��Ԃ�
		NODISCARD constexpr bool GetKeyDown(Keys keyCode) const noexcept {
			return keyDown[keyCode] != 0;
		}
		// @param key ������Ă��邩�m�F�������L�[
		// @return �L�[�𗣂����t���[���̊Ԃ����Atrue ��Ԃ�
		NODISCARD constexpr bool GetKeyUp(Keys keyCode) const noexcept {
			return keyUp[keyCode] != 0;
		}
		// @param button ������Ă��邩�m�F�������{�^��
		// @return �}�E�X�{�^����������Ă��邩�ǂ�����Ԃ�
		NODISCARD constexpr bool GetMouseButton(Mouse button) const noexcept {
			return (mouse & button) != 0;
		}
		// @param button ������Ă��邩�m�F�������{�^��
		// @return �}�E�X�{�^�����������t���[���̊Ԃ��� true ��Ԃ�
		NODISCARD constexpr bool GetMouseButtonDown(Mouse button) const noexcept {
			return (mouseDown & button) != 0;
		}
		// @param button ������Ă��邩�m�F�������{�^��
		// @return �}�E�X�{�^���𗣂����t���[���̊Ԃ��� true ��Ԃ�
		NODISCARD constexpr bool GetMouseButtonUp(Mouse button) const noexcept {
			return (mouseUp & button) != 0;
		}
		// @return ���݂̃}�E�X�J�[�\�����W�� Vector2 �^�ŕԂ�
		const Vector2& GetMousePosition() const noexcept {
			return Vector2(static_cast<float>(position.x), static_cast<float>(position.y));
		}
		// @return ���݂̃}�E�X�J�[�\�����W�� int �^�ŕԂ�
		std::pair<int32, int32> GetMousePositionToInt() const noexcept {
			return { static_cast<int32>(position.x), static_cast<int32>(position.y) };
		}
		// @return �}�E�X�J�[�\�����W�̈ړ��ʂ� Vector2 �^�ŕԂ�
		const Vector2& GetMouseDelta() const noexcept {
			return Vector2(static_cast<float>(delta.x), static_cast<float>(delta.y));
		}
		// @return �}�E�X�J�[�\�����W�̈ړ��ʂ� int �^�ŕԂ�
		std::pair<int32, int32> GetMouseDeltaToInt() const noexcept {
			return { static_cast<int32>(delta.x), static_cast<int32>(delta.y) };
		}
    };
#define input Input::GetInstance();
}

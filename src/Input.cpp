#include <DxLib.h>
#include "../header/Input.hpp"

namespace Ay {
	void Input::Update() noexcept {
		if (GetHitKeyStateAll(key) == 0) {
			for (int i = 0; i < std::size(key); ++i) {
				keyDown[i] = ~keySave[i] & key[i];
				keyUp[i] = keySave[i] & ~key[i];
				keySave[i] = key[i];
			}
		}

		mouse = GetMouseInput();
		mouseDown = ~mouseSave & mouse;
		mouseUp = mouseSave & ~mouse;
		mouseSave = mouse;

		int mx, my;
		GetMousePoint(&mx, &my);
		Vector2 newPos(static_cast<float>(mx), static_cast<float>(my));
		delta = newPos - position;
		position = newPos;
	}
}

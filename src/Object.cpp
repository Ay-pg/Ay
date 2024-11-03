#include "../header/Object.hpp"

namespace Ay {
	constexpr Object::Object(stringView name) noexcept : name(name) {
		Ready();
	}
	void Object::Ready() noexcept {
		// TODO: Transform,Sprite の初期化処理を追加

	}

	void Object::Update(float deltaTime = 0.f) noexcept {
		for (const auto& comp : components) {
			comp.second->Update(deltaTime);
		}
	}

	void Object::Draw() const noexcept {
		for (const auto& comp : components) {
			comp.second->Draw();
		}
	}
}

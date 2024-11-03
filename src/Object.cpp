#include "../header/Object.hpp"

namespace Ay {
	constexpr Object::Object(stringView name) noexcept : name(name) {
		Ready();
	}
	void Object::Ready() noexcept {
		// TODO: Transform,Sprite ‚Ì‰Šú‰»ˆ—‚ð’Ç‰Á

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

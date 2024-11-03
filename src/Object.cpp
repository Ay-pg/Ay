#include "../header/Object.hpp"

namespace Ay {
	Object::Object(stringView name) noexcept : name(name),IsActive(false) {
	}

	void Object::Ready() {
		// TODO: Transform,Sprite ‚Ì‰Šú‰»ˆ—‚ð’Ç‰Á

	}

	void Object::Update(float deltaTime) {
		for (const auto& comp : components) {
			comp.second->Update(deltaTime);
		}
	}

	void Object::Draw() const {
		for (const auto& comp : components) {
			comp.second->Draw();
		}
	}
}

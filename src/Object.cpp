#include "../header/Object.hpp"

namespace Ay {
	Object::Object(stringView name) noexcept : name(name),IsActive(false) {
	}

	void Object::Ready() {
		// TODO: Transform,Sprite の初期化処理を追加

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

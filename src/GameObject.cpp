#include "../header/GameObject.hpp"

namespace Ay {
	GameObject::GameObject(stringView name) noexcept : Object(name), IsActive(false) {

	}

	void GameObject::Ready() {
		transform = AddComponent<Transform>();
		transform->Ready();
		// TODO: Component Sprite ‚ð‰Šú‰»
	}

	void GameObject::Update(float deltaTime) {
		for (const auto& component : orderComponents) {
			component->Update(deltaTime);
		}
	}

	void GameObject::Draw() const {
		for (const auto& component : orderComponents) {
			component->Draw();
		}
	}
}

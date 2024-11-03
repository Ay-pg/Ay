#include "../header/GameObject.hpp"

namespace Ay {
	uInt GameObject::createCount = 0;

	constexpr GameObject::GameObject(stringView name) noexcept : Object(name) {
		Ready();
	}

	void GameObject::Ready() {
		++createCount;
		id = createCount;
	}

	void GameObject::Update(float deltaTime = 0.f) {
		Object::Update(deltaTime);
	}

	void GameObject::Draw() const {
		Object::Draw();
	}
}

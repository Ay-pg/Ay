#include "../header/GameObject.hpp"

namespace Ay {
	uInt GameObject::createCount = 0;

	GameObject::GameObject(stringView name) noexcept : Object(name), id(0) {
	}

	void GameObject::Ready() {
		Object::Ready();
		++createCount;
		id = createCount;
	}

	void GameObject::Update(float deltaTime) {
		Object::Update(deltaTime);
	}

	void GameObject::Draw() const {
		Object::Draw();
	}
}

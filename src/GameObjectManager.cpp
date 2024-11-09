#include "../header/GameObjectManager.hpp"

namespace Ay {
	GameObjectManager::GameObjectManager() noexcept {
		Ready();
	}

	void GameObjectManager::Ready() {
		objects.clear();
	}

	void GameObjectManager::Update(float deltaTime) {
		for (const auto& object : objects) {
			if (!object->GetActive()) continue;
			object->Update(deltaTime);
		}
	}

	void GameObjectManager::Draw() const {
		for (const auto& object : objects) {
			if (!object->GetActive()) continue;
			object->Draw();
		}
	}

	void GameObjectManager::AddObject(std::shared_ptr<GameObject> object) noexcept {
		objects.emplace_back(object);
	}

	void GameObjectManager::DeleteObject(stringView name) noexcept {
		objects.erase(std::remove_if(objects.begin(), objects.end(),
			[&](const std::shared_ptr<GameObject>& object) {
				return object->GetName() == name;
			}), objects.end());
	}

	std::shared_ptr<GameObject> GameObjectManager::FindObject(stringView name) noexcept {
		auto it = std::find_if(objects.begin(), objects.end(),
			[&](const std::shared_ptr<GameObject>& object) {
				return object->GetName() == name;
			});
		return (it != objects.end()) ? *it : nullptr;
	}

	std::shared_ptr<GameObject> GameObjectManager::FindObject(uInt id) noexcept {
		auto it = std::find_if(objects.begin(), objects.end(),
			[&](const std::shared_ptr<GameObject>& object) {
				return object->GetID() == id;
			});
		return (it != objects.end()) ? *it : nullptr;
	}
}

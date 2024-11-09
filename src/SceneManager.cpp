#include "../header/SceneManager.hpp"
#include "../header/Scene.hpp"

namespace Ay {
	void SceneManager::Ready() {
		DeleteScene();
	}

	void SceneManager::Update(float deltaTime) {
		if (scene.empty()) return;
		scene.top()->Update(deltaTime);
	}

	void SceneManager::Draw() const	{
		if (scene.empty()) return;
		scene.top()->Draw();
	}

	void SceneManager::LoadScene(std::shared_ptr<Scene> scene) {
		if (this->scene.empty()) return;
		this->scene.pop();
		this->scene.emplace(scene);
	}

	void SceneManager::AddScene(std::shared_ptr<Scene> scene) {
		this->scene.emplace(scene);
	}

	void SceneManager::DeleteScene() {
		scene.pop();
	}
}

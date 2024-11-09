#include <DxLib.h>
#include "../header/FpsControll.hpp"

namespace Ay {
	FpsControll::FpsControll(float fps, std::optional<Vector2> pos, std::optional<Color> color) noexcept
		: startTime(std::chrono::steady_clock::now()), targetFPS(fps), fps(0.f), count(0) {
		this->pos = pos.value_or(Vector2::zero());
		this->color = color.value_or(Color::black());
		GetNowHiPerformanceCount();
	}

	void FpsControll::Ready() {
		startTime = std::chrono::steady_clock::now();
		count = 0;
		fps = 0.f;
	}

	void FpsControll::Update() {
		if (count == 0) {
			startTime = std::chrono::steady_clock::now();
		}
		if (count == targetFPS) {
			auto t = std::chrono::steady_clock::now();
			fps = 1000.f / ((t - startTime) / targetFPS).count();
			count = 0;
			startTime = t;
		}
		++count;
	}
	void FpsControll::Draw() const {
		DrawFormatStringF(pos.x, pos.y, color.ToUInt(), "%.1f", fps);
	}

	void FpsControll::Wait() {
		auto tookTime = std::chrono::steady_clock::now() - startTime;
		auto waitTime = count * 1000 / fps - tookTime.count();
	}
}

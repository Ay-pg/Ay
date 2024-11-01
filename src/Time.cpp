#include "../header/Time.hpp"

namespace Ay {
	Time::Time()
		: timeScale(1.f)
		, deltaTimer(std::chrono::high_resolution_clock::now()) {
	}

	float Time::DeltaTime() {
		auto now = std::chrono::high_resolution_clock::now(); // 現時刻を取得
		std::chrono::duration<float> t = now - deltaTimer;    // 経過時間を計算
		deltaTimer = now;                                     // 更新
		return t.count() * timeScale;
	}
}

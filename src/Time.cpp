#include "../header/Time.hpp"

namespace Ay {
	Time::Time()
		: timeScale(1.f)
		, deltaTimer(std::chrono::high_resolution_clock::now()) {
	}

	float Time::DeltaTime() {
		auto now = std::chrono::high_resolution_clock::now(); // ���������擾
		std::chrono::duration<float> t = now - deltaTimer;    // �o�ߎ��Ԃ��v�Z
		deltaTimer = now;                                     // �X�V
		return t.count() * timeScale;
	}
}

#include "../header/Time.hpp"

namespace Ay {
	Time::Time()
		: timeScale(1.f)
		, deltaTimer(high_resolution_clock::now()) {
	}

	float Time::DeltaTime() {
		auto now = high_resolution_clock::now(); // ���������擾
		duration<float> t = now - deltaTimer;    // �o�ߎ��Ԃ��v�Z
		deltaTimer = now;                                     // �X�V
		return t.count() * timeScale;
	}
}

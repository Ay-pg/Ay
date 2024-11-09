/*
 �@@file FpsControll.hpp
 �@@brief FPS����
 �@@author Ay
 �@@date 2024/11/05
*/
#pragma once
#include "Utility.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace Ay {
	// @brief FPS����
	class FpsControll final {
	private:
		std::chrono::steady_clock::time_point startTime; // ����J�n����
		int32 count; // �J�E���g
		float fps; // fps �l
		const float targetFPS; // �ݒ肷��l
		Vector2 pos; // ���W
		Color color; // �F
	public:
		// @brief �R���X�g���N�^
		// @param fps �l
		NODISCARD FpsControll(float fps, std::optional<Vector2> pos = std::nullopt, std::optional<Color> color = std::nullopt) noexcept;
		// @brief �f�X�g���N�^
		~FpsControll() noexcept = default;
		// @brief ����������
		void Ready();
		// @brief �X�V����
		void Update();
		// @brief �`�揈��
		void Draw() const;
		// @brief �ҋ@
		void Wait();
	};
}
/*
	@file Time.hpp
	@brief ���ԏ����֌W
	@author Ay
	@date 2024/10/30
*/
#pragma once
#include "Utility.hpp"
#include "Concepts.hpp"


namespace Ay {
	/*
	@class Time
	@brief ���ԏ����֌W
*/
	class Time {
	private:
		float timeScale;   // �^�C���X�P�[��
		std::chrono::steady_clock::time_point deltaTimer; // �����ۑ��p
	public:
		/*
			@brief �R���X�g���N�^
		*/
		Time();
		/*
			@brief �f�t�H���g�f�X�g���N�^
		*/
		~Time() = default;
		/*
			@brief �f���^�^�C�����擾
			@return �o�ߎ���
		*/
		float DeltaTime();
		/*
			@brief �S�̂̎��ԃX�P�[�����Z�b�g
			@param scale �Z�b�g����l
		*/
		void SetTimeScale(float scale) {
			timeScale = scale;
		}
		/*
			@brief �w�莞�ԏ������~�߂�
			@param sec �������~�߂�b�� (���������_�^�̂�)
		*/
		template <Floating T>
		static void WaitForSeconds(T sec) {
			std::this_thread::sleep_for(duration<T>(sec));
		}
	};
}

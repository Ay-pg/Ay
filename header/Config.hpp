/*
	@file Config.hpp
	@author Ay
	@date 2024/10/30
*/
#pragma once

#define CPP20 202002L
#define CPP17 201703L

#if (__cplusplus >= CPP20)
	#define NODISCARD_CPP20 [[nodiscard]] // this nodiscard is cpp '20'
	#define NODISCARD [[nodiscard]]       // this nodiscard is cpp '17' and cpp '20'
#elif (__cplusplus >= CPP17)
	#define NODISCARD_CPP20         // empty
	#define NODISCARD [[nodiscard]] // this nodiscard is cpp17
#else
	#define NODISCARD_CPP20 // empty
	#define NODISCARD       // empty
#endif

#ifdef _DEBUG
	#define DEBUG _DEBUG
#endif 
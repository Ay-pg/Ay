/*
	@file Utility.hpp
	@author Ay
	@date 2024/10/31
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <thread>
#include <chrono>
#include <random>
#include <functional>

namespace Ay {
	using cInt = const int;
	using pInt = int*;
	using uInt = unsigned int;
	using Int = int;

	using pcChar = const char*;
	using stringView = std::string_view;
	using string = std::string;

	using std::cout;
	using std::endl;

	using std::function;

	using namespace std::chrono;
	using namespace std::this_thread;
}
/*
	@file Utility.hpp
	@author Ay
	@date 2024/11/01
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
#include <functional>


#include "Config.hpp"

namespace Ay {
	using cInt = const int;
	using pInt = int*;
	using uInt = unsigned int;
	using int32 = int;

	using pcChar = const char*;
	using stringView = std::string_view;
	using string = std::string;

	using std::cout;
	using std::endl;

	using std::function;
}
/*
	@file Utility.hpp
	@author Ay
	@date 2024/10/30
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <utility>
#include <functional>
#include <optional>
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <Windows.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <array>

namespace Ay {
	using cInt = const int;
	using pInt = int*;
	using uInt = unsigned int;
	using Int = int;

	using pcChar = const char*;
	using stringView = std::string_view;
	using string = std::string;

	using std::cout, std::endl;

	using namespace std::chrono;
	using namespace std::this_thread;
}
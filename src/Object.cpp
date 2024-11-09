#include "../header/Object.hpp"

namespace Ay {
	int32 Object::createCount = 0;

	Object::Object(stringView name) noexcept : id(0), name(name) {
		id = ++createCount;
		if (name.empty()) {
			this->name = std::string(typeid(Object).name()) + std::to_string(id);
		}
	}
}

#include <DxLib.h>
#include "../header/Text.hpp"

namespace Ay {
	constexpr Text::Text() noexcept : Component()
		, pos(Vector2::zero()), text(""), font(""), color(Color::black()) {
		Ready();
	}

    void Text::Ready() {
		SetOrder(OrderList::TEXT);
    }

	void Text::Draw() const {
		DrawStringF(pos.x - (size.x / 2), pos.y - (size.y / 2), text.data(), color.ToUInt());
	}
	void Text::SetInfo(const Vector2& pos, stringView text, stringView font, const Color& color) {
		this->pos = pos;
		this->text = text;
		this->font = font;
		this->color = color;
		size.x = static_cast<float>(GetDrawStringWidth(text.data(), static_cast<int>(text.length())));
		size.y = static_cast<float>(GetFontSize());
	}
}

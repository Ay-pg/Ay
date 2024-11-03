/*
    @file Text.hpp
    @brief テキストを表示
    @author Ay
    @date 2024/11/04
*/
#pragma once
#include "Component.hpp"
#include "Color.hpp"
#include "Vector2.hpp"

namespace Ay {
    // @brief テキストを表示
    class Text final : public Component {
    private:
        Vector2 size; // テキストサイズ
        Vector2 pos;  // 座標
        string text;  // 表示する文字列
        string font;  // フォント名
        Color color;  // 色
    public:
        // @brief コンストラクタ
        NODISCARD_CPP20 constexpr Text() noexcept;
        // @brief デストラクタ
        virtual ~Text() = default;
        // @brief 初期化処理
        virtual void Ready() override;
        // @brief 更新処理
        // @param deltaTime 経過時間
        virtual void Update(float deltaTime) override {
        }
        // @brief 描画処理
        virtual void Draw() const override;
        // @brief テキストの位置、内容、フォント、色を設定する
        // @param pos テキストの表示位置を指定するベクトル
        // @param text 表示するテキストの内容
        // @param font フォント名
        // @param color テキストの色を指定するオブジェクト
        void SetInfo(const Vector2& pos, stringView text, stringView font, const Color& color);
    };
}

/*
	@file Object.hpp
	@brief オブジェクトの基底クラス
	@author Ay
	@date 2024/11/07
*/
#pragma once
#include "Utility.hpp"

namespace Ay {
	// @brief オブジェクトの基底クラス
	class Object {
	private:
		static int32 createCount; // オブジェクトが生成された回数
	protected:
		uInt id;     // オブジェクトid
		string name; // オブジェクト名
	public:
		// @brief デフォルトコンストラクタ
		NODISCARD_CPP20 Object() noexcept = default;
		// @brief コンストラクタ
		// @param name オブジェクトの名前
		NODISCARD_CPP20 Object(stringView name) noexcept;
		// @brief デストラクタ
		virtual ~Object() noexcept = default;
		// @brief 初期化処理
		virtual void Ready() = 0;
		// @brief 更新処理
		// @param deltaTime 経過時間
		virtual void Update(float deltaTime) = 0;
		// @brief 描画処理
		virtual void Draw() const = 0;
		// @brief オブジェクトの名前をセットする
		// @brief name セットする名前
		void SetName(stringView name) noexcept {
			this->name = name;
		}
		// @return オブジェクトの名前を返す
		NODISCARD const string& GetName() const noexcept {
			return name;
		}
		// @brief オブジェクトIDをセットする
		// @param other セットしたいオブジェクトID
		void SetID(uInt other) noexcept {
			id = other;
		}
		// @return オブジェクトIDを返す
		NODISCARD uInt GetID() const noexcept {
			return id;
		}
		// オブジェクトを生成した回数
		static NODISCARD uInt GetCreateCount() noexcept {
			return createCount;
		}
	};
}

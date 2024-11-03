/*
    @file GameObjectManager.hpp
    @brief オブジェクト管理
    @author Ay
    @date 2024/11/03
*/
#pragma once

namespace Ay {
    // @brief オブジェクト管理
    template <class T>
    class ObjectManager final {
    private:
        std::vector<std::shared_ptr<T>> objects; // 所持しているオブジェクト
    public:
        // @brief コンストラクタ
        ObjectManager() noexcept {
            Ready();
        }
        // @brief デストラクタ
        ~ObjectManager() noexcept = default;
        // @brief 初期化処理
        void Ready() {
            objects.clear();
        }
        // @brief 更新処理
        void Update(float deltaTime) {
            for (const auto& object : objects) {
                object->Update(deltaTime);
            }
        }
        // @brief 描画処理
        void Draw() const {
            for (const auto& object : objects) {
                object->Draw();
            }
        }
        // @brief オブジェクトを追加
        void AddObject(std::shared_ptr<T> object) noexcept {
            objects.emplace_back(object);
        }
        // @brief 指定したオブジェクトを消す
        // @param name 消すオブジェクトの名前
        void DeleteObject(stringView name) noexcept {
            objects.erase(std::remove_if(objects.begin(), objects.end(),
                [&](const std::shared_ptr<T>& object){
                return object->GetName() == name;
            }), objects.end());
        }
        // @brief 指定したオブジェクトを探す
        // @brief name 探したいオブジェクトの名前
        std::shared_ptr<T> FindObject(stringView name) noexcept {
            auto it = std::find_if(objects.begin(), objects.end(),
                [&](const std::shared_ptr<T>& object) {
                    return object->GetName() == name;
                });
            return (it != objects.end()) ? *it : nullptr;
        }
    };
}

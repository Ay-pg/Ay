/*
    @file GameObjectManager.hpp
    @brief �I�u�W�F�N�g�Ǘ�
    @author Ay
    @date 2024/11/03
*/
#pragma once

namespace Ay {
    // @brief �I�u�W�F�N�g�Ǘ�
    template <class T>
    class ObjectManager final {
    private:
        std::vector<std::shared_ptr<T>> objects; // �������Ă���I�u�W�F�N�g
    public:
        // @brief �R���X�g���N�^
        ObjectManager() noexcept {
            Ready();
        }
        // @brief �f�X�g���N�^
        ~ObjectManager() noexcept = default;
        // @brief ����������
        void Ready() {
            objects.clear();
        }
        // @brief �X�V����
        void Update(float deltaTime) {
            for (const auto& object : objects) {
                object->Update(deltaTime);
            }
        }
        // @brief �`�揈��
        void Draw() const {
            for (const auto& object : objects) {
                object->Draw();
            }
        }
        // @brief �I�u�W�F�N�g��ǉ�
        void AddObject(std::shared_ptr<T> object) noexcept {
            objects.emplace_back(object);
        }
        // @brief �w�肵���I�u�W�F�N�g������
        // @param name �����I�u�W�F�N�g�̖��O
        void DeleteObject(stringView name) noexcept {
            objects.erase(std::remove_if(objects.begin(), objects.end(),
                [&](const std::shared_ptr<T>& object){
                return object->GetName() == name;
            }), objects.end());
        }
        // @brief �w�肵���I�u�W�F�N�g��T��
        // @brief name �T�������I�u�W�F�N�g�̖��O
        std::shared_ptr<T> FindObject(stringView name) noexcept {
            auto it = std::find_if(objects.begin(), objects.end(),
                [&](const std::shared_ptr<T>& object) {
                    return object->GetName() == name;
                });
            return (it != objects.end()) ? *it : nullptr;
        }
    };
}

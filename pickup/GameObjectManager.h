#pragma once
#include "GameObject.h"
#include "DrawManager.h"

class GameObjectManager
{
private:
    std::vector<std::unique_ptr<GameObject>> objects;

    GameObjectManager() = default;
    DrawManager* drawManager = nullptr;
public:
    static GameObjectManager& GetInstance()
    {
        static GameObjectManager instance;
        return instance;
    }

	void SetDrawManager(DrawManager* dm) { drawManager = dm; }  

    template<typename T, typename... Args>
    T* Create(Args&&... args)
    {
        static_assert(std::is_base_of<GameObject, T>::value,
            "T must derive from GameObject");

        auto obj = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = obj.get();
        objects.push_back(std::move(obj));
        return ptr;
    }

    void Destroy(GameObject* obj);
    void Update();
	void ClearDeadObjects()
	{
        objects.erase(
            std::remove_if(objects.begin(), objects.end(),
                [this](const std::unique_ptr<GameObject>& obj)
                {
                    if (obj->IsDead())
                    {
                        drawManager->Remove(obj.get());
                        return true;
                    }
                    return false;
                }),
            objects.end()
        );
	}
    void Clear();
};

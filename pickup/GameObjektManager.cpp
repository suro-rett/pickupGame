#include "stdafx.h"
#include "GameObjectManager.h"

void GameObjectManager::Destroy(GameObject* obj)
{
	obj->IsDead(); // すぐに削除せず、Updateでまとめて削除する
}

void GameObjectManager::Update()
{
    for (auto& obj : objects)
    {
        obj->Update();
    }
}


void GameObjectManager::Clear()
{
    objects.clear(); // unique_ptr なので一括解放
}
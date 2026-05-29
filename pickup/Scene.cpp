#include "stdafx.h"
#include "Scene.h"
#include "GameObjectManager.h"
#include "ColliderManager.h"

void Scene::Initialize()
{
	GameObjectManager::GetInstance().SetDrawManager(&drawManager);
	
}

void Scene::Update()
{
	GameObjectManager::GetInstance().Update();
	ColliderManager::GetInstance().CheckAllCollisions();
	GameObjectManager::GetInstance().ClearDeadObjects();
}

void Scene::Draw()
{
	drawManager.Clear();
	drawManager.DrawAll(camera);
#if DEBUG
	ColliderManager::GetInstance().DebugDraw();
#endif
}

void Scene::Finalize()
{
	GameObjectManager::GetInstance().Clear();
}

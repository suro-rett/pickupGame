#include "stdafx.h"
#include "Scene.h"
#include "GameObjectManager.h"
#include "ColliderManager.h"
#include "Player.h"


void Scene::Initialize()
{
	GameObjectManager::GetInstance().SetDrawManager(&drawManager);
	//camera.SetCameraPos({ Config::ScreenWidth / 2,Config::ScreenHeight / 2 });
	player.Initialize();
}

void Scene::Update()
{
	GameObjectManager::GetInstance().Update();
	ColliderManager::GetInstance().CheckAllCollisions();
	GameObjectManager::GetInstance().ClearDeadObjects();
	player.Update();
}

void Scene::Draw()
{
	drawManager.Clear();
	drawManager.Add(&player);
	drawManager.DrawAll(camera);
#if DEBUG
	ColliderManager::GetInstance().DebugDraw();
#endif
}

void Scene::Finalize()
{
	GameObjectManager::GetInstance().Clear();
}

#include "stdafx.h"
#include "Scene.h"
#include "GameObjectManager.h"
#include "ColliderManager.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemObjMgr.h"


void Scene::Initialize()
{
	GameObjectManager::GetInstance().SetDrawManager(&drawManager);
	//camera.SetCameraPos({ Config::ScreenWidth / 2,Config::ScreenHeight / 2 });
	player.Initialize();
	enemy = new Enemy{ {100,200},50,50,5 };
}

void Scene::Update()
{
	GameObjectManager::GetInstance().Update();
	ColliderManager::GetInstance().CheckAllCollisions();
	GameObjectManager::GetInstance().ClearDeadObjects();
	enemy->Update();
	player.Update();
}

void Scene::Draw()
{
	drawManager.Clear();
	drawManager.Add(&player);
	drawManager.Add(enemy);
	ItemObjMgr::GetInstance()->RegisterDraw(drawManager);
	drawManager.DrawAll(camera);
	ui.Draw();
#if DEBUG
	ColliderManager::GetInstance().DebugDraw();
#endif
}

void Scene::Finalize()
{
	GameObjectManager::GetInstance().Clear();
}

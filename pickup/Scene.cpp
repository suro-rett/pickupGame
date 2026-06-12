#include "stdafx.h"
#include "Scene.h"
#include "GameObjectManager.h"
#include "ColliderManager.h"
#include "Enemy.h"
#include "ItemObjMgr.h"

void Scene::Initialize()
{
	GameObjectManager::GetInstance().SetDrawManager(&drawManager);
	//Enemy::GetInstance().Enemy()
	enemy = new Enemy{ {100,200},50,50,5 };
}

void Scene::Update()
{
	GameObjectManager::GetInstance().Update();
	ColliderManager::GetInstance().CheckAllCollisions();
	GameObjectManager::GetInstance().ClearDeadObjects();
	enemy->Update();
}

void Scene::Draw()
{
	drawManager.Clear();
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
	delete enemy;
	GameObjectManager::GetInstance().Clear();
}

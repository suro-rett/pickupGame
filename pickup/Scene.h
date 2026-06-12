#pragma once
#include "DrawManager.h"
#include "Camera.h"
#include "Enemy.h"
#include "UIManager.h"
#include "Player.h"
class Scene
{
private:
	DrawManager drawManager;
	Camera camera;
	Enemy* enemy = nullptr;
	UIManager* ui = nullptr;
	Player player;
public:
	virtual ~Scene() {}
	void Finalize();
	void Initialize();
	void Update() ;
	void Draw() ;
};


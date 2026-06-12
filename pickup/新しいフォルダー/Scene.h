#pragma once
#include "DrawManager.h"
#include "Camera.h"
#include "Enemy.h"
#include "UIManager.h"

class Scene
{
private:
	DrawManager drawManager;
	Camera camera;
	Enemy* enemy = nullptr;
	UIManager ui;
public:
	virtual ~Scene() {}
	void Finalize();
	void Initialize();
	void Update() ;
	void Draw() ;
};


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
	UIManager* ui = nullptr;
public:
	virtual ~Scene() {}
	void Finalize();
	void Initialize();
	void Update() ;
	void Draw() ;
};


#pragma once
#include "DrawManager.h"
#include "Camera.h"
#include "Player.h"

class Scene
{
private:
	DrawManager drawManager;
	Camera camera;
	Player player;
public:
	virtual ~Scene() {}
	void Finalize();
	void Initialize();
	void Update() ;
	void Draw() ;
};


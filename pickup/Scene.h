#pragma once
#include "DrawManager.h"
#include "Camera.h"

class Scene
{
private:
	DrawManager drawManager;
	Camera camera;
public:
	virtual ~Scene() {}
	void Finalize();
	void Initialize();
	void Update() ;
	void Draw() ;
};


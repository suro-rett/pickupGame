#pragma once

#include "GameObject.h"
#include "stdafx.h"
#include "Collider.h"

class UIManager :public GameObject
{
private:
	int x = 50,y = 100,width = 860, height = 390;
	Vector2D<float> size;
	BoxCollider* collider = nullptr;
public:
	UIManager(Vec2f _pos);
//	Vec2f GetPosition() const { return Vec2f(x, y); }
	void Initialize();
	void Draw();

};

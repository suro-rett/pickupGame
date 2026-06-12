#pragma once

#include "GameObject.h"
#include "stdafx.h"
#include "Collider.h"

class Enemy:public GameObject
{
private:
	int width, height;	//敵のxy座標、幅、高さ
	int px;				//敵の移動量
	Vector2D<float> size;
	BoxCollider* collider = nullptr;
public:
//	Enemy();
	Enemy(Vec2f _pos,int width,int height,int Px);
	void Update() override;
	void Draw(const Camera& camera) override;
	void Initialize();
	void MoveEnemy();
//	void DrawEnemy();

};

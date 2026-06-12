#include "stdafx.h"
#include "Enemy.h"
#include "Collider.h"


Enemy::Enemy(Vec2f _pos,int Width,int Height,int Px)
{
	pos.x = _pos.x,pos.y = _pos.y;
	width = Width, height = Height;
	size = Vec2f((float)width/2, (float)height/2);
	px = Px;
}

void Enemy::MoveEnemy()
{
	pos.x += px;	//敵の移動

	if (pos.x < 50 || pos.x + width > 910) {	//敵が画面外に出たら
		pos.x -= px;							//敵がはみ出さないようにする
		px = -px;								//移動量を反転させる
	}
	
}

void Enemy::Initialize()
{
	auto co = std::make_unique<BoxCollider>(Vec2f{0 + (float)width / 2,0 +(float)height / 2 }, size);
	collider = co.get();
	co->SetTag(ColliderTag::TAG_ENEMY);
	AddCollider(std::move(co));
}

void Enemy::Update() 
{
	MoveEnemy();
}

void Enemy::Draw(const Camera& camera)
{
	DrawBox((int)pos.x, (int)pos.y, (int)pos.x + width, (int)pos.y + height, 0xffffff, TRUE);	//敵の描画
}
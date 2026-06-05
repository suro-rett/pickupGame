#include "stdafx.h"
#include "ItemObj.h"
#include "Collider.h"
ItemObj::ItemObj()
{
	Initialize();
}


void ItemObj::Initialize()
{
	auto collider = std::make_unique<CircleCollider>(Vec2f(0.0f, 0.0f), radius);
	collider->SetTag(ColliderTag::TAG_ITEM);
	AddCollider(std::move(collider));
	pos = RandomPos();
}

Vec2f ItemObj::RandomPos()
{
	return { static_cast<float>(rand() % Config::ScreenWidth), static_cast<float>(rand() % Config::ScreenHeight) };
}

void ItemObj::OnCollision(BaseCollider* collider)
{
	if (collider->GetTag() == ColliderTag::TAG_PLAYER)
	{
		//Kill(); // プレイヤーと衝突した際に自身を消す
		isPickUp = true; // プレイヤーと衝突した際にアイテムを拾ったことにする
	}
}

void ItemObj::Draw(const Camera& camera)
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		isPickUp = true;
		
	}
	else {
		isPickUp = false;
	}

	if (IsPickUp()) {
		//ここでプレイヤーのポインタを参照して、プレイヤーの位置に描画するようにする
		//仮呼び出し
		Vec2f playerPos = {10,10};
		Vec2f* cPos = &playerPos; 

		DrawCircleAA(cPos->x, cPos->y, radius, 32, GetColor(0, 0, 255), TRUE);
	}
	else {
		DrawCircleAA(pos.x, pos.y, radius, 32, GetColor(0, 0, 255), TRUE);
	}
}
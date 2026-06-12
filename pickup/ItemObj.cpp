#include "stdafx.h"
#include "ItemObj.h"
#include "Collider.h"
#include "ItemObjMgr.h"
ItemObj::ItemObj(rect genarateOffArea)
{
	Initialize();
	RandomPos(genarateOffArea);
}


void ItemObj::Initialize()
{
	auto collider = std::make_unique<CircleCollider>(Vec2f(0.0f, 0.0f), radius);
	collider->SetTag(ColliderTag::TAG_ITEM);
	AddCollider(std::move(collider));
}

void ItemObj::RandomPos(rect genarateOffArea)
{
	genarateOffArea.GetRect();
	int l, r, t, b;
	l=Config::ScreenWidth* genarateOffArea.GetRect().GetLeft();
	r = Config::ScreenWidth * (1-genarateOffArea.GetRect().GetRight());
	t = Config::ScreenHeight * genarateOffArea.GetRect().GetTop();
	b =  Config::ScreenHeight *(1 - genarateOffArea.GetRect().GetBottom());

	pos = { static_cast<float>(rand() % (r - l) + l), static_cast<float>(rand() % (b - t) + t) };
}

void ItemObj::OnCollision(BaseCollider* collider)
{
	if (collider->GetTag() == ColliderTag::TAG_PLAYER)
	{
		isPickUp = true; // プレイヤーと衝突した際にアイテムを拾ったことにする
	}
	if(collider->GetTag() == ColliderTag::TAG_ENEMY
	   &&IsPickUp())
	{
		//敵と衝突した際は現在のプレイヤーの位置にアイテムを落とす 勝手に戻さないよう取得状態かも確認する
		isPickUp = false; // アイテムを落とす
		pos = *ItemObjMgr::GetInstance()->GetpPlayerPos();
	}
}

void ItemObj::Draw(const Camera& camera)
{

	if (IsPickUp()) {
		//ここでプレイヤーのポインタを参照して、プレイヤーの位置に描画するようにする
		//仮呼び出しVec2f*
	
		Vec2f* cPos = ItemObjMgr::GetInstance()->GetpPlayerPos(); 

		//プレイヤーの位置座標のポインタがnullptrでないことを確認
		assert(cPos != nullptr );

		DrawCircleAA(cPos->x, cPos->y, radius, 32, GetColor(0, 0, 255), TRUE);
	}
	else {
		DrawCircleAA(pos.x, pos.y, radius, 32, GetColor(0, 0, 255), TRUE);
	}
}
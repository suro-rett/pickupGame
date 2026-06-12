#pragma once
#include <vector>
#include <memory>

#include "ItemObj.h"
#include "DrawManager.h"

class ItemObjMgr
{
private:
	ItemObjMgr();
	~ItemObjMgr();
	static ItemObjMgr* instance;
	std::vector<ItemObj*> itemObjs;

	Vec2f* pPlayerPos;//プレイヤーの位置を参照するためのポインタ

	int ganarataCount;//生成するアイテムの数
	rect generateOffArea;//生成するエリアの範囲

	void Init();
	

public:
	//シングルトン化
	static ItemObjMgr* GetInstance()
	{
		if(instance == nullptr)
		{
			instance = new ItemObjMgr();
		}
		return instance;
	}

	void RegisterDraw(DrawManager& drawManager);
	void RisetPickUpItem();//プレイヤーが敵に当たるなど取得が不可になった状態に呼ぶ関数
	int GetAllPickUpItem();//プレイヤーの長さが指定以下になったときに回収用で呼ぶ関数

	void SetPPlayerPos(Vec2f* pos) { pPlayerPos = pos; } // プレイヤーの位置をセットするための関数
	Vec2f* GetpPlayerPos() { return pPlayerPos; } // プレイヤーの位置を取得するための関数
};
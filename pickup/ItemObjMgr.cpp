#include "stdafx.h"
#include "ItemObjMgr.h"
#include "DrawManager.h"
ItemObjMgr* ItemObjMgr::instance;

ItemObjMgr::ItemObjMgr()
{
    Init();
}

ItemObjMgr::~ItemObjMgr()
{

    for (auto& item : itemObjs)
    {
        delete item;
    }
    itemObjs.clear();
}

void ItemObjMgr::Init()
{
	currentGetItemCount = 0; //初期化
	ganarataCount = 20; //生成するアイテムの数
    generateOffArea = rect(0.05f, 0.35f, 0.05f, 0.1f);
    for (int i = 0; i < ganarataCount; i++) {
        itemObjs.push_back(new ItemObj(generateOffArea));
    }
}

void ItemObjMgr::Update()
{
    
    //高さが取得条件を満たしているかを見た後に、フラグが立っていればアイテム回収をする
    for (auto& item : itemObjs)
    {
        if (item && !item->IsDead())
        {
            if(item->IsPickUp())
            {
				item->SetPosition(*pPlayerPos); // アイテムの位置をプレイヤーの位置に合わせる
			}

            if (item->IsHeightCheck()) {
                if (item && item->IsPickUp())
                {
                    currentGetItemCount++;
                    item->Kill(); // アイテムを回収した後は削除する
                }
            }
        }
    }
}

void ItemObjMgr::RegisterDraw(DrawManager& drawManager)
{
    for (auto& item : itemObjs)
    {
        if (item && !item->IsDead())
        {
            drawManager.Add(item);
        }
    }
}


void ItemObjMgr::RisetPickUpItem()
{
    for (auto& item : itemObjs)
    {
        if (item && item->IsPickUp())
        {
			RisetPickUpItem(); // アイテムの取得状態をリセット
        }
    }
}
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
	ganarataCount = 20; //生成するアイテムの数
    generateOffArea = rect(0.05f, 0.3f, 0.05f, 0.1f);
    for (int i = 0; i < ganarataCount; i++) {
        itemObjs.push_back(new ItemObj(generateOffArea));
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

int ItemObjMgr::GetAllPickUpItem()
{
    int count = 0;
    for (auto& item : itemObjs)
    {
        if (item && item->IsPickUp())
        {
            count++;
            item->Kill(); // アイテムを回収した後は削除する
        }
    }
    return count;
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
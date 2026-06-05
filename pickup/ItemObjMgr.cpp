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
    // アイテムオブジェクトのクリーンアップ
    for (auto& item : itemObjs)
    {
        delete item;
    }
    itemObjs.clear();
}

void ItemObjMgr::Init()
{
    // アイテムオブジェクトの初期化
    // ここでは例として、いくつかのアイテムオブジェクトを作成して追加しています。
    for (int i = 0; i < 10; i++) {
        itemObjs.push_back(new ItemObj());
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
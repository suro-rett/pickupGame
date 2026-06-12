#include "stdafx.h"
#include "UIManager.h"
#include "Collider.h"

UIManager::UIManager(Vec2f _pos)
{
	size = Vec2f((float)width / 2, (float)height / 2);
}


void UIManager::Draw()
{
	DrawBox(x, y, x + width, y + height, 0xffffff, FALSE);
}

void UIManager::Initialize()
{
	auto co1 = std::make_unique<BoxCollider>(Vec2f{ x + -(float)width / 2, y + (float)height / 2 }, size);
	collider = co1.get();
	co1->SetTag(ColliderTag::TAG_STAGE);
	AddCollider(std::move(co1));
	auto co2 = std::make_unique<BoxCollider>(Vec2f{ x + (float)width * 1.5f, y + (float)height / 2 }, size);
	collider = co2.get();
	co2->SetTag(ColliderTag::TAG_STAGE);
	AddCollider(std::move(co2));
	auto co3 = std::make_unique<BoxCollider>(Vec2f{ x + (float)width / 2, y + (float)height * 1.5f }, size);
	collider = co3.get();
	co3->SetTag(ColliderTag::TAG_STAGE);
	AddCollider(std::move(co3));
}

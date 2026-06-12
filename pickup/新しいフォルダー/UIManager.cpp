#include "stdafx.h"
#include "UIManager.h"


void UIManager::Draw()
{
	DrawBox(x, y, x + width, y + height, 0xffffff, FALSE);
}

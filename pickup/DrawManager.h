#pragma once
#include "Drawable.h"

class DrawManager
{
public:
    void Add(Drawable* obj);

    void Remove(Drawable* obj);

    void DrawAll(const Camera& camera);

	void Clear() { drawList.clear(); }

private:
	bool isSorted = true; // 描画リストがソートされているかどうかのフラグ.
    std::vector<Drawable*> drawList;
};

#pragma once
#include "GameObject.h"

class rect {
private:
	float left;
	float top;
	float right;
	float bottom;
public:
	rect() = default;

	rect(float l, float t, float r, float b)
		: left(l), top(t), right(r), bottom(b)
	{
	}
	void SetRect(float l, float t, float r, float b) { left = l; top = t; right = r; bottom = b; }
	rect GetRect() const
	{
		return rect (left, top, right, bottom);
	}
	float GetLeft() const { return left; }
	float GetTop() const { return top; }
	float GetRight() const { return right; }
	float GetBottom() const { return bottom; }

};

class ItemObj : public GameObject
{
private:
	bool isPickUp = false;
	float radius = 15.0f;


	void RandomPos(rect genarateOffArea);
public:
	ItemObj(rect genarateOffArea);
	~ItemObj() = default;
	void Initialize() override;
	void Finalize() override {};
	void Update() override {};
	void Draw(const Camera& camera) override ;
	void OnCollision(BaseCollider* other) override;

	bool IsPickUp() const { return isPickUp; }
	bool RisetIsPickUp() { return isPickUp = false; }
};

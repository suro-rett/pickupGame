#pragma once
#include "GameObject.h"

class ItemObj : public GameObject
{
private:
	bool isPickUp = false;
	float radius = 15.0f;

	Vec2f RandomPos();
public:
	ItemObj();
	~ItemObj() = default;
	void Initialize() override;
	void Finalize() override {};
	void Update() override {};
	void Draw(const Camera& camera) override ;
	void OnCollision(BaseCollider* other) override;

	bool IsPickUp() const { return isPickUp; }
	bool RisetIsPickUp() { return isPickUp = false; }
};

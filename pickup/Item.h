#pragma once
#include "GameObject.h"
class Enemy :
    public GameObject
{
public:
	void OnCollision(BaseCollider* collider) override;

	void Initialize();
	void Finalize();
	void Update();
	void Draw(const Camera& camera) override;
};


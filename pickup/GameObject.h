#pragma once
#include "BaseCollider.h"
#include "Drawable.h"
#include "DrawManager.h"
class GameObject : public Drawable
{
protected:
    Vector2D<float> pos = { 0,0 };
private:
    std::vector<std::unique_ptr<BaseCollider>> colliders;

	bool isDead = false; //オブジェクトが死んでいるかどうかのフラグ.
public:
    
    Vector2D<float> GetPosition() const { return pos; }
    void SetPosition(const Vector2D<float>& p) { pos = p; }

    void AddCollider(std::unique_ptr<BaseCollider> col);

	void Kill() {
        isDead = true; 
        for (auto& col : colliders)
        {
            col->MarkRemove();
        }
    }
	bool IsDead() const { return isDead; }

    const auto& GetColliders() const { return colliders; }

    virtual void OnCollision(BaseCollider* other) {};

	void CreateAnimation() override {};

    virtual void Initialize()   {}; //初期化.
    virtual void Finalize()     {}; //終了処理.
    virtual void Update()       {}; //更新.
    virtual void Draw(const Camera& camera) override {};

};
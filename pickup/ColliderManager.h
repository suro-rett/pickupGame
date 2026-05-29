#pragma once
#include <vector>
#include "BaseCollider.h"
#include "Collider.h"

class ColliderManager
{
private:
    std::vector<BaseCollider*> colliders;
    ColliderManager() = default;

    bool CheckPair(BaseCollider* a, BaseCollider* b);

    bool CircleVsCircle(const CircleCollider* a, const CircleCollider* b);
    bool BoxVsBox(const BoxCollider* a, const BoxCollider* b);
    bool CircleVsBox(const CircleCollider* c, const BoxCollider* b);
    bool CircleVsCapsule(const CircleCollider* circle, const CapsuleCollider* cap);
    bool CapsuleVsCapsule(const CapsuleCollider* a, const CapsuleCollider* b);
    bool CapsuleVsBox(const CapsuleCollider* cap, const BoxCollider* box);
    bool SegmentVsBox(const Vector2D<float>& a, const Vector2D<float>& b, const BoxCollider* box, float radius);
public:
    static ColliderManager& GetInstance()
    {
        static ColliderManager instance;
        return instance;
    }
    // 登録・解除
    void Register(BaseCollider* col)
    {
        colliders.push_back(col);
    }
    void Unregister(BaseCollider* col)
    {
        if (col)
        {
            col->MarkRemove();
        }
    }

    float DistanceSq_Point_Segment(const Vector2D<float>& pc, const Vector2D<float>& a,const Vector2D<float>& b);

    // 衝突判定
    void CheckAllCollisions();
#ifdef DEBUG
    void DebugDraw();
#endif 

};

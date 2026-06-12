#pragma once

enum class ColliderTag
{
    TAG_NULL,
    TAG_PLAYER,
    TAG_ENEMY,
    TAG_STAGE,
};

enum class ColliderType
{
    BOX,
    CIRCLE,
    CAPSULE,

    TYPE_NULL
};

class GameObject;

class BaseCollider
{
private:
    bool pendingRemove = false;
protected:
    Vector2D<float> localPos{ 0,0 };
    GameObject* owner = nullptr;
    ColliderTag tag = ColliderTag::TAG_NULL;

public:
    virtual ~BaseCollider();

    void SetOwner(GameObject* o);
    GameObject* GetOwner() const { return owner; }

    void SetLocalPosition(const Vector2D<float>& p) { localPos = p; }
    Vector2D<float> GetWorldPosition() const;

    void SetTag(ColliderTag t) { tag = t; }
    ColliderTag GetTag() const { return tag; }

    virtual ColliderType GetColliderType() const = 0;

    void MarkRemove()
    {
        pendingRemove = true;
    }

    bool IsPendingRemove() const
    {
        return pendingRemove;
    }

#ifdef DEBUG
    virtual void DebugDraw() {};
#endif
};
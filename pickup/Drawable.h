#pragma once
#include "Camera.h"

//描画の基底クラス.
class Drawable
{
protected:
private:
    int drawLayer = 0;
public:
    virtual ~Drawable() {}

    virtual void Draw(const Camera& camera) = 0;
    virtual void CreateAnimation() {};

    std::function<void()> onLayerChanged;
    void SetDrawLayer(int _drawLayer) { 
        drawLayer = _drawLayer;
        if (onLayerChanged)
            onLayerChanged();
    }

    int GetDrawLayer() const { return drawLayer; }
};


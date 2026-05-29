#include "stdafx.h"
#include "TimeLayer.h"

void TimeLayer::Update(float baseDelta) {
    time += baseDelta * timeScale;
}
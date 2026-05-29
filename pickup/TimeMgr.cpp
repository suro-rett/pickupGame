#include "stdafx.h"
#include "TimeMgr.h"

TimeMgr* TimeMgr::instance = nullptr;

void TimeMgr::unInit() {                   //デストラクタの代わり
    delete instance;
    instance = nullptr;
}

TimeMgr* TimeMgr::getInstance() {

    if (instance == nullptr) {
        instance = new TimeMgr();
        instance->Initialize();
    }
    return instance;
}

void TimeMgr::Update() {
    unsigned int now = GetNowCount();
    float delta = (float)(now - prevRealTime);
    prevRealTime = now;
    gameTime += delta;

    for (auto& layer : layers) {
        layer.Update(delta);
    }
}

int TimeMgr::setGameTime() {
    return (int)gameTime;
}

void TimeMgr::Initialize() {
    prevRealTime = GetNowCount();
    gameTime = 0.0f;

    for (auto& layer : layers) {
        layer = TimeLayer();
    }
}
#pragma once
#include "Time.h"

class OneShiftLerp {
private:
    float* Num1;      // 外部変数を直接更新
    float startNum1;
    float targetNum1;
    float duration;

    bool Back;
    bool BackNext = false;

    Time timer;
    bool finished = false;

public:
    OneShiftLerp(float* num1, float targetNum1, float duration,TimeLayerType timelayer, bool back = false);

    void Update();

    bool IsFinished() const;
};
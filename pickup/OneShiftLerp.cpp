#include "stdafx.h"
#include "OneShiftLerp.h"

OneShiftLerp::OneShiftLerp(float* num1, float targetNum1, float duration, TimeLayerType timelayer, bool back)
    : Num1(num1), duration(duration), targetNum1(targetNum1),timer(timelayer), Back(back)
{
    startNum1 = *Num1;
    timer.resetTimer();
}

void OneShiftLerp::Update() {
    if (finished) return;
    float t;
    if (!Back) {
        t = timer.setTimeMS() / duration;
    }
    else {
        t = timer.setTimeMS() / (duration / 2);
    }

    if (t >= 1.0f) {
        t = 1.0f;
    }

    *Num1 = startNum1 + (targetNum1 - startNum1) * t;
    
    if (t >= 1.0f) {
        if (!BackNext && Back) {
            timer.resetTimer();
            std::swap(startNum1, targetNum1);
            BackNext = true;
        }
        else {
            finished = true;
        }
    }
}

bool OneShiftLerp::IsFinished() const {
    return finished;
}
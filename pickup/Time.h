#pragma once
#include "TimeLayer.h"





class Time{
private:
	float start=0;
	TimeLayer* layer = nullptr;
public:
	Time(TimeLayerType type);
	void resetTimer();	// タイマーの初期値をリセットする
	float setTimeS();	// 今現在resetTimerがされてか何秒経過したかが取得できる 下三桁まで
	float setTimeMS();	// 今現在resetTimerがされてから
};





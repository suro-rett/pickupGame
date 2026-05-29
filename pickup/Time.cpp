#include "stdafx.h"
#include "Time.h"
#include "TimeMgr.h"
//#include "DxLib.h"





void Time::resetTimer() {
    start = layer->getTime();
}

float Time::setTimeS() {
	float now = layer->getTime();
	return (now - start) / 1000.f;
}

float Time::setTimeMS() {
    return layer->getTime() - start;
}

Time::Time(TimeLayerType type) {
    layer = &TimeMgr::getInstance()->getLayer(type);
}


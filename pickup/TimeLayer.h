#pragma once

enum class TimeLayerType {
	Object,
	UI,

	MAX_LAYER_NUM
};

class TimeLayer {
private:
	float time = 0.0f;
	float timeScale = 1.0f;

public:
	void Update(float baseDelta);

	float getTime() const { return time; }

	void TimeAlter(float s) { if (s < 0)s = 0; timeScale = s; }

	float getLayerTimeScale() { return timeScale; }
};
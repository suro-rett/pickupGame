#pragma once
#include <array>
#include "TimeLayer.h"

class TimeMgr {
private:
	TimeMgr(){}
	~TimeMgr() {}
	static TimeMgr* instance;

	std::array<TimeLayer, static_cast<size_t>(TimeLayerType::MAX_LAYER_NUM)> layers;
	unsigned int prevRealTime = 0;   // 前フレームの実時間
	float gameTime = 0.0f;           // ゲーム内時間（秒）
public:
	TimeLayer& getLayer(TimeLayerType type) { return layers[static_cast<size_t>(type)]; }

	float getDelta() const { return gameTime; }
	static void unInit();                   //デストラクタの代わり
	static TimeMgr* getInstance();          //インスタンスを取得するゲッター 
	int setGameTime();
	void Initialize();      //初期化処理
	void Update();          //更新処理
};
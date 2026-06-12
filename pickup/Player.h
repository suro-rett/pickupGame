#pragma once
#include "GameObject.h"
#include "Camera.h"
class Player :
    public GameObject
{
private:
	Camera* camera = nullptr; // カメラへのポインタ
	const float speed = 5.0f; // プレイヤーの移動速度

	float circleR = 16;		//プレイヤーの円の半径
	int vector = 1;


	int length = 50;
	float time = 0.0f;
	float angle = 0.0f;
	float Linespeed = 0.02f;

	bool shot = false;		//発射してる状態か
	bool back = false;		//帰ってきてる途中か
public:
	void OnCollision(BaseCollider* collider) override;

	void GetCamera(Camera* cam) { camera = cam; } // カメラをセットするための関数

	void Initialize() ;
	void Finalize() ;
	void Update() ;
	void Draw(const Camera& camera) override;

};


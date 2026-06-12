#include "stdafx.h"
#include "Player.h"
#include "Collider.h"
#include "ItemObjMgr.h"

void Player::OnCollision(BaseCollider* collider)
{
	if (collider->GetTag() == ColliderTag::TAG_ENEMY || collider->GetTag() == ColliderTag::TAG_STAGE)
	{
		if (shot) {
			shot = false;
			back = true;
		}
		if (!shot && !back) {
			timeVec *= -1;
		}

	}
}

void Player::Initialize()
{
	auto collider = std::make_unique<CircleCollider>(Vec2f(0.0f, 0.0f), 8.0f);
	collider->SetTag(ColliderTag::TAG_PLAYER);
	AddCollider(std::move(collider));

	Stinger = { Config::ScreenWidth / 2,Config::ScreenHeight / 4 - 35 };
}

void Player::Finalize()
{
	// Clean up resources if needed         
}

void Player::Update()
{
	Vec2f inputDir = { 0.0f, 0.0f };
	if (IsPushKey(KEY_INPUT_LEFT) && Stinger.x >= 50 + circleR)
	{
		inputDir.x -= speed;
	}
	if (IsPushKey(KEY_INPUT_RIGHT) && Stinger.x <= Config::ScreenWidth - 50 -circleR)
	{
		inputDir.x += speed;
	}
	Stinger += inputDir;

	if (IsPushKey(KEY_INPUT_SPACE) && !shot&&!back &&Remaining > 0)
	{
		shot = true;
		back = false;
		Remaining--;
	}

	if (IsPushKey(KEY_INPUT_C) && shot && !back)
	{
		shot = false;
		back = true;
	}

	if (!shot &&back&&length<50)
	{
		
		shot = false;
		back = false;
	}

	if (shot) {
		length += 5;
	}

	if (back) {
		length -= 5;
	}

	if (!shot && !back) {
		time += 0.05f * timeVec;
		angle = sin(time) * DX_PI_F / 4.0f;
	}


	//Vec2f cameraPos = camera->GetPos() - inputDir; // カメラの位置をプレイヤーの位置に合わせる	
	//camera->SetCameraPos(cameraPos); // カメラの位置をプレイヤーの位置に合わせる

}

void Player::Draw(const Camera& camera)
{
	//Vec2f screenPosition = camera.ToScreen(pos);
	DrawCircleAA(Stinger.x, Stinger.y, circleR, 32, GetColor(0, 255, 0));


	// ±45度
	pos = { Stinger.x + static_cast<float>(length * sin(angle)) ,Stinger.y + static_cast<int>(length * cos(angle)) };
	

	DrawLineAA( Stinger.x, Stinger.y, pos.x, pos.y, GetColor(255, 255, 255));
	DrawCircleAA(pos.x, pos.y, 8,32, GetColor(255,255, 0), TRUE);

	DrawFormatString(Config::ScreenWidth - Config::ScreenWidth / 4, Config::ScreenHeight / 4 - 100, GetColor(255, 255, 255), "残り発射回数:%d", Remaining);
	DrawFormatString(Config::ScreenWidth - Config::ScreenWidth / 4, Config::ScreenHeight / 4 - 75, GetColor(255, 255, 255), "手に入れたお宝:%d個", ItemObjMgr::GetInstance()->GetItemCount());
}

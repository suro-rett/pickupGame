#include "stdafx.h"
#include "Player.h"
#include "Collider.h"

void Player::OnCollision(BaseCollider* collider)
{
	if (collider->GetTag() == ColliderTag::TAG_ENEMY)
	{
		
	}
}

void Player::Initialize()
{
	auto collider = std::make_unique<CircleCollider>(Vec2f(0.0f, 0.0f), 16.0f);
	collider->SetTag(ColliderTag::TAG_PLAYER);
	AddCollider(std::move(collider));

	pos = { Config::ScreenWidth / 2,Config::ScreenHeight / 4 };
}

void Player::Finalize()
{
	// Clean up resources if needed         
}

void Player::Update()
{
	Vec2f inputDir = { 0.0f, 0.0f };
	if (IsPushKey(KEY_INPUT_LEFT) && pos.x >= 0 + circleR)
	{
		inputDir.x -= speed;
	}
	if (IsPushKey(KEY_INPUT_RIGHT) && pos.x <= Config::ScreenWidth - circleR)
	{
		inputDir.x += speed;
	}
	pos += inputDir;

	time += 0.05f;
	angle = sin(time) * DX_PI_F / 4.0f;
	//Vec2f cameraPos = camera->GetPos() - inputDir; // カメラの位置をプレイヤーの位置に合わせる	
	//camera->SetCameraPos(cameraPos); // カメラの位置をプレイヤーの位置に合わせる

}

void Player::Draw(const Camera& camera)
{
	//Vec2f screenPosition = camera.ToScreen(pos);
	DrawCircleAA(pos.x, pos.y, circleR, 32, GetColor(0, 255, 0));


	// ±45度

	int endX = pos.x + static_cast<int>(length * sin(angle));
	int endY = pos.y + static_cast<int>(length * cos(angle));

	DrawLine(pos.x, pos.y, endX, endY, GetColor(255, 255, 255));
	DrawCircle(endX, endY, 15, GetColor(255, 0, 0), TRUE);
}

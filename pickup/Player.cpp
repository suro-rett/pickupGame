#include "stdafx.h"
#include "Player.h"
#include "Collider.h"
#include "PlayerManager.h"

void Player::OnCollision(BaseCollider* collider)
{
	if (collider->GetTag() == ColliderTag::TAG_ENEMY)
	{
		Kill(); // プレイヤーが敵と衝突した場合、プレイヤーを死なせる
		PlayerManager::GetInstance().SetPlayer(nullptr); // プレイヤーが死んだので、PlayerManagerのプレイヤーポインタをnullptrにする
	}
}

void Player::Initialize()
{
	auto collider = std::make_unique<CircleCollider>(Vec2f(0.0f, 0.0f), 16.0f);
	collider->SetTag(ColliderTag::TAG_PLAYER);
	AddCollider(std::move(collider));

	pos = { Config::ScreenWidth / 2,Config::ScreenHeight / 2 };
}

void Player::Finalize()
{
	// Clean up resources if needed         
}

void Player::Update()
{
	Vec2f inputDir = { 0.0f, 0.0f };
	const int space = 50; // プレイヤーの移動速度
	if (IsPushKey(KEY_INPUT_UP) && pos.y <= Config::ScreenHeight + space)
	{
		inputDir.y += speed;
	}
	if (IsPushKey(KEY_INPUT_DOWN) && pos.y >= 0 - space)
	{
		inputDir.y -= speed;
	}
	if (IsPushKey(KEY_INPUT_LEFT) && pos.x <= Config::ScreenWidth + space)
	{
		inputDir.x += speed;
	}
	if (IsPushKey(KEY_INPUT_RIGHT) && pos.x >= 0 - space)
	{
		inputDir.x -= speed;
	}
	pos += inputDir;
	Vec2f cameraPos = camera->GetPos() - inputDir; // カメラの位置をプレイヤーの位置に合わせる	
	camera->SetCameraPos(cameraPos); // カメラの位置をプレイヤーの位置に合わせる

}

void Player::Draw(const Camera& camera)
{
	Vec2f screenPosition = camera.ToScreen(pos);
	DrawCircleAA(pos.x, pos.y, 16, 32, GetColor(0, 255, 0));
}
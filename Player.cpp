#include "Player.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::Init()
{
	player.pos = { 640,360 };
	player.size = { 100,100 };

	player.color = WHITE;

}

void Player::Upadte()
{
	if (InputManager::GetIsTriggerKey(DIK_W))
	{
		player.pos.y_ -= 10;
		Novice::DrawBox(0, 100, 50, 50, 0, BLUE, kFillModeSolid);

	}
	if (InputManager::GetIsPressKey(DIK_D))
	{
		player.pos.y_ -= 10;
		Novice::DrawBox(0, 150, 50, 50, 0, GREEN, kFillModeSolid);

	}
	if (InputManager::GetIsReleaseKey(DIK_S))
	{
		player.pos.y_ -= 10;
		Novice::DrawBox(0, 200, 50, 50, 0, RED, kFillModeSolid);
	}
	InputManager::GetLeftStick(inputNum);

	Novice::ScreenPrintf(0, 0, "%d %d", inputNum.x, inputNum.y);

}

void Player::Draw()
{
	Novice::DrawEllipse(int(player.pos.x_), int(player.pos.y_), int(player.size.x_ / 2), int(player.size.y_ / 2), 0, player.color,kFillModeSolid);
}

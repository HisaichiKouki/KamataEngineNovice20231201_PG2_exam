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
	}

	InputManager::GetLeftStick(inputNum);

	Novice::ScreenPrintf(0, 0, "%d %d", inputNum.x, inputNum.y);

}

void Player::Draw()
{
	Novice::DrawEllipse(int(player.pos.x_), int(player.pos.y_), int(player.size.x_ / 2), int(player.size.y_ / 2), 0, player.color,kFillModeSolid);
}

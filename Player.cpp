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

	player.velocity = { 8,8 };
	currentVel = player.velocity;
	moveRaito = 1;
	for (int i = 0; i < kMaxBullet; i++)
	{
		bullet[i] = new Bullet;
	}

	shotCT = 20;
	cullentShotCT = 0;

	easeSize=0;
	easeSizeT=0;
	setEaseTime = 30;
}

void Player::Upadte()
{
	PlayerInputMove(inputVel);

	currentVel.x_ = player.velocity.x_ * moveRaito;
	currentVel.y_ = player.velocity.y_ * moveRaito;
	player.pos += inputVel * currentVel;

	Shot();
	for (int i = 0; i < kMaxBullet; i++)
	{
		bullet[i]->Update();
	}
	InputManager::GetLeftStick(inputNum);


}

void Player::Draw()
{
	MoveSizeShake();
	Novice::DrawEllipse(int(player.pos.x_), int(player.pos.y_), int(player.size.x_ / 2+easeSize), int(player.size.y_ / 2- easeSize), 0, player.color, kFillModeSolid);


}

void Player::Debug()
{
#ifdef DEBUG


#endif // DEBUG
	Novice::ScreenPrintf(0, 0, "%d %d", inputNum.x, inputNum.y);

	Novice::ScreenPrintf(0, 20, "pos");
	player.pos.Vec2Op::Vec2OpScreenPrintf(60, 20, 1);

	Novice::ScreenPrintf(0, 100, "currentShotCT=%f", currentShotCT);

}

void Player::PlayerInputMove(Vec2Op& inputVel_)
{
	inputVel_ = { 0,0 };
	if (InputManager::GetIsPressKey(DIK_W))
	{
		inputVel_.y_--;
	}
	if (InputManager::GetIsPressKey(DIK_S))
	{
		inputVel_.y_++;
	}
	if (InputManager::GetIsPressKey(DIK_A))
	{
		inputVel_.x_--;
	}
	if (InputManager::GetIsPressKey(DIK_D))
	{
		inputVel_.x_++;
	}

	inputVel_ = Vec2Normalize(inputVel_);
}

void Player::Shot()
{

	//currentShotCT = shotCT;
	if (cullentShotCT > 0)
	{
		cullentShotCT--;
	}
	if (cullentShotCT <= 0 && InputManager::GetIsPressKey(DIK_SPACE))
	{
		for (int i = 0; i < kMaxBullet; i++)
		{
			if (!bullet[i]->isAlive)
			{
				bullet[i]->isAlive = true;

				bullet[i]->pos = player.pos;

				cullentShotCT = (int)currentShotCT;

				easeSizeT = 0;

				break;
			}
		}
	}

	if (InputManager::GetIsPressKey(DIK_SPACE))
	{
		holdSpaceTime++;
		currentShotCT = (shotCT * (1.0f - holdSpaceTime / 150));
		moveRaito = (1.0f - holdSpaceTime / 300);
		if (currentShotCT <= 2)
		{
			currentShotCT = 2;
		}
		if (moveRaito<=0.2f)
		{
			moveRaito = 0.2f;
		}
	}
	else
	{
		holdSpaceTime = 0;
		moveRaito = 1;
	}
}

void Player::MoveSizeShake()
{
	if (InputManager::GetIsReleaseKey(DIK_W)||
		InputManager::GetIsReleaseKey(DIK_A) ||
		InputManager::GetIsReleaseKey(DIK_S) ||
		InputManager::GetIsReleaseKey(DIK_D) )
	{
		easeSizeT = 0;
		
	}
	if (easeSizeT < setEaseTime)
	{
		easeSizeT++;
	}
	easeSize = Easing::OutElasticAmplitude(easeSizeT, setEaseTime, 15.0f, 0.3f);
}

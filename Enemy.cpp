#include "Enemy.h"

Enemy::Enemy()
{

	deadCountNum = 0;
	direction = 1;

	Init();
}

void Enemy::Init()
{
	pos = { 640,100 };
	//size = { 40,40 };
	radius = 40 - 13 * deadCountNum;

	color = 0xaa00aaff;

	velocity = { 4 * direction,-7 };
	isAlive = true;
	respawnTime = 60;
	currentTime = 0;
	deadTime = 30;

	isDead = false;
	isHit = false;

	hitPoint = 30;


	randPos = {};
	initRandSize = (int)radius / 4;
	currentRandSize = 0;
	easeSize = 0;
	easeSizeT = 0;
	setEaseTime = 60;

	easeDeadTime = 20;
	easeDeadSize = 0;
	easeDeadSizeT = easeDeadTime;

	rotateDeadSize = 0;
}

void Enemy::Update()
{

	if (isAlive)
	{
		pos += velocity;
		if (pos.x_ - radius < 0)
		{
			velocity.x_ *= -1;
			pos.x_ = radius;
			resetEaseT = true;
		}
		if (pos.x_ + radius > 1280)
		{
			velocity.x_ *= -1;
			pos.x_ = 1280 - radius;
			resetEaseT = true;
		}
		if (pos.y_ - radius < 0)
		{
			velocity.y_ *= -1;
			pos.y_ = radius;
			resetEaseT = true;
		}
		if (pos.y_ + radius > 720)
		{
			velocity.y_ *= -1;
			pos.y_ = 720 - radius;
			resetEaseT = true;
		}

		if (isHit)
		{
			hitPoint--;
			currentRandSize = initRandSize;
			isHit = false;
		}

		if (hitPoint <= 0)
		{

			isAlive = false;
			isDead = true;
			easeDeadSizeT = 0;

		}
	}
	else
	{
		if (currentTime < respawnTime)
		{
			currentTime++;
			if (currentTime > deadTime)
			{
				isDead = false;
			}
			else
			{
				if (easeDeadSizeT<easeDeadTime)
				{
					easeDeadSizeT++;
					rotateDeadSize += 90;
					easeDeadSize = Easing::OutElasticAmplitude(easeDeadSizeT, easeDeadTime, 30.0f, 0.3f);

				}
			}

		}
		else
		{
			direction *= -1;
			deadCountNum++;
			if (deadCountNum < 3)
			{
				Init();
			}
			else
			{
				if (InputManager::GetIsTriggerKey(DIK_R))
				{
					direction = 1;
					deadCountNum = 0;
					Init();
				}
			}


		}
	}

}

void Enemy::Draw()
{
	MoveSizeShake();
	if (currentRandSize >= 0)
	{
		randPos.x_ = (float)GetRandMinMax(-currentRandSize, currentRandSize);
		randPos.y_ = (float)GetRandMinMax(-currentRandSize, currentRandSize);
		currentRandSize -= 1;

	}
	if (deadCountNum < 3)
	{
		if (isAlive)
		{
			Novice::DrawEllipse(int(pos.x_ + randPos.x_), int(pos.y_ + randPos.y_), int(radius + easeSize), int(radius - +easeSize), 0, color, kFillModeSolid);

		}
		if (isHit)
		{
			Novice::DrawEllipse(int(pos.x_ + randPos.x_), int(pos.y_ + randPos.y_), int(radius + easeSize), int(radius - +easeSize), 0, WHITE, kFillModeSolid);

		}
		if (isDead)
		{
			Novice::DrawEllipse(int(pos.x_ + randPos.x_), int(pos.y_ + randPos.y_), int(radius + easeSize + easeDeadSize), int(radius - +easeSize - easeDeadSize), (rotateDeadSize/180.0f)*3.1415f, RED, kFillModeSolid);

		}
	}
	else
	{
		Novice::ScreenPrintf(590, 360, "Game Clear");
		Novice::ScreenPrintf(590, 380, "Restart > R <");
		Novice::ScreenPrintf(560, 400, "GoTitle > Enter <");


	}



}

void Enemy::MoveSizeShake()
{
	if (resetEaseT)
	{
		easeSizeT = 0;
		resetEaseT = false;
	}

	if (easeSizeT < setEaseTime)
	{
		easeSizeT++;
	}
	easeSize = Easing::OutElasticAmplitude(easeSizeT, setEaseTime, 15.0f, 0.3f);
}

#include "Enemy.h"

Enemy::Enemy()
{
	Init();
	deadCountNum=0;
}

void Enemy::Init()
{
	pos = { 640,100 };
	//size = { 40,40 };
	radius = 40 - 5 * deadCountNum;
	color = 0xaa00aaff;

	velocity = { 4,7 };
	isAlive = true;
	respawnTime = 60;
	currentTime = 0;
	deadTime = 30;

	isDead = false;
	isHit = false;

	hitPoint = 30;

	randPos = {};
	initRandSize= (int)radius/4;
	currentRandSize=0;

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
		}
		if (pos.x_ + radius > 1280)
		{
			velocity.x_ *= -1;
			pos.x_ = 1280 - radius;
		}
		if (pos.y_ - radius < 0)
		{
			velocity.y_ *= -1;
			pos.y_ = radius;
		}
		if (pos.y_ + radius > 720)
		{
			velocity.y_ *= -1;
			pos.y_ = 720 - radius;
		}

		if (isHit)
		{
			hitPoint--;
			currentRandSize = initRandSize;
			isHit = false;
		}

		if (hitPoint<=0)
		{
			
			isAlive = false;
			isDead = true;
			
		}
	}
	else
	{
		if (currentTime<respawnTime)
		{
			currentTime++;
			if (currentTime>deadTime)
			{
				isDead = false;
			}

		}
		else
		{
			deadCountNum++;
			Init();
		}
	}
	
}

void Enemy::Draw()
{
	if (currentRandSize>=0)
	{
		randPos.x_ = (float)GetRandMinMax(-currentRandSize, currentRandSize);
		randPos.y_ = (float)GetRandMinMax(-currentRandSize, currentRandSize);
		currentRandSize-=1;

	}
	
	if (isAlive)
	{
		Novice::DrawEllipse(int(pos.x_+ randPos.x_), int(pos.y_+ randPos.y_), int(radius), int(radius), 0, color, kFillModeSolid);

	}
	if (isHit)
	{
		Novice::DrawEllipse(int(pos.x_ + randPos.x_), int(pos.y_ + randPos.y_), int(radius), int(radius), 0, WHITE, kFillModeSolid);

	}
	if (isDead)
	{
		Novice::DrawEllipse(int(pos.x_ + randPos.x_), int(pos.y_+ randPos.y_), int(radius), int(radius), 0, RED, kFillModeSolid);

	}
}

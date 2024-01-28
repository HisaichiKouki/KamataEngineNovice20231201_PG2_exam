#include "Enemy.h"

Enemy::Enemy()
{
	Init();
}

void Enemy::Init()
{
	pos = { 640,100 };
	//size = { 40,40 };
	radius = 20;
	color = 0xaa00aaff;

	velocity = { 4,7 };
	isAlive = true;
	respawnTime = 60;
	currentTime = 0;
	deadTime = 30;

	isDead = false;
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
			Init();
		}
	}
	
}

void Enemy::Draw()
{
	if (isAlive)
	{
		Novice::DrawEllipse(int(pos.x_), int(pos.y_), int(radius), int(radius), 0, color, kFillModeSolid);

	}
	if (isDead)
	{
		Novice::DrawEllipse(int(pos.x_), int(pos.y_), int(radius), int(radius), 0, RED, kFillModeSolid);

	}
}

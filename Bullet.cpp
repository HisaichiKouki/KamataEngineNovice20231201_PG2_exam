#include "Bullet.h"

Bullet::Bullet()
{
	Init();
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	size = { 10,10 };
	velocity = { 0,10 };
	color = RED;

	isAlive = false;
}

void Bullet::Update()
{
	if (isAlive)
	{
		pos.y_ -= velocity.y_;

		if (pos.y_ + size.y_ <= 0)
		{
			isAlive = false;
		}

	}

}

void Bullet::Draw()
{
	if (isAlive)
	{
		Novice::DrawEllipse(int(pos.x_), int(pos.y_), int(size.x_), int(size.y_), 0, color, kFillModeSolid);
	}
}

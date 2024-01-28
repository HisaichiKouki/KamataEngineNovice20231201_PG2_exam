#include "Collision.h"

bool EllipseCollision(Vec2Op pos1, float radius1, Vec2Op pos2, float radius2)
{
	Vec2Op length{};
	length.x_ = pos1.x_ - pos2.x_;
	length.y_ = pos1.y_ - pos2.y_;

	float hitLength = sqrtf(length.x_ * length.x_ + length.y_ * length.y_);

	if (hitLength<= radius1+ radius2)
	{
		return true;
	}


	return false;
}

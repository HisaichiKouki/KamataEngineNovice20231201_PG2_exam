#include "Vec2Op.h"


void Vec2Op::Vec2OpScreenPrintf(int posX, int posY, int digit)
{
	if (digit>7)
	{
		digit = 7;
	}
	Novice::ScreenPrintf(posX, posY, "[x=%0.*f y=%0.*f]", digit,x_, digit,y_);
}

Vec2Op Vec2Op::operator+(const Vec2Op& obj)
{
	Vec2Op sc;
	sc.x_ = x_ + obj.x_;
	sc.y_ = y_ + obj.y_;
	return sc;
}

void Vec2Op::operator+=(const Vec2Op& obj)
{
	
	x_ +=  obj.x_;
	y_ += obj.y_;
	

}

Vec2Op Vec2Op::operator-(const Vec2Op& obj)
{
	Vec2Op sc;
	sc.x_ = x_ - obj.x_;
	sc.y_ = y_ - obj.y_;
	return sc;
}

void Vec2Op::operator-=(const Vec2Op& obj)
{
	Vec2Op sc;
	sc.x_ -= obj.x_;
	sc.y_ -= obj.y_;
}

Vec2Op Vec2Op::operator/(const Vec2Op& obj)
{
	Vec2Op sc;
	sc.x_ = x_ / obj.x_;
	sc.y_ = y_ / obj.y_;
	return sc;
}

void Vec2Op::operator/=(const Vec2Op& obj)
{
	Vec2Op sc;
	sc.x_ /= obj.x_;
	sc.y_ /= obj.y_;
}

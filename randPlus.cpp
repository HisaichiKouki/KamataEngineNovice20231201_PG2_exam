#include "RandPlus.h"

int GetRand()
{
	return rand();
}

Vec2Op GetRandPos(Vec2Op radius)
{
	if (radius.x_ != 0 && radius.y_ != 0) return Vec2Op({ float(rand() % int(radius.x_ * 4 - (radius.x_ * 2 - 1))) , float(rand() % int(radius.y_ * 4 - (radius.y_ * 2 - 1))) });
	return Vec2Op{ 0,0 };
}

int GetRandMinMax(int min, int max)
{
	if (abs(min) + abs(max) != 0)return (rand() % (max - min+1) + min);//(abs(min) + abs(max) - min + 1)
	return 0;
}





#pragma once
#include <Novice.h>
#include "Vec2Op.h"
class Bullet
{
public:
	Vec2Op pos;
	Vec2Op size;
	Vec2Op velocity;
	unsigned int color;

	bool isAlive;

	Bullet();
	~Bullet();

	void Init();
	void Update();
	void Draw();

};


#pragma once
#include <Novice.h>
#include "Vec2Op.h"
#include "InputManager.h"
struct PlayerStruct
{
	Vec2Op pos;
	Vec2Op size;
	Vec2Op velocity;
	Vec2Op accleration;

	unsigned int color;
};

class Player
{

private:
	PlayerStruct player{};

	Vec2Op input{};
	ContorollerVector2 inputNum;
	

public:

	 Player();
	 ~Player();

	 void Init();
	 void Upadte();
	 void Draw();

};


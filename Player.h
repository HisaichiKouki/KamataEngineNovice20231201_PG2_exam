#pragma once
#include <Novice.h>
#include "Vec2Op.h"
#include "InputManager.h"

#include "Bullet.h"
#include "Easing.h"

const int kMaxBullet = 100;
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

	Vec2Op inputVel{};
	ContorollerVector2 inputNum;
	Vec2Op currentVel;
	float moveRaito;
	
	float easeSize;
	float easeSizeT;
	float setEaseTime;

public:


	Bullet* bullet[kMaxBullet];
	float holdSpaceTime;

	float shotCT;
	float currentShotCT;
	int cullentShotCT;

	 Player();
	 ~Player();

	 void Init();
	 void Upadte();
	 void Draw();
	 void Debug();

	 void PlayerInputMove(Vec2Op &inputVel);

	 void Shot();

	 void MoveSizeShake();

};


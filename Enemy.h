#pragma once
#include <Novice.h>
#include "Vec2Op.h"
#include "randPlus.h"
#include "Easing.h"



class Enemy
{
private:
	Vec2Op pos;
	//Vec2Op size;
	float radius;
	unsigned int color;

	Vec2Op velocity;

	bool isAlive;
	int respawnTime;
	int currentTime;
	int deadTime;

	bool isDead;
	bool isHit;

	int hitPoint;

	Vec2Op randPos;
	int initRandSize;
	int currentRandSize;

	float deadCountNum;
	float direction;


	float easeSize;
	float easeSizeT;
	float setEaseTime;
	bool resetEaseT;

public:

	Enemy();

	void Init();
	void Update();
	void Draw();

	Vec2Op GetPos() { return pos; }
	//Vec2Op GetSize() { return size; }
	bool GetIsAlive() { return isAlive; }
	float GetRadius() { return radius; }

	void setIsAlive(bool setisAlive_) { this->isAlive = setisAlive_; }
	void setIsDead(bool setIsDead_) { this->isDead = setIsDead_; }
	void setIsHit(bool setIsHit) { this->isHit = setIsHit; }

	void MoveSizeShake();

};


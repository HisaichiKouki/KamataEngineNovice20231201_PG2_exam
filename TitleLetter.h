#pragma once
#include <Novice.h>
#include "Vec2Op.h"
#include "Easing.h"
struct Rect
{
	Vec2Op leftTop;
	Vec2Op rightTop;
	Vec2Op leftBottom;
	Vec2Op rightBottom;
};
class TitleLetter
{
private:
	Vec2Op pos;
	Vec2Op size;


	int texture;
	float easeSize;
	float easeSizeT;
	float setEaseTime;

	bool isHit;

	float maxHP;
	float currentHP;
	float raitoHP;


public:
	Rect rect;
	TitleLetter();
	~TitleLetter();

	void Init();
	void Update();
	void Draw();

	void  elastic();

	void SetIsHit(bool SetHit_) { isHit = SetHit_; }
	void SetEaseT(float setEaseT_) { this->easeSizeT = setEaseT_; }
	void Damage();

	float GetCurrentHP() { return currentHP; }
};


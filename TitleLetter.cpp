#include "TitleLetter.h"

TitleLetter::TitleLetter()
{
	Init();
}

TitleLetter::~TitleLetter()
{

}

void TitleLetter::Init()
{
	pos = { 640,200 };
	size = { 545,80 };
	rect.leftTop = { pos.x_ - size.x_ / 2,pos.y_ - size.y_ / 2 };
	rect.rightTop = { pos.x_ + size.x_ / 2,pos.y_ - size.y_ / 2 };
	rect.leftBottom = { pos.x_ - size.x_ / 2,pos.y_ + size.y_ / 2 };
	rect.rightBottom = { pos.x_ + size.x_ / 2,pos.y_ + size.y_ / 2 };

	texture = Novice::LoadTexture("./Resources/pg2_Title.png");

	easeSize=0;
	setEaseTime = 30;
	easeSizeT= setEaseTime;
	
	isHit = false;
	maxHP=60;
	currentHP= maxHP;
	raitoHP = 1;
}

void TitleLetter::Update()
{
	elastic();
	raitoHP = currentHP / maxHP;
	if (raitoHP<0)
	{
		raitoHP = 0;
	}
}

void TitleLetter::Draw()
{
	
	
	//if (isHit)
	//{
	//	Novice::DrawQuad(
	//		int(rect.leftTop.x_ - easeSize), int(rect.leftTop.y_ - easeSize/2),
	//		int(rect.rightTop.x_ + easeSize), int(rect.rightTop.y_ - easeSize),
	//		int(rect.leftBottom.x_ - easeSize), int(rect.leftBottom.y_ - easeSize),
	//		int(rect.rightBottom.x_ + easeSize), int(rect.rightBottom.y_ - easeSize),
	//		0, 0, 1, 1, texture, RED
	//	);
	//}
	//else
	//{
	//	
	//}
	Novice::DrawQuad(
		int(rect.leftTop.x_ + easeSize), int(rect.leftTop.y_ + easeSize / 2),
		int(rect.rightTop.x_ - easeSize), int(rect.rightTop.y_ + easeSize / 2),
		int(rect.leftBottom.x_ + easeSize), int(rect.leftBottom.y_ + easeSize / 2),
		int(rect.rightBottom.x_ - easeSize), int(rect.rightBottom.y_ + easeSize / 2),
		0, 0, 545, 80, texture, WHITE
	);
	if (currentHP>0)
	{
		Novice::DrawQuad(
			int(rect.leftTop.x_ + easeSize), int(rect.leftTop.y_ + easeSize / 2),
			int(rect.leftTop.x_ + size.x_ * raitoHP - easeSize * raitoHP), int(rect.rightTop.y_ + easeSize / 2),
			int(rect.leftBottom.x_ + easeSize), int(rect.leftBottom.y_ + easeSize / 2),
			int(rect.leftTop.x_ + size.x_ * raitoHP - easeSize * raitoHP), int(rect.rightBottom.y_ + easeSize / 2),
			0, 0, int(545 * raitoHP), 80, texture, RED
		);
	}
}

void TitleLetter::elastic()
{
	easeSize = Easing::OutElasticAmplitude(easeSizeT, setEaseTime, 30.0f, 0.3f);

	if (easeSizeT< setEaseTime)
	{
		easeSizeT++;
	}
	else
	{
		easeSize = 0;
	}
}

void TitleLetter::Damage()
{
	if (currentHP>0)
	{
		currentHP--;
	}
	else
	{
		currentHP = 0;
	}
}

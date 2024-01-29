
#include "Title.h"

Title::Title()
{
	Init();
}

Title::~Title()
{
	delete player;
	player = nullptr;
	delete titleLetter;
	titleLetter = nullptr;

}

void Title::Init()
{
	player = new Player;
	titleLetter = new TitleLetter;
}

void Title::Update()
{
	player->Upadte();

	for (int i = 0; i < kMaxBullet; i++)
	{
		if (player->bullet[i]->isAlive)
		{
			if (player->bullet[i]->pos.x_ > titleLetter->rect.leftTop.x_ &&
				player->bullet[i]->pos.x_ < titleLetter->rect.rightTop.x_ &&
				player->bullet[i]->pos.y_ > titleLetter->rect.rightTop.y_ &&
				player->bullet[i]->pos.y_ < titleLetter->rect.rightBottom.y_)
			{

				//	titleLetter->SetIsHit(true);
				titleLetter->SetEaseT(0);
				titleLetter->Damage();
				player->bullet[i]->isAlive = false;
			}
		}
		
	}
	titleLetter->Update();
}

void Title::Draw()
{

	Novice::DrawBox(0, 0, 1280, 720, 0, 0x888888ff, kFillModeSolid);
	titleLetter->Draw();

	player->Draw();
	for (int i = 0; i < kMaxBullet; i++)
	{
		player->bullet[i]->Draw();
	}
	//Novice::ScreenPrintf(600, 360, "title");

}

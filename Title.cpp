
#include "Title.h"

Title::Title()
{
	Init();
}

Title::~Title()
{
	delete player;
	player = nullptr;
}

void Title::Init()
{
	player = new Player;
}

void Title::Update()
{
	player->Upadte();
}

void Title::Draw()
{
	player->Draw();
	for (int i = 0; i < kMaxBullet; i++)
	{
		player->bullet[i]->Draw();
	}
	Novice::ScreenPrintf(600, 360, "title");
}

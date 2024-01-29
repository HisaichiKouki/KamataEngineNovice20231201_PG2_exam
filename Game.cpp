#include "Game.h"

Game::Game()
{
	Init();
}

Game::~Game()
{
	Finalize();
}

void Game::Update()
{

	///------------------///
		/// ↓更新処理ここから
		///------------------///



    	player->Upadte();
	enemy->Update();

	if (enemy->GetIsAlive())
	{
		for (int i = 0; i < kMaxBullet; i++)
		{
			if (player->bullet[i]->isAlive)
			{
				if (EllipseCollision(enemy->GetPos(), enemy->GetRadius()
					, player->bullet[i]->pos, player->bullet[i]->radius))
				{
					//enemy->setIsAlive(false);
					enemy->setIsHit(true);

					player->bullet[i]->isAlive = false;
				}
			}

		}
	}

	if (EllipseCollision(enemy->GetPos(), enemy->GetRadius()
		, player->GetPos(), player->GetRadius()))
	{
		player->isAlive = false;


	}

	if (player->isAlive == false)
	{
		if (InputManager::GetIsTriggerKey(DIK_R))
		{
			enemy->Init();
			player->Init();
		}
	}
	///------------------///
	/// ↑更新処理ここまで
	///------------------///

	
}

void Game::Init()
{
	player = new Player;
	enemy = new Enemy;
}

void Game::Finalize()
{
	delete player;
	delete enemy;

	player = nullptr;
	enemy = nullptr;
}

void Game::Draw()
{
	///------------------///
	/// ↓描画処理ここから
	///------------------///
	Novice::DrawBox(0, 0, 1280, 720, 0, 0x333333ff, kFillModeSolid);

	enemy->Draw();
	player->Draw();


	for (int i = 0; i < kMaxBullet; i++)
	{
		player->bullet[i]->Draw();
	}

	player->Debug();
	if (!player->isAlive)
	{
		Novice::ScreenPrintf(590, 360, "GameOver");
		Novice::ScreenPrintf(600, 380, "> R <");
	}
	///------------------///
	/// ↑描画処理ここまで
	///------------------///
}

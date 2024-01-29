#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
class Game
{
	Player* player;

	Enemy* enemy;
public:
	Game();
	~Game();
	
	void Update();
	void Init();
	void Draw();
	
};


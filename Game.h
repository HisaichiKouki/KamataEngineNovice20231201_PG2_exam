#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"
class Game
{
	Player* player = new Player;

	Enemy* enemy = new Enemy;
public:
	void Update();
};


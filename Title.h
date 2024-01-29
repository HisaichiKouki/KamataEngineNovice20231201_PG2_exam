#pragma once
#include "Novice.h"
#include "Player.h"
class Title
{


public:

	Player* player;

	Title();
	~Title();

	void Init();
	void Update();
	void Draw();
};


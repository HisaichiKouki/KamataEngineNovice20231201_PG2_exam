#pragma once
#include "Novice.h"
#include "Player.h"
#include "TitleLetter.h"
class Title
{


public:

	Player* player;
	TitleLetter* titleLetter;

	Title();
	~Title();

	void Init();
	void Update();
	void Draw();
};


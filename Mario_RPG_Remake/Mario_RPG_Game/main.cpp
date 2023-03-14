#include "MarioRPG.h"
#include <iostream>

class Mario_RPG_Game_App : public MarioRPG::MarioRPGApp
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Game is running \n";
	}
};

MARIORPG_GAME_START(Mario_RPG_Game_App)
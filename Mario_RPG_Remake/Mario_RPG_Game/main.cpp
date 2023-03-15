#include "MarioRPG.h"
#include <iostream>

class Mario_RPG_Game_App : public Mario_RPG_Engine::MarioRPGApp
{
public:
	Mario_RPG_Game_App()
	{
		Mario_RPG_Engine::GameWindow::Init();
		Mario_RPG_Engine::GameWindow::CreateWindow(800, 600, "Mario RPG Remake");
	}

	virtual void OnUpdate() override
	{
		std::cout << "Game is running \n";
	}
};

MARIORPG_GAME_START(Mario_RPG_Game_App)
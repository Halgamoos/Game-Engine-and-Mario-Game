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

	// OnUpdate() Runs between frames
	virtual void OnUpdate() override
	{
		Mario_RPG_Engine::GameWindow::SwapBuffers();
		Mario_RPG_Engine::GameWindow::PollEvents();
	}
};

MARIORPG_GAME_START(Mario_RPG_Game_App)
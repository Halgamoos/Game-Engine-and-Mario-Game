#include "MarioRPG.h"
#include <iostream>
#include<functional>

class Mario_RPG_Game_App : public Mario_RPG_Engine::MarioRPGApp
{
public:
	Mario_RPG_Game_App()
	{
		SetKeyPressedCallBack([this](const Mario_RPG_Engine::KeyPressed& e) { MyKeyPressedFunc(e); });
	}
	
	// OnUpdate() Runs between frames
	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0, 0 });
		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const Mario_RPG_Engine::KeyPressed& e)
	{
		if (e.GetKeyCode() == MARIO_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == MARIO_KEY_LEFT)
			unit.UpdateXCoord(-20);
	}
private:
	Mario_RPG_Engine::Renderer renderer;

	Mario_RPG_Engine::Unit unit{ "../Assets/Images/original_mario_jump.png", {200, 100} };
	Mario_RPG_Engine::Image back { "../Assets/Images/background.png" };
};

MARIORPG_GAME_START(Mario_RPG_Game_App)
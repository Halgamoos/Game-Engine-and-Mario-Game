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
		renderer.Draw(hp, { 300, 450 });
		renderer.Draw(mario);
		renderer.Draw(bowser);

		if (move_forward)
		{
			bowser_movement += 1;
			bowser.UpdateXCoord(-5);
			if (bowser_movement % 30 == 0)
			{
				move_forward = false;
				move_back = true;
				bowser_movement = 0;
			}
		}
		else if (move_back)
		{
			bowser_movement += 1;
			bowser.UpdateXCoord(5);
			if (bowser_movement % 30 == 0)
			{
				move_forward = true;
				move_back = false;
				bowser_movement = 0;
			}
		}

		if (shoot_fireball)
		{
			renderer.Draw(fireball);
			animate_fireball(fireball);
		}

		if (Mario_RPG_Engine::UnitsOverlap(fireball, bowser) and hp_count < 4)
		{
			hp_count += 1;
			hp = Mario_RPG_Engine::Image{ "../Assets/Images/hp" + std::to_string(hp_count) + ".png" };
			shoot_fireball = false;
			fireball.SetCoords({ 1000, 1000 });
		}
		else if (hp_count >= 4)
		{
			renderer.Draw(dead_bowser);
			renderer.Draw(winning_screen, {50, 250});
			bowser.SetCoords({ 1000, 1000 });
		}
	}

	void MyKeyPressedFunc(const Mario_RPG_Engine::KeyPressed& e)
	{
		if (e.GetKeyCode() == MARIO_KEY_RIGHT)
			mario.UpdateXCoord(20);
		else if (e.GetKeyCode() == MARIO_KEY_LEFT)
			mario.UpdateXCoord(-20);
		else if (e.GetKeyCode() == MARIO_KEY_UP)
			mario.UpdateYCoord(20);
		else if (e.GetKeyCode() == MARIO_KEY_DOWN)
			mario.UpdateYCoord(-20);
		else if (e.GetKeyCode() == MARIO_KEY_SPACE)
		{
			shoot_fireball = true; 
			fireball.SetCoords(mario.GetCoords());
		}
	}

	void animate_fireball(Mario_RPG_Engine::Unit& fireball)
	{
		fireball.UpdateXCoord(5);
	}

private:
	Mario_RPG_Engine::Renderer renderer;
	Mario_RPG_Engine::Unit mario{ "../Assets/Images/original_mario_jump.png", {100, 220} };
	Mario_RPG_Engine::Unit bowser{ "../Assets/Images/bowser.png", {500, 210} };
	Mario_RPG_Engine::Unit dead_bowser{ "../Assets/Images/dead_bowser.png", { 300, 100} };
	Mario_RPG_Engine::Unit fireball{ "../Assets/Images/fireball.png", mario.GetCoords() };
	Mario_RPG_Engine::Image back { "../Assets/Images/background.png" };
	Mario_RPG_Engine::Image hp{ "../Assets/Images/hp0.png" };
	Mario_RPG_Engine::Image winning_screen{ "../Assets/Images/winning_screen.png" };
	bool move_back{ true }, move_forward{ true };
	bool shoot_fireball{ false };
	int bowser_movement{ 0 };
	int hp_count{ 0 };
};

MARIORPG_GAME_START(Mario_RPG_Game_App)
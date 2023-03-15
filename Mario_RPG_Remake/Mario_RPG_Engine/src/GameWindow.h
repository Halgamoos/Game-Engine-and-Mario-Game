#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"
#include "WindowImplementation.h"

namespace Mario_RPG_Engine
{
	class MARIORPG_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int GetWidth();
		static int GetHeight();

		~GameWindow();
	private:
		GameWindow(); // prevent posibility of creating second object
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };
		
		WindowImplementation* mImplementation{ nullptr };
	};
}
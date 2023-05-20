#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"
#include "WindowImplementation.h"
#include "MarioRPGEvents.h"

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

		void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);
	private:
		GameWindow(); // prevent posibility of creating second object
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };
		
		WindowImplementation* mImplementation{ nullptr };
	};
}
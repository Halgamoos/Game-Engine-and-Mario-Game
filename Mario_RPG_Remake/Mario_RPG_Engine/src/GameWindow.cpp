#include "pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWimplementation.h"

namespace Mario_RPG_Engine
{
	void GameWindow::Init()
	{
		if (!mInstance)
			mInstance = std::unique_ptr<GameWindow>(new GameWindow);
	}

	std::unique_ptr<GameWindow>& GameWindow::GetWindow()
	{
		return mInstance;
	}

	void GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, windowName);
	}

	void GameWindow::CreateWindow(int width, int height, std::string&& windowName)
	{
		mInstance->mImplementation->CreateWindow(width, height, windowName);
	}

	int GameWindow::GetWidth()
	{
		return mInstance->mImplementation->GetWidth();
	}

	int GameWindow::GetHeight()
	{
		return mInstance->mImplementation->GetHeight();
	}

	GameWindow::GameWindow()
	{
#ifdef MARIO_RPG_ENGINE_GLFW
		mImplementation = new GLFWimplementation;
#else
	#ERROR_only_glfw_is_supported
#endif // MARIO_RPG_ENGINE_GLFW
	}
}
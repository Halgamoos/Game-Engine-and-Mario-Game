#include "pch.h"
#include "GameWindow.h"
#include "GLFWCode/GLFWimplementation.h"

namespace Mario_RPG_Engine
{
	GameWindow::GameWindow()
	{
#ifdef MARIO_RPG_ENGINE_GLFW
		mImplementation = new GLFWimplementation;
#else
		#ERROR_only_GLFW_is_supported
#endif // MARIO_RPG_ENGINE_GLFW
	}
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
		mInstance->mImplementation->CreateWindow(width, height, std::move(windowName));
	}

	void GameWindow::SwapBuffers()
	{
		mInstance->mImplementation->SwapBuffers();
	}

	void GameWindow::PollEvents()
	{
		mInstance->mImplementation->PollEvents();
	}

	int GameWindow::GetWidth()
	{
		return mInstance->mImplementation->GetWidth();
	}

	int GameWindow::GetHeight()
	{
		return mInstance->mImplementation->GetHeight();
	}

	GameWindow::~GameWindow()
	{
		if (mImplementation != nullptr)
		{
			delete mImplementation;
		}
	}
	void GameWindow::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mImplementation->SetKeyPressedCallBack(callbackFunc);
	}
	void GameWindow::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mImplementation->SetKeyReleasedCallBack(callbackFunc);
	}
	void GameWindow::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mImplementation->SetWindowCloseCallback(callbackFunc);
	}
}
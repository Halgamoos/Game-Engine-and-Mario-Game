#include "pch.h"
#include "MarioRPGApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"

namespace Mario_RPG_Engine
{
	MarioRPGApp::MarioRPGApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(800, 600, "Mario RPG Game");

		SetWindowCloseCallback([this]() { DefaultWindowCloseHandler();  });
	}
	void MarioRPGApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Mario_RPG_Engine::GameWindow::SwapBuffers();
			Mario_RPG_Engine::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void MarioRPGApp::SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallBack(callbackFunc);
	}
	void MarioRPGApp::SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallBack(callbackFunc);
	}
	void MarioRPGApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}
	void MarioRPGApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}
}
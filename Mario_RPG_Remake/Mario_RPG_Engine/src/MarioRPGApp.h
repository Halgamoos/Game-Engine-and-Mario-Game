#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"
#include "MarioRPGEvents.h"

constexpr int FPS{ 60 };

namespace Mario_RPG_Engine
{
	class MARIORPG_API MarioRPGApp
	{
	public:
		MarioRPGApp();
		virtual void OnUpdate() = 0;
		void Run();
		void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);
	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

		bool mGameWindowShouldClose{ false };

		void DefaultWindowCloseHandler();
	};
}
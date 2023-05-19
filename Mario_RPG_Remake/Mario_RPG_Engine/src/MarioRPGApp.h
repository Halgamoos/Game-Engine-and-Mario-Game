#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"

constexpr int FPS{ 60 };

namespace Mario_RPG_Engine
{
	class MARIORPG_API MarioRPGApp
	{
	public:
		virtual void OnUpdate() = 0; // Purely Virtual
		void Run();
	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::seconds{1} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
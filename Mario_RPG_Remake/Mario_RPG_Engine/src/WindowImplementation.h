#pragma once

#include "pch.h"
#include "MarioRPGEvents.h"

namespace Mario_RPG_Engine
{
	class WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void CreateWindow(int width, int height, std::string&& windowName) = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		
		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc) = 0;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc) = 0;
		virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) = 0;

		virtual ~WindowImplementation() {};
	};
}
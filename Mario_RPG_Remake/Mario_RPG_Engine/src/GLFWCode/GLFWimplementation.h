#pragma once

#include "pch.h"
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace Mario_RPG_Engine
{
	class GLFWimplementation : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void SetKeyPressedCallBack(std::function<void(const KeyPressed&)> callbackFunc) override;
		virtual void SetKeyReleasedCallBack(std::function<void(const KeyReleased&)> callbackFunc) override;
		virtual void SetWindowCloseCallback(std::function<void()> callbackFunc) override;

	private:
		struct CallBacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc { [](const KeyPressed&) {}};
			std::function<void(const KeyReleased&)> keyReleasedFunc{ [](const KeyReleased&) {}};
			std::function<void()> windowCloseFunc { []() {} };
		} mCallbacks;
		
		GLFWwindow* mWindow{ nullptr };
	};
}
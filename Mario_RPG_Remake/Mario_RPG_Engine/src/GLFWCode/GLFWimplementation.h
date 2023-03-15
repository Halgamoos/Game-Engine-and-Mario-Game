#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace Mario_RPG_Engine
{
	class GLFWimplementation : public WindowImplementation
	{
	public:
		virtual void CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void CreateWindow(int width, int height, std::string&& windowName) override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
	private:
		GLFWwindow* mWindow{ nullptr };
	};
}
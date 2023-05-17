#include "pch.h"
#include "MarioRPGApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Mario_RPG_Engine
{
	void MarioRPGApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}
}
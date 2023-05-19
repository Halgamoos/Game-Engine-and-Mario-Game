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
	void MarioRPGApp::Run()
	{
		Renderer renderer;

		Image image{ "../Assets/Images/original_mario_jump.png" };

		image.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl" , "../Assets/Shaders/DefaultFragmentShader.glsl" };

		sProgram.Pass2FLoatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		while (true)
		{
			renderer.Clear();
			renderer.Draw(image, { 200, 100 });

			OnUpdate();
		}
	}
}
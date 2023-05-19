#pragma once

#include "pch.h"
#include "MarioRPGUtils.h"
#include "ImplShader.h"

namespace Mario_RPG_Engine
{
	class MARIORPG_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Activate();

		void Pass2FLoatValues(const std::string& name, float val1, float val2);
		void Pass2FLoatValues(std::string&& name, float val1, float val2);

	private:
		std::unique_ptr<ImplShader> mImplementation{ nullptr };
	};
}
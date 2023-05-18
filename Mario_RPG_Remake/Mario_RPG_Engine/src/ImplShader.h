#pragma once

namespace Mario_RPG_Engine
{
	class ImplShader
	{
	public:
		virtual void Activate() = 0;
		virtual void Pass2FLoatValues(const std::string& name, float val1, float val2) = 0;
		virtual void Pass2FLoatValues(std::string&& name, float val1, float val2) = 0;
	};
}
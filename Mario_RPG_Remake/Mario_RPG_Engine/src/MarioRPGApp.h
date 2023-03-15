#pragma once

#include "MarioRPGUtils.h"

namespace Mario_RPG_Engine
{
	class MARIORPG_API MarioRPGApp
	{
	public:
		virtual void OnUpdate() = 0; // Purely Virtual
		void Run();
	};
}
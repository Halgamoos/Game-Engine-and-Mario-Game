#pragma once

#include "MarioRPGUtils.h"

namespace MarioRPG
{
	class MARIORPG_API MarioRPGApp
	{
	public:
		virtual void OnUpdate() = 0; // Purely Virtual
		void Run();

	private:
	};
}
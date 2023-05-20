#pragma once

#include "MarioRPGUtils.h"

namespace Mario_RPG_Engine
{
	class MARIORPG_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class MARIORPG_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetReleased() const;

	private:
		int mKeyCode;
	};

	class MARIORPG_API WindowClosed
	{
	};
}
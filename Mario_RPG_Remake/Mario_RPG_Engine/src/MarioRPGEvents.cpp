#include "pch.h"
#include "MarioRPGEvents.h"

namespace Mario_RPG_Engine
{
	KeyPressed::KeyPressed(int kCode) : mKeyCode(kCode)
	{
	}

	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int kCode) : mKeyCode(kCode)
	{
	}

	int KeyReleased::GetReleased() const
	{
		return mKeyCode;
	}
}
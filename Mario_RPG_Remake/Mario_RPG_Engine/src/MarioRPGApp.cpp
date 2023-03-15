#include "pch.h"
#include "MarioRPGApp.h"

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
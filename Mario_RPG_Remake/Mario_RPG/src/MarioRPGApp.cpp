#include "MarioRPGApp.h"
#include <iostream>

namespace MarioRPG
{
	void MarioRPGApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}
}
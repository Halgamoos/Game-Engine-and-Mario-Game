#pragma once

#include "MarioRPGUtils.h"

#ifdef MARIORPG_WINDOWS
	#ifdef MARIORPG_LIB
		#define MARIORPG_API __declspec(dllexport)
	#else
		#define MARIORPG_API __declspec(dllimport)
	#endif // MarioRPG_Lib
#else
	#define MARIORPG_API
#endif

#define MARIORPG_GAME_START(ClassName)\
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}
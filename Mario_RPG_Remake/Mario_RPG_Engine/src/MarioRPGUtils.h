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

#if MARIO_DEBUG == 2
	#define MARIO_LOG(x) std::clog << "Log: " << x << std::endl;
	#define MARIO_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#elif MARIO_DEBUG == 1
	#define MARIO_LOG(x)
	#define MARIO_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#else
	#define MARIO_LOG(x)
	#define MARIO_ERROR(x)
#endif
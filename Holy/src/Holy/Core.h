#pragma once



/* 
	the idea is to create a HOLY_API macro that export the dll from the game engine to the sandbox,
	to do so we'll add HL_BUILD_DLL to Holy's preprocessor definitions
*/
#ifdef HL_PLATFORM_WINDOWS
    #ifdef HL_BUILD_DLL
		#define HOLY_API __declspec(dllexport)
	#else
		#define HOLY_API __declspec(dllimport)
	#endif
#else
	#error Holy needs Windows to  run!
#endif


 
#pragma once

/*
	this is the engine's entry point
*/
#ifdef HL_PLATFORM_WINDOWS

extern Holy::Application* Holy::CreateApplication(); 


int main(int argc, char** argv)

{
	Holy::Log::Init();
	HL_CORE_INFO("LOG SYSTEM INIT");
	HL_CORE_INFO("READY FOR METAGAMING");
	HL_CORE_WARN("FILE LOGGING UNABLED");
	HL_INFO("Welcome to Holy Engine");
	HL_CORE_ERROR("ATTACK FUNCTION HAS NO PTR TO HL_ENTITY");
	//Create the app by calling the external function inside of Sandbox
	Holy::Application* app = Holy::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Holy needs Windows to  run!
#endif

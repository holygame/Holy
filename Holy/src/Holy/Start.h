#pragma once


#ifdef HL_PLATFORM_WINDOWS

extern Holy::Application* Holy::CreateApplication(); 


int main(int argc, char** argv)

{
	Holy::Log::Init();
	Holy::Log::GetCoreLogger()->warn("initialized log");
	Holy::Log::GetClientLogger()->info("Hello");
	//Create the app by calling the external function inside of Sandbox
	Holy::Application* app = Holy::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Holy needs Windows to  run!
#endif

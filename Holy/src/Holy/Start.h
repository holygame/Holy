#pragma once


#ifdef HL_PLATFORM_WINDOWS

extern Holy::Application* Holy::CreateApplication(); 


int main(int argc, char** argv)

{
	//Create app by calling the function inside of Sandbox
	Holy::Application* app = Holy::CreateApplication();
	app->Run();
	delete app;
}
#else
#error Holy needs Windows to  run!
#endif

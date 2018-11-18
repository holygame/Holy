#include <Holy.h>

class Sandbox : public Holy::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};


Holy::Application* Holy::CreateApplication()
{
	return new Sandbox(); 
}
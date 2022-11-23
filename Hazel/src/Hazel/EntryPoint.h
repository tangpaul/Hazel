#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int args, char** argv)	
{
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif

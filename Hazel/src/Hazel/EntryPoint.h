#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int args, char** argv)	
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized log!");
	//int a = 5;
	//HZ_INFO("Hello! var={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif

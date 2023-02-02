#include "hzpch.h"
#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

namespace Hazel
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		HZ_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE("e is in Input Event.");
		}
		if(e.IsInCategory(EventCategoryApplication)){
			HZ_TRACE("e is in Application Event.");
		}

		while(true);
	}

}
#pragma once
#include "Core.h"

#include "Window.h"

namespace Hazel
{
	class HAZEL_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running	= true;
	};

	//////////////////////////////////////////////////////////////////////////
	/// to be defined in client
	Application* CreateApplication();
}
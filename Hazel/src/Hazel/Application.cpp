#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel
{
#define HZ_EVENT_BIND(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(HZ_EVENT_BIND(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(HZ_EVENT_BIND(Application::OnWindowClose));

		HZ_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		while(m_Running){
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
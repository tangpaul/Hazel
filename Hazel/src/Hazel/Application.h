#pragma once
#include "Core.h"

#include "Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	private:
		static Application* s_Instance;

	public:
		inline static Application& Get() { return *s_Instance; }

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running	= true;
		LayerStack m_LayerStack;
	};

	//////////////////////////////////////////////////////////////////////////
	/// to be defined in client
	Application* CreateApplication();
}
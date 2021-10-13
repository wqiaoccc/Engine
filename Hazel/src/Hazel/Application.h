#pragma once

#include"Core.h"
#include"Events/Event.h"
#include"Window.h"
#include"Hazel/Events/ApplicationEvent.h"

namespace Hazel {

	class HZ_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
		void Application::OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}
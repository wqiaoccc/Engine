#include "Hzpch.h"  //����.cpp����
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include<GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());   // create() -> windowswindow() -> init()
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));	// window�¼�����onEvent
	}
	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		HZ_CORE_INFO("{0}", e);  //Ŀǰ����ӡ��log�ʹ�����windowclose�¼�
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		HZ_TRACE(e);

		while (m_Running)
		{
			glClearColor(0, 0.5, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}



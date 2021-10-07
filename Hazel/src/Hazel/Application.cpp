#include "Hzpch.h"  //放在.cpp里面
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

#include<GLFW/glfw3.h>

namespace Hazel {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());   // create() -> windowswindow() -> init()
	}
	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720); //事件处理还没有，只有定义
		HZ_TRACE(e);

		while (m_Running)
		{
			glClearColor(0, 0.5, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}



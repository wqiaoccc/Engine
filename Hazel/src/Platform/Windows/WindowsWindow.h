#pragma once

#include<Hazel/Window.h>

#include<GLFW/glfw3.h>

namespace Hazel {

	class WindowsWindow : public Window  //windowsƽ̨����
	{ 
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width;  }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enbaled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

		GLFWwindow* m_Window;

		struct WindowData	//windowƽ̨�Ĵ�������
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync;
			EventCallbackFn EventCallback; //��ʱû����
		};

		WindowData m_Data;
	};


}
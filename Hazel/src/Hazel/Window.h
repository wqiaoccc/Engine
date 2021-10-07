#pragma once
#include"hzpch.h"

#include"Hazel/Core.h"
#include"Hazel/Events/Event.h"

namespace Hazel {

	struct WindowProps // 通用窗口属性
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Hazel Engine",
			unsigned int width = 1280,
			unsigned int height = 720) :
			Title(title),Width(width),Height(height)
		{}
	};

	class Window //通用窗口
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>; //回调函数
		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());


	};
}







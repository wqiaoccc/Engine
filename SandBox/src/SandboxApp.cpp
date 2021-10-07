

#include"Hazel.h"


class Sandbox : public Hazel::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}

/*
// main 放在这里也可以，但是专门写个entryPoint.h更容易找到
int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}
*/
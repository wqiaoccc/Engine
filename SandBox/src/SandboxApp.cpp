

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
// main ��������Ҳ���ԣ�����ר��д��entryPoint.h�������ҵ�
int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}
*/
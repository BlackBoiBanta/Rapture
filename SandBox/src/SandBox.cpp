#include "Rapture.h"
#include <stdio.h>

class SandBox : public Rapture::Application
{
public: 
	SandBox()
	{

	}

	~SandBox()
	{

	}

	void Run() override
	{
	}

};


Rapture::Application* Rapture::CreateApplication()
{
	return new SandBox();
}


#pragma once
#include <mutex>
class Application
{
public:
	Application();
	~Application();
	void Run();
	bool SysInit();
	bool ShutDown();
};


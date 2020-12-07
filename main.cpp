#include <DxLib.h>
#include <mutex>
#include "Application.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR IpCmdLine,int nCmdShow)
{
	auto app = std::make_shared<Application>();
	app->SysInit();
	app->Run();
}

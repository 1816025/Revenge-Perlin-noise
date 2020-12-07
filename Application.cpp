#include <DxLib.h>
#include "Noise.h"
#include "Application.h"

Application::Application()
{
}

Application::~Application()
{
}

void Application::Run()
{
    auto noise = std::make_shared<Noise>();
    noise->SetSeed();
    auto hash = noise->GetHash();
    noise->MakeNoise(Size3(100, 100, 0));
    while (ProcessMessage() != -1)
    {
    }
}

bool Application::SysInit()
{
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(true);
	SetDrawScreen(DX_SCREEN_BACK);

    if (DxLib_Init())
    {
        return false;
    }
    return true;
}

bool Application::ShutDown()
{
    DxLib_End();
    return true;
}

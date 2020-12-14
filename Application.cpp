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
    auto hash = noise->GetHash();
    const Size3 size = Size3(100.0f, 100.0f, 1.0f);
    const float frequency = 16.0f;
    std::vector<float> result;
    for (float a = 0; a < size.z; a++)
    {
        for (float b = 0; b < size.y; b++)
        {
            for (float c = 0; c < size.x; c++)
            {
                float x = c / frequency;
                float y = b / frequency;
                float z = a / frequency;
                result.push_back(noise->MakeNoise(Position3(x, y, z)));
            }
        }
    }
    while (ProcessMessage() != -1)
    {
        ClsDrawScreen();
        ScreenFlip();
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

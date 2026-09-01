#pragma once

#include <vector>
#include <string>

#include "AppErrorType.h"
#include "Window.h"
#include "ImguiWindow.h"

namespace Core{

class Application{
public:
    Application(std::string _app_name);
    ~Application();
    bool Init();
    void AddImguiWindow(ImguiWindow* imgui_window);
    void Run();
    void Stop();
private:
    std::string app_name = "Application";
    Window app_window;
    bool running;
};


}
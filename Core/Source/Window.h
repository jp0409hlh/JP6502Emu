#pragma once

#include <string>
#include <vector>

#include "AppErrorType.h"
#include "ImguiWindow.h"
#include "SDL3/SDL.h"
#include "imgui.h"

namespace Core{

class Window{
public:
    Window();
    ~Window();
    AppErrorType create(std::string window_name);
    void setScale();
    void setWindowFlags();
    bool createSDLWindow(const std::string& window_name);
    bool createSDLRenderer();
    void setupImgui();
    void setupRendererBackends();
    void pushImguiWindow(ImguiWindow* imgui_window);
    void render();
    SDL_WindowID getSDLWindowID();
private:
    float main_scale;
    SDL_WindowFlags window_flags;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ImGuiIO* io;
    ImGuiStyle* style;
    std::vector<ImguiWindow*> imgui_win_vec;
};

}
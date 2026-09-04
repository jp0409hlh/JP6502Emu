#pragma once

#include "imgui.h"
#include "ImguiWindow.h"

namespace UI{

class MenuBar : public Core::ImguiWindow{
public:
    MenuBar(bool, std::string imgui_win_name);
    ~MenuBar();
    void renderImguiWindow(Core::Application& app) override;
private:
    void showFileMenu();
    void showOptionMenu();
    void showSessionMenu();
    void showHelpMenu();
};


}
#include "imgui.h"
#include "TerminalWindow.h"

namespace UI{
TerminalWindow::TerminalWindow(bool _show, std::string imgui_win_name){
    this->show = _show;
    this->ImguiWindowName = imgui_win_name;
}

TerminalWindow::~TerminalWindow(){

}

void TerminalWindow::renderImguiWindow(){
    ImGui::Begin(this->ImguiWindowName.c_str());

    ImGui::End();
}

}
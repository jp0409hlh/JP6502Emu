#include "imgui.h"
#include "MemViewerWindow.h"

namespace UI{
MemViewerWindow::MemViewerWindow(bool _show, std::string imgui_win_name){
    this->show = _show;
    this->ImguiWindowName = imgui_win_name;
}

MemViewerWindow::~MemViewerWindow(){

}

void MemViewerWindow::renderImguiWindow(){
    ImGui::Begin(this->ImguiWindowName.c_str());

    ImGui::End();
}

}
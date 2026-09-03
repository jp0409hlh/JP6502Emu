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
    this->mem_edit.DrawContents(&(this->test_memory), 1<<15);
    ImGui::End();
}

}
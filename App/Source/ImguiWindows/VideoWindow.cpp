#include "imgui.h"
#include "VideoWindow.h"

namespace UI{
VideoWindow::VideoWindow(bool _show, std::string imgui_win_name){
    this->show = _show;
    this->ImguiWindowName = imgui_win_name;
}

VideoWindow::~VideoWindow(){

}

void VideoWindow::renderImguiWindow(){
    ImGui::Begin(this->ImguiWindowName.c_str());

    ImGui::End();
}

}
#include "imgui.h"
#include "DisasmWindow.h"

namespace UI{
DisasmWindow::DisasmWindow(bool _show, std::string imgui_win_name){
    this->show;
    this->ImguiWindowName = imgui_win_name;
}

DisasmWindow::~DisasmWindow(){


}

void DisasmWindow::renderImguiWindow(){
    ImGui::Begin(this->ImguiWindowName.c_str());

    ImGui::End();
}

}
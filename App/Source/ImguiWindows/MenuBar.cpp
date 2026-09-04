#include "imgui.h"
#include "MenuBar.h"

namespace UI{
MenuBar::MenuBar(bool _show, std::string imgui_win_name){
#ifdef DEBUG
    printf("Begin MenuBAr Constructor\n");
#endif
    this->show = _show;
    this->ImguiWindowName = imgui_win_name;
#ifdef DEBUG
    printf("End MenuBar Constructor\n");
#endif
}

MenuBar::~MenuBar(){
#ifdef DEBUG
    printf("Im MenuBar Destructor\n");
#endif
}

void MenuBar::renderImguiWindow(Core::Application& app){
    if(ImGui::BeginMainMenuBar()){
        if(ImGui::BeginMenu("File")){
            showFileMenu();
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Settings")){
            showOptionMenu();
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Session")){
            showSessionMenu();
            ImGui::EndMenu();
        }
        if(ImGui::BeginMenu("Help")){
            showHelpMenu();
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void MenuBar::showFileMenu(){
    if(ImGui::MenuItem("Load File To ROM")){

    }
    if(ImGui::MenuItem("Load File To RAM")){

    }
}
void MenuBar::showOptionMenu(){
    if(ImGui::MenuItem("Style")){

    }

}
void MenuBar::showSessionMenu(){
    if(ImGui::MenuItem("Begin Session")){

    }
    if(ImGui::MenuItem("Configure Session")){

    }
    if(ImGui::MenuItem("Load Session")){

    }
    if(ImGui::MenuItem("Save Session")){

    }
}
void MenuBar::showHelpMenu(){
    if(ImGui::MenuItem("Github Page")){

    }
}

}
#include "imgui.h"
#include "ChipViewer.h"

namespace UI{

    // Chip6502Viewer
    Chip6502Viewer::Chip6502Viewer(bool _show, std::string imgui_win_name){
        this->show = _show;
        this->ImguiWindowName = imgui_win_name;
    }
    Chip6502Viewer::~Chip6502Viewer(){

    }
    void Chip6502Viewer::renderImguiWindow(Core::Application& app){
        if(this->show){
        ImGui::Begin(this->ImguiWindowName.c_str());

        ImGui::End();
        }
    }


    // Chip6522Viewer
    Chip6522Viewer::Chip6522Viewer(bool _show, std::string imgui_win_name){
        this->show = _show;
        this->ImguiWindowName = imgui_win_name;
    }
    Chip6522Viewer::~Chip6522Viewer(){

    }
    void Chip6522Viewer::renderImguiWindow(Core::Application& app){
        if(this->show){
        ImGui::Begin(this->ImguiWindowName.c_str());
        
        ImGui::End();
        }
    };


    // Chip6551Viewer
    Chip6551Viewer::Chip6551Viewer(bool _show, std::string imgui_win_name){
        this->show = _show;
        this->ImguiWindowName = imgui_win_name;
    }
    Chip6551Viewer::~Chip6551Viewer(){

    }
    void Chip6551Viewer::renderImguiWindow(Core::Application& app){
        if(this->show){
        ImGui::Begin(this->ImguiWindowName.c_str());
        
        ImGui::End();
        }
    }


    // ChipTMS9918Viewer
    ChipTMS9918Viewer::ChipTMS9918Viewer(bool _show, std::string imgui_win_name){
        this->show = _show;
        this->ImguiWindowName = imgui_win_name;
    }
    ChipTMS9918Viewer::~ChipTMS9918Viewer(){

    }
    void ChipTMS9918Viewer::renderImguiWindow(Core::Application& app){
        if(this->show){
        ImGui::Begin(this->ImguiWindowName.c_str());
        
        ImGui::End();
        }
    }

}
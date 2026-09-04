#include "imgui.h"
#include "DisasmWindow.h"

#define DISASM_TEXTURE_WIDTH 500
#define DISASM_TEXTURE_HEIGHT 2000

namespace UI{
DisasmWindow::DisasmWindow(bool _show, std::string imgui_win_name){
    this->show;
    this->ImguiWindowName = imgui_win_name;
}

DisasmWindow::~DisasmWindow(){


}

void DisasmWindow::createSDLTexture(SDL_Renderer* sdl_renderer){
    this->text_texture = SDL_CreateTexture(
        sdl_renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,   // remember to change it back to SDL_TEXTUREACCESS_STREAMING
        DISASM_TEXTURE_WIDTH,
        DISASM_TEXTURE_HEIGHT);
}

void DisasmWindow::renderImguiWindow(Core::Application& app){
    ImGui::Begin(this->ImguiWindowName.c_str());

    ImGui::End();
}



}
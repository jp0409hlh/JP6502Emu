#include "imgui.h"
#include "VideoWindow.h"

// TESTING ONLY 
#define TMS9918_PIXELS_X 256
#define TMS9918_PIXELS_Y 192

namespace UI{
VideoWindow::VideoWindow(bool _show, std::string imgui_win_name){
    this->show = _show;
    this->ImguiWindowName = imgui_win_name;
}

VideoWindow::~VideoWindow(){

}

void VideoWindow::createSDLTexture(SDL_Renderer* sdl_renderer){
    this->TMS9918_texture = SDL_CreateTexture(
        sdl_renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,   // remember to change it back to SDL_TEXTUREACCESS_STREAMING
        TMS9918_PIXELS_X,
        TMS9918_PIXELS_Y);
}

void VideoWindow::renderImguiWindow(){
    ImGui::Begin(this->ImguiWindowName.c_str());
    ImTextureID texture_id = (ImTextureID)(intptr_t)(this->TMS9918_texture);
    ImVec2 size = ImVec2((float)(TMS9918_PIXELS_X), (float)(TMS9918_PIXELS_Y));

    ImGui::Image(texture_id, size);

    ImGui::End();
}

}
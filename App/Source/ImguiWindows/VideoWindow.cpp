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

void VideoWindow::renderImguiWindow(Core::Application& app){
    ImGui::Begin(this->ImguiWindowName.c_str());
    ImTextureID texture_id = (ImTextureID)(intptr_t)(this->TMS9918_texture);
    ImVec2 size = ImVec2((float)(TMS9918_PIXELS_X), (float)(TMS9918_PIXELS_Y));

    SDL_SetRenderTarget(app.appGetSDLRenderer(), this->TMS9918_texture);
    SDL_SetRenderDrawColor(app.appGetSDLRenderer(), 255, 0, 0, 255);

    ImVec2 cur_window_pos = ImGui::GetWindowPos();
    ImVec2 mouse_pos = ImGui::GetMousePos();
    ImVec2 relative_pos = ImVec2(mouse_pos.x - cur_window_pos.x, mouse_pos.y - cur_window_pos.y);

    if(ImGui::IsMousePosValid() && ImGui::GetIO().WantCaptureMouse){
        float rect_x = relative_pos.x;
        float rect_y = relative_pos.y;

        SDL_FRect rect = { rect_x, rect_y, 50, 50 };
        SDL_RenderFillRect(app.appGetSDLRenderer(), &rect); 

        SDL_RenderClear(app.appGetSDLRenderer());
    }

    ImGui::Image(texture_id, size);
    SDL_SetRenderTarget(app.appGetSDLRenderer(), NULL);

    ImGui::End();
}

}
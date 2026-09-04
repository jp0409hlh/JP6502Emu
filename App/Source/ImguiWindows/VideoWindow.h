#pragma once

#include "SDL3/SDL.h"
#include "ImguiWindow.h"

namespace UI{

class VideoWindow : public Core::ImguiWindow{
public:
    VideoWindow(bool, std::string);
    ~VideoWindow();
    void renderImguiWindow(Core::Application& app) override;
    void createSDLTexture(SDL_Renderer* sdl_renderer);
private:
    SDL_Texture* TMS9918_texture = nullptr;
};

}
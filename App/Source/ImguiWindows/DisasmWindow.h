#pragma once

#include "SDL3/SDL.h"
#include "ImguiWindow.h"

namespace UI{

class DisasmWindow : public Core::ImguiWindow{
public:
    DisasmWindow(bool, std::string);
    ~DisasmWindow();
    void createSDLTexture(SDL_Renderer* sdl_renderer);
    void renderImguiWindow(Core::Application& app) override;
private:
    SDL_Texture* text_texture = nullptr;
};

}
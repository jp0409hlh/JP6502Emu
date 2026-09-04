#include <stdio.h>

#include "AppErrorType.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "SDL3/SDL.h"
#include "Window.h"

namespace Core{

Window::Window(){
    
}

Window::~Window(){
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

AppErrorType Window::create(std::string window_name){
    // Setup SDL
    // [If using SDL_MAIN_USE_CALLBACKS: all code below until the main loop starts would likely be your SDL_AppInit() function]
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        // TODO : Change to Error message window?
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        exit(1);
    }

    setScale();
    setWindowFlags();

    if(!createSDLWindow(window_name)){
        return AppErrorType::SDL_ERR; 
    }

    if(!createSDLRenderer()){
        return AppErrorType::SDL_ERR;
    }

    SDL_SetWindowPosition(this->window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    
    setupImgui();
    setupRendererBackends();

    SDL_ShowWindow(this->window);

    return AppErrorType::NO_ERR;
}

void Window::setScale(){
    this->main_scale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
}

void Window::setWindowFlags(){
    this->window_flags = SDL_WINDOW_RESIZABLE
                        | SDL_WINDOW_HIDDEN 
                        | SDL_WINDOW_HIGH_PIXEL_DENSITY;
}

bool Window::createSDLWindow(const std::string& window_name){
    this->window = SDL_CreateWindow( window_name.c_str(),
                                    (int)(1280 * main_scale),
                                    (int)(800 * main_scale),
                                    this->window_flags );
    if(window == nullptr){
        return false;
    }else{
        return true;
    }
}

bool Window::createSDLRenderer(){
    this->renderer = SDL_CreateRenderer(this->window, nullptr);
    SDL_SetRenderVSync(renderer, 1);
    if (renderer == nullptr){
        return false;
    }else{
        return true;
    }
}

void Window::setupImgui(){
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    this->io = &ImGui::GetIO();
    this->io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    this->io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    this->io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    this->io->ConfigDpiScaleFonts = true;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup scaling
    this->style = &ImGui::GetStyle();
    this->style->ScaleAllSizes(this->main_scale);        // Bake a fixed style scale.
    this->style->FontScaleDpi = this->main_scale;        // Set initial font scale.

}

void Window::setupRendererBackends(){
    ImGui_ImplSDL3_InitForSDLRenderer(this->window, this->renderer);
    ImGui_ImplSDLRenderer3_Init(this->renderer);
}

void Window::pushImguiWindow(ImguiWindow* window){
    this->imgui_win_vec.push_back(window);
}

void Window::render(){
    // Start the Dear ImGui frame
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::DockSpaceOverViewport();

    for(auto& imgui_window : imgui_win_vec){
        imgui_window->renderImguiWindow();
    }

    ImGui::Render();
    SDL_SetRenderScale(this->renderer,
        this->io->DisplayFramebufferScale.x,
        this->io->DisplayFramebufferScale.y);
    SDL_RenderClear(this->renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), this->renderer);
    SDL_RenderPresent(this->renderer);
}

SDL_WindowID Window::getSDLWindowID(){
    return SDL_GetWindowID(this->window);
}

SDL_Renderer* Window::getSDLRenderer() const {
    return this->renderer;
}

}
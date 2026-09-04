#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

#include "Application.h"

namespace Core{

Application::Application(std::string _app_name){
    this->app_name = _app_name;
}

Application::~Application(){

}

bool Application::Init(){
    AppErrorType error = app_window.create(this->app_name);
    if(error == AppErrorType::NO_ERR){
        this->running = true;
        return true;
    }else{
        // TODO : Show error message
        return false;
    }    
}

void Application::AddImguiWindow(ImguiWindow* imgui_window){
    this->app_window.pushImguiWindow(imgui_window);
}

void Application::Run(){
    while(running){

        SDL_Event event;
        while(SDL_PollEvent(&event)){
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT){
#ifdef DEBUG
                printf("SDL_EVENT_QUIT\n");
#endif
                running = false;
            }
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED
                 && event.window.windowID == this->app_window.getSDLWindowID()){
#ifdef DEBUG
                printf("SDL_CLOSE_WINDOW_REQUEST\n");
#endif
                running = false;
            }
        }

        this->app_window.render();
    }

#ifdef DEBUG
    printf("Exiting APP.RUN()");
#endif
}

void Application::Stop(){
    running = false;
}

SDL_Renderer* Application::appGetSDLRenderer() const{
    return this->app_window.getSDLRenderer();
}

}
cmake_minimum_required(VERSION 3.14)
project(JP6502Emu VERSION 1.0.0 LANGUAGES C CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ------------------------------------------------------------------------------
# Third-Party Dependencies (external/)
# ------------------------------------------------------------------------------

# 1. Add SDL subdirectory (Disables SDL internal tests to speed up build)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
add_subdirectory(external/SDL)

# 2. Define ImGui library directly
add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_demo.cpp
    external/Imgui/backends/imgui_impl_sdl3.cpp
    external/Imgui/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(imgui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
        ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui/backends
)

# Link ImGui against SDL target (Use SDL2::SDL2 if using SDL2)
target_link_libraries(imgui
    PUBLIC
        SDL3::SDL3
)

# ------------------------------------------------------------------------------
# Project Targets
# ------------------------------------------------------------------------------
add_subdirectory(Core)
add_subdirectory(App)
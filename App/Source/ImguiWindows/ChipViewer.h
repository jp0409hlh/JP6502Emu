#pragma once

#include "Application.h"
#include "ImguiWindow.h"

namespace UI{

class Chip6502Viewer : public Core::ImguiWindow{
public:
    Chip6502Viewer(bool, std::string imgui_win_name);
    ~Chip6502Viewer();
    void renderImguiWindow(Core::Application& app) override;
private:

};

class Chip6522Viewer : public Core::ImguiWindow{
public:
    Chip6522Viewer(bool, std::string imgui_win_name);
    ~Chip6522Viewer();
    void renderImguiWindow(Core::Application& app) override;
private:

};

class Chip6551Viewer : public Core::ImguiWindow{
public:
    Chip6551Viewer(bool, std::string imgui_win_name);
    ~Chip6551Viewer();
    void renderImguiWindow(Core::Application& app) override;
private:

};

class ChipTMS9918Viewer : public Core::ImguiWindow{
public:
    ChipTMS9918Viewer(bool, std::string imgui_win_name);
    ~ChipTMS9918Viewer();
    void renderImguiWindow(Core::Application& app) override;
private:

};


}
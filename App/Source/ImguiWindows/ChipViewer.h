#pragma once

#include "ImguiWindow.h"

namespace UI{

class Chip6502Viewer : public Core::ImguiWindow{
public:
    Chip6502Viewer(bool, std::string imgui_win_name);
    ~Chip6502Viewer();
    void renderImguiWindow() override;
private:

};

class Chip6522Viewer : public Core::ImguiWindow{
public:
    Chip6522Viewer(bool, std::string imgui_win_name);
    ~Chip6522Viewer();
    void renderImguiWindow() override;
private:

};

class Chip6551Viewer : public Core::ImguiWindow{
public:
    Chip6551Viewer(bool, std::string imgui_win_name);
    ~Chip6551Viewer();
    void renderImguiWindow() override;
private:

};

class ChipTMS9918Viewer : public Core::ImguiWindow{
public:
    ChipTMS9918Viewer(bool, std::string imgui_win_name);
    ~ChipTMS9918Viewer();
    void renderImguiWindow() override;
private:

};


}
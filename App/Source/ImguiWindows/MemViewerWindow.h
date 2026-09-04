#pragma once

#include "imgui.h"
#include "ImguiWindow.h"
#include "imgui_memory_editor.h"

namespace UI{

class MemViewerWindow : public Core::ImguiWindow{
public:
    MemViewerWindow(bool, std::string);
    ~MemViewerWindow();
    void renderImguiWindow(Core::Application& app) override;
private:
    MemoryEditor mem_edit;

    char test_memory[1<<15];
};


}
#pragma once

#include "ImguiWindow.h"
#include "imgui_memory_editor.h"

namespace UI{

class MemViewerWindow : public Core::ImguiWindow{
public:
    MemViewerWindow(bool, std::string);
    ~MemViewerWindow();
    void renderImguiWindow() override;
private:
};


}
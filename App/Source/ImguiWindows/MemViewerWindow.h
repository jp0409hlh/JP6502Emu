#pragma once

#include "ImguiWindow.h"

namespace UI{

class MemViewerWindow : public Core::ImguiWindow{
public:
    MemViewerWindow(bool, std::string);
    ~MemViewerWindow();
    void renderImguiWindow() override;
private:
};


}
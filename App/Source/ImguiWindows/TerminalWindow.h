#pragma once

#include "ImguiWindow.h"

namespace UI{

class TerminalWindow : public Core::ImguiWindow{
public:
    TerminalWindow(bool, std::string);
    ~TerminalWindow();
    void renderImguiWindow() override;
private:

};


}
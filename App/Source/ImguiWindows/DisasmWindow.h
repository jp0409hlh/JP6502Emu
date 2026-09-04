#pragma once

#include "ImguiWindow.h"

namespace UI{

class DisasmWindow : public Core::ImguiWindow{
public:
    DisasmWindow(bool, std::string);
    ~DisasmWindow();
    void renderImguiWindow(Core::Application& app) override;
private:
};

}
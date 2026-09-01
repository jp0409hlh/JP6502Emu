#pragma once

#include "ImguiWindow.h"

namespace UI{

class VideoWindow : public Core::ImguiWindow{
public:
    VideoWindow(bool, std::string);
    ~VideoWindow();
    void renderImguiWindow() override;
private:
};

}
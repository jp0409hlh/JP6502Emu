#pragma once

#include <string>

namespace Core{

class ImguiWindow{
public:
    ImguiWindow() = default;
    ImguiWindow(bool, std::string){}; // For abstract Base class constructor must be implemented
    ~ImguiWindow(){}; // For abstract Base class destructor must be implemented
    virtual void renderImguiWindow() = 0;
protected:
    std::string ImguiWindowName;
    bool show;
};

}
#pragma once

#include <string>

#include "Application.h"

namespace Core{

class Application; // Forward declaration

class ImguiWindow{
public:
    ImguiWindow() = default;
    ImguiWindow(bool, std::string){}; // For abstract Base class constructor must be implemented
    ~ImguiWindow() = default; // For abstract Base class destructor must be implemented as defaults
    virtual void renderImguiWindow(Application& app) = 0;
protected:
    std::string ImguiWindowName;
    bool show;
};

}
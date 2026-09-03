#include <stdio.h>

#include "ImguiWindows/MenuBar.h"
#include "ImguiWindows/ChipViewer.h"
#include "ImguiWindows/DisasmWindow.h"
#include "ImguiWindows/MemViewerWindow.h"
#include "ImguiWindows/TerminalWindow.h"
#include "ImguiWindows/VideoWindow.h"
#include "Application.h"


int main(int argc, char** argv){
    std::string app_name = "JP6502Emu";
    Core::Application app(app_name);
    if(!app.Init()){
        // TODO : Change this to error popup
        printf("INITALIZATION FAILED");
        return 0;
    }
    UI::MenuBar menu_bar(true, "Menu_bar");
    UI::Chip6502Viewer c_6502_view(true, "6502");
    UI::Chip6522Viewer c_6522_view(true, "6522");
    UI::Chip6551Viewer c_6551_view(true, "6551");
    UI::ChipTMS9918Viewer c_9918_view(true, "TMS9918");
    UI::DisasmWindow disasm_view(true, "Disassembly");
    UI::MemViewerWindow mem_view(true, "Memory viewer");
    UI::TerminalWindow term_view(true, "Terminal");
    UI::VideoWindow vid_view(true, "Video output");

#ifdef DEBUG
    printf("Start pushing windows");
#endif 

    app.AddImguiWindow(&menu_bar);
    app.AddImguiWindow(&c_6502_view);
    app.AddImguiWindow(&c_6522_view);
    app.AddImguiWindow(&c_6551_view);
    app.AddImguiWindow(&c_9918_view);
    app.AddImguiWindow(&disasm_view);
    app.AddImguiWindow(&mem_view);
    app.AddImguiWindow(&term_view);
    app.AddImguiWindow(&vid_view);

#ifdef DEBUG
    printf("APP start running");
#endif

    app.Run();

#ifdef DEBUG
    printf("APP QUIT\n");
#endif

    return 0;
}
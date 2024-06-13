#pragma once

#include <imgui.h>

#include "subController.hpp"


class GuiController: public SubController {
public:
    GuiController(Model& model, MainController& controller);

    inline bool WantCaptureMouse()
        { return ImGui::GetIO().WantCaptureMouse; }

    inline void SetOuterTesselationLevel(int level)
        { model.SetOuterTesselationLevel(level); }

    inline void SetInnerTesselationLevel(int level)
        { model.SetInnerTesselationLevel(level); }
};

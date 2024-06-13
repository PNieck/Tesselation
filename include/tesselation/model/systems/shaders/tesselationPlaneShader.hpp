#pragma once

#include "shader.hpp"


class TesselationPlaneShader: private Shader {
public:
    TesselationPlaneShader():
        Shader(
            "../../shaders/stdShader.vert",
            "../../shaders/stdShader.frag",
            nullptr,
            "../../shaders/plane.tese"
        ) {}

    inline void SetOuterTesselationLevel(float level) const {
        float v[] = { level, level, level, level };
        glPatchParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL, v);
    }

    inline void SetInnerTesselationLevel(float level) const {
        float v[] = { level, level };
        glPatchParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL, v);
    }

    inline void SetColor(const alg::Vec4& color) const
        { setVec4("color", color); }

    inline void SetMVP(const alg::Mat4x4& matrix) const
        { setMatrix4("MVP", matrix); }

    inline void Use() const
        { use(); }
};

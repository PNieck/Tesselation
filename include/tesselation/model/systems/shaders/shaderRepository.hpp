#pragma once

#include "stdShader.hpp"
#include "bicubicBezierSurfaceShader.hpp"


class ShaderRepository {
public:
    inline const StdShader& GetStdShader() const
        { return stdShader; }

    inline const BicubicBezierSurfaceShader& GetBezierSurfaceShader() const
        { return bezierSurfaceShader; }

private:
    StdShader stdShader;
    BicubicBezierSurfaceShader bezierSurfaceShader;
};

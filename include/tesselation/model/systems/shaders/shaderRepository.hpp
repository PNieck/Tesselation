#pragma once

#include "stdShader.hpp"


class ShaderRepository {
public:
    inline const StdShader& GetStdShader() const
        { return stdShader; }

private:
    StdShader stdShader;
};

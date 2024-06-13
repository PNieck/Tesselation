#pragma once

#include <ecs/system.hpp>

#include "shaders/shaderRepository.hpp"

#include <vector>


class TesselationPlaneSystem: public System {
public:
    static void RegisterSystem(Coordinator& coordinator);

    inline void Init(ShaderRepository* shaderRepo)
        { this->shaderRepo = shaderRepo; }

    void CreatePlane(Entity entity);

    void Render() const;

private:
    ShaderRepository* shaderRepo;
    float outerLevel = 3.f;
    float innerLevel = 5.f;

    std::vector<float> GenerateVertices() const;
    std::vector<uint32_t> GenerateIndices() const;
};

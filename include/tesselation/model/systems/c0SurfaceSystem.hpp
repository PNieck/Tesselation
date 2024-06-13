#pragma once

#include <ecs/system.hpp>

#include "shaders/shaderRepository.hpp"
#include "../components/position.hpp"
#include "../components/controlPoints.hpp"
#include "../components/c0SurfacePatches.hpp"
#include "../components/c0SurfaceDensity.hpp"
#include "c0PatchesSystem.hpp"


class C0SurfaceSystem: public System {
public:
    static void RegisterSystem(Coordinator& coordinator);

    Entity CreateSurface(const Position& pos);

    void AddRowOfPatches(Entity surface) const;
    void AddColOfPatches(Entity surface) const;

    void DeleteRowOfPatches(Entity surface) const;
    void DeleteColOfPatches(Entity surface) const;

    inline void SetDensity(Entity entity, C0SurfaceDensity density) const
        { coordinator->SetComponent<C0SurfaceDensity>(entity, density); }

    inline void ShowBezierPolygon(Entity cylinder) const
        { coordinator->GetSystem<C0PatchesSystem>()->ShowPolygon(cylinder); }

    inline void HideBezierPolygon(Entity cylinder) const
        { coordinator->GetSystem<C0PatchesSystem>()->HidePolygon(cylinder); }

private:
    static const alg::Vec3 offsetX;
    static const alg::Vec3 offsetZ;
};

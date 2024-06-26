#pragma once

#include <ecs/coordinator.hpp>

#include "model/systems/cameraSystem.hpp"
#include "model/systems/pointsSystem.hpp"
#include "model/systems/tesselationPlaneSystem.hpp"
#include "model/systems/shaders/shaderRepository.hpp"
#include "model/systems/c0SurfaceSystem.hpp"
#include "model/systems/c0PatchesSystem.hpp"

#include "model/components/scale.hpp"
#include "model/components/rotation.hpp"

#include "utilities/line.hpp"


class Model
{
public:
    Model(int viewport_width, int viewport_height);

    void Update() {};

    void RenderFrame();

    inline void RotateCamera(float x, float y) const
        { cameraSys->RotateAroundTarget(x, y); }

    inline float GetCameraDistanceFromTarget() const
        { return cameraSys->GetDistanceToTarget(); }

    inline void SetCameraDistance(float newDist) const
        { cameraSys->SetDistanceToTarget(newDist); }

    inline void MultiplyCameraDistanceFromTarget(float coefficient) const
        { cameraSys->MultiplyDistanceToTarget(coefficient); }

    void ChangeViewportSize(int width, int height);

    inline const std::set<ComponentId>& GetEntityComponents(Entity entity) const
        { return coordinator.GetEntityComponents(entity); }

    template <typename Comp>
    inline const Comp& GetComponent(Entity entity) const
        { return coordinator.GetComponent<Comp>(entity); }

    template <typename Comp>
    inline void SetComponent(Entity entity, const Comp& comp)
        { coordinator.SetComponent<Comp>(entity, comp); }

    template <typename Comp>
    static inline constexpr ComponentId GetComponentId()
        { return ComponentsManager::GetComponentId<Comp>(); }

    inline void SetOuterTesselationLevel(int level)
        { c0PatchesSystem->SetOuterTesselationLevel(level); }

    inline void SetInnerTesselationLevel(int level)
        { c0PatchesSystem->SetInnerTesselationLevel(level); }

    inline int GetOuterTesselationLevel() const
        { return c0PatchesSystem->GetOuterTesselationLevel(); }

    inline int GetInnerTesselationLevel() const
        { return c0PatchesSystem->GetInnerTesselationLevel(); }

private:
    Coordinator coordinator;
    ShaderRepository shadersRepo;

    std::shared_ptr<CameraSystem> cameraSys;
    std::shared_ptr<PointsSystem> pointsSys;
    std::shared_ptr<C0SurfaceSystem> c0SurfaceSystem;
    std::shared_ptr<C0PatchesSystem> c0PatchesSystem;

    Entity cube, water, duck;

    alg::Vec3 PointFromViewportCoordinates(float x, float y) const;
    Line LineFromViewportCoordinates(float x, float y) const;
};

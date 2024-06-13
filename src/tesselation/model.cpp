#include <tesselation/model.hpp>

#include <tesselation/utilities/line.hpp>
#include <tesselation/utilities/plane.hpp>
#include <tesselation/utilities/angle.hpp>

#include <tesselation/model/components/registerComponents.hpp>
#include <tesselation/model/components/cameraParameters.hpp>

#include <tesselation/model/systems/toUpdateSystem.hpp>
#include <tesselation/model/systems/controlPointsSystem.hpp>

#include <stdexcept>


Model::Model(int viewport_width, int viewport_height)
{
    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(std::numeric_limits<uint32_t>::max());

    RegisterAllComponents(coordinator);

    CameraSystem::RegisterSystem(coordinator);
    ToUpdateSystem::RegisterSystem(coordinator);
    PointsSystem::RegisterSystem(coordinator);
    TesselationPlaneSystem::RegisterSystem(coordinator);
    C0SurfaceSystem::RegisterSystem(coordinator);
    C0PatchesSystem::RegisterSystem(coordinator);
    ControlPointsSystem::RegisterSystem(coordinator);

    cameraSys = coordinator.GetSystem<CameraSystem>();
    pointsSys = coordinator.GetSystem<PointsSystem>();
    c0SurfaceSystem = coordinator.GetSystem<C0SurfaceSystem>();
    c0PatchesSystem = coordinator.GetSystem<C0PatchesSystem>();
    auto controlPointsSystem = coordinator.GetSystem<ControlPointsSystem>();

    CameraParameters params {
        .target = Position(0.0f),
        .viewportWidth = viewport_width,
        .viewportHeight = viewport_height,
        .fov = Angle::FromDegrees(45.f).ToRadians(),
        .near_plane = 0.1f,
        .far_plane = 100.0f,
    };

    cameraSys->Init(params, Position(0.0f, 0.0f, 10.0f));
    pointsSys->Init(&shadersRepo);
    c0PatchesSystem->Init(&shadersRepo);
    controlPointsSystem->Init();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable( GL_PROGRAM_POINT_SIZE );
    glPointSize(10.0f);

    Entity plane = c0SurfaceSystem->CreateSurface(Position(-0.5f, 0.f, 0.5f));
}


void Model::RenderFrame()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    c0PatchesSystem->Render();
}


void Model::ChangeViewportSize(int width, int height)
{
    glViewport(0, 0, width, height);
    cameraSys->ChangeViewportSize(width, height);
}


Line Model::LineFromViewportCoordinates(float x, float y) const
{
    auto viewMtx = cameraSys->ViewMatrix();
    auto perspectiveMtx = cameraSys->PerspectiveMatrix();

    auto cameraInv = (perspectiveMtx * viewMtx).Inverse().value();

    alg::Vec4 nearV4 = cameraInv * alg::Vec4(x, y, 1.0f, 1.0f);
    alg::Vec4 farV4 = cameraInv * alg::Vec4(x, y, -1.0f, 1.0f);

    alg::Vec3 near = alg::Vec3(
        nearV4.X() / nearV4.W(),
        nearV4.Y() / nearV4.W(),
        nearV4.Z() / nearV4.W()
    );

    alg::Vec3 far = alg::Vec3(
        farV4.X() / farV4.W(),
        farV4.Y() / farV4.W(),
        farV4.Z() / farV4.W()
    );

    return Line::FromTwoPoints(near, far);
}

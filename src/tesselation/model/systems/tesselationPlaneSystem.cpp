#include <tesselation/model/systems/tesselationPlaneSystem.hpp>

#include <ecs/coordinator.hpp>

#include <tesselation/model/components/mesh.hpp>

#include <tesselation/model/systems/cameraSystem.hpp>


void TesselationPlaneSystem::RegisterSystem(Coordinator &coordinator)
{
    coordinator.RegisterSystem<TesselationPlaneSystem>();
}


void TesselationPlaneSystem::CreatePlane(Entity entity)
{
    Mesh mesh;

    mesh.Update(
        GenerateVertices(),
        GenerateIndices()
    );

    coordinator->AddComponent<Mesh>(entity, mesh);

    entities.insert(entity);
}


void TesselationPlaneSystem::Render() const
{
    // if (entities.empty()) {
    //     return;
    // }

    // auto const& cameraSystem = coordinator->GetSystem<CameraSystem>();
    // auto const& shader = shaderRepo->GetTesselationPlaneShader();

    // alg::Mat4x4 cameraMtx = cameraSystem->PerspectiveMatrix() * cameraSystem->ViewMatrix();

    // shader.Use();
    // shader.SetColor(alg::Vec4(1.0f));

    // glPatchParameteri(GL_PATCH_VERTICES, 4);
    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    // for (auto const entity : entities) {
    //     auto const mesh = coordinator->GetComponent<Mesh>(entity);

    //     shader.SetMVP(cameraMtx);
    //     shader.SetOuterTesselationLevel(5.0);
    //     shader.SetInnerTesselationLevel(3.0);
        
    //     mesh.Use();
    //     glDrawElements(GL_PATCHES, mesh.GetElementsCnt(), GL_UNSIGNED_INT, 0);
    // }
}


std::vector<float> TesselationPlaneSystem::GenerateVertices() const
{
    return {
        // Vertex 0
        1.f, 0.f, 1.f,

        // Vertex 1
        1.f, 0.f, -1.f,

        // Vertex 2
        -1.f, 0.f, -1.f,

        // Vertex 3
        -1.f, 0.f, 1.f
    };
}


std::vector<uint32_t> TesselationPlaneSystem::GenerateIndices() const
{
    return {
        0, 1, 2, 3
    };
}

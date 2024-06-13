#include <tesselation/model/components/registerComponents.hpp>

#include <tesselation/model/components/cameraParameters.hpp>
#include <tesselation/model/components/mesh.hpp>
#include <tesselation/model/components/position.hpp>
#include <tesselation/model/components/rotation.hpp>
#include <tesselation/model/components/scale.hpp>
#include <tesselation/model/components/toUpdate.hpp>
#include <tesselation/model/components/texture.hpp>
#include <tesselation/model/components/meshWithTex.hpp>
#include <tesselation/model/components/c0SurfaceDensity.hpp>
#include <tesselation/model/components/c0SurfacePatches.hpp>
#include <tesselation/model/components/controlPoints.hpp>
#include <tesselation/model/components/hasPatchesPolygon.hpp>
#include <tesselation/model/components/patchesPolygonMesh.hpp>


void RegisterAllComponents(Coordinator& coordinator)
{
    coordinator.RegisterComponent<CameraParameters>();
    coordinator.RegisterComponent<Mesh>();
    coordinator.RegisterComponent<Position>();
    coordinator.RegisterComponent<Rotation>();
    coordinator.RegisterComponent<Scale>();
    coordinator.RegisterComponent<ToUpdate>();
    coordinator.RegisterComponent<Texture>();
    coordinator.RegisterComponent<MeshWithTex>();
    coordinator.RegisterComponent<C0SurfaceDensity>();
    coordinator.RegisterComponent<C0SurfacePatches>();
    coordinator.RegisterComponent<ControlPoints>();
    coordinator.RegisterComponent<HasPatchesPolygon>();
    coordinator.RegisterComponent<PatchesPolygonMesh>();
}

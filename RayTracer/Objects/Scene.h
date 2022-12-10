#pragma once
#include "../Math/Color.h"
#include <vector>
#include <memory>

class Object;
struct Ray;
struct RaycastHit;

class Scene
{
public:
    Scene() = default;
    Scene(color3& topColor, color3& bottomColor) :
        m_topColor{ topColor },
        m_bottomColor{ bottomColor }{}
    color3 Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth);
    void AddObject(std::unique_ptr<Object> object);

private:
    color3 m_topColor{ 1.0, 1.0, 1.0 };
    color3 m_bottomColor { 0.5f, 0.7f, 1.0f };
    std::vector <std::unique_ptr<Object>> m_objects;
};
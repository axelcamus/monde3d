#include "light.h"

class PointLight : public Light
{
public:
    PointLight(const PropertyList &propList)
        : Light(propList.getColor("intensity", Color3f(1.f)))
    {
        m_position = propList.getPoint("position", Point3f::UnitX());
    }

    Vector3f direction(const Point3f& x, float* dist = 0) const
    {
        if(dist)
            return m_position - x;

        return Vector3f(0.f);
    }

    Color3f intensity(const Point3f& x) const
    {
        float dist = sqrt( pow(x.x() - m_position.x(), 2) + pow(x.y() - m_position.y(), 2) + pow(x.z() - m_position.z(), 2) );
        return Color3f(m_intensity/(dist*dist));
    }

    std::string toString() const {
        return tfm::format(
            "PointLight[\n"
            "  intensity = %s\n"
            "  position = %s\n"
            "]", m_intensity.toString(),
                 ::toString(m_position));
    }

protected:
    Point3f m_position;
};

REGISTER_CLASS(PointLight, "pointLight")

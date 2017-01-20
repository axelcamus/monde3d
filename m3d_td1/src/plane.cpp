#include "plane.h"

Plane::Plane()
{
}

Plane::Plane(const PropertyList &propList)
{
    m_position = propList.getPoint("position",Point3f(0,0,0));
    m_normal = propList.getVector("direction",Point3f(0,0,1));
}

Plane::~Plane()
{
}

bool Plane::intersect(const Ray& ray, Hit& hit) const
{
    float t = (m_position.dot(m_normal) - ray.origin.dot(m_normal)) / ray.direction.dot(m_normal);

    if(t > 0){
    	hit.setT(t);
    	hit.setShape(this);
    	hit.setNormal(m_normal);
    	return true;
    }

    return false;
}

REGISTER_CLASS(Plane, "plane")

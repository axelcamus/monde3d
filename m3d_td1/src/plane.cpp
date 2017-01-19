#include "plane.h"

Plane::Plane()
{
}

Plane::Plane(const PropertyList &propList)
{
    m_position = propList.getPoint("point",Point3f(0,0,0));
    m_normal = propList.getVector("direction",Point3f(0,0,1));
}

Plane::~Plane()
{
}

bool Plane::intersect(const Ray& ray, Hit& hit) const
{
    float t = ((ray.origin.dot(m_normal)) + (m_position.dot(m_normal))) / (ray.direction.dot(m_normal));

    if(t > 0){
    	printf("%f\n", t);
    	hit.setT(t);
    }

    return true;
}

REGISTER_CLASS(Plane, "plane")

#include "sphere.h"
#include <iostream>

Sphere::Sphere(float radius)
    : m_radius(radius)
{
}

Sphere::Sphere(const PropertyList &propList)
{
    m_radius = propList.getFloat("radius",1.f);
    m_center = propList.getPoint("center",Point3f(0,0,0));
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
	float a = ray.direction.squaredNorm();
	float b = 2* ray.direction.dot(ray.origin - m_center);
	float c = (ray.origin - m_center).squaredNorm() - (m_radius*m_radius);
	
	float delta = b*b - 4*a*c;
	if(delta < 0)
		return false;

	if(delta == 0){
		float t = -b/(2*a);
		hit.setT(t);
		hit.setNormal((ray.at(t)-m_center)/m_radius);
	}
	else{
		float t1 = (-b - sqrt(delta))/(2*a);
		float t2 = (-b + sqrt(delta)/(2*a));
		if(t1 > t2){
			hit.setT(t2);
			hit.setNormal((ray.at(t2)-m_center)/m_radius);
		}
		else{
			hit.setT(t1);
			hit.setNormal((ray.at(t1)-m_center)/m_radius);
		}
	}
	hit.setShape(this);
	return true;
}

REGISTER_CLASS(Sphere, "sphere")

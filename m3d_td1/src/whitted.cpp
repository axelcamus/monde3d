#include "integrator.h"
#include "scene.h"

class WhittedIntegrator : public Integrator {
public:
    WhittedIntegrator(const PropertyList &props)
        : maxRecursion(props.getInteger("maxRecursion", 0))
    {}

    Color3f Li(const Scene *scene, const Ray &ray) const {
        Hit hit = Hit();
        scene->intersect(ray, hit);

        if(ray.recursionLevel >= maxRecursion)
            return Color3f(0.f);
        
        if(hit.foundIntersection()){

            Color3f c = Color3f(0.f);
            Color3f brdf = Color3f(0.f);

            Point3f x = ray.at(hit.t());

            float dir_dot_n = 0.f;
            float dist = 0.f;
            Ray rayLight;
            Hit hitLight;
            
            for(int i = 0; i < scene->lightList().size(); i++){
                rayLight = Ray(x + 0.001 * hit.normal(), scene->lightList()[i]->direction(x));
                hitLight = Hit();

                scene->intersect(rayLight, hitLight);
                scene->lightList()[i]->direction(x, &dist);

                if(hitLight.foundIntersection()){
                    if(hitLight.t() > dist){
                        dir_dot_n = scene->lightList()[i]->direction(x).dot(hit.normal());
                        brdf = hit.shape()->material()->brdf(-ray.direction, scene->lightList()[i]->direction(x), hit.normal(), NULL);
                        c += brdf * std::max(dir_dot_n, 0.f) * scene->lightList()[i]->intensity(x);
                    }
                }
                else{
                    dir_dot_n = scene->lightList()[i]->direction(x).dot(hit.normal());
                    brdf = hit.shape()->material()->brdf(-ray.direction, scene->lightList()[i]->direction(x), hit.normal(), NULL);
                    c += brdf * std::max(dir_dot_n, 0.f) * scene->lightList()[i]->intensity(x);
                }
            }
            Vector3f refract = 2*(hit.normal().dot(-ray.direction)) * hit.normal() + ray.direction;
            Ray recRay = Ray(x + 0.001 * hit.normal(), refract);
            recRay.recursionLevel ++;
            return c + Li(scene, recRay) * hit.shape()->material()->reflectivity() * std::max(recRay.direction.dot(hit.normal()), 0.f);
        }
        if(ray.recursionLevel == 0)
            return scene->backgroundColor();
        return Color3f(0.f);
    }

    std::string toString() const {
        return "WhittedIntegrator[]";
    }

private:
    int maxRecursion;
};

REGISTER_CLASS(WhittedIntegrator, "whitted")

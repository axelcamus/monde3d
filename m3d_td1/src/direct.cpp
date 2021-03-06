#include "integrator.h"
#include "scene.h"

class DirectIntegrator : public Integrator {
public:
    DirectIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, const Ray &ray) const {
        Hit hit = Hit();
        scene->intersect(ray, hit);
        
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
            
            
            return c;
        }
        return scene->backgroundColor();
    }

    std::string toString() const {
        return "DirectIntegrator[]";
    }
};

REGISTER_CLASS(DirectIntegrator, "direct")

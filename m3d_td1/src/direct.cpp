#include "integrator.h"
#include "scene.h"

class DirectIntegrator : public Integrator {
public:
    DirectIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, const Ray &ray) const {
        Hit hit;
        scene->intersect(ray, hit);
        float dir = 0.f;
        if(hit.shape() != NULL){
            for(int i=0; i < scene->lightList.size(); i++){
                
            }
        }
        return scene->backgroundColor();
    }

    std::string toString() const {
        return "DirectIntegrator[]";
    }
};

REGISTER_CLASS(DirectIntegrator, "direct")

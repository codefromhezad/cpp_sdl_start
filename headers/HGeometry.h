using namespace Eigen;

class HGeometry {
public:
    virtual int intersect(HRay &ray, float &distance) = 0;
    virtual void getNormal(Vector3d &intersectPoint, Vector3d &normal) = 0;
};
using namespace Eigen;

class HGeometrySphere : public HGeometry {
public:
	Vector3d center;
	float radius;

	HGeometrySphere(Vector3d defCenter, float defRadius) {
		center = defCenter;
		radius = defRadius;
	}

    int intersect(HRay &ray, float &distance) {

    	Vector3d originToCenterRay = ray.position - center;
    	float A = ray.direction.dot(ray.direction);
    	float B = 2.0 * ray.direction.dot(originToCenterRay);
    	float C = originToCenterRay.dot(originToCenterRay) - radius * radius;
    	float disc = B * B - 4 * A * C;

    	if( disc > 0 ) {
    		disc = std::sqrtf(disc);
    		float dist1 = (-B - disc) / (2.0 * A);
    		float dist2 = (-B + disc) / (2.0 * A);

    		if(dist2 > FLT_EPSILON) {
			    if(dist1 < FLT_EPSILON) {
			        if(dist2 < dist1) {
			            distance = dist2;
			            return -1; // In Object
			        }
			    } else {
			        if(dist1 < distance) {
			            distance = dist1;
			            return 1;
			        }
			    }
			}
    	}

    	// Ray Misses
		return 0;
    }
    
    void getNormal(Vector3d &intersectPoint, Vector3d &normalVector) {
    	normalVector = intersectPoint - center;
    	normalVector.normalize();
    }
};
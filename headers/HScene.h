

class HScene {
public:
	std::vector<HGeometrySphere> spheres;

	void addSphere(HGeometrySphere &geometry) {
		spheres.push_back(geometry);
	}

	HColor castRay(HRay sceneRay) {

		/* CHECK FOR SPHERES */
		float intersectionDistance = MAX_DISTANCE;
		float lastIntersectionDistance = MAX_DISTANCE;
		HColor intersectionColor(0, 0, 0);

		for(int n = 0; n < spheres.size(); n++) {
			if( spheres[n].intersect(sceneRay, intersectionDistance) > 0 ) {
				if( intersectionDistance < lastIntersectionDistance ) {
					intersectionColor.r = 1.0;
					intersectionColor.g = 1.0;
					intersectionColor.b = 1.0;
				}
			}
		}

		return intersectionColor;
	}
};
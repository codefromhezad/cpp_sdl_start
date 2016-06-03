using namespace Eigen;

class HRay {
public:
	Vector3d position,
			 direction;

	HRay() {
		// Nothing
	}

	HRay(Vector3d defPosition, Vector3d defDirection) {
		position = defPosition;
		direction = defDirection;
	}
};
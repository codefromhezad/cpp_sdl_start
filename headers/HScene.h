#include <vector>

class HScene {
protected:
	std::vector<HGeometry*> geometries;

public:
	void add(HGeometry *geometry) {
		geometries.push_back(geometry);
	}
};
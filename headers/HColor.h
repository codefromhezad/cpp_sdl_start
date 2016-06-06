class HColor {
public:
	float r, g, b, a;

	HColor(float inR, float inG, float inB) {
		r = inR;
		g = inG;
		b = inB;
		a = 1.0;
	}

	HColor(float inR, float inG, float inB, float inA) {
		r = inR;
		g = inG;
		b = inB;
		a = inA;
	}
};
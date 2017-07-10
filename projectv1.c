#include <math.h>
#include <stdio.h>
#include <float.h>

int main() {
	int K = 32;
	int i;
  float M = 0.1;
	float LUT[K];

	for (i = 0; i < K - 1; i++) {
		LUT[i] = log2(1 + pow(2, -i));				
	}

	float f = 1.0;
	for (i = 0; i < K - 1; i++) {
		float MU = M - LUT[i];
		float PHI = f * (1 + pow(2, -i));

		if (MU >= 0) {
			M = MU;
			f = PHI;		
		}
	}

	printf("%f\n", f);
	return 0;
}



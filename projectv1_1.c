#include <math.h>
#include <stdio.h>
#include <float.h>

int main() {
	int K = 16;
	int i;
  int M = 1;
	int LUT[K];
	for (i = 0; i < K - 1; i++) {
		LUT[i] = ((1 << K) + (2>>i));
		printf("%i\n", LUT[i]);
	}

	printf("%f\n", pow(2, -5));
	printf("%f\n",  (2>>i) );

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



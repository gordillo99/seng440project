#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdint.h>

int main() {
	int K = 14;
    int M = 6 << K;
	int i;
    uint32_t f = 1 << K;
    uint32_t f_sqrt =  1 << K;

	for (i = 0; i < K - 1; i++) {
		uint32_t MU = (f * (((1 << K) + (2 << K - i)) * ((1 << K) + (2 << K - i)) >> K)) >> K; 
		uint32_t MU_SQRT = (f_sqrt * ((1 << K) + (2 << K - i))) >> K;
        
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}
	}

	printf("%f\n", ((float) f_sqrt) / pow(2,K));
	return 0;
}


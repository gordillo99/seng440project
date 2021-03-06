#include <stdio.h>
#include <stdint.h>

/*
	Fixed point arithmetic
	operator strength reduction (remove pow)
    variable caching
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
    
    uint32_t i;
    uint32_t f = 1 << K;
    uint32_t f_sqrt = 1 << K;
    uint32_t a;
    uint32_t MU;
    uint32_t MU_SQRT;

	for (i = 0; i < K - 1; i++) {
		a = (1 << K) + (1 << K - i);
		MU = (f * (a * a >> K)) >> K; 
		MU_SQRT = (f_sqrt * a) >> K;
        
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}
	}
	return f_sqrt;
}

int main() {
	uint32_t K = 14; // precision bits
    uint32_t M = (unsigned int) (2.5 * (1 << K)); // sqrt(M)
	M = calculate_sqrt(K, M);
	printf("%f\n", (float) M/(1 << K));
	return 0;
}


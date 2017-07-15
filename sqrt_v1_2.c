#include <stdio.h>
#include <stdint.h>

/*
	loop optimization (i counter)
	variable caching
	register caching (also declared in number of usage)
	operator strength reduction (remove multiplications)
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt = 1 << K;
	register uint32_t MU;
	register uint32_t MU_SQRT;
	M = M << K; // final output = sqrt(M)

	for (i ^= i; i != K - 1; i++) {
		MU = f + ( (f+f) >> i ) + ( f >> (i << 1) ); // previously (f * (a * a >> K)) >> K;      
		MU_SQRT = f_sqrt + ( f_sqrt >> i ); // previously (f_sqrt * a) >> K;
		
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}
	}

	return f_sqrt;
}

int main() {
	uint32_t K = 14; // precision bits
  uint32_t M = 2; // sqrt(M)
	
	printf("%d\n", calculate_sqrt(K, M));
	return 0;
}


#include <stdio.h>
#include <stdint.h>

/*
	loop unrolling
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt = f;
	register uint32_t MU;
	register uint32_t small_k = K - 1;

	for (i ^= i; i <= small_k; i += 2) { // have to use <= for loop unrolling
		MU = f + ( (f << 1) >> i ) + ( f >> (i << 1) );    
		
		if (MU <= M) {
			f = MU;
			f_sqrt = f_sqrt + ( f_sqrt >> i );
		}

		MU = f + ( (f << 1) >> (i+1) ) + ( f >> ((i+1) << 1) );    
		
		if (MU <= M) {
			f = MU;
			f_sqrt = f_sqrt + ( f_sqrt >> (i+1) );	
		}
	}

	return f_sqrt;
}

int main() {
	uint32_t K = 29; // precision bits
  	uint32_t M = (unsigned int) (2.0 * (1 << K)); // sqrt(M)
	M = calculate_sqrt(K, M);
	printf("%f\n", (float) M/(1 << K));
	return 0;
}


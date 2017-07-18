#include <stdio.h>
#include <stdint.h>

/*
	loop unrolling
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt = 1 << K;
	register uint32_t MU;
	register uint32_t MU_SQRT;
	register uint32_t small_k = K - 1;
	M = M << K; // final output = sqrt(M)

	// TODO: verify the actual number of iterations
	for (i ^= i; i <= small_k; i += 2) { // have to use <= for loop unrolling
		MU = f + ( (f << 1) >> i ) + ( f >> (i << 1) );    
		MU_SQRT = f_sqrt + ( f_sqrt >> i );
		
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}

		MU = f + ( (f << 1) >> (i+1) ) + ( f >> ((i+1) << 1) );    
		MU_SQRT = f_sqrt + ( f_sqrt >> (i+1) );
		
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


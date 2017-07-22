#include <stdio.h>
#include <stdint.h>

/*
	loop optimization (i counter)
	register caching (also declared in number of usage)
	operator strength reduction (remove multiplications)
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt = f;
	register uint32_t MU;
    register uint32_t small_k = K - 1;

	for (i ^= i; i != small_k; i++) {

		MU = f + ( (f << 1) >> i ) + ( f >> (i << 1) ); // previously (f * (a * a >> K)) >> K;      
		
		if (MU <= M) {
			f = MU;
			f_sqrt = f_sqrt + ( f_sqrt >> i );		
		}
	}

	return f_sqrt;
}

int main() {
	uint32_t K = 29; // precision bits
  	uint32_t M = (unsigned int) (3.625 * (1 << K)); //replace 2.5 with the number
	M = calculate_sqrt(K, M);
	printf("%f\n", (float) M/(1 << K));
	return 0;
}


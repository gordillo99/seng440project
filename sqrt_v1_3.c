#include <stdio.h>
#include <stdint.h>

/*
software pipeline
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt =  1 << K;
	register uint32_t m = M << K; // sqrt(M)
	register uint32_t MU;
	register uint32_t MU_SQRT;
	register uint32_t temp_a = 3 << K;
	printf("%d\n", temp_a);
	printf("%d\n", 3 << K);

	for (i ^= i; i != K; i++) {
		MU = (f * (temp_a * temp_a >> K)) >> K; 
		MU_SQRT = (f_sqrt * temp_a) >> K;
		temp_a = (1 << K) + (2 << K - i + 1);
	      
		if (MU <= m) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}		
	}
	return f_sqrt;
}

int main() {
	uint32_t K = 14; // precision bits
  uint32_t M = 6; // sqrt(M)
	
	printf("%d\n", calculate_sqrt(K, M));
	return 0;
}


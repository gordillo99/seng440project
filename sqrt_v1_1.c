#include <stdio.h>
#include <stdint.h>

/*
Fixed point arithmetic
operator strength reduction
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
		M = M << K;
	  uint32_t i;
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
	return f_sqrt;
}

int main() {
	uint32_t K = 14; // precision bits
  uint32_t M = 6 << K; // sqrt(M)
	
	printf("%d\n", calculate_sqrt(K, M));
	return 0;
}


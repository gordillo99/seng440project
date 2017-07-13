#include <stdio.h>
#include <stdint.h>

/*
loop optimization (i counter)
variable caching
register caching (also declared in number of usage)
*/

uint32_t calculate_sqrt(uint32_t K, uint32_t M) {
	register uint32_t i;
	register uint32_t f = 1 << K;
	register uint32_t f_sqrt =  1 << K;
	register uint32_t m = M << K; // sqrt(M)
	register uint32_t a;
	register uint32_t MU;
	register uint32_t MU_SQRT;

	for (i ^= i; i != K - 1; i++) {
	  a = (1 << K) + (2 << K - i);
		MU = (f * (a * a >> K)) >> K; 
		MU_SQRT = (f_sqrt * a) >> K;
	      
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


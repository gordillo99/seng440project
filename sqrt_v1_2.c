#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdint.h>

/*
loop optimization (i counter)
variable caching
register caching (also declared in number of usage)
*/

int main() {
	register uint32_t K = 14; // precision bits
    register uint32_t i;
    register uint32_t f = 1 << K;
    register uint32_t f_sqrt =  1 << K;
    register uint32_t M = 6 << K; // sqrt(M)

	for (i ^= i; i != K - 1; i++) {
        register uint32_t a = (1 << K) + (2 << K - i);
		register uint32_t MU = (f * (a * a >> K)) >> K; 
		register uint32_t MU_SQRT = (f_sqrt * a) >> K;
        
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}
	}

	printf("%f\n", ((float) f_sqrt) / pow(2,K) );
	return 0;
}


#include <stdio.h>
#include <stdint.h>

int main() {
	uint32_t K = 29; // precision bits
    uint32_t M = (unsigned int) (2.0 * (1 << K)); // sqrt(M)
	uint32_t result;
	__asm__ ( "calculate_sqrt %0, %1" : "=r" (result) : "r" (K) , "r" (M) );
	printf("%f\n", (float) result/(1 << K)); // result is scaled by 2^K
	return 0;
}

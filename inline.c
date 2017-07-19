#include <stdio.h>
#include <stdint.h>

int main() {
	uint32_t K = 14; // precision bits
        uint32_t M = 2; // sqrt(M)
	uint32_t result;
	__asm__ ( "calculate_sqrt %0, %1" : "=r" (result) : "r" (K) , "r" (M) );
	printf("%d\n", result); // result is scaled by 2^K
	return 0;
}

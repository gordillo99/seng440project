#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

void test() {
    uint32_t i;
    uint32_t j;
    uint32_t num_fails = 0;
    uint32_t num_success = 0;
    uint32_t counter = 0;

    FILE* file = fopen("test_output.txt", "r"); /* should check the result */
    char line[256];

    for (j = 1; j < 30; j++) {
        float a = 1.0;
        for (i = 0; i < 30; i++) {
            uint32_t M = (uint32_t) (a * (float)(1<<j));
            uint32_t K = j;
            uint32_t result = calculate_sqrt(K,M);
            fgets(line, sizeof(line), file);
            uint32_t expected = atoi (line);
            if (result == expected) {
                printf("the sqrt of M: %d is %d with %d precision bits is CORRECT\n", M, result, K); 
            } else {
                printf("the sqrt of M: %d is %d with %d precision bits is INCORRECT\n", M, result, K); 
                num_fails++;
            }
            a += 0.1;
            counter++;
        }
    }
    fclose(file);
    num_success = counter - num_fails;
    printf("\nThe total number of succeses: %d\n", num_success);
    printf("The total number of failures: %d\n", num_fails);
    printf("Success rate: %f percent\n", ( (float)num_success ) / counter * 100);
}

int main() {
  	test();
    return 0;
}



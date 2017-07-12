#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdint.h>

int32_t log2fix (uint32_t x, size_t precision)
{
    // This implementation is based on Clay. S. Turner's fast binary logarithm
    // algorithm[1].

    int32_t b = 1U << (precision - 1);
    int32_t y = 0;

    if (precision < 1 || precision > 31) {
        return INT32_MAX; // indicates an error
    }

    if (x == 0) {
        return INT32_MIN; // represents negative infinity
    }

    while (x < 1U << precision) {
        x <<= 1;
        y -= 1U << precision;
    }

    while (x >= 2U << precision) {
        x >>= 1;
        y += 1U << precision;
    }

    uint64_t z = x;

    for (size_t i = 0; i < precision; i++) {
        z = z * z >> precision;
        if (z >= 2U << precision) {
            z >>= 1;
            y += b;
        }
        b >>= 1;
    }

    return y;
}


int main() {
	int K = 8;
	int i;
    int M = 1;
	int LUT[K];
/*
    for (i = 0; i < K - 1; i++) {
		LUT[i] = log2fix( (  (1 + (2>>i)) * 1U  ) << K, K );
		printf("%i\n", LUT[i]);
        printf("%f\n", log2(1 + pow(2, -i)));
	}

	//printf("%f\n", pow(2, -5));
	//printf("%f\n",  (2>>i) );

	float f = 1.0;
	for (i = 0; i < K - 1; i++) {
		float MU = M - LUT[i];
		float PHI = f * (1 + pow(2, -i));

		if (MU >= 0) {
			M = MU;
			f = PHI;		
		}
	}

	printf("%f\n", f);
*/

    double scale = 1U << K;   
    printf("scale: %d\n", scale);

    for (i = 0; i < K - 1; i++) {
        int x = (1 + (2>>i));
		printf("log2fix(%f) = %f\n",x, log2fix(x * scale, K) / scale); 		
	}
   
	return 0;
}



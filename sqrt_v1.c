#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdint.h>

int main() {
	int K = 14;
    int M = 6;
	int i;
    double f = 1;
    double f_sqrt = 1;

	for (i = 0; i < K - 1; i++) {
		double MU = f * (1 + pow(2,-i)) * (1 + pow(2,-i)); 
		double MU_SQRT = f_sqrt * (1 + pow(2,-i));
        
		if (MU <= M) {
			f = MU;
			f_sqrt = MU_SQRT;		
		}
	}

	printf("%lf\n", f_sqrt);
	return 0;
}


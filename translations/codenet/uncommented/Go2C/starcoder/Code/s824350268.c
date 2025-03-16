#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000000
#define MOD 1000000007

int main() {
	int N;
	scanf("%d", &N);

	int sqrtN = (int)sqrt(N);
	int min = N;
	for (int i = 1; i <= sqrtN; i++) {
		if (N % i!= 0) {
			continue;
		}

		int num = i + (N / i) - 2;
		if (num < min) {
			min = num;
		}
	}

	printf("%d\n", min);
	return 0;
}


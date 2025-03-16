#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod 998244353
#define facNum 300001

int main() {
	int N;
	scanf("%d", &N);
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i%3 == 0 || i%5 == 0) {
			continue;
		}
		sum += i;
	}
	printf("%d\n", sum);
}

// 
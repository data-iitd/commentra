//problem_b.c
// This is the main file for problem B solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 1000000
#define MAX_M 1000000
#define MAX_A 1000000
#define MAX_SUM 1000000000
#define MAX_RATE 1000000000
#define constMod 1000000007

int main() {
	int n, m, sum, count;
	int a[MAX_N];

	scanf("%d %d", &n, &m);

	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	count = 0;
	for (int i = 0; i < n; i++) {
		double rate = (double)sum / (4 * m);
		if (a[i] >= rate) {
			count++;
		}
	}

	if (count >= m) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}


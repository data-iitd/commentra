//problem_b.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000000
#define MAX_M 1000000
#define MAX_A 1000000
#define MOD 1000000007

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int a[MAX_N];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		double rate = (double)sum / (4.0 * m);
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


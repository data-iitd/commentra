#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

// const abcd = "abcdefghijklmnopqrstuvwxyz"
// const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

int main() {
	char N[100000];
	scanf("%s", N);
	int n = 0;
	for (int i = 0; i < strlen(N); i++) {
		n += N[i] - '0';
	}
	int m = atoi(N);
	if (m % n == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

// 
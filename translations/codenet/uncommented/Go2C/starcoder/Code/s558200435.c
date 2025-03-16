#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 100000

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);

	int a[MAX_N];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int b[MAX_N];
	int b_len = 0;
	for (int i = 0; i < n; i++) {
		int v = a[i];
		int x = b_len;
		while (x > 0 && b[x-1] < v) {
			x--;
		}
		if (x == b_len) {
			b[b_len] = v;
			b_len++;
		} else {
			b[x] = v;
		}
	}

	printf("%d\n", b_len);
}


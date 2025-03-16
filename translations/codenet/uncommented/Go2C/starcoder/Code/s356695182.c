#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int len = 5;
	int l[len];
	for (int i = 0; i < len; i++) {
		scanf("%d", &l[i]);
	}
	int n = l[0]*l[3] + l[1]*l[4];
	int m = 2*l[2]*max(l[3],l[4]);
	int k = 2*l[2]*min(l[3],l[4]) + (l[0] > l[1]? l[0] * (l[3] - l[4]) : l[1] * (l[4] - l[3]));
	printf("%d\n", min(n, m, k));
	return 0;
}


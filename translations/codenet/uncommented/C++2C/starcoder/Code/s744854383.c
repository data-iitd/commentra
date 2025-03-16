#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int N;
	scanf("%d", &N);
	int a[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	int idx = 1;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] == idx) {
			idx++;
		} else {
			ans++;
		}
	}

	if (idx == 1) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}


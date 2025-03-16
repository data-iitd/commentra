#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int R, G, B, N;
	scanf("%d %d %d %d", &R, &G, &B, &N);

	int ans = 0;
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			int tmp = N - R*x - G*y;
			if (tmp >= 0 && tmp%B == 0) {
				ans++;
			}
		}
	}

	printf("%d", ans);
}

// END-OF-CODE

// Copyright (c) 2019 by <NAME>. All rights reserved.
// End of file.

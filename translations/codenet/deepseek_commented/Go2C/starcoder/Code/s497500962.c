
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
	int R, G, B, N;
	scanf("%d %d %d %d", &R, &G, &B, &N);

	int ans = 0;
	// Iterate over all possible values of x and y
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			// Calculate the remaining value after subtracting x*R and y*G
			int tmp = N - R*x - G*y;
			// Check if the remaining value is non-negative and a multiple of B
			if (tmp >= 0 && tmp%B == 0) {
				ans++;
			}
		}
	}

	printf("%d\n", ans);
}

// END-OF-CODE

// Translate the above C code to Python and end with comment "
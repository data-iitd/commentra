#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initializes a new Scanner instance to read from standard input.
int main() {
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	
	// Determines the maximum of H and W and assigns it to A.
	int A = (H > W)? H : W;
	
	// Calculates the result by dividing N by A and rounding up.
	// This is done by adding N-1 to the division result and then performing integer division by A.
	printf("%d\n", (N + A - 1) / A);
}


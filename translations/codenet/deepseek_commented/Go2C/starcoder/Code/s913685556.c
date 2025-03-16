
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// max function: Returns the larger of two integers.
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Main function: Initializes a new Scanner, reads two integers A and B,
// and calculates the maximum value among A+B, A-B, and A*B. Finally, it prints the maximum value.
int main() {
	int A, B;
	scanf("%d %d", &A, &B);

	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	printf("%d\n", mx);
}


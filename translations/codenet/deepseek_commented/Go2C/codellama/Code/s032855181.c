
#include <stdio.h>

// The `group` function takes an integer `n` and returns "B" if `n` is 4, 6, 9, or 11, otherwise it returns "A".
char *group(int n) {
	if (n == 4 || n == 6 || n == 9 || n == 11) {
		return "B";
	} else {
		return "A";
	}
}

int main() {
	int x, y;
	// Reads two integers `x` and `y` from the standard input.
	scanf("%d %d", &x, &y);

	// Checks if either `x` or `y` is 2. If so, it prints "No" and returns immediately.
	if (x == 2 || y == 2) {
		printf("No\n");
		return 0;
	}

	// Calls the `group` function for both `x` and `y` to determine their respective groups.
	char *xg = group(x);
	char *yg = group(y);

	// Compares the groups of `x` and `y`. If they are the same, it prints "Yes"; otherwise, it prints "No".
	if (strcmp(xg, yg) == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}


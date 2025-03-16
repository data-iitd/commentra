#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	if (x == 2 || y == 2) {
		printf("No\n");
		return 0;
	}

	char xg = group(x);
	char yg = group(y);

	if (xg == yg) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

char group(int n) {
	if (n == 4 || n == 6 || n == 9 || n == 11) {
		return 'B';
	} else {
		return 'A';
	}
}


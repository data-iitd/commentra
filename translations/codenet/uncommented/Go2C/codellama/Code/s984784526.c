#include <stdio.h>

int main() {
	int a[3];

	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	int five = 0;
	int seven = 0;

	for (int i = 0; i < 3; i++) {
		if (a[i] == 5) {
			five++;
		}
		if (a[i] == 7) {
			seven++;
		}

	}

	if (five == 2 && seven == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}


#include <stdio.h>

int main() {
	int A, B;
	scanf("%d %d", &A, &B);

	int ans;
	if (6 <= A && A <= 12) {
		ans = B / 2;
	} else if (12 < A) {
		ans = B;
	}
	printf("%d\n", ans);
}

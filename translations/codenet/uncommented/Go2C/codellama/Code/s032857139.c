
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000
#define MOD 1000000007
#define ALPHABET_NUM 26

int n, x;
int A[MAX_N];

int main() {
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	// S := make([]int, n)
	// sum := 0
	// for i := 0; i < n; i++ {
	// 	sum += A[i]
	// 	S[i] = sum
	// }

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
		} else {
			break;
		}
	}
	if (ans == n && x > 0) {
		ans--;
	}
	printf("%d\n", ans);

	return 0;
}


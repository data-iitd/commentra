#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n); // Read the number of elements
	int *as = (int *)malloc(sizeof(int) * n);
	int *ps = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]); // Read each element of the array

		int ns[n];
		int j = 0;
		while (as[i] > 1) {
			if (as[i] % 2 == 0) {
				ns[j] = 2;
				as[i] /= 2;
			} else if (as[i] % 3 == 0) {
				ns[j] = 3;
				as[i] /= 3;
			} else if (as[i] % 5 == 0) {
				ns[j] = 5;
				as[i] /= 5;
			} else {
				ns[j] = as[i];
				break;
			}
			j++;
		}
		for (int k = 0; k < j; k++) {
			ps[ns[k]]++;
		}
	}

	int x = 1;
	for (int k = 2; k <= 5; k++) {
		for (int i = 0; i < ps[k]; i++) {
			x = (x * k) % 1000000007;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + x / as[i]) % 1000000007;
	}
	printf("%d", ans); // Print the final answer
}


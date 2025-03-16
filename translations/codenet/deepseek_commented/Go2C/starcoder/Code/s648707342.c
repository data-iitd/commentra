#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Reads a single integer from standard input.
int scanInt() {
	int res;
	scanf("%d", &res);
	return res;
}

// Initializes the scanner to split input by words.
void init() {
	setbuf(stdout, NULL);
	setbuf(stdin, NULL);
}

// Defines a struct to represent an arm with left and right endpoints.
typedef struct {
	int l, r;
} arm;

// Sorts the arms based on their right endpoints.
void sortArms(arm *as, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (as[i].r > as[j].r) {
				arm tmp = as[i];
				as[i] = as[j];
				as[j] = tmp;
			}
		}
	}
}

// Counts the number of non-overlapping arms.
int countArms(arm *as, int n) {
	int ans = 1;
	int r = as[0].r;
	for (int i = 1; i < n; i++) {
		if (as[i].l >= r) {
			ans++;
			r = as[i].r;
		}
	}
	return ans;
}

int main() {
	// Reads the number of arms.
	int n = scanInt();
	
	// Creates a slice to store the arms.
	arm *as = malloc(n * sizeof(arm));
	
	// Reads each arm's range and stores the left and right endpoints.
	for (int i = 0; i < n; i++) {
		int x, l;
		scanf("%d %d", &x, &l);
		as[i].l = x - l;
		as[i].r = x + l;
	}
	
	// Sorts the arms based on their right endpoints.
	sortArms(as, n);
	
	// Counts the number of non-overlapping arms.
	int ans = countArms(as, n);
	
	// Prints the count of non-overlapping arms.
	printf("%d\n", ans);
}


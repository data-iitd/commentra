

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Read two integers from input: n (number of elements) and k (some parameter)
	int n = atoi(next());
	int k = atoi(next());
	
	// Read 'n' integers into slice 'a'
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		a[i] = atoi(next());
	}
	
	// Avoid unused variable error by assigning a value to the first element of 'a'
	a[0] = 0;
	
	// Initialize sum with the value of k and set ans to 1
	int sum = k;
	int ans = 1;
	
	// Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
	while (sum < n) {
		sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
		ans++; // Increment the answer counter
	}
	
	// Print the final answer
	printf("%d\n", ans);
}



#include <stdio.h>
#include <stdlib.h>

// Function to read a single word from the input
char* next() {
	char* word = malloc(sizeof(char) * 100);
	scanf("%s", word);
	return word;
}

// Function to read an integer from the input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a float64 from the input
float nextFloat64() {
	float f;
	scanf("%f", &f);
	return f;
}

// Function to read n integers from the input
int* nextInts(int n) {
	int* slice = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		slice[i] = nextInt();
	}
	return slice;
}

// Main function
int main() {
	// Set scanner to read words as input
	// Set scanner to read words as input
	// Read number of elements n and the sum of elements k from the input
	int n, k;
	n = nextInt();
	k = nextInt();

	// Initialize a slice of size n to store the input elements
	int* a = malloc(sizeof(int) * n);

	// Assign a default value of 0 to the first element of the slice to avoid unused variable error
	a[0] = 0;

	// Initialize sum and answer variables
	int sum, ans;
	sum = 0;
	ans = 1;

	// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	while (sum < n) {
		// Subtract 1 from sum and add k to find the next index to check
		sum = sum - 1 + k;
		// Increment the answer variable for each iteration
		ans++;
	}

	// Print the answer
	printf("%d\n", ans);

	// End of code
	return 0;
}


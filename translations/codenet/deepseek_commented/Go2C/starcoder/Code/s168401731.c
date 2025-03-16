#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_next_string reads the next word from the stdin.
char* get_next_string(char* str) {
	scanf("%s", str);
	return str;
}

// get_next_int reads the next word from the stdin and converts it to an integer.
int get_next_int(int* num) {
	char str[1000001];
	scanf("%s", str);
	*num = atoi(str);
	return *num;
}

// get_next_int64 reads the next word from the stdin and converts it to an int64.
int64_t get_next_int64(int64_t* num) {
	char str[1000001];
	scanf("%s", str);
	*num = atoll(str);
	return *num;
}

// get_next_uint64 reads the next word from the stdin and converts it to an uint64.
uint64_t get_next_uint64(uint64_t* num) {
	char str[1000001];
	scanf("%s", str);
	*num = atoll(str);
	return *num;
}

// get_next_float64 reads the next word from the stdin and converts it to an float64.
double get_next_float64(double* num) {
	char str[1000001];
	scanf("%s", str);
	*num = atof(str);
	return *num;
}

// main function handles the input/output operations.
int main(int argc, char** argv) {
	// Declare a variable to store the number of integers to process.
	int n;
	// Read the number of integers to process.
	get_next_int(&n);

	// Initialize the answer to "second".
	char* ans = "second";
	for (int i = 0; i < n; i++) {
		// Read the next integer.
		int a;
		get_next_int(&a);
		// Check if the integer is odd.
		if (a % 2 == 1) {
			ans = "first";
			break;
		}
	}
	// Print the result based on the condition.
	printf("%s\n", ans);
	return EXIT_SUCCESS;
}


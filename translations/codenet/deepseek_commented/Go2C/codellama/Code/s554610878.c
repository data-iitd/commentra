#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

int main() {
	char *week[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	char *s = getString(); // Get the input day as a string.
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(s, week[i]) == 0) {
			index = i; // Set the index of the day found in the week array.
			break;
		}
	}

	printf("%d\n", 7 - index); // Print the number of days until Sunday.
	return 0;
}

// Helper function to read an integer from standard input.
int getInt() {
	char *line = NULL;
	size_t size = 0;
	int i;
	if (getline(&line, &size, stdin) == -1) {
		return -1;
	}
	i = atoi(line);
	free(line);
	return i;
}

// Helper function to read a string from standard input.
char *getString() {
	char *line = NULL;
	size_t size = 0;
	if (getline(&line, &size, stdin) == -1) {
		return NULL;
	}
	return line;
}

// Function to return the absolute value of an integer.
int abs(int a) {
	return (int)fabs(a);
}

// Function to return the result of raising the first argument to the power of the second argument.
int pow(int p, int q) {
	return (int)pow(p, q);
}

// Function to return the smallest integer from a list of integers.
int min(int nums[], int size) {
	int res = nums[0];
	for (int i = 1; i < size; i++) {
		res = (int)fmin(res, nums[i]);
	}
	return res;
}

// Function to return the largest integer from a list of integers.
int max(int nums[], int size) {
	int res = nums[0];
	for (int i = 1; i < size; i++) {
		res = (int)fmax(res, nums[i]);
	}
	return res;
}

// Function to check if a string is present in a slice of strings.
int strSearch(char *a[], char *b) {
	for (int i = 0; i < 7; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print a slice of integers in a specific format.
void printIntArray(int *array, int size) {
	char *strArray = (char *)malloc(size * sizeof(char));
	sprintf(strArray, "%d", array[0]);
	for (int i = 1; i < size; i++) {
		sprintf(strArray, "%s %d", strArray, array[i]);
	}
	printf("%s\n", strArray);
	free(strArray);
}

// Function to return the modulo of an integer with respect to mod.
int calcMod(int x) {
	return x % mod;
}


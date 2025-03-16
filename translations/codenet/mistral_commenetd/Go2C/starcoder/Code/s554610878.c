
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MOD 1000000007

// Function to read a single line of input as string
char* getString() {
	char* str = malloc(MAX_SIZE);
	scanf("%s", str);
	return str;
}

// Function to read a single line of input as integer
int getInt() {
	char* str = getString();
	int num = atoi(str);
	free(str);
	return num;
}

// Function to calculate the absolute value of a number
int abs(int num) {
	return num < 0? -num : num;
}

// Function to calculate the power of a number
int pow(int base, int exp) {
	int res = 1;
	while (exp > 0) {
		if (exp & 1) {
			res *= base;
			res %= MOD;
		}
		base *= base;
		base %= MOD;
		exp >>= 1;
	}
	return res;
}

// Function to find the minimum of given numbers
int min(int nums[], int size) {
	int min = nums[0];
	for (int i = 1; i < size; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find the maximum of given numbers
int max(int nums[], int size) {
	int max = nums[0];
	for (int i = 1; i < size; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char* strs[], int size, char* str) {
	for (int i = 0; i < size; i++) {
		if (strcmp(strs[i], str) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array
void printIntArray(int nums[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

// Function to calculate the modulo of a number
int calcMod(int num) {
	return num % MOD;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	char* week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// Read input string from scanner
	char* s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(s, week[i]) == 0) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		printf("Invalid day of the week\n");
		return 0;
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	int daysUntilSunday = 7 - index;
	printf("The number of days until Sunday is: %d\n", daysUntilSunday);
}

// 
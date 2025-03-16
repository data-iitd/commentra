
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

// Initialize scanner
char *scanner(char *buf, int *buf_size, int *buf_pos) {
	if (*buf_pos >= *buf_size) {
		*buf_size = *buf_size * 2;
		if (*buf_size > MAX_BUF_SIZE) {
			*buf_size = MAX_BUF_SIZE;
		}
		buf = realloc(buf, *buf_size);
	}
	return buf;
}

// Function to read integer input from scanner
int getInt() {
	int i, e;
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	sscanf(buf, "%d", &i);
	return i;
}

// Function to read string input from scanner
char *getString() {
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	return buf;
}

// Function to calculate absolute value of a number
int abs(int num) {
	return (int)fabs(num);
}

// Function to calculate power of a number
int pow(int base, int exp) {
	return (int)pow(base, exp);
}

// Function to find minimum of given numbers
int min(int nums, ...) {
	int min = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find maximum of given numbers
int max(int nums, ...) {
	int max = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char **slice, char *str) {
	for (int i = 0; i < nums; i++) {
		if (strcmp(slice[i], str) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array
void printIntArray(int *array) {
	printf("%d", array);
}

// Function to calculate modulo of a number
int calcMod(int num) {
	return num % MOD;
}

// Function to read a single line of input as string
char *getString() {
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	return buf;
}

// Function to read a single line of input as integer
int getInt() {
	int i, e;
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	sscanf(buf, "%d", &i);
	return i;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	// Read input string from scanner
	char *s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(week[i], s) == 0) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		panic("Invalid day of the week");
	}

	// Calculate the difference between the index of the given day and the index of Sunday
	// and print the result
	printf("%d", 7 - index);
}

// Function to calculate absolute value of a number
int abs(int num) {
	return (int)fabs(num);
}

// Function to calculate power of a number
int pow(int base, int exp) {
	return (int)pow(base, exp);
}

// Function to find minimum of given numbers
int min(int nums, ...) {
	int min = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find maximum of given numbers
int max(int nums, ...) {
	int max = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char **slice, char *str) {
	for (int i = 0; i < nums; i++) {
		if (strcmp(slice[i], str) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array
void printIntArray(int *array) {
	printf("%d", array);
}

// Function to calculate modulo of a number
int calcMod(int num) {
	return num % MOD;
}

// Function to read a single line of input as string
char *getString() {
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	return buf;
}

// Function to read a single line of input as integer
int getInt() {
	int i, e;
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	sscanf(buf, "%d", &i);
	return i;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// Read input string from scanner
	char *s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(week[i], s) == 0) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		panic("Invalid day of the week");
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	printf("%d", 7 - index);
}

// Function to calculate absolute value of a number
int abs(int num) {
	return (int)fabs(num);
}

// Function to calculate power of a number
int pow(int base, int exp) {
	return (int)pow(base, exp);
}

// Function to find minimum of given numbers
int min(int nums, ...) {
	int min = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find maximum of given numbers
int max(int nums, ...) {
	int max = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char **slice, char *str) {
	for (int i = 0; i < nums; i++) {
		if (strcmp(slice[i], str) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array
void printIntArray(int *array) {
	printf("%d", array);
}

// Function to calculate modulo of a number
int calcMod(int num) {
	return num % MOD;
}

// Function to read a single line of input as string
char *getString() {
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	return buf;
}

// Function to read a single line of input as integer
int getInt() {
	int i, e;
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	sscanf(buf, "%d", &i);
	return i;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// Read input string from scanner
	char *s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(week[i], s) == 0) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		panic("Invalid day of the week");
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	printf("%d", 7 - index);
}

// Function to calculate absolute value of a number
int abs(int num) {
	return (int)fabs(num);
}

// Function to calculate power of a number
int pow(int base, int exp) {
	return (int)pow(base, exp);
}

// Function to find minimum of given numbers
int min(int nums, ...) {
	int min = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find maximum of given numbers
int max(int nums, ...) {
	int max = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char **slice, char *str) {
	for (int i = 0; i < nums; i++) {
		if (strcmp(slice[i], str) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an integer array
void printIntArray(int *array) {
	printf("%d", array);
}

// Function to calculate modulo of a number
int calcMod(int num) {
	return num % MOD;
}

// Function to read a single line of input as string
char *getString() {
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	return buf;
}

// Function to read a single line of input as integer
int getInt() {
	int i, e;
	char *buf = malloc(initial_buf_size);
	int buf_size = initial_buf_size;
	int buf_pos = 0;
	buf = scanner(buf, &buf_size, &buf_pos);
	sscanf(buf, "%d", &i);
	return i;
}

// Main function
int main() {
	// Initialize week array with 7 days of the week
	char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	// Read input string from scanner
	char *s = getString();

	// Find index of the given day in week array
	int index = -1;
	for (int i = 0; i < 7; i++) {
		if (strcmp(week[i], s) == 0) {
			index = i;
			break;
		}
	}

	// If the given day is not present in the week array, panic with error message
	if (index == -1) {
		panic("Invalid day of the week");
	}

	// Calculate the number of days between the given day and Sunday
	// and print the result
	printf("%d", 7 - index);
}

// Function to calculate absolute value of a number
int abs(int num) {
	return (int)fabs(num);
}

// Function to calculate power of a number
int pow(int base, int exp) {
	return (int)pow(base, exp);
}

// Function to find minimum of given numbers
int min(int nums, ...) {
	int min = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	return min;
}

// Function to find maximum of given numbers
int max(int nums, ...) {
	int max = nums[0];
	for (int i = 1; i < nums; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char **slice, char *str) {
	for (int i = 0; i < nums; i++) {
		if (strcmp(slice[i], str) =
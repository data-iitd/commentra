
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Pair struct to hold two values of any type
typedef struct {
	void *p1;
	void *p2;
} Pair;

// Constants for buffer sizes
const int initialBufSize = 1e4; // Initial buffer size for scanner
const int maxBufSize = 1e8; // Maximum buffer size for scanner

// Global variables for input and output
FILE *scanner; // Scanner for reading input
FILE *writer; // Writer for output

// Function to convert a number from base 10 to base N
char *TenToN(int number, int n) {
	char *s = (char *)malloc(sizeof(char) * 1000000); // String to hold the result
	int tmp = number; // Temporary variable to hold the current number
	while (1) {
		// Prepend the remainder of the division to the result string
		s = strcat(s, i2s(tmp % n));
		if (tmp < n) { // If the temporary number is less than the base, exit the loop
			break;
		}
		tmp /= n; // Divide the temporary number by the base
	}
	return s; // Return the converted string
}

// Function to write a string to the output
void write(char *s) {
	fprintf(writer, "%s", s);
}

// Function to flush the writer buffer to output
void print() {
	fflush(writer);
}

// Function to read a line of input
char *readLine() {
	char *s = (char *)malloc(sizeof(char) * 1000000); // String to hold the read line
	fscanf(scanner, "%s", s);
	return s; // Return the read line
}

// Function to read an integer from input
int readInt() {
	int read; // Integer to hold the read value
	fscanf(scanner, "%d", &read);
	return read; // Return the read integer
}

// Function to read a float from input
float readFloat() {
	float read; // Float to hold the read value
	fscanf(scanner, "%f", &read);
	return read; // Return the read float
}

// Function to read runes from input
char *readRunes() {
	char *s = (char *)malloc(sizeof(char) * 1000000); // String to hold the read runes
	fscanf(scanner, "%s", s);
	return s; // Return the slice of runes
}

// Function to read a string from input
char *readString() {
	char *s = (char *)malloc(sizeof(char) * 1000000); // String to hold the read string
	fscanf(scanner, "%s", s);
	return s; // Return the read string
}

// Function to read a slice of strings from input
char **readStrings() {
	char **s = (char **)malloc(sizeof(char *) * 1000000); // Slice of strings to hold the read strings
	fscanf(scanner, "%s", s);
	return s; // Return the slice of strings
}

// Function to convert a string to an integer
int s2i(char *s) {
	int intVal; // Integer to hold the converted value
	intVal = atoi(s); // Convert the string to an integer
	return intVal; // Return the converted value
}

// Function to convert an integer to a string
char *i2s(int i) {
	char *strVal = (char *)malloc(sizeof(char) * 1000000); // String to hold the converted value
	strVal = itoa(i, strVal, 10); // Convert the integer to a string
	return strVal; // Return the converted value
}

// Function to convert a string to a float
float s2f(char *s) {
	float floatVal; // Float to hold the converted value
	floatVal = atof(s); // Convert the string to a float
	return floatVal; // Return the converted value
}

// Function to calculate the sum of a slice of integers
int sum(int *i) {
	int sum = 0; // Initialize sum
	for (int j = 0; j < sizeof(i); j++) {
		sum += i[j]; // Add each value to the sum
	}
	return sum; // Return the total sum
}

// Function to split a string into a slice of strings
char **split(char *s) {
	char **strs = (char **)malloc(sizeof(char *) * 1000000); // Slice of strings to hold the split string
	strs = strtok(s, " "); // Split the string by whitespace and return the slice
	return strs; // Return the slice of strings
}

// Function to convert a slice of strings to a slice of integers
int *strAry2intAry(char **strs) {
	int *ret = (int *)malloc(sizeof(int) * 1000000); // Initialize the result slice
	for (int i = 0; i < sizeof(strs); i++) {
		int intVal; // Integer to hold the converted value
		intVal = atoi(strs[i]); // Convert each string to an integer
		ret[i] = intVal; // Append the integer to the result slice
	}
	return ret; // Return the slice of integers
}

// Function to convert a slice of integers to a slice of strings
char **intAry2strAry(int *nums) {
	char **ret = (char **)malloc(sizeof(char *) * 1000000); // Initialize the result slice
	for (int i = 0; i < sizeof(nums); i++) {
		char *strVal = (char *)malloc(sizeof(char) * 1000000); // String to hold the converted value
		strVal = itoa(nums[i], strVal, 10); // Convert each integer to a string
		ret[i] = strVal; // Append the string to the result slice
	}
	return ret; // Return the slice of strings
}

// Function to join a slice of strings into a single string
char *ary2str(char **strs) {
	char *ret = (char *)malloc(sizeof(char) * 1000000); // Initialize the result string
	for (int i = 0; i < sizeof(strs); i++) {
		ret = strcat(ret, strs[i]); // Join the strings with a space and return
	}
	return ret; // Return the joined string
}

// Function to reverse a slice of integers
int *reverse(int *res) {
	for (int i = 0, j = sizeof(res) - 1; i < j; i++, j--) {
		res[i] = res[j]; // Swap elements to reverse the slice
	}
	return res; // Return the reversed slice
}

// Function to initialize a slice with a given value
void initalize(int *res, int init) {
	if (sizeof(res) == 0) {
		return; // Do nothing if the slice is empty
	}
	res[0] = init; // Set the first element to the initial value
	for (int i = 0; i < sizeof(res); i++) {
		memcpy(res[i], res[i - 1], sizeof(res[i])); // Copy elements to shift them
	}
}

// Example function for regular expressions (commented out)
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     regcomp(&r, "(\\d+):(\\d+)", 0);
//     regmatch_t pmatch[3];
//     regexec(&r, str, 3, pmatch, 0);
//     printf("%s\n", str + pmatch[1].rm_so);
// }

// Struct to hold medal counts for a country (commented out)
// typedef struct {
//     int gold;
//     int silver;
//     int blonze;
// } Country;

// // Example function for stable sorting (commented out)
// Country *stableSortExample() {
//     Country *country = (Country *)malloc(sizeof(Country) * 1000000); // Slice of countries to hold the medal counts
//     country[0].gold = 1;
//     country[0].silver = 2;
//     country[0].blonze = 3;
//     country[1].gold = 1;
//     country[1].silver = 2;
//     country[1].blonze = 3;
//     country[2].gold = 1;
//     country[2].silver = 3;
//     country[2].blonze = 2;
//     country[3].gold = 1;
//     country[3].silver = 3;
//     country[3].blonze = 3;
//     qsort(country, sizeof(country), sizeof(country[0]), compare);
//     qsort(country, sizeof(country), sizeof(country[0]), compare);
//     qsort(country, sizeof(country), sizeof(country[0]), compare);
//     return country;
// }

// Function to compare two countries by blonze medals
int compare(const void *a, const void *b) {
	Country *countryA = (Country *)a;
	Country *countryB = (Country *)b;
	return countryA->blonze - countryB->blonze;
}

int main() {
	// Allocate buffer for scanner and set its maximum size
	char *buf = (char *)malloc(sizeof(char) * 1000000);
	scanner = fopen("input.txt", "r");
	writer = fopen("output.txt", "w");

	// Read two integers N and K from input
	int N, K;
	N = readInt();
	K = readInt();
	// Convert the number N from base 10 to base K
	char *s = TenToN(N, K);
	// Print the length of the resulting string
	fprintf(writer, "%d\n", strlen(s));

	// Free memory
	free(buf);
	free(s);
	fclose(scanner);
	fclose(writer);
	return 0;
}


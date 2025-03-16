


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a number from base 10 to base N
char* TenToN(int number, int n) {
	char* s = (char*)malloc(sizeof(char) * 100); // String to hold the result
	int tmp = number; // Temporary variable to hold the current number
	for (int i = 0; ; i++) {
		// Prepend the remainder of the division to the result string
		s[i] = (tmp % n) + '0';
		if (tmp < n) { // If the temporary number is less than the base, exit the loop
			break;
		}
		tmp /= n; // Divide the temporary number by the base
	}
	return s; // Return the converted string
}

// Function to read a line of input
char* readLine() {
	char* s = (char*)malloc(sizeof(char) * 100); // String to hold the input
	scanf("%s", s); // Read the next input
	return s; // Return the read line
}

// Function to read an integer from input
int readInt() {
	int read;
	scanf("%d", &read); // Read the next input
	return read; // Return the read integer
}

// Function to read a float from input
float readFloat() {
	float read;
	scanf("%f", &read); // Read the next input
	return read; // Return the read float
}

// Function to read runes from input
char* readRunes() {
	char* read = (char*)malloc(sizeof(char) * 100); // String to hold the input
	scanf("%s", read); // Read the next input
	return read; // Return the read string
}

// Function to read a string from input
char* readString() {
	char* read = (char*)malloc(sizeof(char) * 100); // String to hold the input
	scanf("%s", read); // Read the next input
	return read; // Return the read string
}

// Function to read a slice of strings from input
char** readStrings() {
	char** read = (char**)malloc(sizeof(char*) * 100); // String to hold the input
	int i = 0;
	char* s = (char*)malloc(sizeof(char) * 100); // String to hold the input
	scanf("%s", s); // Read the next input
	while (s[0]!= '\0') {
		read[i] = (char*)malloc(sizeof(char) * 100); // String to hold the input
		strcpy(read[i], s); // Copy the string to the slice
		i++;
		scanf("%s", s); // Read the next input
	}
	return read; // Return the slice of strings
}

// Function to convert a string to an integer
int s2i(char* s) {
	int intVal, e = atoi(s); // Convert string to integer
	if (e!= 0) {
		printf("Error in conversion\n");
		exit(1); // Exit if there is an error in conversion
	}
	return intVal; // Return the integer value
}

// Function to convert an integer to a string
char* i2s(int i) {
	char* strVal = (char*)malloc(sizeof(char) * 100); // String to hold the integer value
	sprintf(strVal, "%d", i); // Convert integer to string
	return strVal; // Return the string value
}

// Function to convert a string to a float
float s2f(char* s) {
	float floatVal, e = atof(s); // Convert string to float
	if (e!= 0) {
		printf("Error in conversion\n");
		exit(1); // Exit if there is an error in conversion
	}
	return floatVal; // Return the float value
}

// Function to calculate the sum of a slice of integers
int sum(int* i, int n) {
	int sum = 0; // Initialize sum
	for (int j = 0; j < n; j++) {
		sum += i[j]; // Add each value to the sum
	}
	return sum; // Return the total sum
}

// Function to split a string into a slice of strings
char** split(char* s) {
	char** ret = (char**)malloc(sizeof(char*) * 100); // Initialize the result slice
	int i = 0;
	char* token = strtok(s, " "); // Split the string by whitespace
	while (token!= NULL) {
		ret[i] = (char*)malloc(sizeof(char) * 100); // String to hold the token
		strcpy(ret[i], token); // Copy the token to the slice
		i++;
		token = strtok(NULL, " "); // Split the string by whitespace
	}
	return ret; // Return the slice of strings
}

// Function to convert a slice of strings to a slice of integers
int* strAry2intAry(char** strs, int n) {
	int* ret = (int*)malloc(sizeof(int) * n); // Initialize the result slice
	for (int i = 0; i < n; i++) {
		ret[i] = atoi(strs[i]); // Convert each string to an integer
	}
	return ret; // Return the slice of integers
}

// Function to convert a slice of integers to a slice of strings
char** intAry2strAry(int* nums, int n) {
	char** ret = (char**)malloc(sizeof(char*) * n); // Initialize the result slice
	for (int i = 0; i < n; i++) {
		ret[i] = (char*)malloc(sizeof(char) * 100); // String to hold the integer value
		sprintf(ret[i], "%d", nums[i]); // Convert integer to string
	}
	return ret; // Return the slice of strings
}

// Function to join a slice of strings into a single string
char* ary2str(char** strs, int n) {
	char* ret = (char*)malloc(sizeof(char) * 100); // String to hold the result
	int i = 0;
	for (int j = 0; j < n; j++) {
		ret[i] = strs[j][0]; // Copy the first character of each string to the result
		i++;
	}
	return ret; // Return the result string
}

// Function to reverse a slice of integers
int* reverse(int* res, int n) {
	for (int i = 0; i < n/2; i++) {
		int tmp = res[i]; // Temporary variable to hold the current element
		res[i] = res[n-i-1]; // Swap elements to reverse the slice
		res[n-i-1] = tmp;
	}
	return res; // Return the reversed slice
}

// Function to initialize a slice with a given value
void initalize(int* res, int n, int init) {
	if (n == 0) {
		return; // Do nothing if the slice is empty
	}
	res[0] = init; // Set the first element to the initial value
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			res[i] = res[j]; // Copy elements to shift them
		}
	}
}

// Example function for regular expressions (commented out)
// void regexpExample() {
//     // Your code here!
//     char* str = "13:20";
//     char* r = (char*)malloc(sizeof(char) * 100);
//     strcpy(r, "(\d+):(\d+)");
//     char* submatch = (char*)malloc(sizeof(char) * 100);
//     strcpy(submatch, r);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", submatch);
//     printf("%s\n", r);
//     printf("%s\n", str);
//     printf("%s\n", s
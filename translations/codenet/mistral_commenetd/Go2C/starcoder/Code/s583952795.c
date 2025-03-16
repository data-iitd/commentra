#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a number to its base-10 string representation
// with digit count K
char* TenToN(int number, int n) {
	char* s = (char*)malloc(sizeof(char) * 1000);
	int tmp = number; // Initialize temporary variable

	// Repeat the following process until the number becomes less than N
	while (1) {
		// Append the remainder of the division by N to the result string
		s = strcat(s, i2s(tmp%n));

		// If the number is less than N, break the loop
		if (tmp < n) {
			break;
		}

		// Divide the number by N
		tmp /= n;
	}

	// Return the result string
	return s;
}

// Helper functions

// Write a string to the output writer
void write(char* s) {
	printf("%s", s);
}

// Print the content of the output writer
void print() {
	printf("\n");
}

// Read a line from the input scanner
char* readLine() {
	char* s = (char*)malloc(sizeof(char) * 1000);
	scanf("%s", s);
	return s;
}

// Read an integer from the input scanner
int readInt() {
	int read;
	scanf("%d", &read);
	return read;
}

// Read a float from the input scanner
float readFloat() {
	float read;
	scanf("%f", &read);
	return read;
}

// Read runes from the input scanner
char* readRunes() {
	char* read = (char*)malloc(sizeof(char) * 1000);
	scanf("%s", read);
	return read;
}

// Read a string from the input scanner
char* readString() {
	char* read = (char*)malloc(sizeof(char) * 1000);
	scanf("%s", read);
	return read;
}

// Read multiple strings from the input scanner
char** readStrings() {
	char** read = (char**)malloc(sizeof(char*) * 1000);
	int i = 0;
	char* s = (char*)malloc(sizeof(char) * 1000);
	while (scanf("%s", s)!= EOF) {
		read[i] = (char*)malloc(sizeof(char) * 1000);
		strcpy(read[i], s);
		i++;
	}
	return read;
}

// Convert an integer to its string representation
char* s2i(char* s) {
	char* intVal = (char*)malloc(sizeof(char) * 1000);
	int e = atoi(s);
	if (e!= NULL) {
		printf("Error: %d\n", e);
	}
	return intVal;
}

// Convert a string to an integer
char* i2s(int i) {
	char* strVal = (char*)malloc(sizeof(char) * 1000);
	sprintf(strVal, "%d", i);
	return strVal;
}

// Sum all integers in an integer slice
int sum(int* i, int len) {
	int sum = 0;
	for (int j = 0; j < len; j++) {
		sum += i[j];
	}
	return sum;
}

// Split a string by a delimiter
char** split(char* s) {
	char** ret = (char**)malloc(sizeof(char*) * 1000);
	int i = 0;
	char* token = (char*)malloc(sizeof(char) * 1000);
	while (1) {
		token = strsep(&s, " ");
		if (token == NULL) {
			break;
		}
		ret[i] = (char*)malloc(sizeof(char) * 1000);
		strcpy(ret[i], token);
		i++;
	}
	return ret;
}

// Convert a string array to an integer array
int* strAry2intAry(char** strs, int len) {
	int* ret = (int*)malloc(sizeof(int) * 1000);
	for (int i = 0; i < len; i++) {
		int e = atoi(strs[i]);
		if (e!= NULL) {
			printf("Error: %d\n", e);
		}
		ret[i] = e;
	}
	return ret;
}

// Convert an integer array to a string array
char** intAry2strAry(int* nums, int len) {
	char** ret = (char**)malloc(sizeof(char*) * 1000);
	for (int i = 0; i < len; i++) {
		char* strVal = (char*)malloc(sizeof(char) * 1000);
		sprintf(strVal, "%d", nums[i]);
		ret[i] = strVal;
	}
	return ret;
}

// Join multiple strings into a single string with a delimiter
char* ary2str(char** strs, int len) {
	char* ret = (char*)malloc(sizeof(char) * 1000);
	int i = 0;
	for (int j = 0; j < len; j++) {
		ret = strcat(ret, strs[j]);
		if (j < len-1) {
			ret = strcat(ret, " ");
		}
	}
	return ret;
}

// Reverse the order of elements in an integer slice
int* reverse(int* res, int len) {
	for (int i = 0; i < len/2; i++) {
		int tmp = res[i];
		res[i] = res[len-i-1];
		res[len-i-1] = tmp;
	}
	return res;
}

// Initialize an integer slice with a given value
int* initalize(int* res, int len, int init) {
	if (len == 0) {
		return res;
	}
	res[0] = init;
	for (int i = 0; i < len; i++) {
		memcpy(res+i, res, i);
	}
	return res;
}

// Unused function, remove it
// char* regexpExample() {
// 	// Your code here!
// 	char* str = "13:20";
// 	char* r = (char*)malloc(sizeof(char) * 1000);
// 	sprintf(r, "%d:%d", 13, 20);
// 	return r;
// }


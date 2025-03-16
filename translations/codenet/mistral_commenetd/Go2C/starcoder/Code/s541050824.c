#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read input from stdin
void readInput(char *input) {
	fgets(input, 1000, stdin);
}

// Function to write output to stdout
void writeOutput(char *output) {
	printf("%s", output);
}

// Function to convert string to integer
int stringToInt(char *input) {
	return atoi(input);
}

// Function to convert integer to string
char *intToString(int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to float
float stringToFloat(char *input) {
	return atof(input);
}

// Function to convert float to string
char *floatToString(float input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%f", input);
	return output;
}

// Function to convert string to double
double stringToDouble(char *input) {
	return atof(input);
}

// Function to convert double to string
char *doubleToString(double input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lf", input);
	return output;
}

// Function to convert string to long
long stringToLong(char *input) {
	return atol(input);
}

// Function to convert long to string
char *longToString(long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%ld", input);
	return output;
}

// Function to convert string to long long
long long stringToLongLong(char *input) {
	return atoll(input);
}

// Function to convert long long to string
char *longLongToString(long long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lld", input);
	return output;
}

// Function to convert string to unsigned integer
unsigned int stringToUnsignedInt(char *input) {
	return atoi(input);
}

// Function to convert unsigned integer to string
char *unsignedIntToString(unsigned int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to unsigned long
unsigned long stringToUnsignedLong(char *input) {
	return atol(input);
}

// Function to convert unsigned long to string
char *unsignedLongToString(unsigned long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lu", input);
	return output;
}

// Function to convert string to unsigned long long
unsigned long long stringToUnsignedLongLong(char *input) {
	return atoll(input);
}

// Function to convert unsigned long long to string
char *unsignedLongLongToString(unsigned long long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%llu", input);
	return output;
}

// Function to convert string to unsigned char
unsigned char stringToUnsignedChar(char *input) {
	return atoi(input);
}

// Function to convert unsigned char to string
char *unsignedCharToString(unsigned char input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to signed char
signed char stringToSignedChar(char *input) {
	return atoi(input);
}

// Function to convert signed char to string
char *signedCharToString(signed char input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to short
short stringToShort(char *input) {
	return atoi(input);
}

// Function to convert short to string
char *shortToString(short input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to unsigned short
unsigned short stringToUnsignedShort(char *input) {
	return atoi(input);
}

// Function to convert unsigned short to string
char *unsignedShortToString(unsigned short input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to long double
long double stringToLongDouble(char *input) {
	return atof(input);
}

// Function to convert long double to string
char *longDoubleToString(long double input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%Lf", input);
	return output;
}

// Function to convert string to long long int
long long int stringToLongLongInt(char *input) {
	return atoll(input);
}

// Function to convert long long int to string
char *longLongIntToString(long long int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lld", input);
	return output;
}

// Function to convert string to unsigned long long int
unsigned long long int stringToUnsignedLongLongInt(char *input) {
	return atoll(input);
}

// Function to convert unsigned long long int to string
char *unsignedLongLongIntToString(unsigned long long int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%llu", input);
	return output;
}

// Function to convert string to long int
long int stringToLongInt(char *input) {
	return atol(input);
}

// Function to convert long int to string
char *longIntToString(long int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%ld", input);
	return output;
}

// Function to convert string to unsigned long int
unsigned long int stringToUnsignedLongInt(char *input) {
	return atol(input);
}

// Function to convert unsigned long int to string
char *unsignedLongIntToString(unsigned long int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lu", input);
	return output;
}

// Function to convert string to unsigned short int
unsigned short int stringToUnsignedShortInt(char *input) {
	return atoi(input);
}

// Function to convert unsigned short int to string
char *unsignedShortIntToString(unsigned short int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to short int
short int stringToShortInt(char *input) {
	return atoi(input);
}

// Function to convert short int to string
char *shortIntToString(short int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to unsigned int
unsigned int stringToUnsignedInt(char *input) {
	return atoi(input);
}

// Function to convert unsigned int to string
char *unsignedIntToString(unsigned int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to int
int stringToInt(char *input) {
	return atoi(input);
}

// Function to convert int to string
char *intToString(int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to float
float stringToFloat(char *input) {
	return atof(input);
}

// Function to convert float to string
char *floatToString(float input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%f", input);
	return output;
}

// Function to convert string to double
double stringToDouble(char *input) {
	return atof(input);
}

// Function to convert double to string
char *doubleToString(double input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lf", input);
	return output;
}

// Function to convert string to long
long stringToLong(char *input) {
	return atol(input);
}

// Function to convert long to string
char *longToString(long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%ld", input);
	return output;
}

// Function to convert string to long long
long long stringToLongLong(char *input) {
	return atoll(input);
}

// Function to convert long long to string
char *longLongToString(long long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lld", input);
	return output;
}

// Function to convert string to unsigned long long
unsigned long long stringToUnsignedLongLong(char *input) {
	return atoll(input);
}

// Function to convert unsigned long long to string
char *unsignedLongLongToString(unsigned long long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%llu", input);
	return output;
}

// Function to convert string to unsigned long
unsigned long stringToUnsignedLong(char *input) {
	return atol(input);
}

// Function to convert unsigned long to string
char *unsignedLongToString(unsigned long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lu", input);
	return output;
}

// Function to convert string to unsigned int
unsigned int stringToUnsignedInt(char *input) {
	return atoi(input);
}

// Function to convert unsigned int to string
char *unsignedIntToString(unsigned int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%u", input);
	return output;
}

// Function to convert string to int
int stringToInt(char *input) {
	return atoi(input);
}

// Function to convert int to string
char *intToString(int input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%d", input);
	return output;
}

// Function to convert string to float
float stringToFloat(char *input) {
	return atof(input);
}

// Function to convert float to string
char *floatToString(float input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%f", input);
	return output;
}

// Function to convert string to double
double stringToDouble(char *input) {
	return atof(input);
}

// Function to convert double to string
char *doubleToString(double input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lf", input);
	return output;
}

// Function to convert string to long
long stringToLong(char *input) {
	return atol(input);
}

// Function to convert long to string
char *longToString(long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%ld", input);
	return output;
}

// Function to convert string to long long
long long stringToLongLong(char *input) {
	return atoll(input);
}

// Function to convert long long to string
char *longLongToString(long long input) {
	char *output = malloc(1000 * sizeof(char));
	sprintf(output, "%lld", input);
	return output;
}

// Functio
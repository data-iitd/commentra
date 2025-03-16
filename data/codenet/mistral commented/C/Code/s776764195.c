#include <stdio.h>

#define PutChar(c) ; *p = (char)(c); ++p; // Macro to write a character to the output string

#define MAX_N (2000001) // Maximum number of integers to be read
#define MAX_Ai (10001)   // Maximum value of an integer
#define STR_SIZE (10000010) // Size of the input string

int getNum(); // Function to read an integer from the input string
void putNum(int n); // Function to write an integer to the output string
void CountingSort(int A[], int B[], int k, int len); // Function to perform counting sort

int A[MAX_N]; // Array to store the input integers
int B[MAX_N]; // Array to store the sorted integers
char str[STR_SIZE]; // Buffer to store the input string
char *p = str; // Pointer to the current position in the string

int main(void) {
    register int i; // Declare a register variable for the loop counter
    int n; // Variable to store the number of integers to be read
}
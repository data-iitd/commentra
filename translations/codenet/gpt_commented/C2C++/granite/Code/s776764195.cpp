
#include <iostream>
#include <cstring>

// Macro to put a character into the output string and increment the pointer
#define PutChar(c) ; *p = (char)(c); ++p;

// Define constants for maximum sizes
#define MAX_N (2000001) // Maximum number of elements
#define MAX_Ai (10001)  // Maximum value of elements
#define STR_SIZE (10000010) // Size of the output string

// Function prototypes
int getNum(void); // Function to read an integer from the input string
void putNum(int n); // Function to write an integer to the output string
void CountingSort(int A[], int B[], int k, int len); // Counting sort algorithm

// Global arrays for input and output
int A[MAX_N]; // Array to hold input numbers
int B[MAX_N]; // Array to hold sorted numbers
char str[STR_SIZE]; // Buffer for output string
char *p = str; // Pointer to the current position in the output string

int main(void) {
    register int i; // Loop variable
    int n; // Number of elements to sort

    // Read the entire input into the string
    std::cin.getline(str, STR_SIZE);
      
    // Get the number of elements from the input
    n = getNum();
    // Read each number into the array A
    for (i = 1; i <= n; ++i) {
        A[i] = getNum();
    }
      
    // Perform counting sort on the array A and store the result in B
    CountingSort(A, B, MAX_Ai, n);
      
    // Reset the pointer to the start of the output string
    p = str;
    --n; // Adjust n for zero-based indexing
    // Write the sorted numbers to the output string
    for (i = 1; i <= n; ++i) {
        putNum(B[i]); // Convert number to string and append
        PutChar(' '); // Append a space after each number
    }
    putNum(B[i]); // Append the last number without a trailing space
    PutChar('\0'); // Null-terminate the output string
      
    // Output the final result
    std::cout << str << std::endl;
      
    return 0; // Return success
}

// Function to read an integer from the input string
int getNum(void) {
    int n = 0; // Variable to store the number
    // Read digits until a non-digit character is encountered
    while ((*p >= '0') && (*p <= '9')) {
        n = n * 10 + (int)(*p - '0'); // Build the number
        ++p; // Move to the next character
    }
    ++p; // Skip the non-digit character (likely a space or newline)
    return n; // Return the read number
}

// Function to write an integer to the output string
void putNum(int n) {
    int d; // Variable for division
    // Handle single-digit numbers directly
    if (n < 10) {
        PutChar('0' + n); // Convert to character and append
        return;
    }
    // Recursively write the digits of the number
    d = n / 10; // Get the quotient
    if (d) putNum(d); // Recursively call for the quotient
    PutChar('0' + (n - (d * 10))); // Append the last digit
}

// Counting sort algorithm implementation
void CountingSort(int A[], int B[], int k, int len) {
    int C[MAX_Ai] = { 0 }; // Count array initialized to zero
    int i, j;
    // Count occurrences of each number in A
    for (j = 1; j <= len; ++j) {
        ++C[A[j]]; // Increment count for each number
    }
    // Update count array to hold the position of each number
    for (i = 1; i <= k; ++i) {
        C[i] += C[i - 1]; // C[i] now contains the position
    }
    // Build the output array B using the count array
    for (j = len; j > 0; --j) {
        B[C[A[j]]] = A[j]; // Place the number in the correct position
        --C[A[j]]; // Decrement the count for the number
    }
}


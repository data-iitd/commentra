#include <iostream>
#include <cstdio>
#include <vector>

#define MAX_N 2000001
#define MAX_Ai 10001
#define STR_SIZE 10000010

int getNum();
void putNum(int n);
void CountingSort(int A[], int B[], int k, int len);

int A[MAX_N]; // Input array
int B[MAX_N]; // Output array
char str[STR_SIZE]; // Buffer to read input
char *p = str; // Pointer to traverse the buffer

int main() {
    int n;

    std::fread(str, 1, STR_SIZE, stdin); // Read input into the buffer

    n = getNum(); // Get the number of elements
    for (int i = 1; i <= n; ++i) {
        A[i] = getNum(); // Read each element into the array A
    }

    CountingSort(A, B, MAX_Ai, n); // Sort the array A using Counting Sort

    p = str; // Reset the pointer to the start of the buffer
    --n; // Decrement n to exclude the last element from the output
    for (int i = 1; i <= n; ++i) {
        putNum(B[i]); // Write each sorted element
        *p = ' '; // Write a space between elements
        ++p;
    }
    putNum(B[n + 1]); // Write the last element without a space
    *p = '\0'; // Null-terminate the string

    std::puts(str); // Output the sorted string

    return 0;
}

int getNum() {
    int n = 0;
    while ((*p >= '0') && (*p <= '9')) {
        n = n * 10 + (int)(*p - '0'); // Convert character to integer
        ++p;
    }
    ++p; // Move past the space or newline
    return n;
}

void putNum(int n) {
    int d;
    if (n < 10) {
        *p = '0' + n; // Write single digit number
        ++p;
        return;
    }
    d = n / 10;
    if (d) putNum(d); // Recursively write higher digits
    *p = '0' + (n - (d * 10)); // Write the last digit
    ++p;
}

void CountingSort(int A[], int B[], int k, int len) {
    int C[MAX_Ai] = { 0 }; // Initialize count array

    for (int j = 1; j <= len; ++j) {
        ++C[A[j]]; // Count occurrences of each element
    }
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1]; // Calculate cumulative count
    }
    for (int j = len; j > 0; --j) {
        B[C[A[j]]] = A[j]; // Place elements in sorted order
        --C[A[j]]; // Decrement count for the element
    }
}


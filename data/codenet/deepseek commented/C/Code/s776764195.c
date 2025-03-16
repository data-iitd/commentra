#include <stdio.h>
  
#define PutChar(c) ; *p = (char)(c); ++p;
  
#define MAX_N (2000001)
#define MAX_Ai (10001)
#define STR_SIZE (10000010)
  
int getNum(void);
void putNum(int n);
void CountingSort(int A[], int B[], int k, int len);
  
int A[MAX_N]; // Input array
int B[MAX_N]; // Output array
char str[STR_SIZE]; // Buffer to read input
char *p = str; // Pointer to traverse the buffer
  
int main(void) {
    register int i;
    int n;
  
    fread(str, 1, STR_SIZE, stdin); // Read input into the buffer
      
    n = getNum(); // Get the number of elements
    for (i = 1; i <= n; ++i) {
        A[i] = getNum(); // Read each element into the array A
    }
      
    CountingSort(A, B, MAX_Ai, n); // Sort the array A using Counting Sort
      
    p = str; // Reset the pointer to the start of the buffer
    --n; // Decrement n to exclude the last element from the output
    for (i = 1; i <= n; ++i) {
        putNum(B[i]); // Write each sorted element
        PutChar(' '); // Write a space between elements
    }
    putNum(B[i]); // Write the last element without a space
    PutChar('\0'); // Null-terminate the string
      
    puts(str); // Output the sorted string
      
    return 0;
}
  
int getNum(void) {
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
        PutChar('0' + n); // Write single digit number
        return;
    }
    d = n / 10;
    if (d) putNum(d); // Recursively write higher digits
    PutChar('0' + (n - (d * 10))); // Write the last digit
}
  
void CountingSort(int A[], int B[], int k, int len) {
    int C[MAX_Ai] = { 0 }; // Initialize count array
    int i, j;
    for (j = 1; j <= len; ++j) {
        ++C[A[j]]; // Count occurrences of each element
    }
    for (i = 1; i <= k; ++i) {
        C[i] += C[i - 1]; // Calculate cumulative count
    }
    for (j = len; j > 0; --j) {
        B[C[A[j]]] = A[j]; // Place elements in sorted order
        --C[A[j]]; // Decrement count for the element
    }
}

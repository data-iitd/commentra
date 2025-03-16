#include <iostream>
#include <cstring>
#include <cstdio>
  
using namespace std;
  
int getNum(void);
void putNum(int n);
void CountingSort(int A[], int B[], int k, int len);
  
int A[2000001]; // Input array
int B[2000001]; // Output array
char str[10000010]; // Buffer to read input
char *p = str; // Pointer to traverse the buffer
  
int main(void) {
    register int i;
    int n;
  
    fread(str, 1, 10000010, stdin); // Read input into the buffer
      
    n = getNum(); // Get the number of elements
    for (i = 1; i <= n; ++i) {
        A[i] = getNum(); // Read each element into the array A
    }
      
    CountingSort(A, B, 10001, n); // Sort the array A using Counting Sort
      
    p = str; // Reset the pointer to the start of the buffer
    --n; // Decrement n to exclude the last element from the output
    for (i = 1; i <= n; ++i) {
        putNum(B[i]); // Write each sorted element
        cout << ' '; // Write a space between elements
    }
    putNum(B[i]); // Write the last element without a space
    cout << endl; // Newline
      
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
        cout << '0' + n; // Write single digit number
        return;
    }
    d = n / 10;
    if (d) putNum(d); // Recursively write higher digits
    cout << '0' + (n - (d * 10)); // Write the last digit
}
  
void CountingSort(int A[], int B[], int k, int len) {
    int C[10001] = { 0 }; // Initialize count array
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


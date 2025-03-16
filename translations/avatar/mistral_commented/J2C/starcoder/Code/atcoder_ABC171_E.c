
#include <stdio.h>
#include <stdlib.h>

int main() {
// Initializing the Scanner object to read input from the console
int n;
scanf("%d", &n);

// Creating an integer array 'a' of size 'n' to store the input elements
int a[n];

// Initializing the XOR result to 0
int r = 0;

// Reading the elements of the array 'a' from the user input and performing XOR operation
for (int i = 0; i < n; i++) {
// Reading the next integer from the user input
scanf("%d", &a[i]);

// Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
r ^= a[i];
}

// Printing the XOR result
for (int i = 0; i < n; i++) {
// If it's not the first element, print a space before the current element
if (i!= 0)
printf(" ");

// Printing the XOR result of 'r' and the current element 'a[i]'
printf("%d", r ^ a[i]);
}

// Printing the end of code marker
printf("
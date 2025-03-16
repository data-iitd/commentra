

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
 long startTime = clock(); // Start time measurement
 int n; // Number of elements in the array A
 scanf("%d", &n); // Reading the number of elements in the array A
 long div = pow(10, 9) + 7; // Modulus constant for efficient modular arithmetic
 long A[n]; // Array of long type with size n
 long ans = 0; // Answer variable initialized to zero

 // Reading the elements of the array A
 for (int i = 0; i < n; i++) {
 scanf("%ld", &A[i]); // Reading an element of the array A
 }

 // Calculating the answer using the given formula
 for (int i = 0; i < 60; i++) { // Looping through all the bits from 0 to 59
 long a = 0; // Variable a initialized to zero
 long count1 = 0; // Variable count1 initialized to zero

 // Counting the number of elements in the array A with the i-th bit set to 1
 for (int j = 0; j < n; j++) {
 if ((A[j] >> i & 1) == 1) // Checking if the i-th bit is set in the j-th element of the array A
 count1++; // Incrementing the count1 variable
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1 * (n - count1); // a = a + (count1 \* (n - count1))

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for (int j = 0; j < i; j++) {
 a = (a << 1) % div; // a = (a << 1) % div
 }

 // Adding the contribution to the answer
 ans += a; // ans += a
 ans %= div; // ans %= div
 }

 // Printing the answer
 printf("%ld\n", ans); // Printing the answer
 long endTime = clock(); // End time measurement
 printf("Time taken by the program is : %ld milliseconds\n", (endTime - startTime)); // Printing the time taken by the program to execute
 return 0;
}


#include <stdio.h>
#include <math.h>

#define MOD 1000000007

int main() {
 unsigned long long startTime = clock(); // Start time measurement
 int n;
 scanf("%d", &n); // Reading the number of elements in the array
 unsigned long long A[n]; // Creating an array of unsigned long long type with size n
 unsigned long long ans = 0; // Initializing the answer variable to zero

 // Reading the elements of the array A
 for (int i = 0; i < n; i++) {
 scanf("%llu", &A[i]); // Reading an element of the array A
 }

 // Calculating the answer using the given formula
 for (int i = 0; i < 60; i++) { // Looping through all the bits from 0 to 59
 unsigned long long a = 0; // Initializing the variable a to zero
 unsigned long long count1 = 0; // Initializing the variable count1 to zero

 // Counting the number of elements in the array A with the i-th bit set to 1
 for (int j = 0; j < n; j++) {
 if (A[j] & (1ULL << i)) // Checking if the i-th bit is set in the j-th element of the array A
 count1++; // Incrementing the count1 variable
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1 * (n - count1); // a = a + (count1 * (n - count1))

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for (int j = 0; j < i; j++) {
 a = (a << 1) % MOD; // a = (a << 1) % MOD
 }

 // Adding the contribution to the answer
 ans += a; // ans += a
 ans %= MOD; // ans %= MOD
 }

 // Printing the answer
 printf("%llu\n", ans); // Printing the answer
 unsigned long long endTime = clock(); // End time measurement
 printf("Time taken by the program is : %llu milliseconds\n", (endTime - startTime)); // Printing the time taken by the program to execute
 return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 int n; // Number of elements in the array 'a'
 int *a; // Array of integers
 int *s; // Sorted array to store the count of each element

 scanf("%d", &n); // Read the number of elements 'n' from the input

 a = (int*)malloc(n * sizeof(int)); // Allocate memory for the array 'a'
 s = (int*)malloc(n * sizeof(int)); // Allocate memory for the sorted array's'

 for (int i = 0; i < n; i++) {
 scanf("%d", &a[i]); // Read the elements of the array 'a' from the input
 }

 int ng = 0; // Initialize the lower bound of the search range
 int ok = n; // Initialize the upper bound of the search range

 while (ok - ng > 1) { // Run the while loop until the search range is narrowed down to a single element
 int k = (ng + ok) / 2; // Calculate the middle index of the search range
 if (isPossible(k, a, n, s)) { // If the middle index 'k' is a valid solution, update the upper bound
 ok = k;
 } else { // Otherwise, update the lower bound
 ng = k;
 }
 }

 printf("%d\n", ok); // Print the solution

 free(a); // Free the memory allocated for the array 'a'
 free(s); // Free the memory allocated for the sorted array's'

 return 0;
}

int isPossible(int k, int *a, int n, int *s) {
 memset(s, 0, n * sizeof(int)); // Clear the sorted array's' before processing the new condition
 int current = 0; // Initialize the current index in the array 'a'

 for (int i = 0; i < n; i++) { // Iterate through each element in the array 'a'
 if (a[i] <= current) { // If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
 if (k == 1) return false; // If 'k' is 1, return false as there is no possible solution

 int p = a[i] - 1; // Calculate the previous index 'p'
 while (true) { // Find the previous index 'p' with the count 'k' in the sorted array's'
 if (p < 0) return false; // If 'p' is out of the array bounds, return false

 int sp = s[p] + 1; // Get the count of 'p' in the sorted array's' or initialize it to 1
 s[p] = sp; // Update the count of 'p' in the sorted array's'

 if (sp == k) { // If the count of 'p' is equal to 'k', remove it and move to the previous index
 s[p] = 0;
 p--;
 } else { // Otherwise, break the loop
 break;
 }
 }
 }
 current = a[i]; // Update the current index
 }

 return true; // If all elements in the array 'a' are processed, return true as a valid solution is found
}

These comments should provide a clear understanding of the code logic and flow. Let me know if you need any further assistance.
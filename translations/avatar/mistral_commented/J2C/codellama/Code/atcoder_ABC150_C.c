
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find permutations of a given string
void permutation(char *target, char *ans, int *list, int *listSize) {
 if (strlen(target) <= 1) { // Base case: if the target string length is less than or equal to 1
 list[*listSize] = atoi(ans); // Add the current permutation to the list
 *listSize += 1; // Increment the list size
 } else {
 for (int i = 0; i < strlen(target); i++) { // Iterate through each character in the target string
 permutation(target + i + 1, ans + target[i], list, listSize); // Recursive call to find permutations of the remaining string
 }
 }
}

// Main function to read user input and find the sum of the permutations
int main() {
 int n; // Declare an integer variable to store the number of test cases

 // Read the number of test cases from the user
 scanf("%d", &n);

 char number[n + 1]; // Declare a character array to store the number string
 for (int i = 0; i < n; i++) { // Iterate through each test case and create the number string
 number[i] = '0' + i;
 }
 number[n] = '\0';

 int list[n]; // Declare an integer array to store the permutations
 int listSize = 0; // Declare an integer variable to store the size of the list
 permutation(number, "", list, &listSize); // Call the permutation function to find all permutations of the number string

 int sum = 0; // Declare an integer variable to store the sum of the indices of the matching permutations
 for (int j = 0; j < n; j++) { // Iterate through each line read from the user
 for (int i = 0; i < listSize; i++) { // Iterate through each permutation in the list
 if (list[i] == j) { // Check if the current permutation matches the current line
 if (sum == 0) { // If this is the first matching permutation
 sum += i; // Add the index of the matching permutation to the sum
 } else { // If there is already a matching permutation in the sum
 sum -= i; // Subtract the index of the previous matching permutation from the sum
 }
 }
 }
 }

 printf("%d\n", abs(sum)); // Print the absolute value of the sum

 return 0;
}


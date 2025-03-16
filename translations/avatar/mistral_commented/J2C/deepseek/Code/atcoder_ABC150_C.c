#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find permutations of a given string
void permutation(char **list, char *target, char *ans, int *index) {
 if (strlen(target) <= 1) { // Base case: if the target string length is less than or equal to 1
 list[*index] = (char *)malloc((strlen(ans) + strlen(target) + 1) * sizeof(char));
 strcpy(list[*index], ans);
 strcat(list[*index], target);
 (*index)++;
 } else {
 for (int i = 0; i < strlen(target); i++) { // Iterate through each character in the target string
 char *new_target = (char *)malloc((strlen(target) - 1) * sizeof(char));
 int k = 0;
 for (int j = 0; j < strlen(target); j++) {
 if (j != i) {
 new_target[k] = target[j];
 k++;
 }
 }
 new_target[k] = '\0';
 permutation(list, new_target, strcat(ans, target[i]), index); // Recursive call to find permutations of the remaining string
 free(new_target);
 }
 }
}

// Main function to read user input and find the sum of the permutations
int main() {
 int n; // Declare an integer variable to store the number of test cases
 printf("Enter the number of test cases: ");
 scanf("%d", &n);

 char number[10]; // Declare a character array to store the number string
 sprintf(number, "%d", n);
 for (int i = 1; i < n; i++) { // Iterate through each test case and create the number string
 char temp[10];
 sprintf(temp, "%d", i);
 strcat(number, temp);
 }

 char **listA = (char **)malloc(factorial(strlen(number)) * sizeof(char *)); // Declare a dynamic array to store the permutations
 int index = 0; // Initialize the index to 0
 permutation(listA, number, "", &index); // Call the permutation function to find all permutations of the number string

 char line[n][100]; // Declare a 2D character array to store the lines read from the user
 for (int i = 0; i < n; i++) {
 printf("Enter line %d: ", i+1);
 scanf("%s", line[i]);
 }

 int sum = 0; // Declare an integer variable to store the sum of the indices of the matching permutations
 for (int j = 0; j < n; j++) { // Iterate through each line read from the user
 for (int i = 0; i < index; i++) { // Iterate through each permutation in the list
 if (strcmp(listA[i], line[j]) == 0) { // Check if the current permutation matches the current line
 if (sum == 0) { // If this is the first matching permutation
 sum += i; // Add the index of the matching permutation to the sum
 } else { // If there is already a matching permutation in the sum
 sum -= i; // Subtract the index of the previous matching permutation from the sum
 }
 }
 }
 }

 printf("The sum of the indices of the matching permutations is: %d\n", abs(sum)); // Print the absolute value of the sum

 // Free the allocated memory
 for (int i = 0; i < index; i++) {
 free(listA[i]);
 }
 free(listA);

 return 0;
}


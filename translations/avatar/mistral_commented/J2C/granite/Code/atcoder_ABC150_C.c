

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find permutations of a given string
void permutation(char* str, int l, int r, char* ans, int* count) {
 if (l == r) { // Base case: if the left and right indices are equal
 printf("%s\n", ans); // Print the current permutation
 (*count)++; // Increment the count of permutations
 } else {
 for (int i = l; i <= r; i++) { // Iterate through each character in the string
 char temp = str[l]; // Swap the current character with the character at the left index
 str[l] = str[i];
 str[i] = temp;
 permutation(str, l + 1, r, ans, count); // Recursive call to find permutations of the remaining string
 temp = str[l]; // Swap the characters back to their original positions
 str[l] = str[i];
 str[i] = temp;
 }
 }
}

int main() {
 int n; // Declare an integer variable to store the number of test cases
 scanf("%d", &n); // Read the number of test cases from the user

 char number[100]; // Declare a character array to store the number string
 memset(number, 0, sizeof(number)); // Set all elements of the array to 0
 for (int i = 1; i <= n; i++) { // Iterate through each test case and create the number string
 strcat(number, &i);
 }

 char* line[100]; // Declare a 2D character array to store the lines read from the user
 int count = 0; // Declare an integer variable to store the count of matching permutations
 for (int i = 0; i < n; i++) { // Iterate through each line read from the user
 scanf("%s", line[i]);
 char ans[100]; // Declare a character array to store the current permutation
 memset(ans, 0, sizeof(ans)); // Set all elements of the array to 0
 permutation(number, 0, strlen(number) - 1, ans, &count); // Call the permutation function to find all permutations of the number string
 }

 printf("%d\n", abs(count)); // Print the absolute value of the count
 return 0;
}


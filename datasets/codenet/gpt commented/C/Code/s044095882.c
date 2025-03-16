#include <stdio.h>

int main(void)
{
  // Declare a variable to hold the size of the array
  long int n;

  // Read the size of the array from user input
  scanf("%ld", &n);
  
  // Declare two arrays: one to hold the input values and another to count occurrences
  long int a[n];
  long int count[n];

  // Read the input values into the array 'a', starting from index 1
  for (long int i = 1; i < n; i++)
    scanf("%ld", &a[i]);

  // Initialize the count array to zero for all indices
  for (long int i = 0; i < n; i++)
    count[i] = 0;

  // Count the occurrences of each value in the array 'a'
  // The value at a[i] is used to index into the count array
  for (long int i = 1; i < n; i++)
    count[a[i]-1]++;

  // Print the counts of each index in the count array
  for (long int i = 0; i < n; i++)
    printf("%ld\n", count[i]);

  // Return 0 to indicate successful completion of the program
  return 0;
}


#include <stdio.h>

int main(void) {
  long int n; // Declare a variable to store the number of elements in the array

  printf("Enter the number of elements: ");
  scanf("%ld", &n); // Read the number of elements from the standard input and store it in n

  long int a[n]; // Declare an array of size n to store the input numbers
  long int count[n]; // Declare an array of size n to store the count of occurrences of each number

  printf("Enter %ld numbers:\n", n);
  for (long int i = 0; i < n; i++) { // Initialize the array a with input numbers
    scanf("%ld", &a[i]);
  }

  printf("Initializing count array with zeros:\n");
  for (long int i = 0; i < n; i++) { // Initialize all elements of the count array to zero
    count[i] = 0;
  }

  printf("Counting occurrences:\n");
  for (long int i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
    count[a[i]-1]++;
  }

  printf("Printing the contents of the count array:\n");
  for (long int i = 0; i < n; i++) { // Print the contents of the count array to the standard output
    printf("%ld\n", count[i]);
  }

  printf("Program completed successfully.\n");
  return 0; // Return 0 to indicate successful termination
}


#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for memory allocation and deallocation
#include <stdbool.h> // Include the standard boolean library

int main() {
  int n; // Declare and initialize the number of elements in the list
  scanf("%d", &n); // Read the number of elements from the user input

  int *a = (int *)malloc(n * sizeof(int)); // Allocate memory for the list elements
  for (int i = 0; i < n; i++) { // Iterate through the input elements
    scanf("%d", &a[i]); // Read the next input value
  }

  bool found = false; // Declare and initialize the found flag
  for (int i = 0; i < n; i++) { // Iterate through the list elements
    if (i + 1 < n && i + 2 < n) { // Check if the next and next-next elements exist
      if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) { // Check if the difference is 1
        found = true; // Set the found flag if a sequence is found
        break; // Exit the loop if a sequence is found
      }
    }
  }

  // Write the output to the console
  printf("%s\n", found? "YES" : "NO");

  // Free the allocated memory for the list elements
  free(a);

  return 0; // Return 0 to indicate successful execution
}

Translate the above C code to Python and end with comment "
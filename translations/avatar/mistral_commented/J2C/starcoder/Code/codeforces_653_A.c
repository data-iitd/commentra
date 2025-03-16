
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// Define the main function
int main(int argc, char *argv[]) {
  // Declare a variable to store the number of elements in the list
  int n;

  // Read the number of elements in the list from the user input
  scanf("%d", &n);

  // Declare an array to store the unique and sorted list elements
  int a[n];

  // Read the list elements from the user input
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Sort the array using the bubble sort algorithm
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  // Check if there exists a sequence of three consecutive elements with a difference of 1
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (i + 1 < n && i + 2 < n) {
      if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
        found = true;
        break;
      }
    }
  }

  // Write the output to the console
  printf("%s\n", found? "YES" : "NO");

  // Return from the main function
  return 0;
}


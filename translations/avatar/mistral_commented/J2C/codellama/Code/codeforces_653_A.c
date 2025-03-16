
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  // Declare variables
  int n, i, j, k, value;
  bool found = false;
  int *a;

  // Read the number of elements in the list from the user input
  scanf("%d", &n);

  // Allocate memory for the ArrayList
  a = (int *)malloc(n * sizeof(int));

  // Read the input elements
  for (i = 0; i < n; i++) {
    scanf("%d", &value);
    a[i] = value;
  }

  // Sort the ArrayList
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        k = a[i];
        a[i] = a[j];
        a[j] = k;
      }
    }
  }

  // Check if there exists a sequence of three consecutive elements with a difference of 1
  for (i = 0; i < n; i++) {
    if (i + 1 < n && i + 2 < n) {
      if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
        found = true;
        break;
      }
    }
  }

  // Write the output to the console
  printf("%s\n", found ? "YES" : "NO");

  // Free the memory allocated for the ArrayList
  free(a);

  return 0;
}


#include <string.h>  // Include string manipulation functions
#include <stdlib.h>  // Include memory allocation functions
#include <stdio.h>   // Include standard input/output functions

public class Main {
  public static void main(String[] args) {
    String[] t, h;  // Declare pointers to pointers for Tarō and Hanako's strings
    int n, taro = 0, hanako = 0, i;  // Declare number of rounds, scores, and loop index
    scanf("%d", &n);  // Read the number of rounds
    t = malloc(n * sizeof(String));  // Allocate memory for Tarō's strings
    h = malloc(n * sizeof(String));  // Allocate memory for Hanako's strings

    // Loop through each round
    for (i = 0; i < n; i++) {
      t[i] = malloc(100 * sizeof(String));  // Allocate memory for each Tarō's string
      h[i] = malloc(100 * sizeof(String));  // Allocate memory for each Hanako's string
      scanf("%s", t[i]);  // Read Tarō's string
      scanf("%s", h[i]);  // Read Hanako's string
      if (strcmp(t[i], h[i]) < 0) hanako += 3;  // Compare and update Hanako's score
      if (strcmp(t[i], h[i]) > 0) taro += 3;  // Compare and update Tarō's score
      if (strcmp(t[i], h[i]) == 0) {  // If strings are equal
        taro += 1;  // Increment Tarō's score by 1
        hanako += 1;  // Increment Hanako's score by 1
      }
      free(t[i]);  // Free the memory allocated for Tarō's string
      free(h[i]);  // Free the memory allocated for Hanako's string
    }

    printf("%d %d\n", taro, hanako);  // Print the final scores
    return 0;  // Return 0 to indicate successful execution
  }
}


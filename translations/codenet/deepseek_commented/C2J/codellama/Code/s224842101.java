#include <stdio.h> // Step 1: Include necessary headers

public class Main { // Step 2: Define the main class
  public static void main(String[] args) { // Step 3: Define the main function
    int i, a, b, s; // Step 4: Declare necessary variables
    int count[] = new int[4]; // Declare an array to store the count of connections for each node

    for(i = 0; i < 4; i++) count[i] = 0; // Step 5: Initialize the count array

    for(i = 0; i < 3; i++){ // Step 6: Read input values and update the count array
      scanf("%d %d", &a, &b);
      count[a-1]++; // Increment the count for node a
      count[b-1]++; // Increment the count for node b
    }

    s = 1; // Initialize s to 1
    for(i = 0; i < 4; i++) s *= count[i]; // Step 7: Calculate the product of the counts

    if(s == 4) printf("YES\n"); // Step 8: Check if the product is 4 and print the result
    else printf("NO\n");
  }
}


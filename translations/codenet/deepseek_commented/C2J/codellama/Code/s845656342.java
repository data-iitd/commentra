#include <stdio.h>  // Step 1: Include necessary headers
#include <stdlib.h> // for standard library functions
#include <math.h>   // for mathematical functions

public class Main { // Step 2: Define the main class
  public static void main(String[] args) { // Step 3: Define the main function
    int x; // Step 4: Declare an integer variable
    scanf("%d", &x); // Step 5: Read an integer value from the user

    if (x == 1) // Step 6: Implement a simple if-else statement
      printf("0\n"); // Print 0 if the input is 1
    else
      printf("1\n"); // Print 1 if the input is not 1
  }
}


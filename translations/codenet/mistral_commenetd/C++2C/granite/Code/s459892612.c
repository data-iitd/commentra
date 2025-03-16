

#include <stdio.h>

int main(){
  int a, b, c; // Declare and initialize three integer variables

  // Read the values of a, b, and c from the standard input using scanf
  scanf("%d %d %d", &a, &b, &c);

  if (a + b >= c){ // Check if the sum of a and b is greater than or equal to c
    printf("Yes\n"); // If the condition is true, print the string "Yes" to the standard output
  } else {
    printf("No\n"); // If the condition is false, print the string "No" to the standard output
  }

  return 0; // End the main function with a return statement of 0, indicating that the program has executed successfully
}


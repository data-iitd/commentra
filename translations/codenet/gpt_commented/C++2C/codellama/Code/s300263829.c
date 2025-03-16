#include<stdio.h> // Include the stdio library for input and output operations

int main() // Main function where the execution of the program begins
{
  int a, b; // Declare two integer variables a and b to store user input
  
  // Prompt the user to enter two integers
  printf("Enter two integers: "); 
  scanf("%d %d", &a, &b); // Read two integers from user input and store them in variables a and b
  
  // Calculate the product of a and b and display the result
  printf("The product is: %d\n", a * b); 
  
  return 0; // Return 0 to indicate that the program ended successfully
}


#include<stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int you(int x, int y);

int main(){
  // Declare variables x, y, and z
  int x, y, z;

  // Read two integers from the user using scanf
  printf("Enter two integers: ");
  scanf("%d %d",&x,&y);

  // Determine which number is greater and call the you() function with the appropriate arguments
  if(x >= y){
    z = you(x, y); // Call the you() function with x and y as arguments
  } else {
    z = you(y, x); // Call the you() function with y and x as arguments
  }

  // Print the result (the greatest common divisor) to the console
  printf("The greatest common divisor of %d and %d is: %d\n", x, y, z);

  return 0;
}

// The you() function calculates the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int you(int x, int y){
  int z; // Declare a variable z to store the remainder

  // Repeat the following steps until y becomes zero
  while(y != 0){
    // Calculate the remainder of x divided by y and store it in z
    z = x % y;

    // Update the values of x and y
    x = y;
    y = z;
  }

  // Return the final value of x, which is the greatest common divisor
  return x;
}

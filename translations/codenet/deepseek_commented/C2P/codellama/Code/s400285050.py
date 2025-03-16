#include<stdio.h>  # Include the standard input/output library

def you(x, y):  # Function declaration for the you function
  z = 0  # Declare an integer variable to store intermediate results
  while True:  # Infinite loop to apply the Euclidean algorithm
    z = x % y  # Compute the remainder of x divided by y
    x = y  # Update x to be the previous value of y
    y = z  # Update y to be the remainder
    if y <= 0:  # Check if y is zero or negative
      break  # Exit the loop if y is zero or negative
  return x  # Return the GCD of the original two numbers

def main():  # Main function is the entry point of the program
  x, y = map(int, input().split())  # Read two integers from standard input
  if x >= y:  # Check if x is greater than or equal to y
    z = you(x, y)  # Call the you function with x and y as arguments
  else:  # Otherwise
    z = you(y, x)  # Call the you function with y and x as arguments
  print(z)  # Print the result to standard output
  return 0  # Return 0 to indicate successful execution



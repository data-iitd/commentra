#include<stdio.h>  # Include the standard input/output library

def you(x, y):  # Define the you function
  z = x % y  # Compute the remainder of x divided by y
  x = y  # Update x to be the previous value of y
  y = z  # Update y to be the remainder
  if y <= 0:  # Check if y is zero or negative
    return x  # Return the GCD of the original two numbers

def main():  # Main function is the entry point of the program
  x, y, z = int(input()), int(input()), 0  # Declare three integer variables
  if x >= y:  # Check if x is greater than or equal to y
    z = you(x, y)  # Call the you function with x and y as arguments
  else:  # Otherwise
    z = you(y, x)  # Call the you function with y and x as arguments
  print(z)  # Print the result to standard output

if __name__ == "__main__":  # Check if the file is being executed directly
  main()  # Execute the main function


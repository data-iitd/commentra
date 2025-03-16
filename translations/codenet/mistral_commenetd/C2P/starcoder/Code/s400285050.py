#include<stdio.h>

# Function to calculate the greatest common divisor (GCD) of two numbers
def you(x, y):
  z = 0 # Declare a variable z to store the remainder

  # Repeat the following steps until y becomes zero
  while(y!= 0):
    # Calculate the remainder of x divided by y and store it in z
    z = x % y

    # Update the values of x and y
    x = y
    y = z

  # Return the final value of x, which is the greatest common divisor
  return x

# Main function
def main():
  # Declare variables x, y, and z
  x = 0
  y = 0
  z = 0

  # Read two integers from the user using scanf
  print("Enter two integers: ")
  x, y = map(int, input().split())

  # Determine which number is greater and call the you() function with the appropriate arguments
  if(x >= y):
    z = you(x, y) # Call the you() function with x and y as arguments
  else:
    z = you(y, x) # Call the you() function with y and x as arguments

  # Print the result (the greatest common divisor) to the console
  print("The greatest common divisor of %d and %d is: %d\n" % (x, y, z))

  return 0

# Call the main function
if __name__ == "__main__":
  main()

# 
#include<stdio.h>  # Include the standard input/output library for printf and scanf

int main():  # Define the main function, the entry point of the program
  a,b,c = input("Enter three integers: ").split()  # Read three integers from the standard input and store them in a, b, and c

  if a<b and b<c:  # Check if a is less than b and b is less than c
    print("Yes")  # If true, print "Yes"
  else:  # Otherwise
    print("No")  # Print "No"

  return 0  # Return 0 to indicate successful execution of the program


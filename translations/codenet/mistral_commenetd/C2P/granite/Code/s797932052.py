
#include<stdio.h>

// Include the standard input/output library

def main():
  a = int(input()) # Read an integer value from the standard input and store it in variable 'a'
  b = int(input()) # Read an integer value from the standard input and store it in variable 'b'

  if((a*b)%2 == 0): # Check if the product of 'a' and 'b' is even
    print("Even") # If it is even, print "Even" to the standard output
  else:
    print("Odd") # If it is odd, print "Odd" to the standard output

if __name__ == "__main__":
  main()


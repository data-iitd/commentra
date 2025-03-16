

import sys # Importing the required Python module for file I/O

def main ( ):
  n = int ( input ( ) ) # Reading the first line of input which contains the number of test cases

  if n == 1: # Checking if the number of test cases is equal to 1
    print ( "Hello World" ) # If yes, printing "Hello World" as output
  else:
    num1 = int ( input ( ) ) # Reading the next line of input which contains an integer
    num2 = int ( input ( ) ) # Reading the next line of input which contains another integer

    print ( num1 + num2 ) # Printing the sum of the two integers as output

if __name__ == "__main__":
  main ( ) # Calling the main function


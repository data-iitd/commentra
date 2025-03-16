
import sys ; // Importing required Python packages for file I/O and streams
import io ;

def main ( ) :
  n = int ( sys.stdin.readline ( ) ) ; // Reading the first line of input which contains the number of test cases

  if n == 1 : // Checking if the number of test cases is equal to 1
    print ( "Hello World" ) ; // If yes, printing "Hello World" as output
  else :
    strs = sys.stdin.readline ( ).split ( ) ; // Reading the next two lines of input which contain two integers
    num1 = int ( strs [ 0 ] ) ; // Storing the first integer in a variable 'num1'
    num2 = int ( strs [ 1 ] ) ; // Storing the second integer in a variable 'num2'

    print ( num1 + num2 ) ; // Printing the sum of the two integers as output

if __name__ == "__main__" :
  main ( ) ;


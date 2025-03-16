
import sys ; // Importing sys module for reading input from the user

def solve ( n ) :
    # Calculating the result based on the given logic
    print ( ( n // 3 ) * 2 + ( n % 3 == 0 ) ) ; // Printing the result to the console

if __name__ == '__main__' :
    n = int ( sys.stdin.readline ( ) ) ; // Reading an integer input from the user and storing it in variable n
    solve ( n ) ; // Calling the solve method with the input value n


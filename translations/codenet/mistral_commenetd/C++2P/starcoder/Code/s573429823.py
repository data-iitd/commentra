# Include the standard input/output library
from sys import stdin, stdout

# Define the main function, entry point of the program
def main():
    # Read the input number
    n = int(stdin.readline())

    # Check if n is less than 4
    if( n<4 ):
        stdout.write("No\n") # Print "No" and exit the program
        return 0

    # Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for i in range(0, n//4+1): # Outer loop: i from 0 to n/4
        for j in range(0, n//7+1): # Inner loop: j from 0 to n/7
            if( (i*4+j*7)==n ): # Check if the sum of i*4 and j*7 equals n
                stdout.write("Yes\n") # Print "Yes" and exit the program
                return 0

    # Print the result
    stdout.write("No\n") # Print "No" otherwise

# Call the main function, entry point of the program
if __name__ == "__main__":
    main()


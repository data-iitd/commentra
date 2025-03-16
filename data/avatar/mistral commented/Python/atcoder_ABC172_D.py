# Importing the sys module for reading input from standard input
import sys

# Function to read a single line from standard input and return it as a string
# with the trailing newline character removed
def rs ( ): return sys.stdin.readline ( ).rstrip ( )

# Function to read a single integer from standard input
def ri ( ): return int ( rs ( ) )

# Function to read a list of integers from standard input
# Each line of input is assumed to contain space-separated integers
def ri_ ( ): return [ int ( _ ) for _ in rs ( ).split ( ) ]

# Read the number of test cases from standard input
N = ri ( )

# Initialize the answer to 0
ans = 0

# Iterate through all numbers from 1 to N
for i in range ( 1 , N + 1 ):
    # Calculate the contribution of i to the answer
    # The formula is given by the problem statement
    ans += i * ( N // i ) * ( N // i + 1 ) // 2

# Print the answer
print ( ans )

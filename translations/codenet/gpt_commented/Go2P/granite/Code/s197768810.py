
import sys

# Initialize a new scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

# Function to read an integer from input
def readInt():
    sc.scan() # Read the next token from input
    return int(sc.text()) # Convert the token to an integer and return it

# Function to read a float from input
def readFloat():
    sc.scan() # Read the next token from input
    return float(sc.text()) # Convert the token to a float and return it

# Function to read a string from input
def readString():
    sc.scan() # Read the next token from input
    return sc.text() # Return the string value

def main():
    # Set the scanner to split input by whitespace
    sc.whitespace = " "

    # Read two integers n and m from input
    n, m = readInt(), readInt()

    # Initialize a list to hold m integers
    a = []

    # Initialize a variable to hold the sum of the integers read
    sum = 0

    # Read m integers from input and calculate their sum
    for i in range(m):
        a.append(readInt()) # Read an integer and append it to the list
        sum += a[i] # Add the integer to the sum

    # Check if the sum of the integers exceeds n
    if sum > n:
        print(-1) # Print -1 if the sum is greater than n
        return # Exit the function

    # Print the difference between n and the sum of the integers
    print(n - sum)



import sys

# Initialize a new scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

# next reads the next line of input and returns it as a string
def next():
    sc.scan() # Scan the next token
    return sc.text() # Return the scanned text

# nextInt reads the next line of input, converts it to an integer, and returns it
def nextInt():
    sc.scan() # Scan the next token
    i = int(sc.text()) # Convert the scanned text to an integer
    return i # Return the integer value

# nextFloat64 reads the next line of input, converts it to a float64, and returns it
def nextFloat64():
    f = float(next()) # Convert the scanned text to a float64
    return f # Return the float64 value

# nextInts reads 'n' integers from input and returns them as a slice
def nextInts(n):
    slice = [] # Create an empty list to hold 'n' integers
    for i in range(n): # Loop 'n' times to read integers
        slice.append(nextInt()) # Read each integer and append it to the list
    return slice # Return the list of integers

if __name__ == '__main__':
    sc.wordchars += '.' # Set the scanner to accept floating-point numbers
    sc.wordsep = '\n' # Set the scanner to split input by newlines
    # Read two integers, sum them, and compare the result with a third integer
    if nextInt()+nextInt() >= nextInt():
        print("Yes") # Print "Yes" if the sum is greater than or equal to the third integer
    else:
        print("No") # Print "No" otherwise

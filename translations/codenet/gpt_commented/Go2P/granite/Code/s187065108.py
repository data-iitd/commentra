
import sys

# Create a new scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

# scanInt reads an integer from input and returns it
def scanInt():
    return int(scanString())

# scanString reads a single string from input and returns it
def scanString():
    sc.scan() # Scan the next word from input
    return sc.text() # Return the scanned text

# scanInts reads 'n' integers from input and returns them as a slice
def scanInts(n):
    sl = [] # Create an empty list to store the integers
    for i in range(n):
        sl.append(scanInt()) # Append the next integer to the list
    return sl # Return the list of integers

# scanStrings reads 'n' strings from input and returns them as a slice
def scanStrings(n):
    sl = [] # Create an empty list to store the strings
    for i in range(n):
        sl.append(scanString()) # Append the next string to the list
    return sl # Return the list of strings

# init function sets up the scanner to split input by words
def init():
    sc.whitespace = " \n\r\t" # Configure the scanner to split input by whitespace

# main function is the entry point of the program
def main():
    # Read three integers from input: r, D, and x
    r, D, x = scanInt(), scanInt(), scanInt()
    
    # Perform calculations and print the result for 10 iterations
    for i in range(1, 11):
        x = r*x - D # Update x based on the formula
        print(x) # Print the current value of x

# Call the main function to start the program
if __name__ == "__main__":
    main()


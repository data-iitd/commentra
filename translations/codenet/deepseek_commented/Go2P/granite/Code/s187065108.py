
import sys

# Scanner to read input in a word-by-word manner
sc = bufio.Scanner(sys.stdin)

# Converts a scanned string to an integer
def scanInt():
    return int(scanString())

# Reads a single word from the input
def scanString():
    sc.scan()
    return sc.text()

# Reads a slice of integers from input
def scanInts(n):
    return [scanInt() for _ in range(n)]

# Reads a slice of strings from input
def scanStrings(n):
    return [scanString() for _ in range(n)]

# Initializes the scanner to split input words
def init():
    sc.split(bufio.ScanWords)

# Main function to execute the program
def main():
    # Read initial values for r, D, and x
    r, D, x = scanInt(), scanInt(), scanInt()
    
    # Loop to calculate and print the values of x for 10 iterations
    for i in range(1, 11):
        x = r*x - D
        print(x)

# Call the main function to execute the program
main()


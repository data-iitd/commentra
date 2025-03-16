
#!/usr/bin/env python3

import sys

# getScanner initializes a new scanner for the provided file pointer.
# It sets the scanner to split input by words and allocates a buffer size.
def getScanner(fp):
    scanner = fp.split()
    scanner.buffer(500001)
    return scanner

# getNextString retrieves the next string from the scanner.
def getNextString(scanner):
    return scanner.next()

# getNextInt converts the next string from the scanner to an integer.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 converts the next string from the scanner to a 64-bit integer.
def getNextInt64(scanner):
    return int(getNextString(scanner), 10)

# getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
def getNextUint64(scanner):
    return int(getNextString(scanner), 10)

# getNextFloat64 converts the next string from the scanner to a float64.
def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    # Initialize file pointers for input and output.
    fp = sys.stdin
    wfp = sys.stdout

    # Check for command line arguments to open input and output files.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1]) # Open input file if provided.
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w') # Create output file if provided.

    # Create a scanner for reading input and a writer for output.
    scanner = getScanner(fp)
    writer = wfp

    # Read the number of integers to process.
    n = getNextInt(scanner)

    # Initialize the answer as "second" and check for odd integers.
    ans = "second"
    for i in range(n):
        a = getNextInt(scanner) # Read the next integer.
        if a%2 == 1: # Check if the integer is odd.
            ans = "first" # If odd, set answer to "first".
            break # Exit the loop early if an odd integer is found.

    # Write the result to the output.
    print(ans, file=writer)

if __name__ == "__main__":
    main()



#!/usr/bin/env python3

import sys

# getScanner initializes and returns a new bufio.Scanner from the given file pointer
def getScanner(fp):
    scanner = fp.split()
    return scanner

# getNextString reads and returns the next word as a string from the scanner
def getNextString(scanner):
    return scanner.next()

# getNextInt reads and converts the next integer from the scanner to an int
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 reads and converts the next integer from the scanner to an int64
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 reads and converts the next unsigned integer from the scanner to a uint64
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 reads and converts the next floating-point number from the scanner to a float64
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# main function is the entry point of the program
def main():
    # open standard input as default file if no arguments are provided
    fp = sys.stdin
    # open output file if provided as an argument
    wfp = sys.stdout
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
        # create output file if provided as an argument
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    # initialize scanner and writer
    scanner = getScanner(fp)
    writer = wfp

    # read the first integer from the input
    n = getNextInt(scanner)

    # initialize answer variable
    ans = "second"
    # iterate through the input integers
    for i in range(n):
        # read the next integer from the input
        a = getNextInt(scanner)
        # check if the current integer is odd
        if a % 2 == 1:
            # update the answer if an odd integer is found
            ans = "first"
            # exit the loop if only one odd integer is found
            break

    # write the answer to the output
    writer.write(ans + "\n")
    # flush the writer buffer
    writer.flush()

# 
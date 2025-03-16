
#!/usr/bin/env python3

import sys

# getScanner initializes a new scanner for reading from the provided file pointer.
# It sets the scanner to split input by words and allocates a buffer for large inputs.
def getScanner(fp):
    scanner = fp.split()
    return scanner

# getNextString retrieves the next string from the scanner.
def getNextString(scanner):
    return scanner.next()

# getNextInt converts the next string from the scanner to an integer.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 converts the next string from the scanner to a 64-bit integer.
def getNextInt64(scanner):
    return int(getNextString(scanner))

def main():
    # Determine the input source: standard input or a file specified as a command-line argument.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
    else:
        fp = sys.stdin

    # Initialize the scanner for reading input.
    scanner = getScanner(fp)

    # Create a buffered writer for output.
    writer = sys.stdout

    # Read the number of elements from the input.
    n = getNextInt(scanner)

    # Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    aa = [0] * (n+2)
    sum = 0

    # Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for i in range(0, n):
        aa[i+1] = getNextInt(scanner)
        sum += abs(aa[i+1] - aa[i])

    # Include the difference between the last element and the element before it.
    sum += abs(aa[n+1] - aa[n])

    # Calculate and print the result for each element.
    for i in range(1, n+1):
        # Calculate the new sum of absolute differences if the i-th element is removed.
        ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
        print(ans) # Output the result for the current element.

    # Flush the buffered writer to ensure all output is written.
    writer.flush()

if __name__ == '__main__':
    main()


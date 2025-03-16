

import sys

# Function to create a new bufio.Scanner from a file pointer
def getScanner(fp):
    scanner = bufio.Scanner(fp)
    scanner.buffer(bytearray(500001), 500000) # Buffer size for efficient reading
    return scanner

# Function to read the next string from the scanner
def getNextString(scanner):
    scanner.scan()
    return scanner.string()

# Function to read the next integer from the scanner
def getNextInt(scanner):
    return int(getNextString(scanner))

# Function to read the next int64 from the scanner
def getNextInt64(scanner):
    return int(getNextString(scanner))

# Main function
def main():
    # Open the standard input as a file
    fp = sys.stdin
    # If there is an argument, open the file with that name instead
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    # Create a new bufio.Scanner from the file pointer
    scanner = getScanner(fp)

    # Create a new bufio.Writer for output
    writer = bufio.Writer(sys.stdout)

    # Read the first integer from the input
    n = getNextInt(scanner)

    # Initialize an array 'aa' of size 'n+2'
    aa = [0] * (n + 2)
    # Initialize a variable'sum' to store the sum of absolute differences between consecutive elements
    sum = 0

    # Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for i in range(n):
        # Read the next integer from the scanner and store it in 'aa[i+1]'
        aa[i+1] = getNextInt(scanner)
        # Calculate the absolute difference between the current and previous elements and add it to the sum
        sum += abs(aa[i+1] - aa[i])

    # Calculate the absolute difference between the last two elements and add it to the sum
    sum += abs(aa[n+1] - aa[n])

    # Iterate through the array 'aa' and print the answer for each subarray
    for i in range(1, n+1):
        # Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1])
        # Write the answer to the output writer
        writer.write(str(ans) + '\n')

    # Flush the buffer to write all the data to the output
    writer.flush()

# Function to calculate the absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# End of code

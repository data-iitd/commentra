
#!/usr/bin/env python3

import sys

# Function to calculate the absolute value of an integer
def absint(a):
    if a < 0:
        return -a
    return a

# Function to read the next integer from the input
def getNextInt(scanner):
    return int(scanner.readline())

# Function to read the next string from the input
def getNextString(scanner):
    return scanner.readline().strip()

# Main function
def main():
    # Open the standard input as a file
    fp = sys.stdin
    # If there is an argument, open the file with that name instead
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')

    # Create a new bufio.Scanner from the file pointer
    scanner = fp.readline

    # Read the first integer from the input
    n = getNextInt(scanner)

    # Initialize an array 'aa' of size 'n+2'
    aa = [0] * (n+2)
    # Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    sum = 0

    # Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for i in range(0, n):
        # Read the next integer from the scanner and store it in 'aa[i+1]'
        aa[i+1] = getNextInt(scanner)
        # Calculate the absolute difference between the current and previous elements and add it to the sum
        sum += absint(aa[i+1] - aa[i])

    # Calculate the absolute difference between the last two elements and add it to the sum
    sum += absint(aa[n+1] - aa[n])

    # Iterate through the array 'aa' and print the answer for each subarray
    for i in range(1, n+1):
        # Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        ans = sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1])
        # Write the answer to the output writer
        print(ans)

if __name__ == "__main__":
    main()


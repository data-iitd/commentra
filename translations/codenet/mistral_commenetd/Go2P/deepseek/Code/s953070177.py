import sys
import os

# Function to create a new bufio.Scanner from a file pointer
def get_scanner(fp):
    import io
    return io.TextIOWrapper(fp, encoding='utf-8').readline

# Function to read the next string from the scanner
def get_next_string(scanner):
    return scanner().strip()

# Function to read the next integer from the scanner
def get_next_int(scanner):
    return int(get_next_string(scanner))

# Function to read the next int64 from the scanner
def get_next_int64(scanner):
    return int(get_next_string(scanner))

# Main function
def main():
    # Open the standard input as a file
    fp = sys.stdin
    # If there is an argument, open the file with that name instead
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')

    # Create a new bufio.Scanner from the file pointer
    scanner = get_scanner(fp)

    # Create a new bufio.Writer for output
    writer = sys.stdout

    # Read the first integer from the input
    n = get_next_int(scanner)

    # Initialize an array 'aa' of size 'n+2'
    aa = [0] * (n + 2)
    # Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    sum_abs = 0

    # Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
    for i in range(n):
        # Read the next integer from the scanner and store it in 'aa[i+1]'
        aa[i+1] = get_next_int(scanner)
        # Calculate the absolute difference between the current and previous elements and add it to the sum
        sum_abs += abs(aa[i+1] - aa[i])

    # Calculate the absolute difference between the last two elements and add it to the sum
    sum_abs += abs(aa[n+1] - aa[n])

    # Iterate through the array 'aa' and print the answer for each subarray
    for i in range(1, n+1):
        # Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        ans = sum_abs - abs(aa[i+1] - aa[i]) - abs(aa[i] - aa[i-1]) + abs(aa[i+1] - aa[i-1])
        # Write the answer to the output writer
        print(ans)

# Function to calculate the absolute value of an integer
def absint(a):
    return abs(a)

# Call the main function
main()

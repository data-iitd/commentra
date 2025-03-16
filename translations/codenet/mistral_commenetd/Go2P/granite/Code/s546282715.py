
import sys

# Function to read the next word from the scanner
def getNextWord(scanner):
    return scanner.next()

# Function to read the next integer from the scanner
def getNextInt(scanner):
    return int(getNextWord(scanner))

# Main function
def main():
    # Open the standard input file if the command line argument is provided
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    # Initialize the scanner and writer
    scanner = bufio.Scanner(fp)
    writer = bufio.Writer(sys.stdout)

    # Read the first two integers from the input
    n = getNextInt(scanner)
    m = getNextInt(scanner)

    # Initialize an associative array to store the elements
    aa = {}
    # Read m elements and store them in the associative array
    for i in range(m):
        aa[getNextInt(scanner)] = 1

    # Initialize a slice of length n+1 for dynamic programming
    dp = [0] * (n + 1)
    # Initialize the first element of the slice
    dp[0] = 1

    # Iterate through the array from index 0 to n-1
    for i in range(n):
        # Iterate through the prefix sum from i to i+2
        for ii in range(1, 3):
            # Skip if the current index and its sum are already present in the associative array
            if i + ii <= n and (i + ii) in aa:
                continue
            # Calculate the dynamic programming value for the current index
            dp[i + ii] += dp[i]
            # Perform modulo operation to keep the value within the range of 10^9+7
            dp[i + ii] %= 1000000007

    # Print the final answer
    print(dp[n])

    # Flush the writer buffer
    writer.flush()

# Call the main function
main()


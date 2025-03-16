
import sys

def getScanner(fp):
    return iter(fp.read().split())

def getNextString(scanner):
    return next(scanner)

def getNextInt(scanner):
    return int(getNextString(scanner))

if __name__ == '__main__':
    # Determine the input source: standard input or a file specified as a command-line argument.
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1]) # Open the file if a filename is provided.

    # Initialize the scanner for reading input and a writer for output.
    scanner = getScanner(fp)
    writer = sys.stdout

    # Read the number of elements.
    n = getNextInt(scanner)
    mm = [0] * (n + 1) # Create a list to hold the input values.
    dp = [[0] * (n + 1) for _ in range(n + 1)] # Create a 2D list for dynamic programming.

    # Read the input values into the mm list.
    for i in range(n):
        mm[i] = getNextInt(scanner) # Read the first value.
        mm[i + 1] = getNextInt(scanner) # Read the second value.

    # Perform dynamic programming to calculate the minimum cost.
    for l in range(2, n + 1): # l is the length of the subproblem.
        for i in range(1, n - l + 2): # i is the starting index of the subproblem.
            j = i + l - 1 # j is the ending index of the subproblem.
            for k in range(i, j): # k is the partition point.
                # Calculate the cost of multiplying the matrices.
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                # Update the dp table with the minimum cost found.
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    # Output the minimum cost of multiplying the entire sequence of matrices.
    print(dp[1][n])

    # Flush the writer to ensure all output is written.
    writer.flush()


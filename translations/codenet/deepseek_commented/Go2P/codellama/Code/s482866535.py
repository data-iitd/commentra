
import sys

# getScanner initializes a new scanner for reading from a file.
def getScanner(fp):
    scanner = fp.read().split()
    return scanner

# getNextString reads the next word from the scanner.
def getNextString(scanner):
    return scanner.pop(0)

# getNextInt converts the next word from the scanner to an integer.
def getNextInt(scanner):
    return int(getNextString(scanner))

# Main function to compute the minimum number of matrix multiplications.
def main():
    # Initialize scanner and writer for standard input and output.
    scanner = getScanner(sys.stdin)
    writer = sys.stdout

    # Read the number of matrices.
    n = getNextInt(scanner)

    # Initialize arrays for matrix dimensions and dynamic programming.
    mm = [0] * (n + 1)
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # Read matrix dimensions into the mm array.
    for i in range(n):
        mm[i] = getNextInt(scanner)
        mm[i + 1] = getNextInt(scanner)

    # Use dynamic programming to compute the minimum number of multiplications.
    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            for k in range(i, j):
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    # Print the result to the standard output.
    print(dp[1][n], file=writer)

    # Flush the writer to ensure all data is written to the output.
    writer.flush()



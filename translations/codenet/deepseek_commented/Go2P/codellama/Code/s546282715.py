
import sys

# getNextWord reads the next word from the scanner.
def getNextWord(scanner):
    scanner.scan()
    return scanner.text()

# getNextInt reads the next word from the scanner and converts it to an integer.
def getNextInt(scanner):
    i, _ = int(getNextWord(scanner)), 0
    return i

# main function starts here
def main():
    # Determine the input source based on command-line arguments
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    # Create a new scanner to read from the determined input source
    scanner = fp.read().split()
    scanner = iter(scanner)

    # Create a writer to output the result
    writer = sys.stdout

    # Read the number of elements (n) and the number of restricted positions (m)
    n = getNextInt(scanner)
    m = getNextInt(scanner)

    # Create a map to store the restricted positions
    aa = {}
    for i in range(m):
        aa[getNextInt(scanner)] = 1

    # Initialize the dynamic programming array
    dp = [1] + [0] * n

    # Fill the dynamic programming array based on restricted positions
    for i in range(n):
        for ii in range(1, 3):
            if i + ii > n:
                break
            if i + ii in aa:
                continue
            dp[i + ii] += dp[i]
            dp[i + ii] %= 1000000007

    # Print the result
    print(dp[n], file=writer)

    # Flush the writer to ensure all data is written to the output
    writer.flush()


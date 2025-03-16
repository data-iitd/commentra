
import sys

# getScanner initializes a new bufio.Scanner with specific configurations.
def getScanner(fp):
    scanner = fp.split()
    return scanner

# getNextString reads the next word from the scanner.
def getNextString(scanner):
    return scanner.next()

# getNextInt reads the next word, converts it to an integer, and returns it.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 reads the next word, converts it to an int64, and returns it.
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 reads the next word, converts it to a uint64, and returns it.
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 reads the next word, converts it to a float64, and returns it.
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# Main function handles file input/output operations based on command-line arguments.
def main():
    fp = sys.stdin
    wfp = sys.stdout

    # Check if command-line arguments are provided for file input/output.
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    scanner = getScanner(fp)
    writer = wfp

    # Read the number of integers to process.
    n = getNextInt(scanner)

    # Initialize the answer to "second".
    ans = "second"
    for i in range(n):
        a = getNextInt(scanner)
        if a%2 == 1:
            ans = "first"
            break

    # Print the result based on the condition.
    writer.write(ans + "\n")
    writer.flush()

if __name__ == "__main__":
    main()



import sys

def getScanner(fp):
    return iter(fp.read().split())

def getNextString(scanner):
    return next(scanner)

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def getNextUint64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

if __name__ == "__main__":
    fp = sys.stdin
    wfp = sys.stdout

    if len(sys.argv) > 1:
        fp = open(sys.argv[1]) # Open input file if provided.
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], "w") # Create output file if provided.

    scanner = getScanner(fp)
    writer = wfp

    n = getNextInt(scanner)

    ans = "second"
    for i in range(n):
        a = getNextInt(scanner) # Read the next integer.
        if a % 2 == 1: # Check if the integer is odd.
            ans = "first" # If odd, set answer to "first".
            break # Exit the loop early if an odd integer is found.

    print(ans, file=writer)
    writer.flush() # Ensure all buffered data is written to the output.


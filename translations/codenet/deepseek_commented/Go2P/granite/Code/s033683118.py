
import sys

# getScanner initializes a new scanner to read input from a file.
# It sets the split function to scan words and buffers the input to a specified size.
def getScanner(fp):
    scanner = bufio.Scanner(fp)
    scanner.buffer(500001)
    scanner.split(bufio.ScanWords)
    return scanner

# getNextString reads the next token from the scanner and returns it as a string.
def getNextString(scanner):
    scanner.scan()
    return scanner.string()

# getNextInt reads the next token, converts it to an integer, and returns it.
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 reads the next token, converts it to an int64, and returns it.
def getNextInt64(scanner):
    return int(getNextString(scanner))

# getNextUint64 reads the next token, converts it to a uint64, and returns it.
def getNextUint64(scanner):
    return int(getNextString(scanner))

# getNextFloat64 reads the next token, converts it to a float64, and returns it.
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# main function handles the program's flow.
# It sets up the input and output files based on environment variables,
# calls the solve function, and prints separators if necessary.
def main():
    fp = sys.stdin
    wfp = sys.stdout
    cnt = 0

    if os.getenv("MASPY") == "ますπ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2
    if os.getenv("MASPYPY") == "ますπッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")
    scanner = getScanner(fp)
    solve(scanner, wfp)
    for i in range(cnt):
        print("-----------------------------------", file=wfp)
        solve(scanner, wfp)
    wfp.flush()

# solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
# It writes "Yes" or "No" based on this condition.
def solve(scanner, wfp):
    k = getNextInt(scanner)
    x = getNextInt(scanner)

    ans = "No"
    if k*500 >= x:
        ans = "Yes"
    print(ans, file=wfp)



import sys

# getScanner initializes a new scanner to read input from a file.
# It sets the split function to scan words and buffers the input to a specified size.
def getScanner(fp):
    scanner = sys.stdin
    scanner.split(scanner.scanWords)
    scanner.buffer(500001, 500000)
    return scanner

# getNextString reads the next token from the scanner and returns it as a string.
def getNextString(scanner):
    scanner.scan()
    return scanner.text()

# getNextInt reads the next token, converts it to an integer, and returns it.
def getNextInt(scanner):
    i = int(getNextString(scanner))
    return i

# getNextInt64 reads the next token, converts it to an int64, and returns it.
def getNextInt64(scanner):
    i = int(getNextString(scanner), 10)
    return i

# getNextUint64 reads the next token, converts it to a uint64, and returns it.
def getNextUint64(scanner):
    i = int(getNextString(scanner), 10)
    return i

# getNextFloat64 reads the next token, converts it to a float64, and returns it.
def getNextFloat64(scanner):
    i = float(getNextString(scanner))
    return i

# main function handles the program's flow.
# It sets up the input and output files based on environment variables,
# calls the solve function, and prints separators if necessary.
def main():
    fp = sys.stdin
    wfp = sys.stdout
    cnt = 0

    if os.getenv("MASPY") == "ますピ":
        fp = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
        cnt = 2
    if os.getenv("MASPYPY") == "ますピッピ":
        wfp = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    scanner = getScanner(fp)
    writer = open(wfp, "w")
    solve(scanner, writer)
    for i in range(cnt):
        writer.write("-----------------------------------\n")
        solve(scanner, writer)
    writer.close()

# solve function reads two integers k and x, and determines if k * 500 is greater than or equal to x.
# It writes "Yes" or "No" based on this condition.
def solve(scanner, writer):
    k = getNextInt(scanner)
    x = getNextInt(scanner)

    ans = "No"
    if k*500 >= x:
        ans = "Yes"
    writer.write(ans + "\n")



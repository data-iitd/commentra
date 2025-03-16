
import sys

# getScanner initializes a new bufio.Scanner to read from a file.
# It sets the split function to bufio.ScanWords to read words,
# and it also sets a buffer size.
def getScanner(fp):
    scanner = bufio.Scanner(fp)
    scanner.split(bufio.ScanWords)
    scanner.buffer(make([]byte, 500001), 500000)
    return scanner

# getNextString reads the next word from the scanner and returns it as a string.
def getNextString(scanner):
    scanner.scan()
    return scanner.text()

# getNextInt reads the next word from the scanner, converts it to an integer,
# and returns it.
def getNextInt(scanner):
    i, _ = strconv.Atoi(getNextString(scanner))
    return i

# getNextInt64 reads the next word from the scanner, converts it to an int64,
# and returns it.
def getNextInt64(scanner):
    i, _ = strconv.ParseInt(getNextString(scanner), 10, 64)
    return i

# main is the entry point of the program.
# It first checks if a file name is provided as an argument,
# and if so, it opens that file for reading.
# It then initializes a scanner and a writer.
def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1])

    scanner = getScanner(fp)

    writer = bufio.Writer(sys.stdout)

    # Read the number of elements.
    n = getNextInt(scanner)

    # Initialize a slice to store the elements and a sum variable.
    aa = [0] * (n+2)
    sum = 0

    # Read the elements into the slice and calculate the sum of absolute differences.
    for i in range(0, n):
        aa[i+1] = getNextInt(scanner)
        sum += absint(aa[i+1] - aa[i])

    sum += absint(aa[n+1] - aa[n])

    # Calculate and print the differences for each element.
    for i in range(1, n+1):
        ans = sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1])
        print(ans)

    # Flush the writer to ensure all output is written to the output stream.
    writer.flush()

# absint returns the absolute value of an integer.
def absint(a):
    if a < 0:
        return -a
    return a


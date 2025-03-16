
# Package main is the entry point of the program
import sys

# getScanner function returns a bufio.Scanner instance configured for reading words
def getScanner(fp):
    scanner = bufio.Scanner(fp)
    scanner.split(bufio.ScanWords)
    scanner.buffer(500001) # Buffer size for efficient reading
    return scanner

# getNextString function returns the next word as a string
def getNextString(scanner):
    scanner.scan()
    return scanner.text()

# getNextInt function returns the next integer from the scanner
def getNextInt(scanner):
    return int(getNextString(scanner))

# getNextInt64 function returns the next 64-bit integer from the scanner
def getNextInt64(scanner):
    return int(getNextString(scanner), 10)

# getNextUint64 function returns the next 64-bit unsigned integer from the scanner
def getNextUint64(scanner):
    return int(getNextString(scanner), 10)

# getNextFloat64 function returns the next 64-bit floating-point number from the scanner
def getNextFloat64(scanner):
    return float(getNextString(scanner))

# main function is the entry point of the program
def main():
    # Open the standard input file if a command-line argument is provided
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')

    # Initialize a bufio.Writer for formatted output
    writer = bufio.Writer(sys.stdout)

    # Read the first two integers from the input
    n = getNextInt(getScanner(fp))
    m = getNextInt(getScanner(fp))

    # Initialize the Segment struct with the given size n
    seg = Segment()
    seg.init(n)

    # Process the input data by maximizing the segments
    for i in range(n):
        seg.maximize(i, getNextInt(getScanner(fp)))
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1)

    # Calculate the answer and print it to the output
    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i]

    # Print the answer to the output
    writer.write(str(ans) + '\n')

    # Flush the writer buffer to ensure all data is written
    writer.flush()

# Segment type represents a segment tree data structure
class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    # init function initializes the Segment struct with the given size n
    def init(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [[0] * n]

        # Calculate the chunk size for the segment tree
        chunk = 8
        for i in range(0, n):
            n = (n-1)/chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[i] * chunk)
        self.h = len(self.unit)
        self.chunk = chunk

    # maximize function updates the segment tree with the given index and value
    def maximize(self, index, value):
        # Update the leaf node with the given index and value
        self.bucket[0][index] = value

        # Propagate the update to the parent nodes
        for self.i in range(0, self.h-1):
            s = index - index%self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            parent = index / self.chunk
            max = 0
            for i in range(s, t):
                if max < self.bucket[self.i][i]:
                    max = self.bucket[self.i][i]
            self.bucket[self.i+1][parent] = max
            index /= self.chunk

    # top function returns the index of the maximum value in the current segment
    def top(self):
        index = 0
        for self.i in range(self.h-2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i+1][index]:
                    index = i
                    break
        return index


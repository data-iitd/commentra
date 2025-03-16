
import sys

def main():
    # Create a new scanner to read input
    sc = Scanner()

    # Read three integers from input: H, W, and N
    H, W, N = sc.nextInt(), sc.nextInt(), sc.nextInt()

    # Calculate the maximum of H and W
    A = max(H, W)

    # Calculate and print the number of full groups needed to accommodate N items
    print((N + A - 1) // A)

# Function to return the maximum of two integers
def max(a, b):
    if a < b:
        return b
    return a

# Scanner struct to facilitate reading input
class Scanner:
    def __init__(self):
        self.r = sys.stdin.buffer.readline

    # Read the next token from the input
    def next(self):
        self.pre()
        start = self.p
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                break
            self.p += 1
        return self.buf[start:self.p]

    # Read the next line from the input
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    # Read the next integer from the input
    def nextInt(self):
        return int(self.next())

    # Read the next int64 from the input
    def nextInt64(self):
        return int(self.next())

    # Read the next float64 from the input
    def nextFloat(self):
        return float(self.next())

    # Read a slice of integers from the input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p < len(self.buf) + 1:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v = int(self.buf[start:self.p])
                result.append(v)
                start = self.p + 1
        return result

    # Read a slice of int64 from the input
    def nextInt64Array(self):
        self.pre()
        start = self.p
        result = []
        for self.p < len(self.buf) + 1:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v = int(self.buf[start:self.p])
                result.append(v)
                start = self.p + 1
        return result

    # Read a map of integers from the input
    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                v = int(self.buf[start:self.p])
                mp[v] = True
                start = self.p + 1
        v = int(self.buf[start:self.p])
        mp[v] = True
        return mp

    # pre checks if there is data to read and reads a new line if necessary
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # readLine reads a full line from the input and stores it in the buffer
    def readLine(self):
        self.buf = []
        for l, p, e in self.r():
            if e != None:
                raise e
            self.buf.append(l)
            if not p:
                break

if __name__ == "__main__":
    main()



import sys

#bufReader struct to handle buffered reading from standard input
class bufReader:
    def __init__(self):
        self.r = sys.stdin.buffer
        self.buf = bytearray()
        self.i = 0

    def readLine(self):
        if self.i < len(self.buf):
            return
        self.buf = bytearray()
        self.i = 0
        while True:
            line = self.r.readline()
            if not line:
                break
            self.buf += line
        return

    def next(self):
        self.readLine()
        from_ = self.i
        while self.i < len(self.buf) and self.buf[self.i]!= b' ':
            self.i += 1
        s = self.buf[from_:self.i].decode()
        self.i += 1
        return s

    def nextLine(self):
        self.readLine()
        s = self.buf[self.i:].decode()
        self.i = len(self.buf)
        return s

# Initialize a global bufReader instance for reading input
reader = bufReader()

# next is a wrapper to get the next token as a string
def next():
    return reader.next()

# nextInt retrieves the next token and converts it to an int64
def nextInt():
    i = int(next())
    return i

# nextLine is a wrapper to get the next line as a string
def nextLine():
    return reader.nextLine()

# out prints the output to the standard output
def out(*a):
    print(*a, sep='\n')

# max returns the maximum of two int64 values
def max(x, y):
    if x > y:
        return x
    return y

# min returns the minimum of two int64 values
def min(x, y):
    if x < y:
        return x
    return y

# joinInts converts a slice of int64 to a string with a separator
def joinInts(a, sep):
    b = [str(v) for v in a]
    return sep.join(b)

# divUp performs ceiling division of x by y
def divUp(x, y):
    return (x + y - 1) // y

# main function where the program execution starts
def main():
    solve()

# solve contains the main logic for processing input and producing output
def solve():
    N = nextInt()
    T = [nextInt() for _ in range(N)]
    A = [nextInt() for _ in range(N)]
    t, a = T[0], A[0]
    for i in range(1, N):
        r = max(divUp(t, T[i]), divUp(a, A[i]))
        t, a = T[i]*r, A[i]*r
    out(t + a)

if __name__ == '__main__':
    main()

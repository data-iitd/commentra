
import sys
import math

#bufReader struct definition
# This struct is designed to efficiently read lines from standard input.
# It uses a buffer to minimize the number of system calls.
class bufReader:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.i = 0

    def readLine(self):
        if self.i < len(self.buf):
            return
        self.buf = []
        self.i = 0
        while True:
            line = self.r.readline()
            if not line:
                raise Exception("end of file")
            self.buf.extend(line)
            if not line.endswith("\n"):
                break

    def next(self):
        self.readLine()
        from_ = self.i
        while self.i < len(self.buf) and self.buf[self.i]!= " ":
            self.i += 1
        s = "".join(self.buf[from_:self.i])
        self.i += 1
        return s

    def nextLine(self):
        self.readLine()
        s = "".join(self.buf[self.i:])
        self.i = len(self.buf)
        return s

#bufio Writer initialization
writer = sys.stdout

#next wraps the reader.next() function.
def next():
    return reader.next()

#nextInt reads the next token as an integer.
def nextInt():
    return int(next())

#nextLine wraps the reader.nextLine() function.
def nextLine():
    return reader.nextLine()

#out prints the arguments to the output with a newline.
def out(*a):
    print(*a, file=writer)

#max returns the maximum of two integers.
def max(x, y):
    if x > y:
        return x
    return y

#min returns the minimum of two integers.
def min(x, y):
    if x < y:
        return x
    return y

#joinInts joins an array of integers into a string with a separator.
def joinInts(a, sep):
    return sep.join(map(str, a))

#divUp returns the ceiling of the division of x by y.
def divUp(x, y):
    return (x + y - 1) // y

#Main function
def main():
    solve()
    writer.flush()

#Solve function
#Reads the number of elements N.
#Reads N pairs of integers T and A.
#Iteratively adjusts t and a to ensure the ratios are maintained.
#Outputs the sum of t and a after all adjustments.
def solve():
    N = nextInt()
    T = []
    A = []
    for i in range(N):
        T.append(nextInt())
        A.append(nextInt())
    t = T[0]
    a = A[0]
    for i in range(1, N):
        r = max(math.ceil(t / T[i]), math.ceil(a / A[i]))
        t = T[i] * r
        a = A[i] * r
    out(t + a)

main()




import sys
import math

# bufReader is a struct to efficiently read input.
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
                break
            self.buf.extend(line)

    def next(self):
        self.readLine()
        from_ = self.i
        while self.i < len(self.buf) and self.buf[self.i]!='':
            self.i += 1
        s = ''.join(self.buf[from_:self.i])
        self.i += 1
        return s

    def nextLine(self):
        self.readLine()
        s = ''.join(self.buf[self.i:])
        self.i = len(self.buf)
        return s

# Initialize global reader and writer for input and output operations.
reader = bufReader()
writer = sys.stdout

# next is a wrapper for reader.next().
def next():
    return reader.next()

# nextInt64 reads the next token as an int64.
def nextInt64():
    i = int(next())
    return i

# nextInt reads the next token as an int.
def nextInt():
    return int(nextInt64())

# nextLine is a wrapper for reader.nextLine().
def nextLine():
    return reader.nextLine()

# out prints the arguments to the output.
def out(*a):
    print(*a, file=writer)

# max64 returns the maximum of two int64 values.
def max64(x, y):
    if x > y:
        return x
    return y

# max returns the maximum of two int values.
def max(x, y):
    return int(max64(x, y))

# min64 returns the minimum of two int64 values.
def min64(x, y):
    if x < y:
        return x
    return y

# min returns the minimum of two int values.
def min(x, y):
    return int(min64(x, y))

# abs64 returns the absolute value of an int64.
def abs64(x):
    if x < 0:
        return -x
    return x

# abs returns the absolute value of an int.
def abs(x):
    return int(abs64(x))

# joinInt64s joins an array of int64 values into a string with a separator.
def joinInt64s(a, sep):
    b = [str(v) for v in a]
    return sep.join(b)

# joinInts joins an array of int values into a string with a separator.
def joinInts(a, sep):
    b = [str(v) for v in a]
    return sep.join(b)

# divUp64 returns the ceiling of the division of x by y.
def divUp64(x, y):
    return (x + y - 1) // y

# divUp returns the ceiling of the division of x by y.
def divUp(x, y):
    return int(divUp64(x, y))

# gcd64 returns the greatest common divisor of two int64 values.
def gcd64(x, y):
    if x < y:
        x, y = y, x
    while y!= 0:
        x, y = y, x % y
    return x

# gcd returns the greatest common divisor of two int values.
def gcd(x, y):
    return int(gcd64(x, y))

# lcm64 returns the least common multiple of two int64 values.
def lcm64(x, y):
    return x * y // gcd64(x, y)

# lcm returns the least common multiple of two int values.
def lcm(x, y):
    return int(lcm64(x, y))

# pow64 returns the result of raising x to the power of y.
def pow64(x, y):
    return int(pow(x, y))

# pow returns the result of raising x to the power of y.
def pow(x, y):
    return int(pow(x, y))

# main function calls solve and flushes the writer at the end.
def main():
    solve()
    writer.flush()

# solve function implements the main logic of the program.
def solve():
    N, _ = nextInt(), nextInt()
    A = [nextInt() for _ in range(N)]
    maxProfit = 0
    maxCnt = 0
    maxA = A[-1]
    for i in range(N - 2, -1, -1):
        profit = max(0, maxA - A[i])
        if maxProfit < profit:
            maxProfit = profit
            maxCnt = 1
        elif maxProfit == profit:
            maxCnt += 1
        maxA = max(maxA, A[i])
    out(maxCnt)

main()


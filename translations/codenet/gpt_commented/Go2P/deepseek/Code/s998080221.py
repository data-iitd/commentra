import sys
import math

# Initialize a global bufReader instance for reading input
class bufReader:
    def __init__(self):
        self.r = sys.stdin.readline
        self.buf = []
        self.i = 0

# Initialize a global writer for output
writer = sys.stdout.write

# next reads the next token from the buffer
def next():
    global reader
    reader.buf = reader.r().split()
    reader.i = 0
    return reader.buf[reader.i]

# nextInt reads the next token as an int
def nextInt():
    return int(next())

# nextLine reads the next full line from the buffer
def nextLine():
    return reader.r().strip()

# out writes the output to the writer
def out(a, **kwargs):
    print(a, **kwargs)

# max64 returns the maximum of two int64 values
def max64(x, y):
    return x if x > y else y

# max returns the maximum of two int values
def max(x, y):
    return max64(x, y)

# min64 returns the minimum of two int64 values
def min64(x, y):
    return x if x < y else y

# min returns the minimum of two int values
def min(x, y):
    return min64(x, y)

# abs64 returns the absolute value of an int64
def abs64(x):
    return -x if x < 0 else x

# abs returns the absolute value of an int
def abs(x):
    return abs64(x)

# joinInt64s joins a slice of int64s into a string with a separator
def joinInt64s(a, sep):
    return sep.join(str(v) for v in a)

# joinInts joins a slice of ints into a string with a separator
def joinInts(a, sep):
    return sep.join(str(v) for v in a)

# divUp64 performs ceiling division on two int64 values
def divUp64(x, y):
    return (x + y - 1) // y

# divUp performs ceiling division on two int values
def divUp(x, y):
    return divUp64(x, y)

# gcd64 computes the greatest common divisor of two int64 values
def gcd64(x, y):
    while y != 0:
        x, y = y, x % y
    return x

# gcd computes the greatest common divisor of two int values
def gcd(x, y):
    return gcd64(x, y)

# lcm64 computes the least common multiple of two int64 values
def lcm64(x, y):
    return x * y // gcd64(x, y)

# lcm computes the least common multiple of two int values
def lcm(x, y):
    return lcm64(x, y)

# pow64 computes x raised to the power of y for int64 values
def pow64(x, y):
    return int(math.pow(x, y))

# pow computes x raised to the power of y for int values
def pow(x, y):
    return pow64(x, y)

# Initialize a global bufReader instance for reading input
reader = bufReader()

# main function to execute the program
def main():
    solve()
    sys.stdout.flush()

# solve function to compute the maximum profit and count
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

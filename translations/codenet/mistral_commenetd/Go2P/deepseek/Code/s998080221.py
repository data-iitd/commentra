import sys
import math

def read_line():
    return sys.stdin.readline().strip()

def next():
    return reader.next()

def next_int():
    return int(next())

def next_int64():
    return int(next())

def next_line():
    return reader.next_line()

def out(*a, **kw):
    print(*a, **kw, file=sys.stdout)

def max64(x, y):
    return x if x > y else y

def max(x, y):
    return max64(x, y)

def min64(x, y):
    return x if x < y else y

def min(x, y):
    return min64(x, y)

def abs64(x):
    return -x if x < 0 else x

def abs(x):
    return abs64(x)

def join_int64s(a, sep):
    return sep.join(str(v) for v in a)

def join_ints(a, sep):
    return sep.join(str(v) for v in a)

def div_up64(x, y):
    return (x + y - 1) // y

def div_up(x, y):
    return div_up64(x, y)

def gcd64(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def gcd(x, y):
    return gcd64(x, y)

def lcm64(x, y):
    gcd_val = gcd64(x, y)
    return x * y // gcd_val

def lcm(x, y):
    return lcm64(x, y)

def pow64(x, y):
    return int(math.pow(x, y))

def pow(x, y):
    return pow64(x, y)

reader = (line for line in sys.stdin)

def main():
    solve()

def solve():
    N, K = next_int(), next_int()
    A = [next_int() for _ in range(N)]
    max_profit = 0
    max_cnt = 0
    max_A = A[-1]
    for i in range(N - 2, -1, -1):
        profit = max(0, max_A - A[i])
        if max_profit < profit:
            max_profit = profit
            max_cnt = 1
        elif max_profit == profit:
            max_cnt += 1
        max_A = max(max_A, A[i])
    out(max_cnt)

main()

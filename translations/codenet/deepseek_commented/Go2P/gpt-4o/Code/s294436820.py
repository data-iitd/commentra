import sys
from itertools import product

DEBUG = False

# -----------------------------------------------------------------------------

# IO helper functions

def set_interactive(w, r):
    global output_writer
    output_writer = w

def set_output(w):
    global output_writer
    output_writer = w

def flush():
    if hasattr(output_writer, 'flush'):
        output_writer.flush()

def is_space(c):
    return c in ('\t', '\n', '\v', '\f', '\r', ' ')

def is_new_line(c):
    return c in ('\n', '\r')

def set_input(r):
    global input_reader
    input_reader = r

def readb():
    return next_token()

def reads():
    return readb().decode()

def readbln():
    return next_line()

def readsln():
    return readbln().decode()

def readll():
    return int(reads())

def readi():
    return int(readll())

def readf():
    return float(reads())

def printf(f, *args):
    return output_writer.write(f % args)

def println(*args):
    return output_writer.write(' '.join(map(str, args)) + '\n')

def eprintf(f, *args):
    return sys.stderr.write(f % args)

def eprintln(*args):
    return sys.stderr.write(' '.join(map(str, args)) + '\n')

def debugf(f, *args):
    if DEBUG:
        eprintf(f, *args)

def debug(*args):
    if DEBUG:
        eprintln(*args)

# -----------------------------------------------------------------------------

# Utilities

def sum_slice(a):
    return sum(a)

def sum_slicell(a):
    return sum(a)

def read_ints(N=0):
    if N == 0:
        N = readi()
    return N, [readi() for _ in range(N)]

def read_intsll(N=0):
    if N == 0:
        N = readi()
    return N, [readll() for _ in range(N)]

# -----------------------------------------------------------------------------

# Simple math functions

INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

def min(a, b):
    return a if a < b else b

def minll(a, b):
    return a if a < b else b

def minf(a, b):
    return a if a < b else b

def max(a, b):
    return b if a < b else a

def maxll(a, b):
    return b if a < b else a

def maxf(a, b):
    return b if a < b else a

def abs(a):
    return -a if a < 0 else a

def absll(a):
    return -a if a < 0 else a

def absf(a):
    return -a if a < 0 else a

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = egcd(b, a % b)
    return d, y, x - a // b * y

def egcdll(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = egcdll(b, a % b)
    return d, y, x - a // b * y

def gcd(a, b):
    d, _, _ = egcd(a, b)
    return d

def gcdll(a, b):
    d, _, _ = egcdll(a, b)
    return d

# set up IO functions
input_reader = sys.stdin.buffer
output_writer = sys.stdout.buffer

set_input(input_reader)
set_output(output_writer)

def main():
    h, w, k = readi(), readi(), readi()
    m = []
    for _ in range(h):
        s = reads()
        m.append([int(c) for c in s])

    answer = solve(h, w, k, m)
    println(answer)

Black = 35

def count_black(h, w, m):
    count = 0
    debug("new table")
    for i in range(h):
        for j in range(w):
            if m[i][j] == Black:
                count += 1
        debug(m[i])
    debug("result : ", count)
    return count

def solve(h, w, a, m):
    result = 0
    for i in range(1 << h):
        for k in range(1 << w):
            tmp = [row[:] for row in m]
            for j in range(h):
                if (1 << j) & i:
                    debug("painted ", j, 1 << j, i, (1 << j) & i)
                    for l in range(w):
                        tmp[j][l] = 1
            for j in range(w):
                if (1 << j) & k:
                    for l in range(h):
                        tmp[l][j] = 1
            debug("i", bin(i))
            debug("k", bin(k))
            if count_black(h, w, tmp) == a:
                result += 1
    return result

if __name__ == "__main__":
    main()

flush()
# <END-OF-CODE>

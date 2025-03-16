import sys
from itertools import product

DEBUG = False

# -----------------------------------------------------------------------------

# IO helper functions

def set_interactive():
    global next_token, output_writer
    next_token = sys.stdin.read
    output_writer = sys.stdout

def set_output():
    global output_writer
    output_writer = sys.stdout

def flush():
    if hasattr(output_writer, 'flush'):
        output_writer.flush()

def is_space(c):
    return c in ('\t', '\n', '\v', '\f', '\r', ' ')

def is_new_line(c):
    return c in ('\n', '\r')

def set_input():
    global next_token
    next_token = sys.stdin.read

def readb():
    token = next_token().split()
    if not token:
        raise EOFError
    return token[0].encode()

def reads():
    return readb().decode()

def readbln():
    line = next_token().splitlines()
    if not line:
        raise EOFError
    return line[0].encode()

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

def read_ints(N):
    if N == 0:
        N = readi()
    a = [readi() for _ in range(N)]
    return N, a

def read_intsll(N):
    if N == 0:
        N = readi()
    a = [readll() for _ in range(N)]
    return N, a

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

# Set up IO functions
set_input()
set_output()

# main function to execute the program logic
def main():
    flush()
    h, w, k = readi(), readi(), readi()
    m = [list(map(int, reads().strip())) for _ in range(h)]

    answer = solve(h, w, k, m)
    println(answer)

def count_black(h, w, m):
    count = 0
    debug("new table")
    for i in range(h):
        for j in range(w):
            if m[i][j] == 35:  # Black
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
                    for l in range(w):
                        tmp[j][l] = 1
            for j in range(w):
                if (1 << j) & k:
                    for l in range(h):
                        tmp[l][j] = 1
            debug("i", bin(i)[2:])
            debug("k", bin(k)[2:])
            if count_black(h, w, tmp) == a:
                result += 1
    return result

if __name__ == "__main__":
    main()

# <END-OF-CODE>

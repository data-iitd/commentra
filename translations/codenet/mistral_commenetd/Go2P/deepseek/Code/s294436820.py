import sys
import io
import os
import re
import math
import itertools

# Constants for large prime numbers used in modular arithmetic.
INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

# Global variable for debug mode.
DEBUG = False

# -----------------------------------------------------------------------------
# IO helper functions

# Returns next token from input. It must be initialized by SetInput() before the first call.
def next_token():
    global nextToken
    if callable(nextToken):
        return nextToken()
    raise ValueError("nextToken is not initialized")

def next_line():
    global nextLine
    if callable(nextLine):
        return nextLine()
    raise ValueError("nextLine is not initialized")

# Holds a buffer for output. It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
OutputBuffer = None

# Holds an io.Writer. It must be initialized by SetOutput()
OutputWriter = None

# Set IO functions for interactive input/output.
def set_interactive(w, r):
    set_unbuffered_input(r)
    OutputBuffer = None
    OutputWriter = w

# Setup OutputBuffer and OutputWriter.
def set_output(w):
    global OutputBuffer, OutputWriter
    OutputBuffer = io.BufferedWriter(w)
    OutputWriter = OutputBuffer

# Flushes OutputBuffer
def flush():
    if OutputBuffer is not None:
        OutputBuffer.flush()

# Returns true if c is a white space
def is_space(c):
    return c.isspace()

def is_new_line(c):
    return c in '\n\r'

# Setup nextToken with input buffer.
def set_input(r):
    global nextToken
    buf = io.BytesIO()
    b = None

    def rest():
        nonlocal i, b
        while i < len(b) and is_space(b[i]):
            i += 1
        if i == len(b):
            return None, io.ErrUnexpectedEOF
        j = i
        while i < len(b) and not is_space(b[i]):
            i += 1
        return b[j:i], None

    def initial():
        buf.write(r.read())
        b = buf.getvalue()
        nextToken = rest
        return rest()

    nextToken = initial

# Setup nextToken without input buffer.
def set_unbuffered_input(r):
    buf = io.BufferedReader(r)
    b = None

    def rest():
        nonlocal i, b
        if i == len(b):
            b = buf.readline()
            if not b:
                return None, io.EOF
            i = 0
            j = len(b) - 1
            while j >= 0 and is_space(b[j]):
                j -= 1
            b = b[:j+1]
        while i < len(b) and is_space(b[i]):
            i += 1
        j = i
        while i < len(b) and not is_space(b[i]):
            i += 1
        return b[j:i], None

    nextToken = rest

# -----------------------------------------------------------------------------
# IO functions

# Reads next token and return it as bytes
def readb():
    b, err := next_token()
    if err != None:
        raise err
    return b

# Reads next token and return it as string
def reads():
    return readb().decode()

# Read next line as bytes. Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
    b, err := next_line()
    if err != None:
        raise err
    return b

# Read next line as string
def readsln():
    return readbln().decode()

# Reads next token and return it as int64
def readll():
    i, err := strconv.ParseInt(reads(), 10, 64)
    if err != None:
        raise err
    return i

# Reads next token and return it as int
def readi():
    return int(readll())

# Reads next token and return it as float64
def readf():
    f, err := strconv.ParseFloat(reads(), 64)
    if err != None:
        raise err
    return f

# Write args to OutputWriter with the format f
def printf(f, *args):
    return OutputWriter.write(fmt.format(f, *args))

# Write args to OutputWriter without format
def println(*args):
    return OutputWriter.write(fmt.format(*args) + '\n')

# Write args to stderr with the format f
def eprintf(f, *args):
    return sys.stderr.write(fmt.format(f, *args))

# Write args to stderr without format
def eprintln(*args):
    return sys.stderr.write(fmt.format(*args) + '\n')

def debugf(f, *args):
    if not DEBUG:
        return
    return sys.stderr.write(fmt.format(f, *args))

def debug(*args):
    if not DEBUG:
        return
    return sys.stderr.write(fmt.format(*args) + '\n')

# -----------------------------------------------------------------------------
# Utilities

def sum_slice(a):
    res = 0
    for v in a:
        res += v
    return res

def sum_slice_ll(a):
    res = 0
    for v in a:
        res += v
    return res

# -----------------------------------------------------------------------------
# Simple math functions

# min returns the minimum of two integers.
def min(a, b):
    return a if a < b else b

# minll returns the minimum of two int64.
def minll(a, b):
    return a if a < b else b

# minf returns the minimum of two float64.
def minf(a, b):
    return a if a < b else b

# max returns the maximum of two integers.
def max(a, b):
    return a if a > b else b

# maxll returns the maximum of two int64.
def maxll(a, b):
    return a if a > b else b

# maxf returns the maximum of two float64.
def maxf(a, b):
    return a if a > b else b

# abs returns the absolute value of an integer.
def abs(a):
    return a if a >= 0 else -a

# absll returns the absolute value of an int64.
def absll(a):
    return a if a >= 0 else -a

# absf returns the absolute value of a float64.
def absf(a):
    return a if a >= 0 else -a

# egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
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

# gcd returns the greatest common divisor of two integers.
def gcd(a, b):
    d, _, _ = egcd(a, b)
    return d

# gcdll returns the greatest common divisor of two int64.
def gcdll(a, b):
    d, _, _ = egcdll(a, b)
    return d

# -----------------------------------------------------------------------------
# Main function

def init():
    # for non-interactive
    set_input(sys.stdin)
    set_output(sys.stdout)

    # Enable below when interactive. Its ok to leave above intact.
    set_interactive(sys.stdout, sys.stdin)

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
            tmp = [[m[j][l] for l in range(w)] for j in range(h)]
            for j in range(h):
                hPainted = (1 << j) & i
                if hPainted > 0:
                    debug("painted ", j, 1 << j, i, hPainted)
                    for l in range(w):
                        tmp[j][l] = 1
            for j in range(w):
                wPainted = (1 << j) & k
                if wPainted > 0:
                    for l in range(h):
                        tmp[l][j] = 1
            debug("i", bin(i))
            debug("k", bin(k))
            if count_black(h, w, tmp) == a:
                result += 1
    return result

# Constants for black cell representation.
Black = 35

init()

# Read input
h, w, a = readi(), readi(), readi()
m = [list(readsln()) for _ in range(h)]

# Solve the problem
answer = solve(h, w, a, m)

# Print the result
println(answer)

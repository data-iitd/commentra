
#!/usr/bin/env python3

# Package main contains the main function for solving the problem.

# Constants for large prime numbers used in modular arithmetic.
INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

# Global variable for debug mode.
DEBUG = False

# -----------------------------------------------------------------------------
# IO helper functions

# Returns next token from input. It must be initialized by SetInput() before the first call.
nextToken = None
nextLine = None

# Holds a buffer for output. It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
OutputBuffer = None

# Holds an io.Writer. It must be initialized by SetOutput()
OutputWriter = None

# Set IO functions for interactive input/output.
def SetInteractive(w, r):
    SetUnbufferedInput(r)
    global OutputBuffer
    OutputBuffer = None
    global OutputWriter
    OutputWriter = w

# Setup OutputBuffer and OutputWriter.
def SetOutput(w):
    global OutputBuffer
    OutputBuffer = bufio.Writer(w)
    global OutputWriter
    OutputWriter = OutputBuffer

# Flushes OutputBuffer
def Flush():
    if OutputBuffer != None:
        OutputBuffer.flush()

# Returns true if c is a white space
def IsSpace(c):
    if c == '\t' or c == '\n' or c == '\v' or c == '\f' or c == '\r' or c == ' ':
        return True
    return False

def IsNewLine(c):
    if c == '\n' or c == '\r':
        return True
    return False

# Setup nextToken with input buffer.
def SetInput(r):
    global nextToken
    global nextLine
    buf = io.BytesIO()
    b = None

    i = 0
    def rest():
        nonlocal i
        nonlocal b
        for i in range(i, len(b)):
            if IsSpace(b[i]):
                i += 1
                continue
            j = i
            for i in range(i, len(b)):
                if IsSpace(b[i]):
                    break
            return b[j:i]
        return None, io.ErrUnexpectedEOF

    def initial():
        nonlocal b
        nonlocal nextToken
        buf.write(r.read())
        b = buf.getvalue()
        nextToken = rest
        return rest()

    nextToken = initial

    i = 0
    def restLn():
        nonlocal i
        nonlocal b
        for i in range(i, len(b)):
            if IsNewLine(b[i]):
                i += 1
                continue
            j = i
            for i in range(i, len(b)):
                if IsNewLine(b[i]):
                    break
            return b[j:i]
        return None, io.ErrUnexpectedEOF

    def initialLn():
        nonlocal b
        nonlocal nextLine
        buf.write(r.read())
        b = buf.getvalue()
        nextLine = restLn
        return restLn()

    nextLine = initialLn

# Setup nextToken without input buffer.
def SetUnbufferedInput(r):
    global nextToken
    buf = bufio.Reader(r)
    b = None

    i = 0
    def nextToken():
        nonlocal i
        nonlocal b
        if i == len(b):
            b = buf.readline()
            i = 0
            j = len(b) - 1
            for j in range(j, -1, -1):
                if IsSpace(b[j]):
                    break
            b = b[0:j+1]
        for i in range(i, len(b)):
            if IsSpace(b[i]):
                i += 1
                continue
        j = i
        for i in range(i, len(b)):
            if IsSpace(b[i]):
                break
        if i == j:
            return None, io.ErrUnexpectedEOF
        return b[j:i]

# -----------------------------------------------------------------------------
# IO functions

# Reads next token and return it as []byte
def readb():
    b, err = nextToken()
    if err != None:
        raise err
    return b[:len(b):len(b)]

# Reads next token and return it as string
def reads():
    return str(readb(), 'ascii')

# Read next line as []byte. Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
    b, err = nextLine()
    if err != None:
        raise err
    return b[:len(b):len(b)]

# Read next line as string
def readsln():
    return str(readbln(), 'ascii')

# Reads next token and return it as int64
def readll():
    return int(reads())

# Reads next token and return it as int
def readi():
    return int(readll())

# Reads next token and return it as float64
def readf():
    return float(reads())

# Write args to OutputWriter with the format f
def printf(f, *args):
    return OutputWriter.write(f.format(*args).encode('ascii'))

# Write args to OutputWriter without format
def println(*args):
    return OutputWriter.write(str(args).encode('ascii'))

# Write args to stderr with the format f
def eprintf(f, *args):
    return sys.stderr.write(f.format(*args).encode('ascii'))

# Write args to stderr without format
def eprintln(*args):
    return sys.stderr.write(str(args).encode('ascii'))

def debugf(f, *args):
    if not DEBUG:
        return
    sys.stderr.write(f.format(*args).encode('ascii'))

def debug(*args):
    if not DEBUG:
        return
    sys.stderr.write(str(args).encode('ascii'))

# -----------------------------------------------------------------------------
# Utilities

def sumSlice(a):
    res = 0
    for v in a:
        res += v
    return res

def sumSlicell(a):
    res = 0
    for v in a:
        res += v
    return res

# -----------------------------------------------------------------------------
# Simple math functions

# min returns the minimum of two integers.
def min(a, b):
    if a < b:
        return a
    return b

# minll returns the minimum of two int64.
def minll(a, b):
    if a < b:
        return a
    return b

# minf returns the minimum of two float64.
def minf(a, b):
    if a < b:
        return a
    return b

# max returns the maximum of two integers.
def max(a, b):
    if a < b:
        return b
    return a

# maxll returns the maximum of two int64.
def maxll(a, b):
    if a < b:
        return b
    return a

# maxf returns the maximum of two float64.
def maxf(a, b):
    if a < b:
        return b
    return a

# abs returns the absolute value of an integer.
def abs(a):
    if a < 0:
        return -a
    return a

# absll returns the absolute value of an int64.
def absll(a):
    if a < 0:
        return -a
    return a

# absf returns the absolute value of a float64.
def absf(a):
    if a < 0:
        return -a
    return a

# egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
def egcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = egcd(b, a%b)
    return d, y, x - a/b*y

def egcdll(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = egcdll(b, a%b)
    return d, y, x - a/b*y

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
    SetInput(sys.stdin.buffer)
    SetOutput(sys.stdout.buffer)

    # Enable below when interactive. Its ok to leave above intact.
    SetInteractive(sys.stdout.buffer, sys.stdin.buffer)

# Main function for solving the problem.
def main():
    # Read input
    h, w, a = readi(), readi(), readi()
    m = []
    for i in range(h):
        m.append(reads())

    # Solve the problem
    answer = solve(h, w, a, m)

    # Print the result
    println(answer)

# Function to count the number of black cells in a grid.
def countBlack(h, w, m):
    count = 0
    debug("new table")
    for i in range(h):
        for j in range(w):
            if m[i][j] == Black:
                count += 1
        debug(m[i])
    debug("result : ", count)
    return count

# Function to solve the problem.
def solve(h, w, a, m):
    result = 0
    for i in range(1<<h):
        for k in range(1<<w):
            tmp = []
            for j in range(h):
                tmp.append(m[j])
            for j in range(h):
                hPainted = (1 << j & i)
                if hPainted > 0:
                    debug("painted ", j, 1<<j, i, hPainted)
                    for l in range(w):
                        tmp[j][l] = 1
            for j in range(w):
                wPainted = (1 << j & k)
                if wPainted > 0:
                    for l in range(h):
                        tmp[l][j] = 1
            debug("i", bin(i))
            debug("k", bin(k))
            if countBlack(h, w, tmp) == a:
                result += 1
    return result

# Constants for black cell representation.
Black = 35

# 
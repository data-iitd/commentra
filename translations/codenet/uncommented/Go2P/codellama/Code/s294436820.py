
# -*- coding: utf-8 -*-

import sys

# -----------------------------------------------------------------------------

# IO helper functions

# Returns next token from input.  It must be initialized by SetInput()
# before the first call.
nextToken = None
nextLine = None

# Holds a buffer for output.  It must be initialized by SetOutput()
# before the first call.
OutputBuffer = None

# Holds an io.Writer.  It must be initialized by SetOutput()
# before the first call.
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
    if OutputBuffer is not None:
        OutputBuffer.flush()

# Returns true if c is a white space
def IsSpace(c):
    return c in ['\t', '\n', '\v', '\f', '\r', ' ']

def IsNewLine(c):
    return c in ['\n', '\r']

# Setup nextToken with input buffer.
def SetInput(r):
    global nextToken
    global nextLine
    buf = io.BytesIO()
    b = []

    i = 0
    def rest():
        nonlocal i
        while i < len(b) and IsSpace(b[i]):
            i += 1
        if i == len(b):
            raise io.EOFError
        j = i
        while i < len(b) and not IsSpace(b[i]):
            i += 1
        return b[j:i]

    def initial():
        nonlocal b
        nonlocal nextToken
        buf.write(r.read())
        b = buf.getvalue()
        nextToken = rest
        return rest()

    nextToken = initial

    def restLn():
        nonlocal i
        while i < len(b) and IsNewLine(b[i]):
            i += 1
        if i == len(b):
            raise io.EOFError
        j = i
        while i < len(b) and not IsNewLine(b[i]):
            i += 1
        return b[j:i]

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
    buf = io.BufferedReader(r)
    b = []

    i = 0
    def nextToken():
        nonlocal i
        nonlocal b
        if i == len(b):
            b = list(buf.readline())
            i = 0
        while i < len(b) and IsSpace(b[i]):
            i += 1
        j = i
        while i < len(b) and not IsSpace(b[i]):
            i += 1
        if i == j:
            raise io.EOFError
        return b[j:i]

# -----------------------------------------------------------------------------

# IO functions

# Reads next token and return it as []byte
def readb():
    return nextToken()

# Reads next token and return it as string
def reads():
    return str(readb(), 'ascii')

# Read next line as []byte.  Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
    return nextLine()

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
    return OutputWriter.write(f % args)

# Write args to OutputWriter without format
def println(*args):
    return OutputWriter.write(str(args) + '\n')

# Write args to stderr with the format f
def eprintf(f, *args):
    return sys.stderr.write(f % args)

# Write args to stderr without format
def eprintln(*args):
    return sys.stderr.write(str(args) + '\n')

def debugf(f, *args):
    if not DEBUG:
        return
    sys.stderr.write(f % args)

def debug(*args):
    if not DEBUG:
        return
    sys.stderr.write(str(args) + '\n')

# -----------------------------------------------------------------------------

# Utilities

def sumSlice(a):
    return sum(a)

def sumSlicell(a):
    return sum(a)

def readInts(N):
    if N == 0:
        N = readi()
    a = []
    for i in range(N):
        a.append(readi())
    return N, a

def readIntsll(N):
    if N == 0:
        N = readi()
    a = []
    for i in range(N):
        a.append(readll())
    return N, a

# -----------------------------------------------------------------------------

# Simple math functions

INF = 1000000007
INF2 = 1000000009
INF3 = 998244353

def min(a, b):
    if a < b:
        return a
    return b

def minll(a, b):
    if a < b:
        return a
    return b

def minf(a, b):
    if a < b:
        return a
    return b

def max(a, b):
    if a < b:
        return b
    return a

def maxll(a, b):
    if a < b:
        return b
    return a

def maxf(a, b):
    if a < b:
        return b
    return a

def abs(a):
    if a < 0:
        return -a
    return a

def absll(a):
    if a < 0:
        return -a
    return a

def absf(a):
    if a < 0:
        return -a
    return a

# egcd(a, b) returns d, x, y:
#   d is gcd(a,b)
#   x, y are  integers that satisfy ax + by = d
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

def gcd(a, b):
    d, _, _ = egcd(a, b)
    return d

def gcdll(a, b):
    d, _, _ = egcdll(a, b)
    return d

# set up IO functions
def init():
    # for non-interactive
    SetInput(sys.stdin)
    SetOutput(sys.stdout)

    # Enable below when interactive.  Its ok to leave above intact.
    SetInteractive(sys.stdout, sys.stdin)

def main():
    h, w, k = readi(), readi(), readi()
    m = []
    for i in range(h):
        m.append(reads())

    answer = solve(h, w, k, m)
    println(answer)

def solve(h, w, a, m):
    result = 0
    for i in range(1 << h):
        for k in range(1 << w):
            tmp = []
            for j in range(h):
                tmp.append(list(m[j]))
            for j in range(h):
                hPainted = (1 << j & i)
                if hPainted > 0:
                    for l in range(w):
                        tmp[j][l] = '1'
            for j in range(w):
                wPainted = (1 << j & k)
                if wPainted > 0:
                    for l in range(h):
                        tmp[l][j] = '1'
            if countBlack(h, w, tmp) == a:
                result += 1
    return result

def countBlack(h, w, m):
    count = 0
    debug("new table")
    for i in range(h):
        for j in range(w):
            if m[i][j] == '1':
                count += 1
        debug(m[i])
    debug("result : ", count)
    return count

init()
main()

# 
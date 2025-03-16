import sys
import io
import os
import math
import re
import string

DEBUG = False

# -----------------------------------------------------------------------------

# IO helper functions

# nextToken and nextLine are function variables that will be initialized 
# by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
nextToken = None
nextLine = None

# OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
OutputBuffer = None

# OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
OutputWriter = None

def SetInteractive(w, r):
    SetUnbufferedInput(r) # Set unbuffered input for reading
    global OutputBuffer    
    OutputBuffer = None     # No output buffer for interactive mode
    OutputWriter = w        # Set the output writer

def SetOutput(w):
    global OutputBuffer    
    OutputBuffer = io.BufferedWriter(w) # Initialize the output buffer
    OutputWriter = OutputBuffer         # Set the output writer to the buffer

def Flush():
    if OutputBuffer is not None:
        OutputBuffer.flush() # Flush the buffer if it is initialized

def IsSpace(c):
    return c.isspace()

def IsNewLine(c):
    return c == '\n' or c == '\r'

def SetInput(r):
    global nextToken
    buf = io.BytesIO() # Create a new bytes buffer
    b = bytearray()    # Buffer to hold input bytes

    def rest():
        nonlocal b, i
        for i in range(len(b)):
            if IsSpace(chr(b[i])):
                continue # Skip whitespace
        if i == len(b):
            return None, io.ErrUnexpectedEOF # Return error if end of buffer is reached
        j = i
        while i < len(b) and not IsSpace(chr(b[i])):
            i += 1 # Read until whitespace is found
        return b[j:i], None # Return the token

    def initial():
        nonlocal b
        buf.write(r.read()) # Copy input to buffer
        b = bytearray(buf.getvalue()) # Get bytes from the buffer
        nextToken = rest # Set nextToken to the rest function
        return rest()    # Read the first token

    nextToken = initial # Initialize nextToken

def SetUnbufferedInput(r):
    global nextToken
    buf = io.BufferedReader(r) # Create a new buffered reader
    b = bytearray()              # Buffer to hold input bytes

    def rest():
        nonlocal b, i
        if i == len(b): # If the buffer is empty
            b = bytearray(buf.read()) # Read until newline
            i = 0 # Reset index
            j = len(b) - 1
            while 0 <= j and IsSpace(chr(b[j])):
                j -= 1 # Trim trailing whitespace
            b = b[:j+1] # Resize buffer to remove whitespace
        for i in range(len(b)):
            if IsSpace(chr(b[i])):
                continue # Skip whitespace
        j = i
        while i < len(b) and not IsSpace(chr(b[i])):
            i += 1 # Read until whitespace is found
        if i == j:
            return None, io.ErrUnexpectedEOF # Return error if no token found
        return b[j:i], None # Return the token

    nextToken = rest # Initialize nextToken

# -----------------------------------------------------------------------------

# IO functions

def readb():
    b, err = nextToken() # Read the next token
    if err != None:
        raise err # Panic if an error occurs
    return b

def reads():
    return str(readb(), 'utf-8')

def readbln():
    b, err = nextLine() # Read the next line
    if err != None:
        raise err # Panic if an error occurs
    return b

def readsln():
    return str(readbln(), 'utf-8')

def readll():
    i = int(reads()) # Parse the next token as int64
    if err != None:
        raise err.Error() # Panic if parsing fails
    return i

def readi():
    return int(readll())

def readf():
    f = float(reads()) # Parse the next token as float64
    if err != None:
        raise err.Error() # Panic if parsing fails
    return f

def printf(f, *args):
    return print(f % args, file=OutputWriter)

def println(*args):
    return print(*args, file=OutputWriter)

def eprintf(f, *args):
    return print(f % args, file=sys.stderr)

def eprintln(*args):
    return print(*args, file=sys.stderr)

def debugf(f, *args):
    if not DEBUG:
        return
    print(f % args, file=sys.stderr)

def debug(*args):
    if not DEBUG:
        return
    print(*args, file=sys.stderr)

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

def readInts(N=0):
    if N == 0:
        N = readi()
    a = [readi() for _ in range(N)]
    return N, a

def readIntsll(N=0):
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
    return a if a > b else b

def maxll(a, b):
    return a if a > b else b

def maxf(a, b):
    return a if a > b else b

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

# -----------------------------------------------------------------------------

# set up IO functions
def init():
    # Initialize input and output for non-interactive mode
    SetInput(sys.stdin)
    SetOutput(sys.stdout)

    # Uncomment below to enable interactive mode
    # SetInteractive(sys.stdout, sys.stdin)

# -----------------------------------------------------------------------------

# main function to execute the program logic
def main():
    defer(Flush) # Ensure output is flushed at the end
    h, w, k = readi(), readi(), readi()
    m = [list(reads()) for _ in range(h)]

    answer = solve(h, w, k, m)
    println(answer)

const Black = 35

def countBlack(h, w, m):
    count = 0
    debug("new table")
    for i in range(h):
        for j in range(w):
            if m[i][j] == chr(Black):
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
                if i & (1 << j):
                    debug("painted ", j, 1 << j, i, i & (1 << j))
                    for l in range(w):
                        tmp[j][l] = '#'
            for j in range(w):
                if k & (1 << j):
                    for l in range(h):
                        tmp[l][j] = '#'
            debug("i", bin(i))
            debug("k", bin(k))
            if countBlack(h, w, tmp) == a:
                result += 1
    return result

init()
main()

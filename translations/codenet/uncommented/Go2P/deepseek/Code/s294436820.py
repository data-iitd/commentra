import sys
import io
import os
import re
import math
import itertools
import functools
import bisect
import array
import types
import heapq
import sys
from io import BytesIO, IOBase
from typing import List, Optional, Tuple, Set, Dict, Sequence, Any

# IO helper functions

DEBUG = False

# Returns next token from input.  It must be initialized by SetInput()
# before the first call.
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

# Holds a buffer for output.  It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter
# instead of this.
OutputBuffer = None

# Holds an io.Writer.  It must be initialized by SetOutput()
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

def flush():
    if OutputBuffer is not None:
        OutputBuffer.flush()

# Returns true if c is a white space
def is_space(c):
    return c.isspace()

def is_new_line(c):
    return c == '\n' or c == '\r'

# Setup nextToken with input buffer.
def set_input(r):
    global nextToken
    buf = io.BytesIO()
    b = None

    def rest():
        nonlocal i
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

    i = 0
    nextToken = initial

# Setup nextToken without input buffer.
def set_unbuffered_input(r):
    global nextToken
    buf = io.BufferedReader(r)

    def rest():
        var err = None
        if i == len(b):
            b, err = buf.read(1024)
            if err != None:
                return None, err
            i = 0
        while i < len(b) and is_space(b[i]):
            i += 1
        if i == len(b):
            return None, io.ErrUnexpectedEOF
        j = i
        while i < len(b) and not is_space(b[i]):
            i += 1
        return b[j:i], None

    i = 0
    nextToken = rest

# IO functions

# Reads next token and return it as bytes
def readb():
    b = next_token()
    if b is None:
        raise ValueError("No more tokens")
    return b

# Reads next token and return it as string
def reads():
    return readb().decode('utf-8')

# Read next line as bytes.  Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
    b = next_line()
    if b is None:
        raise ValueError("No more lines")
    return b

# Read next line as string
def readsln():
    return readbln().decode('utf-8')

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
    return print(f % args, file=OutputWriter)

# Write args to OutputWriter without format
def println(*args):
    return print(*args, file=OutputWriter)

# Write args to stderr with the format f
def eprintf(f, *args):
    return print(f % args, file=sys.stderr)

# Write args to stderr without format
def eprintln(*args):
    return print(*args, file=sys.stderr)

def debugf(f, *args):
    if not DEBUG:
        return
    return eprintf(f, *args)

def debug(*args):
    if not DEBUG:
        return
    return eprintln(*args)

# Utilities

def sum_slice(a):
    return sum(a)

def sum_slicell(a):
    return sum(a)

def read_ints(N=0):
    if N == 0:
        N = readi()
    a = [readi() for _ in range(N)]
    return N, a

def read_intsll(N=0):
    if N == 0:
        N = readi()
    a = [readll() for _ in range(N)]
    return N, a

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
    return a if a >= 0 else -a

def absll(a):
    return a if a >= 0 else -a

def absf(a):
    return a if a >= 0 else -a

# egcd(a, b) returns d, x, y:
#   d is gcd(a,b)
#   x, y are  integers that satisfy ax + by = d
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
def init():
    # for non-interactive
    set_input(sys.stdin)
    set_output(sys.stdout)

    # Enable below when interactive.  Its ok to leave above intact.
    set_interactive(sys.stdout, sys.stdin)

def main():
    h, w, k = readi(), readi(), readi()
    m = [list(readsln()) for _ in range(h)]

    answer = solve(h, w, k, m)
    println(answer)

const Black = 35

def count_black(h, w, m):
    count = 0
    for i in range(h):
        for j in range(w):
            if m[i][j] == chr(Black):
                count += 1
    return count

def solve(h, w, a, m):
    result = 0
    for i in range(1 << h):
        for k in range(1 << w):
            tmp = [row[:] for row in m]
            for j in range(h):
                if i & (1 << j):
                    for l in range(w):
                        tmp[j][l] = chr(Black)
            for j in range(w):
                if k & (1 << j):
                    for l in range(h):
                        tmp[l][j] = chr(Black)
            if count_black(h, w, tmp) == a:
                result += 1
    return result

# <END-OF-CODE>
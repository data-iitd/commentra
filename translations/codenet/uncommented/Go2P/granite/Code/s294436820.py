

import sys

DEBUG = False

# -----------------------------------------------------------------------------

# IO helper functions

# Returns next token from input.  It must be initialized by SetInput()
# before the first call.
nextToken = None

# Holds a buffer for output.  It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter
# instead of this.
OutputBuffer = None
OutputWriter = None

# Set IO functions for interactive input/output.
def SetInteractive(w, r):
    SetUnbufferedInput(r)
    global OutputBuffer, OutputWriter
    OutputBuffer = None
    OutputWriter = w

# Setup OutputBuffer and OutputWriter.
def SetOutput(w):
    global OutputBuffer, OutputWriter
    OutputBuffer = sys.stdout.buffer
    OutputWriter = OutputBuffer

# Flushes OutputBuffer
def Flush():
    if OutputBuffer!= None:
        OutputBuffer.flush()

# Returns true if c is a white space
def IsSpace(c):
    return c =='' or c == '\t' or c == '\n' or c == '\v' or c == '\f' or c == '\r'

def IsNewLine(c):
    return c == '\n' or c == '\r'

# Setup nextToken with input buffer.
def SetInput(r):
    buf = bytearray()
    i = 0
    rest = lambda: buf[i:].split(b' ', 1)[0]
    initial = lambda: buf.extend(r.read(1024))
    nextToken = initial
    restLn = lambda: buf[i:].split(b'\n', 1)[0]
    initialLn = lambda: buf.extend(r.read(1024))
    nextLine = initialLn

# Setup nextToken without input buffer.
def SetUnbufferedInput(r):
    buf = bytearray()
    i = 0
    nextToken = lambda: buf.extend(r.read(1))
    nextLine = lambda: buf.extend(r.read(1024))

# -----------------------------------------------------------------------------

# IO functions

# Reads next token and return it as []byte
def readb():
    b = nextToken()
    return b

# Reads next token and return it as string
def reads():
    return b.decode('utf-8')

# Read next line as []byte.  Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
    b = nextLine()
    return b

# Read next line as string
def readsln():
    return b.decode('utf-8')

# Reads next token and return it as int64
def readll():
    return int(reads())

# Reads next token and return it as int
def readi():
    return int(reads())

# Reads next token and return it as float64
def readf():
    return float(reads())

# Write args to OutputWriter with the format f
def printf(f, *args):
    return OutputWriter.write(f.format(*args).encode('utf-8'))

# Write args to OutputWriter without format
def println(*args):
    return OutputWriter.write(b' '.join(str(a).encode('utf-8') for a in args) + b'\n')

# Write args to stderr with the format f
def eprintf(f, *args):
    return sys.stderr.write(f.format(*args).encode('utf-8'))

# Write args to stderr without format
def eprintln(*args):
    return sys.stderr.write(b' '.join(str(a).encode('utf-8') for a in args) + b'\n')

def debugf(f, *args):
    if not DEBUG:
        return
    return sys.stderr.write(f.format(*args).encode('utf-8'))

def debug(*args):
    if not DEBUG:
        return
    return sys.stderr.write(b' '.join(str(a).encode('utf-8') for a in args) + b'\n')

# -----------------------------------------------------------------------------

# Utilities

def sumSlice(a):
    return sum(a)

def sumSlicell(a):
    return sum(a)

def readInts(N=None):
    if N == None:
        N = readi()
    a = []
    for i in range(N):
        a.append(readi())
    return N, a

def readIntsll(N=None):
    if N == None:
        N = readi()
    a = []
    for i in range(N):
        a.append(readll())
    return N, a

# -----------------------------------------------------------------------------

# Simple math functions

const (
    # big prime
    INF  = 1000000007
    INF2 = 1000000009
    INF3 = 998244353
)

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
    d, _, _ := egcd(a, b)
    return d

def gcdll(a, b):
    d, _, _ := egcdll(a, b)
    return d

# set up IO functions
func init() {
    // for non-interactive
    SetInput(os.Stdin)
    SetOutput(os.Stdout)

    // Enable below when interactive.  Its ok to leave above intact.
    SetInteractive(os.Stdout, os.Stdin)
}

func main() {
    defer Flush()
    h, w, k := readi(), readi(), readi()
    m := make([][]int, h)
    for i := 0; i < h; i++ {
        m[i] = make([]int, w)
        s := reads()
        for j := 0; j < w; j++ {
            m[i][j] = int(s[j])
        }
    }
    answer := solve(h, w, k, m)
    println(answer)
}

const Black int = 35

func countBlack(h, w int, m [][]int

func solve(h, w, a int, m [][]int

func main() {
    defer Flush()
    for i := 0; i < 1<<h; i++ {
        for k := 0; k < 1<<w; k++ {
            for l := 0; l < w; l++ {
                for m := 0; m < h; m++ {
                    for n := 0; n < w; n++ {
                        for o := 0; o < h; o++ {
                            for p := 0; p < w; p++ {
                                for q := 0; q < h; q++ {
                                    for r := 0; r < w; r++ {
                                        for s := 0; s < h; s++ {
                                            for t := 0; t < w; t++ {
                                                for u := 0; u < h; u++ {
                                                    for v := 0; v < w; v++ {
                                                        for w := 0; w < h; w++ {
                                                            for x := 0; x < w; x++ {
                                                                for y := 0; y < h; y++ {
                                    for z := 0; z < w; z++ {
                                        for a := 0; a < h; a++ {
                                            for b := 0; b < w; b++ {
                                                for c := 0; c < h; c++ {
                                                    for d := 0; d < w; d++ {
                                                        for e := 0; e < h; e++ {
                                                            for f := 0; f < w; f++ {
                                                                for g := 0; g < h; g++ {
                                    for h := 0; h < w; h++ {
                                        for i := 0; i < h; i++ {
                                            for j := 0; j < w; j++ {
                                                for k := 0; k < h; k++ {
                                                    for l := 0; l < w; l++ {
                                                        for m := 0; m < h; m++ {
                                                            for n := 0; n < w; n++ {
                                                                for o := 0; o < h; o++ {
                                    for p := 0; p < w; p++ {
                                        for q := 0; q < h; q++ {
                                            for r := 0; r < w; r++ {
                                                for s := 0; s < h; s++ {
                                                    for t := 0; t < w; t++ {
                                                        for u := 0; u < h; u++ {
                                                            for v := 0; v < w; v++ {
    // for w := 0; w < h; w++ {
                                        for x := 0; x < w; x++ {
                                            for y := 0; y < h; y++ {
                                                for z := 0; z < w; z++ {
                                                    for a := 0; a < h; a++ {
                                                        for b := 0; b < w; b++ {
                                                            for c := 0; c < h; c++ {
    // for d := 0; d < w; d++ {
    // for e := 0; e < h; e++ {
                                        for f := 0; f < w; f++ {
                                            for g := 0; g < h; g++ {
                                                for h := 0; h < w; h++ {
                                                    for i := 0; i < h; i++ {
                                                        for j := 0; j < w; j++ {
    // for k := 0; k < h; k++ {
    // for l := 0; l < h; l++ {
                                            for m := 0; m < h; m++ {
                                                for n := 0; n < h; n++ {
                                                    for o := 0; o < h; o++ {
                                                        for p := 0; p < h; p++ {
    // for q := 0; q < h; q++ {
    // for r := 0; r < h; r++ {
                                            for s := 0; s < h; s++ {
                                                for t := 0; t < h; t++ {
    // for u := 0; u < h; u++ {
                                                    for v := 0; v < h; v++ {
                                                for w := 0; w < h; w++ {
        for x := 0; x < h; x++ {
            for y := 0; y < h; y++ {
                for z := 0; z < h; z++ {
                    for a := 0; a < h; a++ {
        for b := 0; b < h; b++ {
        for c := 0; c < h; c++ {
            for d

# Package main defines the entry point of the program.
# Importing necessary libraries for the program.
import (
    "bufio"
    "errors"
    "fmt"
    "io"
    "math"
    "os"
    "strconv"
)



# Constants used in the program.
MOD          = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64    = math.MaxInt64
INF_BIT60    = 1 << 60
INF_INT32    = math.MaxInt32
INF_BIT30    = 1 << 30
NIL          = -1
WHITE        = 0
GRAY         = 1
BLACK        = 2



# init function initializes the input reader and output writer.
def init():
    ReadString = newReadString(os.Stdin, bufio.ScanWords)
    stdout = bufio.NewWriter(os.Stdout)

# Main function reads input, processes the data, and prints the result.
def main():
    S = ReadRuneSlice()
    x, y = ReadInt2()

    F = []int()
    cur = 0
    for i in range(len(S)):
        if S[i] == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)
    PrintfDebug("%v\n", F)

    evens, odds = [], []
    for i in range(len(F)):
        if i%2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    dpx = [[False for i in range(18001)] for j in range(len(evens)+1)]
    dpy = [[False for i in range(18001)] for j in range(len(odds)+1)]

    dpx[0][10000], dpy[0][10000] = True, True
    for i in range(len(evens)):
        val = evens[i]
        for j in range(2000, 18000):
            if j+val <= 18000:
                dpx[i+1][j+val] = dpx[i+1][j+val] or dpx[i][j]
            if j-val >= 2000 and i!= 0:
                dpx[i+1][j-val] = dpx[i+1][j-val] or dpx[i][j]
    for i in range(len(odds)):
        val = odds[i]
        for j in range(2000, 18000):
            if j+val <= 18000:
                dpy[i+1][j+val] = dpy[i+1][j+val] or dpy[i][j]
            if j-val >= 2000:
                dpy[i+1][j-val] = dpy[i+1][j-val] or dpy[i][j]

    if dpx[len(evens)][x+10000] and dpy[len(odds)][y+10000]:
        fmt.Println("Yes")
    else:
        fmt.Println("No")

# ReadString returns a WORD string.
var ReadString func() string
var stdout *bufio.Writer

def newReadString(ior io.Reader, sf bufio.SplitFunc) func() string:
    r = bufio.NewScanner(ior)
    r.Buffer(make([]byte, 1024), int(1e+9))
    r.Split(sf)

    return func() string:
        if not r.Scan():
            panic("Scan failed")
        return r.Text()

# ReadInt returns an integer.
def ReadInt() int:
    return int(readInt64())

def ReadInt2() (int, int):
    return int(readInt64()), int(readInt64())

def ReadInt3() (int, int, int):
    return int(readInt64()), int(readInt64()), int(readInt64())

def ReadInt4() (int, int, int, int):
    return int(readInt64()), int(readInt64()), int(readInt64()), int(readInt64())

def ReadInt64() int64:
    return readInt64()

def ReadInt64_2() (int64, int64):
    return readInt64(), readInt64()

def ReadInt64_3() (int64, int64, int64):
    return readInt64(), readInt64(), readInt64()

def ReadInt64_4() (int64, int64, int64, int64):
    return readInt64(), readInt64(), readInt64(), readInt64()

def readInt64() int64:
    i, err = strconv.ParseInt(ReadString(), 0, 64)
    if err!= nil:
        panic(err.Error())
    return i

def ReadIntSlice(n int) []int:
    b = make([]int, n)
    for i in range(n):
        b[i] = ReadInt()
    return b

def ReadInt64Slice(n int) []int64:
    b = make([]int64, n)
    for i in range(n):
        b[i] = ReadInt64()
    return b

def ReadFloat64() float64:
    return float64(readFloat64())

def readFloat64() float64:
    f, err = strconv.ParseFloat(ReadString(), 64)
    if err!= nil:
        panic(err.Error())
    return f

def ReadFloat64Slice(n int) []float64:
    b = make([]float64, n)
    for i in range(n):
        b[i] = ReadFloat64()
    return b

def ReadRuneSlice() []rune:
    return []rune(ReadString())

def ZeroPaddingRuneSlice(n, digitsNum int) []rune:
    sn = fmt.Sprintf("%b", n)

    residualLength = digitsNum - len(sn)
    if residualLength <= 0:
        return []rune(sn)

    zeros = make([]rune, residualLength)
    for i in range(len(zeros)):
        zeros[i] = '0'

    res = []rune{}
    res = append(res, zeros...)
    res = append(res, []rune(sn)...)

    return res

def Strtoi(s string) int:
    if i, err := strconv.Atoi(s); err!= nil:
        panic(errors.New("[argument error]: Strtoi only accepts integer string"))
    else:
        return i

def PrintIntsLine(A...int) string:
    res = []rune{}

    for i in range(len(A)):
        str = strconv.Itoa(A[i])
        res = append(res, []rune(str)...)

        if i!= len(A)-1:
            res = append(res,'')

    return string(res)

def PrintInts64Line(A...int64) string:
    res = []rune{}

    for i in range(len(A)):
        str = strconv.FormatInt(A[i], 10)
        res = append(res, []rune(str)...)

        if i!= len(A)-1:
            res = append(res,'')

    return string(res)

def PrintfDebug(format string, a...interface{}):
    fmt.Fprintf(os.Stderr, format, a...)

def PrintfBufStdout(format string, a...interface{}):
    fmt.Fprintf(stdout, format, a...)


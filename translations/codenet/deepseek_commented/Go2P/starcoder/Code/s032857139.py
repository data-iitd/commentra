
# Package main defines the entry point of the application.
import (
    "bufio"
    "errors"
    "fmt"
    "io"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

# I/O functions for reading input efficiently.
def ReadString() string:
    ior = os.Stdin
    if ior.isatty():
        ior = bufio.NewReader(os.Stdin)
    return ior.readline().rstrip()

def ReadInt() int:
    return int(readInt64())

def readInt64() int64:
    i, err = strconv.ParseInt(ReadString(), 0, 64)
    if err!= None:
        raise RuntimeError(err.message)
    return i

def ReadIntSlice(n int) []int:
    b = make([]int, n)
    for i in range(n):
        b[i] = ReadInt()
    return b

def ReadRuneSlice() []rune:
    return []rune(ReadString())

# Utility functions for dynamic programming.
def ChMin(updatedValue, target):
    if updatedValue > target:
        updatedValue = target
        return True
    return False

def ChMax(updatedValue, target):
    if updatedValue < target:
        updatedValue = target
        return True
    return False

def GetNthBit(num, nth):
    return num >> uint(nth) & 1

# Arithmetic functions for mathematical operations.
def Max(integers):
    m = integers[0]
    for i, integer in enumerate(integers):
        if i == 0:
            continue
        if m < integer:
            m = integer
    return m

def Min(integers):
    m = integers[0]
    for i, integer in enumerate(integers):
        if i == 0:
            continue
        if m > integer:
            m = integer
    return m

def CeilInt(a, b):
    res = a / b
    if a%b > 0:
        res += 1
    return res

def FloorInt(a, b):
    res = a / b
    return res

def PowInt(a, e):
    if a < 0 or e < 0:
        raise RuntimeError("[argument error]: PowInt does not accept negative integers")

    if e == 0:
        return 1

    if e%2 == 0:
        halfE = e / 2
        half = PowInt(a, halfE)
        return half * half

    return a * PowInt(a, e-1)

def AbsInt(a):
    if a < 0:
        return -a
    return a

def Gcd(a, b):
    if a <= 0 or b <= 0:
        raise RuntimeError("[argument error]: Gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a
    for b > 0:
        div = a % b
        a, b = b, div
    return a

def Lcm(a, b):
    if a <= 0 or b <= 0:
        raise RuntimeError("[argument error]: Gcd only accepts two NATURAL numbers")
    gcd = Gcd(a, b)
    return (a / gcd) * b

# Utility functions for string manipulation and permutation.
def DeleteElement(s, i):
    if i < 0 or len(s) <= i:
        raise RuntimeError("[index error]")
    n = make([]int, 0, len(s)-1)
    n = append(n, s[:i]...)
    n = append(n, s[i+1:]...)
    return n

def Concat(s, t):
    n = make([]rune, 0, len(s)+len(t))
    n = append(n, s...)
    n = append(n, t...)
    return n

def UpperRune(r):
    str = strings.ToUpper(string(r))
    return []rune(str)[0]

def LowerRune(r):
    str = strings.ToLower(string(r))
    return []rune(str)[0]

def ToggleRune(r):
    var str string
    if 'a' <= r and r <= 'z':
        str = strings.ToUpper(string(r))
    elif 'A' <= r and r <= 'Z':
        str = strings.ToLower(string(r))
    else:
        str = string(r)
    return []rune(str)[0]

def ToggleString(s):
    inputRunes = []rune(s)
    outputRunes = make([]rune, 0, len(inputRunes))
    for _, r in enumerate(inputRunes):
        outputRunes = append(outputRunes, ToggleRune(r))
    return string(outputRunes)

def Strtoi(s):
    if i, err = strconv.Atoi(s); err!= None:
        raise RuntimeError("[argument error]: Strtoi only accepts integer string")
    return i

# Functions for generating permutations.
def CalcFactorialPatterns(elements):
    copiedResidual = make([]rune, len(elements))
    copy(copiedResidual, elements)
    return factorialRecursion([], copiedResidual)

def factorialRecursion(interim, residual):
    if len(residual) == 0:
        return [interim]

    res = []
    for idx, elem in enumerate(residual):
        copiedInterim = make([]rune, len(interim))
        copy(copiedInterim, interim)
        copiedInterim = append(copiedInterim, elem)
        copiedResidual = genDeletedSlice(idx, residual)
        res = append(res, factorialRecursion(copiedInterim, copiedResidual)...)
    return res

def genDeletedSlice(delId, S):
    res = []
    res = append(res, S[:delId]...)
    res = append(res, S[delId+1:]...)
    return res

def CalcDuplicatePatterns(elements, digit):
    return duplicateRecursion([], elements, digit)

def duplicateRecursion(interim, elements, digit):
    if len(interim) == digit:
        return [interim]

    res = []
    for i in range(len(elements)):
        copiedInterim = make([]rune, len(interim))
        copy(copiedInterim, interim)
        copiedInterim = append(copiedInterim, elements[i])
        res = append(res, duplicateRecursion(copiedInterim, elements, digit)...)
    return res

# Binary search functions.
def GeneralLowerBound(s, key):
    isOK = lambda index, key: s[index] >= key
    ng, ok = -1, len(s)
    for int(math.Abs(float(ok-ng))) > 1:
        mid = (ok + ng) / 2
        if isOK(mid, key):
            ok = mid
        else:
            ng = mid
    return ok

def GeneralUpperBound(s, key):
    isOK = lambda index, key: s[index] > key
    ng, ok = -1, len(s)
    for int(math.Abs(float(ok-ng))) > 1:
        mid = (ok + ng) / 2
        if isOK(mid, key):
            ok = mid
        else:
            ng = mid
    return ok

# Union-Find data structure.
def InitParents(parents, maxNodeId):
    for i in range(maxNodeId+1):
        parents[i] = i

def unite(x, y, parents):
    xp, yp = root(x, parents), root(y, parents)
    if xp == yp:
        return
    parents[xp] = yp

def same(x, y, parents):
    return root(x, parents) == root(y, parents)

def root(x, parents):
    if parents[x] == x:
        return x
    parents[x] = root(parents[x], parents)
    return parents[x]

# Prime factorization and checking.
def TrialDivision(n):
    if n <= 1:
        raise RuntimeError("[argument error]: TrialDivision only accepts a NATURAL number")

    p = {}
    for i in range(2, n+1):
        exp = 0
        for n%i == 0:
            exp += 1
            n /= i
        if exp == 0:
            continue
        p[i] = exp
    if n > 1:
        p[n] = 1
    return p

def IsPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

# Functions for modular arithmetic.
def CalcNegativeMod(val, m):
    res = val % m
    if res < 0:
        res += m
    return res

def modpow(a, e, m):
    if e == 0:
        return 1
    if e%2 == 0:
        halfE = e / 2
        half = modpow(a, halfE, m)
        return half * half % m
    return a * modpow(a, e-1, m) % m

def CalcModInv(a, m):
    return modpow(a, m-2, m)

# Min-heap implementation using the heap package.
class IntHeap(list):
    def __init__(self, xs):
        super(IntHeap, self).__init__(xs)
        self.heapify()

    def heapify(self):
        for i in reversed(range(len(self))):
            self.down(i)

    def push(self, x):
        self.append(x)
        self.up(len(self) - 1)

    def pop(self):
        self.swap(0, len(self) - 1)
        x = self.pop()
        self.down(0)
        return x

    def top(self):
        return self[0]

    def replace(self, x):
        self.swap(0, len(self) - 1)
        self[-1] = x
        self.down(0)

    def up(self, i):
        for {
            j = (i - 1) / 2
            self[i] < self[j]
        } {
            self.swap(i, j)
            i = j

    def down(self, i):
        for {
            j1 = 2*i + 1
            j2 = 2*i + 2
            if j1 >= len(self):
                break
            if j2 >= len(self):
                j = j1
            elif self[j1] < self[j2]:
                j = j1
            else:
                j = j2
            self[i] < self[j]
        } {
            self.swap(i, j)
            i = j

    def swap(self, i, j):
        self[i], self[j] = self[j], self[i]

# Main function to read input, sort the array, and calculate the answer.
n, x = ReadInt(), ReadInt()
A = ReadIntSlice(n)

A.sort()

ans = 0
for i in range(n):
    if x >= A[i]:
        ans += 1
        x -= A[i]
    else:
        break
if ans == n and x > 0:
    ans -= 1
print(ans)


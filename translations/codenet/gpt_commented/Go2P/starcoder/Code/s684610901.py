
# Define a structure for sorting pairs
class pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

# Implement sort.Interface for pairs
class pairs(list):
    def __init__(self, pairs):
        self.extend(pairs)

    def __lt__(self, other):
        return self[0].index < other[0].index

# Define a structure for sorting int64 slices
class Int64Slice(list):
    def __init__(self, int64s):
        self.extend(int64s)

    def __lt__(self, other):
        return self[0] < other[0]

# Utility functions for sorting int64 slices
def Int64s(a):
    a.sort()

def Int64sSliceAreSorted(a):
    return a == sorted(a)

# Constants for buffer sizes and infinity value
initialBufSize = 1e4
maxBufSize = 1e8
INF = 1e8

# Global variables for input/output handling and direction vectors
scanner = bufio.NewScanner(os.Stdin)
writer = bufio.NewWriter(os.Stdout)
di = [-1, 0, 1, 0] # Direction vectors for row movement
dj = [0, -1, 0, 1] # Direction vectors for column movement

def main():
    # Set up the scanner buffer and read three integers A, B, C
    buf = make([]byte, initialBufSize)
    scanner.Buffer(buf, maxBufSize)
    scanner.Split(bufio.ScanWords)
    A, B, C = readInt(), readInt(), readInt()

    # Check if C is within the range [A, B] and print the result
    if C >= A and C <= B:
        print("Yes")
    else:
        print("No")

# NextPermutation generates the next lexicographical permutation of the given sort.Interface
def NextPermutation(x):
    n = x.Len() - 1
    if n < 1:
        return False
    j = n - 1
    # Find the rightmost ascent
    for ; not x.Less(j, j+1); j--:
        if j == 0:
            return False
    l = n
    # Find the rightmost successor to the pivot
    for not x.Less(j, l):
        l--
    x.Swap(j, l) # Swap the pivot with its successor
    # Reverse the suffix
    for k, l in j+1, n:
        x.Swap(k, l)
    return True

# doubleAry initializes a 2D slice with a given height, width, and initial value
def doubleAry(h, w, init):
    res = make([][], h)
    for i in range(h):
        res[i] = make([]int, w)
        for j in range(w):
            res[i][j] = init
    return res

# aryEq checks if two int64 slices are equal
def aryEq(a, b):
    return a == b

# clone creates a copy of an int64 slice
def clone(n):
    r = make([]int, len(n))
    for i in range(len(n)):
        r[i] = n[i]
    return r

# write writes a string to the output buffer
def write(s):
    writer.WriteString(s)

# print flushes the output buffer
def print():
    writer.Flush()

# readLine reads a line from the input
def readLine():
    if scanner.Scan():
        return scanner.Text()
    return ""

# readInt reads an int64 from the input
def readInt():
    scanner.Scan()
    return int(scanner.Text())

# readFloat reads a float64 from the input
def readFloat():
    scanner.Scan()
    return float(scanner.Text())

# readRunes reads a string and returns its runes
def readRunes():
    scanner.Scan()
    return list(scanner.Text())

# readString reads a string from the input
def readString():
    scanner.Scan()
    return scanner.Text()

# readStrings reads a string and returns its characters as a slice of strings
def readStrings():
    scanner.Scan()
    return list(scanner.Text())

# s2i converts a string to int64
def s2i(s):
    return int(s)

# i2s converts an int64 to string
def i2s(i):
    return str(i)

# s2f converts a string to float64
def s2f(s):
    return float(s)

# abs returns the absolute value of an int64
def abs(i):
    return abs(i)

# max returns the maximum value from a variadic list of int64
def max(a):
    ans = a[0]
    for i, v in enumerate(a):
        if i == 0:
            ans = v
        if ans < v:
            ans = v
    return ans

# min returns the minimum value from a variadic list of int64
def min(a):
    ans = a[0]
    for i, v in enumerate(a):
        if i == 0:
            ans = v
        if ans > v:
            ans = v
    return ans

# sum calculates the sum of an int64 slice
def sum(i):
    return sum(i)

# split splits a string into fields
def split(s):
    return s.split()

# strAry2intAry converts a slice of strings to a slice of int64
def strAry2intAry(strs):
    ret = []
    for str in strs:
        intVal = s2i(str)
        ret.append(intVal)
    return ret

# intAry2strAry converts a slice of int64 to a slice of strings
def intAry2strAry(nums):
    ret = []
    for num in nums:
        strVal = i2s(num)
        ret.append(strVal)
    return ret

# ary2str joins a slice of strings into a single string
def ary2str(strs):
    return " ".join(strs)

# reverse reverses an int64 slice
def reverse(res):
    for i, j in enumerate(range(len(res)-1, -1, -1)):
        res[i], res[j] = res[j], res[i]
    return res

# reverseStr reverses a string slice
def reverseStr(res):
    for i, j in enumerate(range(len(res)-1, -1, -1)):
        res[i], res[j] = res[j], res[i]
    return res

# ini initializes the first element of a slice with a given value
def ini(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:] = res[:i]

# Uncomment the following function to see a regex example
# def regexpExample():
#     # Your code here!
#     str = "13:20"
#     r = re.compile(r"(\d+):(\d+)")
#     print(r.findall(str))

# Uncomment the following struct and function to see a stable sort example
# class Country:
#     def __init__(self, gold, silver, blonze):
#         self.gold = gold
#         self.silver = silver
#         self.blonze = blonze

# # Example of stable sorting
# def stableSortExample():
#     country = [
#         Country(1, 2, 3),
#         Country(1, 2, 3),
#         Country(1, 3, 2),
#         Country(1, 3, 3),
#     ]
#     country.sort(key=lambda x: x.blonze, reverse=True)
#     country.sort(key=lambda x: x.silver, reverse=True)
#     country.sort(key=lambda x: x.gold, reverse=True)
#     return country


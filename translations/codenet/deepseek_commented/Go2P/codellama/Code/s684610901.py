
# Go:
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"reflect"
	"sort"
	"strconv"
	"strings"
	// "regexp"
)

// Package main defines the entry point for the program.

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
# Go:
# pair struct holds two values and an index for sorting.
class pair:
    def __init__(self, index, p1, p2):
        self.index = index
        self.p1 = p1
        self.p2 = p2

# pairs is a slice of pair structs for sorting.
class pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.index < other.index

    def __eq__(self, other):
        return self.index == other.index

# Int64Slice is a type alias for sorting slices of int64.
class Int64Slice(list):
    def __init__(self, *args):
        super().__init__(*args)

    def __lt__(self, other):
        return self.index < other.index

    def __eq__(self, other):
        return self.index == other.index

# Int64s sorts a slice of int64.
def Int64s(a):
    a.sort()

# Int64sSliceAreSorted checks if a slice of int64 is sorted.
def Int64sSliceAreSorted(a):
    return a == sorted(a)

/*==========================================
 *             Constants and Variables
 *==========================================*/
# Go:
# scanner and writer are initialized for reading from standard input and writing to standard output.
scanner = bufio.Scanner(sys.stdin)
writer = bufio.Writer(sys.stdout)
di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

/*==========================================
 *             Main Function
 *==========================================*/
# Go:
# main function reads three integers and checks if the third integer lies between the first and second.
def main():
    buf = make([]byte, initialBufSize)
    scanner.Buffer(buf, maxBufSize)
    scanner.Split(bufio.ScanWords)
    A, B, C = readInt(), readInt(), readInt()
    if C >= A and C <= B:
        fmt.Println("Yes")
    else:
        fmt.Println("No")

/*==========================================
 *             Library
 *==========================================*/
# Go:
# NextPermutation finds the next permutation of a slice.
def NextPermutation(x):
    n = len(x) - 1
    if n < 1:
        return False
    j = n - 1
    for ; not x.Less(j, j+1):
        j -= 1
        if j == 0:
            return False
    l = n
    for not x.Less(j, l):
        l -= 1
    x.Swap(j, l)
    for k, l in enumerate(range(j+1, n)):
        x.Swap(k, l)
    return True

# doubleAry creates a 2D slice initialized with a given value.
def doubleAry(h, w, init):
    res = []
    for i in range(h):
        res.append([init] * w)
    return res

# aryEq checks if two slices are equal.
def aryEq(a, b):
    return a == b

# clone creates a copy of a slice.
def clone(n):
    return n[:]

# write writes a string to the writer.
def write(s):
    writer.write(s)

# print flushes the writer.
def print():
    writer.flush()

# readLine reads a line of text from the scanner.
def readLine():
    if scanner.scan():
        return scanner.text()
    return ""

# readInt reads an integer from the scanner.
def readInt():
    scanner.scan()
    return int(scanner.text())

# readFloat reads a float from the scanner.
def readFloat():
    scanner.scan()
    return float(scanner.text())

# readRunes reads a slice of runes from the scanner.
def readRunes():
    scanner.scan()
    return list(scanner.text())

# readString reads a string from the scanner.
def readString():
    scanner.scan()
    return scanner.text()

# readStrings reads multiple strings from the scanner.
def readStrings():
    scanner.scan()
    return list(scanner.text())

# s2i converts a string to an integer.
def s2i(s):
    return int(s)

# i2s converts an integer to a string.
def i2s(i):
    return str(i)

# s2f converts a string to a float.
def s2f(s):
    return float(s)

# abs returns the absolute value of an integer.
def abs(i):
    return abs(i)

# max returns the maximum value in a list of integers.
def max(a):
    ans = 0
    for i, v in enumerate(a):
        if i == 0:
            ans = v
        if ans < v:
            ans = v
    return ans

# min returns the minimum value in a list of integers.
def min(a):
    ans = 0
    for i, v in enumerate(a):
        if i == 0:
            ans = v
        if ans > v:
            ans = v
    return ans

# sum returns the sum of a slice of integers.
def sum(i):
    sum = 0
    for val in i:
        sum += val
    return sum

# split splits a string into a slice of strings.
def split(s):
    return s.split()

# strAry2intAry converts a slice of strings to a slice of integers.
def strAry2intAry(strs):
    ret = []
    for str in strs:
        intVal = s2i(str)
        ret.append(intVal)
    return ret

# intAry2strAry converts a slice of integers to a slice of strings.
def intAry2strAry(nums):
    ret = []
    for num in nums:
        strVal = i2s(num)
        ret.append(strVal)
    return ret

# ary2str joins a slice of strings into a single string.
def ary2str(strs):
    return " ".join(strs)

# reverse reverses a slice of integers.
def reverse(res):
    for i, j in enumerate(range(len(res)-1, -1, -1)):
        res[i], res[j] = res[j], res[i]
    return res

# reverseStr reverses a slice of strings.
def reverseStr(res):
    for i, j in enumerate(range(len(res)-1, -1, -1)):
        res[i], res[j] = res[j], res[i]
    return res

# ini initializes a slice with a specific value.
def ini(res, init):
    if len(res) == 0:
        return
    res[0] = init
    for i in range(len(res)):
        res[i:i+1] = res[:i]

# END-OF-CODE

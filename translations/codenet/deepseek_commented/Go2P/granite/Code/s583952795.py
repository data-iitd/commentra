
import bufio
import os
import sys

def main():
    buf = os.read(0, os.fstat(0).st_size)
    input = buf.split()
    N = int(input[0])
    K = int(input[1])

    s = ten_to_n(N, K)
    print(len(s))

def ten_to_n(number, n):
    s = ""
    tmp = number
    while tmp > 0:
        s = str(tmp % n) + s
        if tmp < n:
            break
        tmp //= n
    return s

# write writes a string to the writer
def write(s):
    sys.stdout.write(s)

# print flushes the writer to ensure all buffered data is written to the output
def print():
    sys.stdout.flush()

# readLine reads a single line from the standard input
def readLine():
    return input()

# readInt reads an integer from the standard input
def readInt():
    return int(readLine())

# readFloat reads a float from the standard input
def readFloat():
    return float(readLine())

# readRunes reads a slice of runes from the standard input
def readRunes():
    return list(readLine())

# readString reads a string from the standard input
def readString():
    return readLine()

# readStrings reads a slice of strings from the standard input
def readStrings():
    return readLine().split()

# s2i converts a string to an integer
def s2i(s):
    return int(s)

# i2s converts an integer to a string
def i2s(i):
    return str(i)

# s2f converts a string to a float
def s2f(s):
    return float(s)

# sum calculates the sum of integers in a slice
def sum(i):
    return sum(i)

# split splits a string into a slice of words
def split(s):
    return s.split()

# strAry2intAry converts a slice of strings to a slice of integers
def strAry2intAry(strs):
    return [s2i(s) for s in strs]

# intAry2strAry converts a slice of integers to a slice of strings
def intAry2strAry(nums):
    return [i2s(num) for num in nums]

# ary2str joins a slice of strings into a single string with spaces
def ary2str(strs):
    return " ".join(strs)

# reverse reverses a slice of integers
def reverse(res):
    return res[::-1]

# initalize initializes a slice with a given value
def initalize(res, init):
    return [init] * len(res)

# regexpExample is a sample function that uses regular expressions
def regexpExample():
    str = "13:20"
    r = re.compile(r"(\d+):(\d+)")
    print(r.findall(str))

# stableSortExample is a sample function that demonstrates stable sorting
def stableSortExample():
    country = [
        {"gold":1, "silver":2, "blonze":3},
        {"gold":1, "silver":2, "blonze":3},
        {"gold":1, "silver":3, "blonze":2},
        {"gold":1, "silver":3, "blonze":3},
    ]
    country.sort(key=lambda x: x["blonze"], reverse=True)
    country.sort(key=lambda x: x["silver"], reverse=True)
    country.sort(key=lambda x: x["gold"], reverse=True)
    return country

main()


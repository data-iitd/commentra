
# package main

import sys
import math

# Initialization
# The code starts with the package declaration and imports necessary libraries.
# This is a common setup for competitive programming in Python.

/*********** I/O ***********/

# ReadString returns a WORD string.
ReadString = lambda: sys.stdin.readline().rstrip("\r\n")

# Initialization
# The `init` function sets up the input reader and the output writer.
# This is a good practice for competitive programming to ensure efficient input and output handling.

# Input Functions
# The code includes various functions to read different types of inputs: integers, float numbers, strings, and slices of these types.
# This is useful for competitive programming where inputs can be large and need to be read efficiently.

# ReadInt returns an integer.
def ReadInt():
    return int(sys.stdin.readline().rstrip("\r\n"))

# ReadInt2 returns two integers.
def ReadInt2():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt3 returns three integers.
def ReadInt3():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt4 returns four integers.
def ReadInt4():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt64 returns as integer as int64.
def ReadInt64():
    return int(sys.stdin.readline().rstrip("\r\n"))

# ReadInt64_2 returns two int64s.
def ReadInt64_2():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt64_3 returns three int64s.
def ReadInt64_3():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt64_4 returns four int64s.
def ReadInt64_4():
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadFloat64 returns an float64.
def ReadFloat64():
    return float(sys.stdin.readline().rstrip("\r\n"))

# ReadFloat64_2 returns two float64s.
def ReadFloat64_2():
    return [float(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadFloat64_3 returns three float64s.
def ReadFloat64_3():
    return [float(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadFloat64_4 returns four float64s.
def ReadFloat64_4():
    return [float(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadRuneSlice returns a rune slice.
def ReadRuneSlice():
    return list(sys.stdin.readline().rstrip("\r\n"))

# ReadIntSlice returns an integer slice that has n integers.
def ReadIntSlice(n):
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadInt64Slice returns as int64 slice that has n integers.
def ReadInt64Slice(n):
    return [int(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadFloat64Slice returns an float64 slice that has n float64s.
def ReadFloat64Slice(n):
    return [float(x) for x in sys.stdin.readline().rstrip("\r\n").split()]

# ReadRuneSlice returns a rune slice.
def ReadRuneSlice():
    return list(sys.stdin.readline().rstrip("\r\n"))

# DP sub-functions
# Functions related to dynamic programming can be included here.

# ChMin accepts a pointer of integer and a target value.
# If target value is SMALLER than the first argument,
#	then the first argument will be updated by the second argument.
def ChMin(updatedValue, target):
    if updatedValue > target:
        updatedValue = target
    return updatedValue

# ChMax accepts a pointer of integer and a target value.
# If target value is LARGER than the first argument,
#	then the first argument will be updated by the second argument.
def ChMax(updatedValue, target):
    if updatedValue < target:
        updatedValue = target
    return updatedValue

# NthBit returns nth bit value of an argument.
# n starts from 0.
def NthBit(num, nth):
    return num >> nth & 1

# OnBit returns the integer that has nth ON bit.
# If an argument has nth ON bit, OnBit returns the argument.
def OnBit(num, nth):
    return num | (1 << nth)

# OffBit returns the integer that has nth OFF bit.
# If an argument has nth OFF bit, OffBit returns the argument.
def OffBit(num, nth):
    return num & ^(1 << nth)

# PopCount returns the number of ON bit of an argument.
def PopCount(num):
    res = 0

    for i in range(0, 70):
        if ((num >> i) & 1) == 1:
            res += 1

    return res

# Arithmetic Functions
# The code includes functions for arithmetic operations such as maximum and minimum values, digit sums, powers, absolute values, and more.
# These are useful for competitive programming where quick calculations are necessary.

# Max returns the max integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def Max(integers):
    m = integers[0]
    for i in integers:
        if m < i:
            m = i
    return m

# Min returns the min integer among input set.
# This function needs at least 1 argument (no argument causes panic).
def Min(integers):
    m = integers[0]
    for i in integers:
        if m > i:
            m = i
    return m

# DigitSum returns digit sum of a decimal number.
# DigitSum only accept a positive integer.
def DigitSum(n):
    if n < 0:
        return -1

    res = 0

    while n > 0:
        res += n % 10
        n //= 10

    return res

# DigitNumOfDecimal returns digits number of n.
# n is non negative number.
def DigitNumOfDecimal(n):
    res = 0

    while n > 0:
        n //= 10
        res += 1

    return res

# Sum returns multiple integers sum.
def Sum(integers):
    s = 0

    for i in integers:
        s += i

    return s

# Kiriage returns Ceil(a/b)
# a >= 0, b > 0
def Kiriage(a, b):
    return (a + (b - 1)) // b

# PowInt is integer version of math.Pow
# PowInt calculate a power by Binary Power (二分累乗法(O(log e))).
def PowInt(a, e):
    if a < 0 or e < 0:
        panic(ValueError("[argument error]: PowInt does not accept negative integers"))

    if e == 0:
        return 1

    if e % 2 == 0:
        halfE = e // 2
        half = PowInt(a, halfE)
        return half * half

    return a * PowInt(a, e - 1)

# AbsInt is integer version of math.Abs
def AbsInt(a):
    if a < 0:
        return -a
    return a

# Gcd returns the Greatest Common Divisor of two natural numbers.
# Gcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Gcd uses the Euclidean Algorithm.
def Gcd(a, b):
    if a <= 0 or b <= 0:
        panic(ValueError("[argument error]: Gcd only accepts two NATURAL numbers"))
    if a < b:
        a, b = b, a

    # Euclidean Algorithm
    while b > 0:
        div = a % b
        a, b = b, div

    return a

# Lcm returns the Least Common Multiple of two natural numbers.
# Lcd only accepts two natural numbers (a, b >= 1).
# 0 or negative number causes panic.
# Lcd uses the Euclidean Algorithm indirectly.
def Lcm(a, b):
    if a <= 0 or b <= 0:
        panic(ValueError("[argument error]: Gcd only accepts two NATURAL numbers"))

    # a = a'*gcd, b = b'*gcd, a*b = a'*b'*gcd^2
    # a' and b' are relatively prime numbers
    # gcd consists of prime numbers, that are included in a and b
    gcd = Gcd(a, b)

    # not (a * b / gcd), because of reducing a probability of overflow
    return (a // gcd) * b

# Strtoi is a wrapper of strconv.Atoi().
# If strconv.Atoi() returns an error, Strtoi calls panic.
def Strtoi(s):
    if i, err := strconv.Atoi(s); err != nil:
        panic(ValueError("[argument error]: Strtoi only accepts integer string"))
    else:
        return i

# PrintIntsLine returns integers string delimited by a space.
def PrintIntsLine(A):
    res = []

    for i in range(len(A)):
        str = str(A[i])
        # str := strconv.Itoa(A[i])  # 64bit int version
        res.append(str)

        if i != len(A) - 1:
            res.append(" ")

    return "".join(res)

# Constants
# The code defines constants for MOD and the number of alphabets, which can be used throughout the program.

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60

# Memoization
# The code uses a memoization array to store counts of each letter.
# This is a common technique in competitive programming to optimize repeated calculations.

memo = [0] * ALPHABET_NUM
str = ""

def main():
    while True:
        str = ReadString()
        S = list(str)
        if len(S) == 0:
            break
        for i in range(len(S)):
            c = S[i]

            if 'a' <= c and c <= 'z':
                # toUpper
                # c-('a'-'A')
                memo[ord(c) - ord('a')] += 1
            elif 'A' <= c and c <= 'Z':
                # toLower
                # c+('a'-'A')
                memo[ord(c) - ord('A')] += 1
            else:
                # stay
                # c
                continue

    for i in range(ALPHABET_NUM):
        print(chr(ord('a') + i), ":", memo[i])

# Main Function
# The main function reads input, processes it, and prints the results.
# This is a common structure for programs that need to handle multiple inputs.

if __name__ == "__main__":
    main()

# END-OF-CODE

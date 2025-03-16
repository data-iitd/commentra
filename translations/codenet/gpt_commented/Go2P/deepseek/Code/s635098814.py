import sys
import io
import os
import math
import re
import string

# Declare global variables for reading input and writing output.
read_string = None
stdout = io.TextIOWrapper(sys.stdout)

# Initialize the ReadString function and the stdout writer.
def init():
    global read_string
    read_string = sys.stdin.readline

# ReadInt returns an integer.
def read_int():
    return int(read_string().strip())

# ReadInt2 returns two integers.
def read_int2():
    return tuple(map(int, read_string().strip().split()))

# ReadInt3 returns three integers.
def read_int3():
    return tuple(map(int, read_string().strip().split()))

# ReadInt4 returns four integers.
def read_int4():
    return tuple(map(int, read_string().strip().split()))

# ReadInt64 returns an integer as int64.
def read_int64():
    return int(read_string().strip())

# ReadInt64_2 returns two int64 integers.
def read_int64_2():
    return tuple(map(int, read_string().strip().split()))

# ReadInt64_3 returns three int64 integers.
def read_int64_3():
    return tuple(map(int, read_string().strip().split()))

# ReadInt64_4 returns four int64 integers.
def read_int64_4():
    return tuple(map(int, read_string().strip().split()))

# ReadFloat64 returns a float64.
def read_float64():
    return float(read_string().strip())

# ReadFloat64Slice returns a slice of float64 of size n.
def read_float64_slice(n):
    return [float(read_string().strip()) for _ in range(n)]

# ReadRuneSlice returns a slice of runes from the input string.
def read_rune_slice():
    return list(read_string().strip())

# ReadIntSlice returns a slice of integers of size n.
def read_int_slice(n):
    return [read_int() for _ in range(n)]

# ReadInt64Slice returns a slice of int64 integers of size n.
def read_int64_slice(n):
    return [read_int64() for _ in range(n)]

# ReadString returns a WORD string.
def read_string():
    return read_string.strip()

# ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding for debugging.
def zero_padding_rune_slice(n, digits_num):
    sn = format(n, 'b')
    residual_length = digits_num - len(sn)
    if residual_length <= 0:
        return list(sn)
    zeros = ['0'] * residual_length
    return zeros + list(sn)

# ChMin updates the value pointed to by updated_value if the target is smaller.
def ch_min(updated_value, target):
    if updated_value > target:
        updated_value = target
        return True
    return False

# ChMax updates the value pointed to by updated_value if the target is larger.
def ch_max(updated_value, target):
    if updated_value < target:
        updated_value = target
        return True
    return False

# NthBit returns the nth bit value of an integer.
def nth_bit(num, nth):
    return (num >> nth) & 1

# OnBit returns the integer with the nth bit set to ON.
def on_bit(num, nth):
    return num | (1 << nth)

# OffBit returns the integer with the nth bit set to OFF.
def off_bit(num, nth):
    return num & ~(1 << nth)

# PopCount returns the number of ON bits in an integer.
def pop_count(num):
    res = 0
    for i in range(70):
        if ((num >> i) & 1) == 1:
            res += 1
    return res

# Max returns the maximum integer from a set of integers.
def max(integers):
    m = integers[0]
    for integer in integers:
        if m < integer:
            m = integer
    return m

# Min returns the minimum integer from a set of integers.
def min(integers):
    m = integers[0]
    for integer in integers:
        if m > integer:
            m = integer
    return m

# DigitSum returns the sum of the digits of a positive integer.
def digit_sum(n):
    if n < 0:
        return -1
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    return res

# DigitNumOfDecimal returns the number of digits in a non-negative integer.
def digit_num_of_decimal(n):
    res = 0
    while n > 0:
        n //= 10
        res += 1
    return res

# Sum returns the sum of multiple integers.
def sum(integers):
    s = 0
    for i in integers:
        s += i
    return s

# Kiriage returns the ceiling of a/b for non-negative a and positive b.
def kiriage(a, b):
    return (a + (b - 1)) // b

# PowInt calculates a power using binary exponentiation.
def pow_int(a, e):
    if a < 0 or e < 0:
        raise ValueError("PowInt does not accept negative integers")
    if e == 0:
        return 1
    if e % 2 == 0:
        half_e = e // 2
        half = pow_int(a, half_e)
        return half * half
    return a * pow_int(a, e - 1)

# AbsInt returns the absolute value of an integer.
def abs_int(a):
    if a < 0:
        return -a
    return a

# Gcd returns the Greatest Common Divisor of two natural numbers using the Euclidean Algorithm.
def gcd(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("Gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a
    while b > 0:
        div = a % b
        a, b = b, div
    return a

# Lcm returns the Least Common Multiple of two natural numbers.
def lcm(a, b):
    if a <= 0 or b <= 0:
        raise ValueError("Gcd only accepts two NATURAL numbers")
    return (a // gcd(a, b)) * b

# Strtoi converts a string to an integer and panics on error.
def strtoi(s):
    try:
        return int(s)
    except ValueError:
        raise ValueError("Strtoi only accepts integer string")

# PrintIntsLine returns a string of integers delimited by a space.
def print_ints_line(A):
    return ' '.join(map(str, A))

# Example usage of the I/O functions:
# str = read_string()
# i = read_int()
# X = read_int_slice(n)
# S = read_rune_slice()
# a = read_float64()
# A = read_float64_slice(n)

# Example usage of debugging functions:
# str = zero_padding_rune_slice(num, 32)
# str = print_ints_line(X)

# Define constants for the program.
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60

# Declare memoization array and string variable.
memo = [0] * ALPHABET_NUM

# Read input until EOF.
for line in sys.stdin:
    str = line.strip()
    if not str:
        break
    # Count occurrences of each letter.
    for c in str:
        if 'a' <= c <= 'z':
            # Increment count for lowercase letters.
            memo[ord(c) - ord('a')] += 1
        elif 'A' <= c <= 'Z':
            # Increment count for uppercase letters.
            memo[ord(c) - ord('A')] += 1
        # Ignore non-alphabet characters.

# Print the count of each letter.
for i in range(ALPHABET_NUM):
    stdout.write(f"{chr(i + ord('a'))} : {memo[i]}\n")


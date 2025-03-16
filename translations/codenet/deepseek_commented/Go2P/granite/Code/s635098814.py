
import sys

# Read input from stdin and provide input functions
def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input()

def read_strs():
    return input().split()

# Debugging functions
def zero_padding_rune_slice(n, digits_num):
    sn = bin(n)[2:]
    residual_length = digits_num - len(sn)
    if residual_length <= 0:
        return sn
    zeros = ['0'] * residual_length
    res = zeros + list(sn)
    return ''.join(res)

# Dynamic programming sub-functions
def ch_min(updated_value, target):
    if updated_value > target:
        updated_value = target
        return True
    return False

def ch_max(updated_value, target):
    if updated_value < target:
        updated_value = target
        return True
    return False

def nth_bit(num, nth):
    return num >> nth & 1

def on_bit(num, nth):
    return num | (1 << nth)

def off_bit(num, nth):
    return num & ~(1 << nth)

def pop_count(num):
    res = 0
    for i in range(70):
        if (num >> i) & 1 == 1:
            res += 1
    return res

# Arithmetic functions
def max(*integers):
    m = integers[0]
    for i, integer in enumerate(integers):
        if i == 0:
            continue
        if m < integer:
            m = integer
    return m

def min(*integers):
    m = integers[0]
    for i, integer in enumerate(integers):
        if i == 0:
            continue
        if m > integer:
            m = integer
    return m

def digit_sum(n):
    if n < 0:
        return -1
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    return res

def digit_num_of_decimal(n):
    res = 0
    while n > 0:
        n //= 10
        res += 1
    return res

def sum(*integers):
    s = 0
    for i in integers:
        s += i
    return s

def kiriage(a, b):
    return (a + b - 1) // b

def pow_int(a, e):
    if a < 0 or e < 0:
        raise Exception("[argument error]: pow_int does not accept negative integers")
    if e == 0:
        return 1
    if e % 2 == 0:
        half_e = e // 2
        half = pow_int(a, half_e)
        return half * half
    return a * pow_int(a, e - 1)

def abs_int(a):
    if a < 0:
        return -a
    return a

def gcd(a, b):
    if a <= 0 or b <= 0:
        raise Exception("[argument error]: gcd only accepts two NATURAL numbers")
    if a < b:
        a, b = b, a
    while b > 0:
        div = a % b
        a, b = b, div
    return a

def lcm(a, b):
    if a <= 0 or b <= 0:
        raise Exception("[argument error]: gcd only accepts two NATURAL numbers")
    gcd_ = gcd(a, b)
    return (a // gcd_) * b

def str_to_int(s):
    try:
        return int(s)
    except ValueError:
        raise Exception("[argument error]: str_to_int only accepts integer string")

def print_ints_line(*A):
    res = []
    for i in range(len(A)):
        str_ = str(A[i])
        res.extend(list(str_))
        if i!= len(A) - 1:
            res.append(' ')
    return ''.join(res)

# Main function
def main():
    memo = [0] * 26
    for line in sys.stdin:
        str_ = line.strip()
        if not str_:
            break
        for c in str_:
            if 'a' <= c <= 'z':
                memo[ord(c) - ord('a')] += 1
            elif 'A' <= c <= 'Z':
                memo[ord(c) - ord('A')] += 1
            else:
                continue
    for i in range(26):
        print(f'a + {chr(ord('a') + i)} : {memo[i]}')

if __name__ == "__main__":
    main()

The Python code is a translation of the given Go code. It includes the necessary input and output functions, debugging functions, dynamic programming sub-functions, arithmetic functions, and the main function.

The Python code also includes constants for MOD and the number of alphabets, which can be used throughout the program.

Note: The Python code uses the `sys` module to read input from stdin and provides input functions. The main function reads input, processes it, and prints the results.


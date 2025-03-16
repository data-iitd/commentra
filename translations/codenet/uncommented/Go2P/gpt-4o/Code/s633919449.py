import sys
import math
from collections import defaultdict, deque

initial_buf_size = 10000
max_buf_size = 1000000
mod = 10**9 + 7

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_array(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def get_string():
    return sys.stdin.readline().strip()

def get_string_array(n):
    return [get_string() for _ in range(n)]

def abs_val(a):
    return abs(a)

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

def calc_mod(x):
    return x % mod

def min_val(*nums):
    if len(nums) == 0:
        raise ValueError("function min() requires at least one argument.")
    return min(nums)

def max_val(*nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")
    return max(nums)

def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False

    return True

def contains(s, e):
    return e in s

def make_range(min_val, max_val):
    return list(range(min_val, max_val + 1))

def calc_gcd(x, y):
    if y == 0:
        return x
    elif x >= y:
        return calc_gcd(y, x % y)
    else:
        return calc_gcd(x, y % x)

def get_divisor(n):
    divisor = set()
    divisor.add(1)
    if n != 1:
        divisor.add(n)

    sqrt_n = int(math.sqrt(n))
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisor.add(i)
            divisor.add(n // i)

    return list(divisor)

def fact_mod(n):
    value = 1
    for i in range(2, n + 1):
        value = calc_mod(value * i)
    return value

def combination_mod(n, k):
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_nk = fact_mod(n - k)
    fact_k_inv = pow_mod(fact_k, mod - 2)
    fact_nk_inv = pow_mod(fact_nk, mod - 2)
    return calc_mod(fact_n * calc_mod(fact_k_inv * fact_nk_inv))

def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            factors.append(i)
            n //= i
        else:
            i += 1
    if n > 1:
        factors.append(n)
    return factors

def main():
    N = get_int()

    if N % 10 in {2, 4, 5, 7, 9}:
        print("hon")
    elif N % 10 in {0, 1, 6, 8}:
        print("pon")
    elif N % 10 == 3:
        print("bon")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

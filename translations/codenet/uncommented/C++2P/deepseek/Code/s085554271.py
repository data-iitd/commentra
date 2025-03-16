import sys
import math

def is_prime(num):
    if num < 2:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False  # 偶数はあらかじめ除く

    sqrt_num = math.sqrt(num)
    for i in range(3, int(sqrt_num) + 1, 2):
        if num % i == 0:
            return False  # 素数ではない

    return True  # 素数である

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def max_of_three(a, b, c):
    return max(a, b, c)

def min_of_three(a, b, c):
    return min(a, b, c)

def is_integer(num):
    return math.floor(num) == num

def factorial(num):
    if num == 0:
        return 1
    else:
        return num * factorial(num - 1)

def number_of_divisors(n):
    cnt = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt += 1
            if i != n // i:
                cnt += 1
    return cnt

def factorial_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = f * (i % mod) % mod
    return f

def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % mod
        x = (x * x) % mod
        n >>= 1
    return res

def combination_mod(n, r, mod):
    if r > n - r:
        r = n - r
    if r == 0:
        return 1
    a = 1
    for i in range(r):
        a = a * ((n - i) % mod) % mod
    b = mod_pow(factorial_mod(r, mod), mod - 2, mod)
    return (a % mod) * (b % mod) % mod

def is_reversed(s):
    return s == s[::-1]

# メイン処理
def main():
    k, a, b = map(int, input().split())
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            return
    print("NG")

if __name__ == "__main__":
    main()

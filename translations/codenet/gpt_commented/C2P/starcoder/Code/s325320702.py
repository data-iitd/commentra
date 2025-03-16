
# Define type aliases for convenience
from typing import List

# Macros for loop iterations and constants
from math import inf

# Function to swap two long long integers
def swap(a: int, b: int) -> None:
    a, b = b, a

# Function to read a long long integer
def cin(n: List[int]) -> None:
    n[0] = int(input())

# Functions to find maximum and minimum of two or three numbers
def max2(a: int, b: int) -> int:
    return a if a >= b else b

def min2(a: int, b: int) -> int:
    return a if a <= b else b

def min3(a: int, b: int, c: int) -> int:
    return a if a <= b and a <= c else b if b <= c else c

def max3(a: int, b: int, c: int) -> int:
    return a if a >= b and a >= c else b if b >= c else c

# Functions to find minimum and maximum in an array
def minn(n: int, a: List[int]) -> int:
    b = inf
    for i in range(n):
        b = min2(b, a[i])
    return b

def maxn(n: int, a: List[int]) -> int:
    b = -inf
    for i in range(n):
        b = max2(b, a[i])
    return b

# Functions for power calculations
def POW(a: int, b: int) -> int:
    c = 1
    for i in range(b):
        c *= a
    return c

# Functions for GCD and LCM calculations
def gcd(a: int, b: int) -> int:
    return gcd(b, a % b) if b else a

def lcm(a: int, b: int) -> int:
    return a // gcd(a, b) * b

# Functions for modular arithmetic
def mod_MOD1(n: int) -> int:
    n += n < 0 and (-n) // MOD1 + 1 or 0
    return n %= MOD1

def mod_p(n: int, p: int) -> int:
    n += n < 0 and (-n) // p + 1 or 0
    return n %= p

# Function to convert a string to a number
def change_into_num(s: str, len: int, p: int) -> int:
    return 0 if not p else POW(10, p - 1) * (ord(s[len - p]) - ord('0')) + change_into_num(s, len, p - 1)

# Function to count the number of digits in a number
def digits(a: int, b: int) -> int:
    return a // b + 1 if a % b else a // b

# Functions to check if an index is within array bounds
def is_inArr1(x: int, n: int) -> int:
    return 1 if x >= 0 and x < n else 0

def is_inArr2(y: int, x: int, h: int, w: int) -> int:
    return 1 if y >= 0 and y < h and x >= 0 and x < w else 0

# Functions for lower and upper bounds in binary search
def lr_lower(l: int, r: int, am: int, val: int, type: int) -> None:
    if type < 3:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

def lr_upper(l: int, r: int, am: int, val: int, type: int) -> None:
    if type < 3:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

# Functions for lower and upper bounds in binary search
def lr_lower(l: int, r: int, am: int, val: int, type: int) -> None:
    if type < 3:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

def lr_upper(l: int, r: int, am: int, val: int, type: int) -> None:
    if type < 3:
        if am <= val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2
    else:
        if am < val:
            l = (l + r) // 2
        else:
            r = (l + r) // 2

# Comparison functions for lower and upper bounds
def cmp_lower(a: int, b: int, type: int) -> int:
    return 1 if type == 1 and a == b else 1 if type == 2 and a >= b else 1 if a > b else 0

def cmp_upper(a: int, b: int, type: int) -> int:
    return 1 if type == 1 and a == b else 1 if type == 2 and a <= b else 1 if a < b else 0

# Function to find the lower bound in an array
def lower_bound(a: List[int], l: int, r: int, val: int, type: int) -> int:
    while r - l > 1:
        lr_lower(l, r, a[(l + r) // 2], val, type)
    return cmp_lower(a[l], val, type) and l or cmp_lower(a[r], val, type) and r or -1

# Function to find the upper bound in an array
def upper_bound(a: List[int], l: int, r: int, val: int, type: int) -> int:
    while r - l > 1:
        lr_upper(l, r, a[(l + r) // 2], val, type)
    return cmp_upper(a[r], val, type) and r or cmp_upper(a[l], val, type) and l or -1

# Function to count occurrences of a value in an array
def count(a: List[int], l: int, r: int, x: int) -> int:
    p = lower_bound(a, l, r, x, 1)
    return p == -1 and 0 or upper_bound(a, p, r, x, 1) - p + 1

# Global variables for factorization
factors: List[List[int]] = [[], []]
fac_cnt: int = 0
is_factor_prepared: int = 0

# Function to prepare factors for prime factorization
def factor_pre() -> int:
    for i in range(2):
        if is_factor_prepared:
            return 0
        tmp = (1e6) // 2 + 1
        fac_tmp: List[int] = [0] * tmp
        for i in range(tmp):
            fac_tmp[i] = i and 2 * i + 1 or 2
        for i in range(1, tmp):
            if fac_tmp[i]:
                for j in range(3, tmp // (2 * i + 1) + 1, 2):
                    if j * (2 * i + 1) < tmp:
                        fac_tmp[(j * (2 * i + 1) - 1) // 2] = 0
        for i in range(tmp):
            if fac_tmp[i]:
                for j in range(2):
                    factors[j].append(j and 0 or fac_tmp[i])
    return 0

# Function to factor a number and update factor counts
def factor(n: int, new_common_plus: int) -> int:
    factor_pre()
    for i in range(fac_cnt):
        cnt: int = 0
        for j in range(2):
            while cnt + (n % factors[0][i] == 0) and (n //= factors[0][i]) % factors[0][i] == 0:
                cnt += 1
        factors[1][i] = new_common_plus == 1 and cnt or new_common_plus == 2 and max2(factors[1][i], cnt) or factors[1][i] + cnt
        if factors[0][i] > n:
            break
    return n

# Function to judge if a number is prime
def judge_prime(n: int) -> int:
    factor_pre()
    for i in range(fac_cnt):
        if n < factors[0][i] * factors[0][i] or n == factors[0][i]:
            break
        elif n % factors[0][i] == 0:
            n //= n
    return n == 1 and 0 or 1

# Global variables for modular inverses and factorials
mf_arr: List[int] = []
inv_arr: List[int] = []
finv_arr: List[int] = []
is_minv_made: int = 0
is_mf_made: int = 0
num_of_inv: int = 2 * 1e6 + 10

# Function to create modular inverses
def makeinv(n: int, mod: int) -> int:
    for i in range(2):
        if is_minv_made:
            return 0
        inv_arr.append(0)
        finv_arr.append(0)
        inv_arr[1] = 1
        finv_arr[0] = finv_arr[1] = 1
        for i in range(2, n + 1):
            inv_arr.append(0)
            finv_arr.append(0)
            inv_arr[i] = mod - inv_arr[mod % i] * (mod // i) % mod
            finv_arr[i] = finv_arr[i - 1] * inv_arr[i] % mod
    return 0

# Function to create factorials
def make_mf(n: int, mod: int) -> int:
    for i in range(2):
        if is_mf_made:
            return 0
        x: int = 1
        mf_arr.append(0)
        mf_arr[0] = mf_arr[1] = x
        for i in range(2, n + 1):
            x = x * i % mod
            mf_arr.append(0)
            mf_arr[i] = x
    return 0

# Function to get modular inverse based on whether it's factorial or not
def m_inv(x: int, mod: int, is_fac: int) -> int:
    makeinv(num_of_inv, mod)
    return is_fac and finv_arr[x] or inv_arr[x]

# Function to get factorial modulo
def m_f(x: int, mod: int) -> int:
    make_mf(num_of_inv, mod)
    return mf_arr[x]

# Function to calculate n choose k modulo
def mod_nck(n: int, k: int, mod: int) -> int:
    return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n - k, mod, 1) % mod

# Function for modular exponentiation
def m_p(r: int, n: int, mod: int) -> int:
    t: int = 1
    s: int = r
    while n > 0:
        t = (n & 1) and t * s % mod or t
        s = s * s % mod
        n >>= 1
    return r and t or 0

# Functions for modular multiplication
def m_mul2(a: int, b: int, mod: int) -> int:
    return a * b % mod

def m_mul3(a: int, b: int, c: int, mod: int) -> int:
    return m_mul2(a * b % mod, c, mod)

def m_mul4(a: int, b: int, c: int, d: int, mod: int) -> int:
    return m_mul3(a * b % mod, c, d, mod)

def m_mul5(a: int, b: int, c: int, d: int, e: int, mod: int) -> int:
    return m_mul4(a * b % mod, c, d, e, mod)

# Comparison functions for sorting
def upll(a: int, b: int) -> int:
    return -1 if a < b else 1 if a > b else 0

def downll(a: int, b: int) -> int:
    return 1 if a < b else -1 if a > b else 0

def cmp_string(a: str, b: str) -> int:
    return -1 if a < b else 1 if a > b else 0

def cmp_char(a: str, b: str) -> int:
    return ord(a) - ord(b)

# Sorting functions
def sortup(a: List[int], n: int) -> None:
    a.sort(key=lambda x: x)

def sortdown(a: List[int], n: int) -> None:
    a.sort(key=lambda x: x, reverse=True)

def sort_string(n: int, size: int, s: List[str]) -> None:
    s.sort(key=lambda x: x)

def sort_char(s: str) -> None:
    s.sort(key=lambda x: ord(x))

# Functions to count unique strings and numbers
def unique_string(n: int, size: int, s: List[str]) -> int:
    ans: int = 1
    for i in range(1, n):
        if s[i]!= s[i - 1]:
            ans += 1
    return ans

def unique_num(n: int, a: List[int]) -> int:
    ans: int = 1
    for i in range(1, n):
        if a[i]!= a[i - 1]:
            ans += 1
    return ans

# Structure for sorting pairs
class fr:
    def __init__(self, a: int, b: int) -> None:
        self.a = a
        self.b = b

# Comparison functions for sorting pairs
def cmp1(p: fr, q: fr) -> int:
    return p.a - q.a

def cmp2(p: fr, q: fr) -> int:
    return q.a - p.a

# Sorting functions for pairs
def strsortup(a: List[fr], n: int) -> None:
    a.sort(key=lambda x: x.a)

def strsortdown(a: List[fr], n: int) -> None:
    a.sort(key=lambda x: x.a, reverse=True)

# Main function
s: List[str] = []
l: List[int] = []
r: List[int] = []
d: List[int] = []
ans: int = 0
cin(l)
cin(r)
cin(d)
for i in range(l, r + 1):
    if i % d == 0:
        ans += 1
print(ans)


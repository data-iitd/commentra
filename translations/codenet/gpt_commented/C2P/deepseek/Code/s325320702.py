# Define type aliases for convenience
from typing import List, Tuple

# Macros for loop iterations and constants
rep = lambda i, l, r: range(l, r)
repp = lambda i, l, r, k: range(l, r, k)
rrep = lambda i, l, r: range(l, r, -1)
INF = 1 << 60
MOD1 = 1000000007
MOD2 = 998244353
MAX_N = 1 << 20
YES = "Yes\n"
NO = "No\n"
PN = "\n"
charsize = 100005  # Maximum character size
PI = 3.141592653589793238

# Function to swap two long long integers
def swap(a: List[int], b: List[int]) -> None:
    a[0], b[0] = b[0], a[0]

# Function to read a long long integer
def cin(n: List[int]) -> None: 
    n[0] = int(input()) 

# Functions to find maximum and minimum of two or three numbers
def max2(a: int, b: int) -> int: return a if a >= b else b
def min2(a: int, b: int) -> int: return a if a <= b else b
def min3(a: int, b: int, c: int) -> int: return min(a, b, c)
def max3(a: int, b: int, c: int) -> int: return max(a, b, c)

# Functions to find minimum and maximum in an array
def minn(n: int, a: List[int]) -> int: 
    b = INF 
    for i in range(n): b = min(b, a[i]) 
    return b 
def maxn(n: int, a: List[int]) -> int: 
    b = -INF 
    for i in range(n): b = max(b, a[i]) 
    return b 

# Functions for power calculations
def POW(a: int, b: int) -> int: 
    c = 1 
    for _ in range(b): c *= a 
    return c 
def POW_d(a: float, b: float) -> float: 
    c = 1 
    for _ in range(b): c *= a 
    return c 

# Functions for GCD and LCM calculations
def gcd(a: int, b: int) -> int: return gcd(b, a % b) if b else a
def lcm(a: int, b: int) -> int: return a * b // gcd(a, b)

# Functions for modular arithmetic
def mod_MOD1(n: int) -> int: 
    n = (n + (-n // MOD1 + 1) * MOD1) % MOD1
    return n 
def mod_p(n: int, p: int) -> int: 
    n = (n + (-n // p + 1) * p) % p
    return n 

# Function to convert a string to a number
def change_into_num(s: str, len: int, p: int) -> int: 
    return (10 ** (p - 1)) * (ord(s[len - p]) - ord('0')) + change_into_num(s, len, p - 1) if p else 0

# Function to count the number of digits in a number
def digits(a: int, b: int) -> int: 
    return 1 + digits(a // b, b) if a // b else 1

# Functions to check if an index is within array bounds
def is_inArr1(x: int, n: int) -> bool: return not (x < 0 or x >= n)
def is_inArr2(y: int, x: int, h: int, w: int) -> bool: return not (y < 0 or y >= h or x < 0 or x >= w)

# Functions for lower and upper bounds in binary search
def lr_lower(l: int, r: int, am: int, val: int, type: int) -> None: 
    (l, r) = ((l + r) // 2, r) if am < val else (l, (l + r) // 2)
def lr_upper(l: int, r: int, am: int, val: int, type: int) -> None: 
    (l, r) = ((l + r) // 2, r) if am <= val else (l, (l + r) // 2)

# Comparison functions for lower and upper bounds
def cmp_lower(a: int, b: int, type: int) -> int: 
    return 1 if (type == 1 and a == b) or (type == 2 and a >= b) or (type == 3 and a > b) else 0
def cmp_upper(a: int, b: int, type: int) -> int: 
    return 1 if (type == 1 and a == b) or (type == 2 and a <= b) or (type == 3 and a < b) else 0

# Function to find the lower bound in an array
def lower_bound(a: List[int], l: int, r: int, val: int, type: int) -> int:  
    while r - l > 1: lr_lower(l, r, a[(l + r) // 2], val, type)
    return cmp_lower(a[l], val, type) if cmp_lower(a[l], val, type) else cmp_lower(a[r], val, type) if cmp_lower(a[r], val, type) else -1

# Function to find the upper bound in an array
def upper_bound(a: List[int], l: int, r: int, val: int, type: int) -> int:  
    while r - l > 1: lr_upper(l, r, a[(l + r) // 2], val, type)
    return cmp_upper(a[r], val, type) if cmp_upper(a[r], val, type) else cmp_upper(a[l], val, type) if cmp_upper(a[l], val, type) else -1

# Function to count occurrences of a value in an array
def count(a: List[int], l: int, r: int, x: int) -> int:  
    p = lower_bound(a, l, r, x, 1)
    return 0 if p == -1 else upper_bound(a, p, r, x, 1) - p + 1

# Global variables for factorization
factors: List[List[int]] = [[] for _ in range(2)]
fac_cnt = 0
is_factor_prepared = 0

# Function to prepare factors for prime factorization
def factor_pre() -> None:  
    if is_factor_prepared: return 0
    tmp = (10**6) // 2 + 1
    fac_tmp = [2 * i + 1 for i in range(tmp)]
    for i in range(1, tmp): 
        if fac_tmp[i]: 
            for j in range(3, tmp // (2 * i + 1) + 1, 2): 
                if j * (2 * i + 1) < tmp: fac_tmp[(j * (2 * i + 1) - 1) // 2] = 0
    for i in range(tmp): 
        if fac_tmp[i]: 
            for j in range(2): 
                factors[j].append(0 if j else fac_tmp[i])
                fac_cnt += 1
    is_factor_prepared = 1
    return 0

# Function to factor a number and update factor counts
def factor(n: int, new_common_plus: int = 1) -> int: 
    factor_pre()
    for i in range(fac_cnt): 
        cnt = 0 
        while n % factors[0][i] == 0: 
            cnt += 1
            n //= factors[0][i]
        factors[1][i] = max(factors[1][i], cnt) if new_common_plus == 1 else new_common_plus == 2 and max(factors[1][i], cnt) or factors[1][i] + cnt
        if factors[0][i] > n: break
    return n

# Function to judge if a number is prime
def judge_prime(n: int) -> int: 
    factor_pre()
    for i in range(fac_cnt): 
        if n < factors[0][i] * factors[0][i] or n == factors[0][i]: break
        elif n % factors[0][i] == 0: n //= n
    return 1 if n == 1 else 0

# Global variables for modular inverses and factorials
mf_arr: List[int] = []
inv_arr: List[int] = []
finv_arr: List[int] = []
is_minv_made = 0
is_mf_made = 0
num_of_inv = 2 * 10**6 + 10

# Function to create modular inverses
def makeinv(n: int, mod: int) -> None:  
    if is_minv_made: return 0
    inv_arr.append(1)
    finv_arr.append(1)
    for i in range(2, n + 1):  
        inv_arr.append((mod - inv_arr[mod % i] * (mod // i)) % mod)
        finv_arr.append(finv_arr[-1] * inv_arr[i] % mod)
    is_minv_made = 1
    return 0

# Function to create factorials
def make_mf(n: int, mod: int) -> None:  
    if is_mf_made: return 0
    x = 1
    mf_arr.append(x)
    for i in range(2, n + 1):   
        x = x * i % mod
        mf_arr.append(x)
    is_mf_made = 1
    return 0

# Function to get modular inverse based on whether it's factorial or not
def m_inv(x: int, mod: int, is_fac: int) -> int: 
    makeinv(num_of_inv, mod)
    return finv_arr[x] if is_fac else inv_arr[x]

# Function to get factorial modulo
def m_f(x: int, mod: int) -> int:  
    make_mf(num_of_inv, mod)
    return mf_arr[x]

# Function to calculate n choose k modulo
def mod_nck(n: int, k: int, mod: int) -> int: 
    return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n - k, mod, 1) % mod

# Function for modular exponentiation
def m_p(r: int, n: int, mod: int) -> int:  
    t = 1
    s = r
    while n > 0: 
        t = t * s % mod if n & 1 else t
        s = s * s % mod
        n >>= 1
    return r and t or 0

# Functions for modular multiplication
def m_mul2(a: int, b: int, mod: int) -> int: return a * b % mod
def m_mul3(a: int, b: int, c: int, mod: int) -> int: return m_mul2(a * b % mod, c, mod)
def m_mul4(a: int, b: int, c: int, d: int, mod: int) -> int: return m_mul3(a * b % mod, c, d, mod)
def m_mul5(a: int, b: int, c: int, d: int, e: int, mod: int) -> int: return m_mul4(a * b % mod, c, d, e, mod)

# Comparison functions for sorting
def upll(a: int, b: int) -> int: return -1 if a < b else 1 if a > b else 0
def downll(a: int, b: int) -> int: return 1 if a < b else -1 if a > b else 0
def cmp_string(a: str, b: str) -> int: return -1 if a < b else 1 if a > b else 0
def cmp_char(a: str, b: str) -> int: return ord(a) - ord(b)

# Sorting functions
def sortup(a: List[int], n: int) -> None: a.sort()
def sortdown(a: List[int], n: int) -> None: a.sort(reverse=True)
def sort_string(n: int, size: int, s: List[str]) -> None: s.sort()
def sort_char(s: str) -> None: s = sorted(s)

# Functions to count unique strings and numbers
def unique_string(n: int, size: int, s: List[str]) -> int: 
    ans = 1
    for i in range(1, n): 
        if s[i] != s[i - 1]: ans += 1
    return ans
def unique_num(n: int, a: List[int]) -> int: 
    ans = 1
    for i in range(1, n): 
        if a[i] != a[i - 1]: ans += 1
    return ans

# Structure for sorting pairs
fr = Tuple[int, int]

# Comparison functions for sorting pairs
def cmp1(p: fr, q: fr) -> int: return p[0] - q[0]
def cmp2(p: fr, q: fr) -> int: return q[0] - p[0]

# Sorting functions for pairs
def strsortup(a: List[fr], n: int) -> None: a.sort(key=lambda x: x[0])
def strsortdown(a: List[fr], n: int) -> None: a.sort(key=lambda x: x[0], reverse=True)

# Main function
if __name__ == "__main__":
    # Read input values for l, r, and d
    l, r, d = map(int, input().split())
    ans = 0

    # Count the multiples of d in the range [l, r]
    for i in range(l, r + 1):
        if i % d == 0: ans += 1

    # Output the result
    print(ans)

# Disable some compiler warnings
# Preprocessor directives and header file inclusions
import sys
import os
import math
import time
from typing import List, Tuple, Set, Dict, Optional, Union
from collections import deque, defaultdict, Counter

# Constants and macro definitions
BIG = 2000000007
VERYBIG = 20000000000000007
MOD = 1000000007
FOD = 998244353
N_MAX = 1048576

# Data type and structure definitions
hwll = Tuple[int, int]
hwllc = Tuple[int, int, int]
hwreal = Tuple[float, float]

# Variable declarations
n: int = 0
m: int = 0
h: int = 0
w: int = 0
k: int = 0
q: int = 0
va: int = 0
vb: int = 0
vc: int = 0
vd: int = 0
ve: int = 0
vf: int = 0
ua: int = 0
ub: int = 0
uc: int = 0
ud: int = 0
ue: int = 0
uf: int = 0
vra: float = 0.0
vrb: float = 0.0
vrc: float = 0.0
vda: float = 0.0
vdb: float = 0.0
vdc: float = 0.0
ch: str = ""
dh: str = ""

# Helper function declarations
def umin(x: int, y: int) -> int:
    return x if x < y else y

def umax(x: int, y: int) -> int:
    return x if x > y else y

def smin(x: int, y: int) -> int:
    return x if x < y else y

def smax(x: int, y: int) -> int:
    return x if x > y else y

def gcd(x: int, y: int) -> int:
    while y:
        x, y = y, x % y
    return x

def bitpow(a: int, x: int, modulo: int) -> int:
    result = 1
    while x > 0:
        if x % 2 == 1:
            result = (result * a) % modulo
        a = (a * a) % modulo
        x //= 2
    return result

def divide(a: int, b: int, modulo: int) -> int:
    return (a * bitpow(b, modulo - 2, modulo)) % modulo

def udiff(a: int, b: int) -> int:
    return a if a > b else b

def bitcount(n: int) -> int:
    return bin(n).count('1')

# Function declarations
def pullcomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def prevcomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def psllcomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def pcharcomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def pdoublecomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def pstrcomp(left: Union[int, float], right: Union[int, float]) -> int:
    return (left > right) - (left < right)

def phwllABcomp(left: hwll, right: hwll) -> int:
    return (left[0] > right[0]) - (left[0] < right[0])

def phwllREVcomp(left: hwll, right: hwll) -> int:
    return (left[0] < right[0]) - (left[0] > right[0])

def ptriplecomp(left: Tuple[int, int, int], right: Tuple[int, int, int]) -> int:
    if left[0] != right[0]:
        return (left[0] > right[0]) - (left[0] < right[0])
    if left[1] != right[1]:
        return (left[1] > right[1]) - (left[1] < right[1])
    return (left[2] > right[2]) - (left[2] < right[2])

def ptripleREVcomp(left: Tuple[int, int, int], right: Tuple[int, int, int]) -> int:
    if left[0] != right[0]:
        return (left[0] < right[0]) - (left[0] > right[0])
    if left[1] != right[1]:
        return (left[1] < right[1]) - (left[1] > right[1])
    return (left[2] < right[2]) - (left[2] > right[2])

def ptripleCABcomp(left: Tuple[int, int, int], right: Tuple[int, int, int]) -> int:
    if left[0] != right[0]:
        return (left[0] > right[0]) - (left[0] < right[0])
    if left[1] != right[1]:
        return (left[1] > right[1]) - (left[1] < right[1])
    return (left[2] > right[2]) - (left[2] < right[2])

def pquadcomp(left: Tuple[int, int, int, int], right: Tuple[int, int, int, int]) -> int:
    if left[0] != right[0]:
        return (left[0] > right[0]) - (left[0] < right[0])
    if left[1] != right[1]:
        return (left[1] > right[1]) - (left[1] < right[1])
    if left[2] != right[2]:
        return (left[2] > right[2]) - (left[2] < right[2])
    return (left[3] > right[3]) - (left[3] < right[3])

def pfracomp(left: Tuple[int, int, int, int], right: Tuple[int, int, int, int]) -> int:
    if left[0] != right[0]:
        return (left[0] > right[0]) - (left[0] < right[0])
    if left[1] != right[1]:
        return (left[1] > right[1]) - (left[1] < right[1])
    if left[2] != right[2]:
        return (left[2] > right[2]) - (left[2] < right[2])
    return (left[3] > right[3]) - (left[3] < right[3])

def isinrange(left: int, x: int, right: int) -> bool:
    return left <= x <= right

def isinrange_soft(left: int, x: int, right: int) -> bool:
    return left <= x <= right

def sw(l: int, r: int) -> None:
    l, r = r, l

def ncr(n: int, r: int, m: int) -> int:
    if r > n - r:
        r = n - r
    num = 1
    denom = 1
    for i in range(1, r + 1):
        num = (num * (n - i + 1)) % m
        denom = (denom * i) % m
    return (num * pow(denom, m - 2, m)) % m

# Main function implementation
def main() -> int:
    global n, m
    i, j = 0, 0

    # Initialize variables
    n = 4
    m = 0

    # Read input values
    # s = input().strip()
    # Initialize arrays
    a = [0] * N_MAX
    b = [0] * N_MAX
    c = [0] * N_MAX

    # Read input values
    n = int(input().strip())
    b = list(map(int, input().strip().split()))

    # Read input values
    m = int(input().strip())
    c = list(map(int, input().strip().split()))

    # Call the solve function
    solve()

    # Terminate the program
    return 0

# Main function implementation
def solve() -> int:
    global n, m
    i, j = 0, 0
    result = 1
    cnt = [0] * 3
    pcnt = 0

    s = input().strip()

    for i in range(n * 3):
        v = 0
        if s[i] == 'R':
            v = 0
        elif s[i] == 'G':
            v = 1
        elif s[i] == 'B':
            v = 2

        if cnt[(v + 1) % 3] and cnt[(v + 2) % 3]:
            result *= pcnt
            pcnt -= 1
            result %= FOD
            cnt[(v + 1) % 3] -= 1
            cnt[(v + 2) % 3] -= 1
        else:
            if (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) > cnt[v]:
                result *= (cnt[(v + 1) % 3] + cnt[(v + 2) % 3]) - cnt[v]
                result %= FOD
                pcnt += 1
            cnt[v] += 1

    for i in range(1, n + 1):
        result = (result * i) % FOD

    print(result)
    return 0

# Call the main function
if __name__ == "__main__":
    main()

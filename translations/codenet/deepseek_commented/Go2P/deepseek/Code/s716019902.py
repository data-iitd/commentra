mod = 998244353
facNum = 300001

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    sum_ = 0
    for i in range(1, N + 1):
        if i % 3 == 0 or i % 5 == 0:
            continue
        sum_ += i
    print(sum_)

# I/O
import sys
input = sys.stdin.readline

def s():
    return input().strip()

def i():
    return int(s())

def f():
    return float(s())

def bs():
    return s().encode()

def is_(n):
    return [i() for _ in range(n)]

def fs(n):
    return [f() for _ in range(n)]

#const factorial = new
def Pow(a, n):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n >>= 1
    return ans

def Gcd(a, b):
    if a < b:
        return Gcd(b, a)
    while b != 0:
        a, b = b, a % b
    return a

def min_(a, b):
    return a if a < b else b

def combination(n, k):
    if n < k or n < 0:
        return 0
    if k == 0:
        return 1
    ans = ifac[k] * ifac[n-k] % mod
    return ans * fac[n] % mod

# 階乗: factorial
# コンビネーションを計算する際に前もって計算しておく
# fac[k] => k! (mod M)
# ifac[k] => k!^(M-2) (mod M)
# n: ex. 2 * 10^5 => 200001
# fac, ifac := factorial()
def factorial():
    fac = [0] * facNum
    fac[0] = 1
    ifac = [0] * facNum
    ifac[0] = 1
    for i in range(1, facNum):
        fac[i] = fac[i-1] * i % mod
        ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod
    return fac, ifac

# vs: sorted slice int value
def lowerBound(vs, v):
    n = len(vs) // 2
    m = len(vs)
    while m != n:
        if vs[n] < v:
            n = (m - n + 1) // 2 + n
        else:
            m = n
            n = n // 2
    return n

def IntSlice(n, init):
    return [init] * n

# Main function call
fac, ifac = factorial()
main()

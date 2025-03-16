import sys
from functools import reduce

# Constants
MOD = 1000000007

def modpow(a, n):
    res = 1
    while n > 0:
        if n & 1 == 1:
            res = res * a % MOD
        a = a * a % MOD
        n >>= 1
    return res

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    c = list(map(int, data[1:n+1]))
    
    ans = 0
    c.sort()
    
    for i in range(n):
        ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD
    
    print(ans * modpow(4, n - 1) % MOD)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

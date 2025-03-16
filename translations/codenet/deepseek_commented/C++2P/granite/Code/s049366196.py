
import sys
input = sys.stdin.readline

def is_prime(x):
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True

N = int(input())
mod = 10**9+7
ans = 1
for i in range(2, N+1):
    if is_prime(i):
        cnt = 0
        NN = N
        while NN:
            cnt += NN // i
            NN //= i
        ans *= cnt+1
        ans %= mod

print(ans)


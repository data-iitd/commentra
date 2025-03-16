
import math

MX = 10000
sieve = [0] * MX
primes = []
for i in range(2, MX):
    if sieve[i]!= 0:
        continue
    primes.append(i)
    for j in range(i + i, MX, i):
        sieve[j] = i

n = int(input())
ans = 0
for _ in range(n):
    x = int(input())
    ans += 1
    for p in primes:
        if x > p and x % p == 0:
            ans -= 1
            break
print(ans)

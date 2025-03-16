import math
import sys

n, m = map(int, sys.stdin.readline().split())
gcd = math.gcd(n, m)
s, t = sys.stdin.readline().strip(), sys.stdin.readline().strip()

# Filtering the range of the GCD and checking character mismatches
print(
    next(
        (k for k in range(gcd) if s[k * n // gcd] != t[k * m // gcd]),
        math.prod(range(n, n + m // gcd))
    )
)



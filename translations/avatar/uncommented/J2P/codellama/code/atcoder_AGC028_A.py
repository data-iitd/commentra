import math
import sys

n, m = map(int, sys.stdin.readline().split())
gcd = math.gcd(n, m)
s, t = sys.stdin.readline().strip(), sys.stdin.readline().strip()

print(sum(1 for i in range(gcd) if s[i * n // gcd] != t[i * m // gcd]))


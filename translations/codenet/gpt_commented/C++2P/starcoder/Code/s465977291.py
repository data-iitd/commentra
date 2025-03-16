# Define a type alias for long long to simplify code
from math import ceil

n, d = map(int, input().split())
a = d * 2 + 1
print(ceil(n / a))


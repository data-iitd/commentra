import sys
import math

def solve():
    n = int(input().strip())
    as_ = list(map(int, input().strip().split()))

    xs = [a - i + 1 for i, a in enumerate(as_)]
    xs.sort()

    b = xs[n // 2]
    ans = sum(abs(x - b) for x in xs)
    print(ans)

# -----------------------------------------

# <END-OF-CODE>
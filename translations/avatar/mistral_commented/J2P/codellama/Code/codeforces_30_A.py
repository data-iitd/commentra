
import math

def solve(A, B, n):
    if A == 0:
        if B == 0:
            return 1
        else:
            return "No solution"
    if B % A != 0:
        return "No solution"
    B /= A
    neg = B < 0
    if neg and n % 2 == 0:
        return "No solution"
    if neg:
        B = -B
    for x in range(0, B + 1):
        if math.pow(x, n) == B:
            return x if not neg else -x
    return "No solution"

# 
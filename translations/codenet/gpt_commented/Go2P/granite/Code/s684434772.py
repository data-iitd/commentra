
import sys

def main():
    n, k = map(int, input().split())
    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total %= (10 ** 9 + 7)
    print(total)

def combi(n, k):
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    return max_val - min_val + 1

# util
# *   math/simple

def abs(x):
    if x >= 0:
        return x
    return -x

def min(*values):
    if len(values) == 0:
        raise ValueError("no values")
    min_val = values[0]
    for v in values:
        if v < min_val:
            min_val = v
    return min_val

def max(*values):
    if len(values) == 0:
        raise ValueError("no values")
    max_val = values[0]
    for v in values:
        if v > max_val:
            max_val = v
    return max_val

def pow(base, exponent):
    answer = 1
    for _ in range(exponent):
        answer *= base
    return answer

def abs64(x):
    if x >= 0:
        return x
    return -x

def min64(*values):
    if len(values) == 0:
        raise ValueError("no values")
    min_val = values[0]
    for v in values:
        if v < min_val:
            min_val = v
    return min_val

def max64(*values):
    if len(values) == 0:
        raise ValueError("no values")
    max_val = values[0]
    for v in values:
        if v > max_val:
            max_val = v
    return max_val

def pow64(base, exponent):
    answer = 1
    for _ in range(exponent):
        answer *= base
    return answer

# *   io

class Scanner:
    def __init__(self):
        self.bufScanner = iter(sys.stdin.read().split())

    def readString(self):
        return next(self.bufScanner)

    def readInt(self):
        return int(self.readString())

    def readInt64(self):
        return int(self.readString())

# 
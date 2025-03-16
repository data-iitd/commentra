
import sys

def main():
    n, k = map(int, input().split())
    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total %= (10 ** 9 + 7)
    print(total)

def combi(n, k):
    min_ = (k - 1) * k // 2
    max_ = (2 * n - k + 1) * k // 2
    return max_ - min_ + 1

# util
# *   math/simple

def abs(x):
    if x >= 0:
        return x
    return -x

def min_(*values):
    if len(values) == 0:
        raise ValueError("no values")
    min_ = values[0]
    for v in values:
        if v < min_:
            min_ = v
    return min_

def max_(*values):
    if len(values) == 0:
        raise ValueError("no values")
    max_ = values[0]
    for v in values:
        if v > max_:
            max_ = v
    return max_

def pow(base, exponent):
    answer = 1
    for _ in range(exponent):
        answer *= base
    return answer

def abs64(x):
    if x >= 0:
        return x
    return -x

def min_64(*values):
    if len(values) == 0:
        raise ValueError("no values")
    min_ = values[0]
    for v in values:
        if v < min_:
            min_ = v
    return min_

def max_64(*values):
    if len(values) == 0:
        raise ValueError("no values")
    max_ = values[0]
    for v in values:
        if v > max_:
            max_ = v
    return max_

def pow64(base, exponent):
    answer = 1
    for _ in range(exponent):
        answer *= base
    return answer

# *   io

class Scanner:
    def __init__(self):
        self.bufScanner = iter(sys.stdin.read().split())

    def read_string(self):
        return next(self.bufScanner)

    def read_int(self):
        return int(self.read_string())

    def read_int64(self):
        return int(self.read_string())

# 
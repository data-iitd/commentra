import sys

def main():
    sc = Scanner()

    n = sc.read_int()
    k = sc.read_int()

    total = 0
    for i in range(k, n + 2):
        total += combi(n, i)
        total = total % (pow(10, 9) + 7)
    print(total)

def combi(n, k):
    min_val = (k - 1) * k // 2
    max_val = (2 * n - k + 1) * k // 2
    return max_val - min_val + 1

# Utility functions
def abs_val(x):
    return x if x >= 0 else -x

def min_val(*values):
    if not values:
        raise ValueError("no values")
    return min(values)

def max_val(*values):
    if not values:
        raise ValueError("no values")
    return max(values)

def pow_val(base, exponent):
    answer = 1
    for _ in range(exponent):
        answer *= base
    return answer

class Scanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def read_string(self):
        if self.index < len(self.buffer):
            result = self.buffer[self.index]
            self.index += 1
            return result
        return ""

    def read_int(self):
        return int(self.read_string())

    def read_int64(self):
        return int(self.read_string())

if __name__ == "__main__":
    main()

# <END-OF-CODE>

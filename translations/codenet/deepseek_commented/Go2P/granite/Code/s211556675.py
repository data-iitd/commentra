
import sys

# I/O
def next_str():
    return input()

def next_int():
    return int(next_str())

def next_float():
    return float(next_str())

def next_rune_slice():
    return list(next_str())

def next_int_slice(n):
    return [next_int() for _ in range(n)]

def next_float_slice(n):
    return [next_float() for _ in range(n)]

# Arithmetic
def max(*nums):
    return max(nums)

def min(*nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return pow(x, y)

# Sort
class Val:
    def __init__(self, id, num):
        self.id = id
        self.num = num

class ByNum(list):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def __lt__(self, other):
        return self.num < other.num

# Main
def main():
    A = next_int()
    B = next_int()
    C = next_int()
    K = next_int()

    ma = max(A, B, C)

    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    for _ in range(K):
        ma *= 2

    print(ma + rest)

if __name__ == '__main__':
    main()


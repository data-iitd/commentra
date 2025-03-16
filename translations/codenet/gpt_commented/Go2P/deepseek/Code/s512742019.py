import sys
import math

# I/O
class Scanner:
    def __init__(self, input_stream):
        self.sc = input_stream

    def next_str(self):
        return self.sc.readline().strip()

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_rune_slice(self):
        return list(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

    def next_float_slice(self, n):
        return [self.next_float() for _ in range(n)]

# Arithmetic
def max(nums):
    return max(nums)

def min(nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return x ** y

def ceil(a, b):
    return -(-a // b) if a % b != 0 else a // b

# Sort
class RuneSlice(list):
    def __lt__(self, other):
        return self < other

# Main
MOD = 10**9 + 7
INF = 1 << 60

class Mon:
    def __init__(self, x, h):
        self.x = x
        self.h = h

class Mons(list):
    def __lt__(self, other):
        return self[0].x < other[0].x

class Node:
    def __init__(self, x, h):
        self.x = x
        self.h = h

class Queue:
    def __init__(self):
        self.arr = []

    def push(self, v):
        self.arr.append(v)

    def first(self):
        return self.arr[0]

    def pop(self):
        res = self.arr[0]
        self.arr = self.arr[1:]
        return res

    def is_empty(self):
        return len(self.arr) == 0

# main function to execute the program logic
def main():
    input_stream = sys.stdin
    sc = Scanner(input_stream)
    wtr = sys.stdout

    N, D, A = sc.next_int(), sc.next_int(), sc.next_int()
    M = [Mon(sc.next_int(), sc.next_int()) for _ in range(N)]
    M.sort(key=lambda m: m.x)

    q = Queue()
    ans = 0
    total = 0

    for m in M:
        while not q.is_empty() and q.first().x < m.x:
            total -= q.pop().h
        if total < m.h:
            m.h -= total
            count = math.ceil(m.h / A)
            ans += count
            damage = count * A
            q.push(Node(m.x + 2 * D, damage))
            total += damage

    print(ans, file=wtr)

if __name__ == "__main__":
    main()

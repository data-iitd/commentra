import sys
import math
import os
import io
import heapq
import bisect
from collections import defaultdict, deque, Counter

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.current_pos = 0
        self.buffer_len = 0
        self.newlines = 0

    def readline(self):
        while self.newlines == 0:
            b = os.read(0, max(os.fstat(0).st_size, 1024))
            self.buffer_len = len(b)
            self.buffer.write(b)
            self.newlines = b.count(b'\n') + (not b)
        self.newlines -= 1
        p = self.buffer.tell()
        self.buffer.seek(self.current_pos)
        result = self.buffer.readline()
        self.buffer.seek(p)
        self.current_pos = self.buffer.tell()
        return result.decode()

    def read(self):
        while self.newlines == 0:
            b = os.read(0, max(os.fstat(0).st_size, 1024))
            self.buffer_len = len(b)
            self.buffer.write(b)
            self.newlines = b.count(b'\n') + (not b)
        self.newlines -= 1
        p = self.buffer.tell()
        self.buffer.seek(self.current_pos)
        result = self.buffer.read()
        self.buffer.seek(p)
        self.current_pos = self.buffer.tell()
        return result.decode()

    def readline_strip(self):
        return self.readline().strip()

    def read_strip(self):
        return self.read().strip()

    def read_int(self):
        return int(self.readline())

    def read_ints(self, sep=None):
        return list(map(int, self.readline().split(sep)))

    def read_float(self):
        return float(self.readline())

    def read_floats(self, sep=None):
        return list(map(float, self.readline().split(sep)))

    def read_list(self, sep=None):
        return list(self.readline().split(sep))

    def read_list_int(self, sep=None):
        return list(map(int, self.readline().split(sep)))

    def read_list_float(self, sep=None):
        return list(map(float, self.readline().split(sep)))

    def read_matrix(self, n, m, sep=None):
        matrix = []
        for _ in range(n):
            row = self.read_list_int(sep)
            matrix.append(row)
        return matrix

    def read_matrix_float(self, n, m, sep=None):
        matrix = []
        for _ in range(n):
            row = self.read_list_float(sep)
            matrix.append(row)
        return matrix

def mod_power(x, y, mod):
    res = 1
    x %= mod
    if x == 0:
        return 0
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % mod
        y = y >> 1
        x = (x * x) % mod
    return res

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

    def __repr__(self):
        return f"({self.first}, {self.second})"

def main():
    inp = FastReader()
    a = [0] * 4
    for i in range(4):
        a[i] = inp.read_long()
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))
    print(result)

if __name__ == "__main__":
    main()

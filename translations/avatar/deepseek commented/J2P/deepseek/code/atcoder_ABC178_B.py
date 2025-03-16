import sys
import math
import io
import os
import sys

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()

    def read(self):
        while True:
            b = os.read(0, 1)
            if not b:
                break
            yield b.decode('utf-8')

    def read_ints(self):
        return list(map(int, self.readline().split()))

    def read_longs(self):
        return list(map(int, self.readline().split()))

    def read_float(self):
        return list(map(float, self.readline().split()))

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

def main():
    inp = FastReader()
    a = inp.read_longs()
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

if __name__ == "__main__":
    main()

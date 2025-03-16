import sys
import math
import io
import os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

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
    a = list(map(int, input().split()))
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

if __name__ == "__main__":
    main()

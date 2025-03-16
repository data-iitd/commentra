import sys
import io
import os
import math
import re
import time
from sys import stdin, stdout
from io import BytesIO
from collections import defaultdict, Counter, deque

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.buf = ""
        self.idx = 0
        self.k = 128

    def next(self):
        while self.idx < len(self.buf):
            char = self.buf[self.idx]
            self.idx += 1
            if char != " ":
                return char
        self.buf = os.read(0, max(os.fstat(0).st_size, self.k))
        self.idx = 0
        return self.next()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return sys.stdin.readline().strip()

def main():
    sc = FastReader()
    x = sc.nextInt()
    count = 0
    tmp = x
    x = 0
    while x != 360:
        x = x + tmp
        if x > 360:
            x = x - 360
        count += 1
    print(count)

if __name__ == "__main__":
    main()

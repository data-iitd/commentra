import sys
import io
import os
import re
import math
import array
import itertools
import collections

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().splitlines()
        self.index = 0

    def next(self):
        while self.index < len(self.buffer) and not self.buffer[self.index]:
            self.index += 1
        if self.index >= len(self.buffer):
            return None
        result = self.buffer[self.index]
        self.index += 1
        return result

    def nextLine(self):
        while self.index < len(self.buffer) and not self.buffer[self.index]:
            self.index += 1
        if self.index >= len(self.buffer):
            return None
        result = self.buffer[self.index]
        self.index += 1
        return result

    def nextByte(self):
        return int(self.next())

    def nextShort(self):
        return int(self.next())

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

def main():
    inp = FastScanner()
    n = inp.nextInt()

    max_sum = 0

    for _ in range(n):
        f = inp.nextInt()
        t = inp.nextInt()

        current_sum = f + t

        if max_sum < current_sum:
            max_sum = current_sum

    print(max_sum)

if __name__ == "__main__":
    main()


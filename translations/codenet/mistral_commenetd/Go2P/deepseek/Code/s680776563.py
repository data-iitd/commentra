import sys
import io
import os
import math

class FastScanner:
    def __init__(self, input):
        self.input = input
        self.buf = []
        self.p = 0

    def next(self):
        while self.p >= len(self.buf):
            self.buf.extend(self.input.readline().split())
        result = self.buf[self.p]
        self.p += 1
        return result

    def next_int(self):
        return int(self.next())

def main():
    input = sys.stdin
    fsc = FastScanner(input)

    A, B, C = fsc.next_int(), fsc.next_int(), fsc.next_int()

    if B - A == C - B:
        print("YES")
    else:
        print("NO")


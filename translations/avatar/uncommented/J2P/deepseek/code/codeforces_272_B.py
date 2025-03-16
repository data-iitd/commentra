import sys
import io
import os
import math

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.tokens = []

    def next(self):
        while not self.tokens:
            line = self.buffer.readline().decode('utf-8')
            if not line:
                return None
            self.tokens = line.split()
        return self.tokens.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.buffer.readline().decode('utf-8').strip()

def rec(x):
    answer = 0
    while x > 0:
        answer += x & 1
        x >>= 1
    return answer

def main():
    sc = FastReader()
    out = sys.stdout.write
    n = sc.next_int()
    a = [0] * 33
    for i in range(n):
        a[rec(sc.next_int())] += 1
    answer = 0
    for i in range(len(a)):
        summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1)
        answer += summ
    out(f"{int(answer)}\n")

if __name__ == "__main__":
    main()

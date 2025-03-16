import sys
import math
from collections import deque

magic = 1000000007

def find(n, p, N):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

def solve():
    io = Io()
    io.flush()

    # PARSE HELPER SESSION
    X = io.next_int()
    N = io.next_int()
    p = [io.next_int() for _ in range(N)]
    print(f"p {p[:10]}")

    for i in range(101):
        if find(X - i, p, N) == 1:
            print(X - i)
            sys.exit(0)
        if find(X + i, p, N) == 1:
            print(X + i)
            sys.exit(0)

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.nextToken = 0

    def flush(self):
        self.writer.flush()

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        while self.nextToken >= len(self.tokens):
            line = self.next_line()
            self.tokens = line.split()
            self.nextToken = 0
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r

    def next_int(self):
        return int(self.next())

    def next_float(self):
        return float(self.next())

    def print_ln(self, *args):
        print(*args, file=self.writer)

    def print_f(self, format, *args):
        print(format % args, file=self.writer)

    def print_int_ln(self, a):
        self.print_ln(a)

    def print_string_ln(self, a):
        self.print_ln(a)

def main():
    solve()

if __name__ == "__main__":
    main()

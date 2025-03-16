
import math
import sys

def run(r, w):
    sc = Scanner(r)

    a = sc.readline().ints()
    N, D = a[0], a[1]

    lines = sc.readlines(N).ints()

    count = 0
    for line in lines:
        d = math.sqrt(line[0]*line[0] + line[1]*line[1])
        if D >= d:
            count += 1
    print(count, file=w)

def main():
    run(sys.stdin, sys.stdout)

class Scanner:
    def __init__(self, r):
        self.sc = iter(r.read().splitlines())

    def readline(self):
        return Value(next(self.sc))

    def readlines(self, n):
        return [self.readline() for _ in range(n)]

class Value:
    def __init__(self, s):
        self.s = s

    def __str__(self):
        return self.s

    def __int__(self):
        return int(self.s)

    def __float__(self):
        return float(self.s)

    def strings(self):
        return self.s.split()

    def ints(self):
        return [int(s) for s in self.strings()]

    def float64s(self):
        return [float(s) for s in self.strings()]

    def runes(self):
        return list(self.s)

class Values:
    def __init__(self, values):
        self.values = values

    def strings(self):
        return [value.strings() for value in self.values]

    def ints(self):
        return [value.ints() for value in self.values]

    def float64s(self):
        return [value.float64s() for value in self.values]

    def runes(self):
        return [value.runes() for value in self.values]

if __name__ == "__main__":
    run(sys.stdin, sys.stdout)


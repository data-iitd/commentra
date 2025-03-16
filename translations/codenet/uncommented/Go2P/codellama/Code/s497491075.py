
import sys

def run(r, w):
    sc = Scanner(r)

    a = sc.readline().ints()
    N, D = a[0], a[1]

    lines = sc.readlines(N).ints()

    count = 0
    for line in lines:
        d = math.sqrt(line[0]**2 + line[1]**2)
        if D >= d:
            count += 1
    print(count, file=w)

class Scanner:
    def __init__(self, r):
        self.sc = bufio.Scanner(r)

    def readline(self):
        if self.sc.scan():
            return Value(self.sc.text())
        raise Exception("scan error")

    def readlines(self, n):
        a = []
        for i in range(n):
            a.append(self.readline())
        return Values(a)

class Value:
    def __init__(self, s):
        self.s = s

    def string(self):
        return self.s

    def int(self):
        return int(self.s)

    def float64(self):
        return float(self.s)

    def strings(self):
        return self.s.split(" ")

    def ints(self):
        a = []
        for s in self.strings():
            a.append(int(s))
        return a

    def float64s(self):
        a = []
        for s in self.strings():
            a.append(float(s))
        return a

    def runes(self):
        return list(self.s)

class Values:
    def __init__(self, a):
        self.a = a

    def strings(self):
        a = []
        for value in self.a:
            a.append(value.strings())
        return a

    def ints(self):
        a = []
        for value in self.a:
            a.append(value.ints())
        return a

    def float64s(self):
        a = []
        for value in self.a:
            a.append(value.float64s())
        return a

    def runes(self):
        a = []
        for value in self.a:
            a.append(value.runes())
        return a

if __name__ == "__main__":
    run(sys.stdin, sys.stdout)


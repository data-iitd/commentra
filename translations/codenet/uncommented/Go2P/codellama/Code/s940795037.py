
import sys

def main():
    sc = Scanner()

    n = sc.nextInt()
    ans = 0.0
    for i in range(n):
        tmp = 1 / float(sc.nextInt())
        ans += tmp
    print(1/ans)

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = self.r.readline()
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for self.p in range(len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = self.buf[start:self.p]
        self.p += 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def nextInt(self):
        v, _ = int(self.next()), 0
        return v

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p in range(len(self.buf)):
            if self.buf[self.p] == ' ':
                v, _ = int(self.buf[start:self.p]), 0
                result.append(v)
                start = self.p + 1
        v, _ = int(self.buf[start:self.p]), 0
        result.append(v)

        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for self.p in range(len(self.buf)):
            if self.buf[self.p] == ' ':
                v, _ = int(self.buf[start:self.p]), 0
                mp[v] = True
                start = self.p + 1
        v, _ = int(self.buf[start:self.p]), 0
        mp[v] = True

        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = self.r.readline()



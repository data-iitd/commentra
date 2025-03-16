
import sys

def main():
    sc = Scanner()
    A, B = sc.nextInt(), sc.nextInt()

    mx = max(A+B, A-B)
    mx = max(mx, A*B)
    print(mx)

def max(a, b):
    if a < b:
        return b
    return a

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p++
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self):
        v, _ = int(self.next()), 0
        return v

    def nextInt64(self):
        v, _ = int(self.next()), 0
        return v

    def nextFloat(self):
        v, _ = float(self.next()), 0
        return v

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = int(''.join(self.buf[start:self.p])), 0
                result.append(v)
                start = self.p + 1
        v, _ = int(''.join(self.buf[start:self.p])), 0
        result.append(v)

        return result

    def nextInt64Array(self):
        self.pre()
        start = self.p
        result = []
        for ; self.p < len(self.buf)+1; self.p++:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v, _ = int(''.join(self.buf[start:self.p])), 0
                result.append(v)
                start = self.p + 1
        v, _ = int(''.join(self.buf[start:self.p])), 0
        result.append(v)

        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                v, _ = int(''.join(self.buf[start:self.p])), 0
                mp[v] = True
                start = self.p + 1
        v, _ = int(''.join(self.buf[start:self.p])), 0
        mp[v] = True

        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for ; True;:
            l, p, e = self.r.readline()
            if e != None:
                panic(e)
            self.buf.extend(l)
            if not p:
                break

# 
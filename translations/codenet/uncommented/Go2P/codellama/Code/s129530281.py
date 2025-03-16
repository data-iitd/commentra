
import sys

def getScanner(fp):
    scanner = fp.read().split()
    return scanner

def getNextString(scanner):
    return scanner.pop(0)

def getNextInt(scanner):
    return int(getNextString(scanner))

def getNextInt64(scanner):
    return int(getNextString(scanner))

def getNextUint64(scanner):
    return int(getNextString(scanner))

def getNextFloat64(scanner):
    return float(getNextString(scanner))

def main():
    fp = sys.stdin
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r')
    scanner = getScanner(fp)
    writer = sys.stdout

    n = getNextInt(scanner)
    m = getNextInt(scanner)
    seg = Segment()
    seg.init(n)
    for i in range(n):
        seg.maximize(i, getNextInt(scanner))
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1)

    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i]

    print(ans)

class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    def init(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [[0] * n]

        chunk = 8
        for i in range(0, len(self.unit)):
            n = (n - 1) // chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[i] * chunk)

        self.h = len(self.unit)
        self.chunk = chunk

    def maximize(self, index, value):
        self.bucket[0][index] = value
        for self.i in range(0, self.h - 1):
            s = index - index % self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            parent = index // self.chunk
            max = 0
            for i in range(s, t):
                if max < self.bucket[self.i][i]:
                    max = self.bucket[self.i][i]
            self.bucket[self.i + 1][parent] = max
            index //= self.chunk

    def top(self):
        index = 0
        for self.i in range(self.h - 2, -1, -1):
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i + 1][index]:
                    index = i
                    break

        return index


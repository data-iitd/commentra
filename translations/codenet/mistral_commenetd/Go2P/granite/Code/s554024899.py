

import sys

def main():
    sc = Scanner()
    x = sc.nextInt()
    y = sc.nextInt()
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]
    xt = -1
    yt = -1
    for i, t in enumerate(a):
        for n in t:
            if x == n:
                xt = i
            if y == n:
                yt = i
    if xt == yt:
        print("Yes")
    else:
        print("No")

class Scanner:
    def __init__(self):
        self.rdr = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 1000)
        self.buf = ""
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def nextInt(self):
        v = int(self.next())
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = self.rdr.readline()


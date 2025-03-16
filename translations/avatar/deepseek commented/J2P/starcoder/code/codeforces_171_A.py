
import sys

class Main:
    def __init__(self):
        self.sc = FastReader()
        self.n = self.sc.nextInt()
        self.m = self.sc.nextInt()
        self.t = self.reverse(self.m)
        print(self.t + self.n)

    def reverse(self, n):
        if n < 10:
            return n * 10
        t = n
        r = 0
        while t > 0:
            r = (r * 10) + t % 10
            t = t // 10
        return r

class FastReader:
    def __init__(self):
        self.r = sys.stdin.buffer
        self.buf = bytearray()
        self.pos = 0
        self.pend = 0

    def readline(self):
        while self.pend <= self.pos:
            self.buf += self.r.read()
            self.pend = len(self.buf)
        line = self.buf[self.pos:self.pend]
        self.pos = self.pend
        return line

    def next(self):
        while self.pend <= self.pos:
            self.buf += self.r.read()
            self.pend = len(self.buf)
        line = self.buf[self.pos:self.pend]
        self.pos = self.pend
        return line.decode().strip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

if __name__ == '__main__':
    obj = Main()


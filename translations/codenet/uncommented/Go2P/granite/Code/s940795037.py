
import bufio
import os
import sys

def main():
    sc = Scanner()

    n = sc.next_int()
    ans = 0.0
    for i in range(n):
        tmp = 1 / float(sc.next_int())
        ans += tmp
    print(1 / ans)

class Scanner:
    def __init__(self):
        self.rdr = bufio.NewReaderSize(sys.stdin, 1000)
        self.buf = ""
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                break
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    def next_line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    def next_int(self):
        return int(self.next())

    def next_int_array(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                result.append(int(self.buf[start:self.p]))
                start = self.p + 1
            self.p += 1
        result.append(int(self.buf[start:self.p]))
        return result

    def next_map(self):
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                mp[int(self.buf[start:self.p])] = True
                start = self.p + 1
            self.p += 1
        mp[int(self.buf[start:self.p])] = True
        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.read_line()
            self.p = 0

    def read_line(self):
        self.buf = ""
        while True:
            l = self.rdr.readline()
            if not l:
                break
            self.buf += l.strip()

# 
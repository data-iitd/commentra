
import bufio
import os
import sys

def main():
    sc = Scanner()
    A, B = sc.next_int(), sc.next_int()

    mx = max(A+B, A-B)
    mx = max(mx, A*B)
    print(mx)

def max(a, b):
    if a < b:
        return b
    return a

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
        while self.p < len(self.buf) and self.buf[self.p]!='':
            if self.buf[self.p] =='':
                result.append(int(self.buf[start:self.p]))
                start = self.p + 1
            self.p += 1
        result.append(int(self.buf[start:self.p]))
        self.p += 1
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
        self.buf = self.rdr.readline()


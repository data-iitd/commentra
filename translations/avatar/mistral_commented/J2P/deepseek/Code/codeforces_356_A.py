import sys
import io
import os
import sys
import math
import bisect
import heapq
import itertools
from collections import deque
from functools import lru_cache
from sys import stdin, stdout

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.current = 0
        self.buffer_len = 0

    def readline(self):
        return self.buffer.readline().decode().strip()

    def read(self):
        while self.current >= self.buffer_len:
            self.buffer_len = os.read(0, 1024)
            self.buffer.truncate(self.buffer_len)
            self.buffer.seek(0)
            self.current = 0
        result = self.buffer.read(1)[0]
        self.current += 1
        return result

    def readline_strip(self):
        return self.buffer.readline().decode().strip()

    def read_int(self):
        result = 0
        neg = False
        c = self.read()
        while c < b'0' or c > b'9':
            if c == b'-':
                neg = True
            c = self.read()
        while c >= b'0' and c <= b'9':
            result = result * 10 + (c & 0x0F)
            c = self.read()
        return -result if neg else result

    def read_float(self):
        result = 0.0
        neg = False
        c = self.read()
        while c < b'0' or c > b'9':
            if c == b'-':
                neg = True
            c = self.read()
        while c >= b'0' and c <= b'9':
            result = result * 10 + (c & 0x0F)
            c = self.read()
        if c == b'.':
            c = self.read()
            decimal = 0.1
            while c >= b'0' and c <= b'9':
                result += (c & 0x0F) * decimal
                decimal /= 10
                c = self.read()
        return -result if neg else result

    def read_word(self):
        c = self.read()
        while c == b' ' or c == b'\n' or c == b'\r' or c == b'\t':
            c = self.read()
        result = b''
        while c != b' ' and c != b'\n' and c != b'\r' and c != b'\t':
            result += bytes([c])
            c = self.read()
        return result.decode()

    def read_line(self):
        result = b''
        c = self.read()
        while c != b'\n' and c != b'\r':
            result += bytes([c])
            c = self.read()
        return result.decode()

class Main:
    def __init__(self):
        self.in_ = FastReader()

    def main(self):
        n = self.in_.read_int()
        left = sortedcontainers.SortedList()
        answer = [-1] * n

        for i in range(n):
            left.add(i)

        q = self.in_.read_int()

        for _ in range(q):
            l = self.in_.read_int() - 1
            r = self.in_.read_int() - 1
            win = self.in_.read_int() - 1

            idx = left.bisect_left(l)
            while idx < len(left) and left[idx] <= r:
                answer[left[idx]] = win
                left.pop(idx)

            answer[win] = 0
            left.add(win)

        ans = []
        for i in range(n):
            ans.append(str(answer[i]))
        print(' '.join(ans))

if __name__ == "__main__":
    main = Main()
    main.main()

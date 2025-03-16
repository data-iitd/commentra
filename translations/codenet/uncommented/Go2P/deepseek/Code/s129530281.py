import sys
import io
import os
import math

class Segment:
    def __init__(self, n):
        self.n = n
        self.unit = [1]
        self.bucket = [ [0] * n ]
        chunk = 8
        i = 0
        while n > 1:
            n = (n - 1) // chunk + 1
            self.bucket.append([0] * n)
            self.unit.append(self.unit[i] * chunk)
            i += 1
        self.h = len(self.unit)
        self.chunk = chunk

    def maximize(self, index, value):
        self.bucket[0][index] = value
        i = 0
        while i < self.h - 1:
            s = index - index % self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            parent = index // self.chunk
            max_val = 0
            for j in range(s, t):
                if max_val < self.bucket[i][j]:
                    max_val = self.bucket[i][j]
            self.bucket[i + 1][parent] = max_val
            index //= self.chunk
            i += 1

    def top(self):
        index = 0
        i = self.h - 2
        while i >= 0:
            s = index * self.chunk
            t = s + self.chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i])
            for j in range(s, t):
                if self.bucket[i][j] == self.bucket[i + 1][index]:
                    index = j
                    break
            i -= 1
        return index

def main():
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    if len(sys.argv) > 1:
        input_stream = open(sys.argv[1], 'r', encoding='utf-8')

    scanner = bufio.Scanner(input_stream)
    scanner.split(bufio.ScanWords)
    scanner.buffer(io.DEFAULT_BUFFER_SIZE)

    n = get_next_int(scanner)
    m = get_next_int(scanner)
    seg = Segment(n)
    for i in range(n):
        seg.maximize(i, get_next_int(scanner))
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] // 2)

    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i]

    print(ans)

def get_next_int(scanner):
    scanner.scan()
    return int(scanner.text)

if __name__ == "__main__":
    main()

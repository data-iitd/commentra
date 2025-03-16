
# <START-OF-CODE>

import sys

class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.off = 0
        self.end = 0
        self.reset()

    def reset(self):
        self.buf.seek(0)
        self.off = 0
        self.end = 0

    def readline(self):
        while self.end == self.off:
            self.off = self.buf.tell()
            self.end = self.buf.seek(0, 2)
            line = self.buf.read().decode()
            self.reset()
            return line
        self.buf.seek(self.off)
        line = self.buf.read(self.end - self.off).decode()
        self.off = self.buf.tell()
        return line

    def read(self):
        while self.end == self.off:
            self.off = self.buf.tell()
            self.end = self.buf.seek(0, 2)
            line = self.buf.read().decode()
            self.reset()
            return line
        self.buf.seek(self.off)
        line = self.buf.read(self.end - self.off).decode()
        self.off = self.buf.tell()
        return line

def main():
    reader = FastReader()
    n = int(reader.readline())
    left = set(range(n))
    answer = [0] * n
    q = int(reader.readline())
    while q > 0:
        l = int(reader.readline()) - 1
        r = int(reader.readline()) - 1
        win = int(reader.readline())
        while left and left.ceil(l) <= r:
            curr = left.ceil(l)
            answer[curr] = win
            left.remove(curr)
        answer[win - 1] = 0
        left.add(win - 1)
        q -= 1
    print(''.join(map(str, answer)))

if __name__ == '__main__':
    main()

# 
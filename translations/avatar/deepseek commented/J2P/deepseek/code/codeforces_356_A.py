import sys
import io
import os
import bisect

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def read(self):
        while True:
            c = self.buffer.read(1)
            if not c:
                break
            yield c

    def readline(self):
        line = []
        while True:
            c = self.buffer.read(1)
            if not c or c == b'\n':
                break
            line.append(c)
        return b''.join(line).decode('utf-8')

    def readInt(self):
        return int(self.readline())

    def readInts(self, n):
        return [int(self.readline()) for _ in range(n)]

    def readFloat(self):
        return float(self.readline())

    def readFloats(self, n):
        return [float(self.readline()) for _ in range(n)]

    def readString(self):
        return self.readline().strip()

    def readStrings(self, n):
        return [self.readline().strip() for _ in range(n)]

class Main:
    def main(self):
        inp = FastReader()
        n = inp.readInt()
        left = []
        answer = [0] * n
        for i in range(n):
            left.append(i)
        q = inp.readInt()
        while q > 0:
            q -= 1
            l = inp.readInt() - 1
            r = inp.readInt() - 1
            win = inp.readInt() - 1
            while left and left[0] >= l and left[0] <= r:
                curr = left.pop(0)
                answer[curr] = win + 1
            answer[win] = 0
            bisect.insort(left, win)
        print(''.join(map(str, answer)))

if __name__ == "__main__":
    Main().main()

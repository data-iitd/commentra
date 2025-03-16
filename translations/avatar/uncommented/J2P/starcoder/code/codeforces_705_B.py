
# <START-OF-CODE>

import sys

class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.lines = self.buf.readlines

    def __iter__(self):
        for line in self.lines():
            yield line.rstrip().decode('utf-8')

    def next(self):
        return next(self.__iter__())

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.next()

scan = FastReader()

def solve():
    t = scan.nextInt()
    arr = [0] * t
    for i in range(t):
        arr[i] = scan.nextInt()
    prevWinner = 0
    for i in range(t):
        if arr[i] == 1:
            if prevWinner == 0:
                prevWinner = 2
            else:
                prevWinner = 1
        if prevWinner == 2 or prevWinner == 0:
            if (arr[i] - 1) % 2 == 0:
                print(2)
                prevWinner = 2
            else:
                print(1)
                prevWinner = 1
        else:
            if (arr[i] - 1) % 2 == 0:
                print(1)
                prevWinner = 1
            else:
                print(2)
                prevWinner = 2

if __name__ == '__main__':
    solve()

# 
import sys
import io
import os
import sys

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def next(self):
        while self.buffer.tell() == 0:
            self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        return self.buffer.readline().decode().strip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.buffer.readline().decode().strip()

scan = FastReader()

def solve():
    t = scan.nextInt()
    arr = [scan.nextInt() for _ in range(t)]
    prevWinner = 0
    for i in range(t):
        if arr[i] == 1:
            if prevWinner == 0:
                prevWinner = 2
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

def main():
    t = 1
    while t > 0:
        solve()
        t -= 1

if __name__ == "__main__":
    main()

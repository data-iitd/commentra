import sys
import io
import os

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def read(self):
        while self.buffer.tell() == 0:
            os.read(0, 1024)
        return self.buffer.readline()

    def readline(self):
        return self.buffer.readline().decode().strip()

    def readInt(self):
        return int(self.read())

    def readFloat(self):
        return float(self.read())

    def readString(self):
        return self.read().decode().strip()

scan = FastReader()

def solve():
    t = int(scan.readInt())
    arr = [0] * t

    for i in range(t):
        arr[i] = int(scan.readInt())

        if arr[i] == 1:
            if prev_winner == 0:
                prev_winner = 2

            if (arr[i] - 1) % 2 == 0:
                print(prev_winner if prev_winner != 0 else 2)
                prev_winner = 2 if prev_winner == 0 else 1

prev_winner = 0

if __name__ == "__main__":
    solve()

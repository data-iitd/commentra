import sys
import io
import os
import math
import sys
import threading

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()

    def read(self):
        while True:
            b = os.read(0, 1)
            if not b:
                return None
            if b == b'\n':
                break
            self.buffer.write(b)
        return self.buffer.getvalue().decode('utf-8').strip()

    def read_int(self):
        return int(self.read())

    def read_ints(self):
        return list(map(int, self.read().split()))

    def read_float(self):
        return float(self.read())

    def read_floats(self):
        return list(map(float, self.read().split()))

    def read_str(self):
        return self.read()

    def read_strs(self):
        return self.read().split()

class Main:
    @staticmethod
    def main():
        sc = FastReader()
        x = sc.read_int()
        count = 0
        tmp = x
        x = 0
        while x != 360:
            x += tmp
            if x > 360:
                x -= 360
            count += 1
        print(count)

if __name__ == "__main__":
    Main.main()

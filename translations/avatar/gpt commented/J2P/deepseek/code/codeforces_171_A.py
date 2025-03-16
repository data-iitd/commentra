import sys
import io
import os

class FastReader(io.TextIOWrapper):
    def __init__(self, input_stream):
        super().__init__(input_stream.buffer)
        self.readline = input_stream.readline
        self.tokens = None

    def next(self):
        while self.tokens is None or not self.tokens:
            self.tokens = self.readline().split()
        return self.tokens.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.readline().strip()

def reverse(n):
    if n < 10:
        return n * 10
    t = n
    r = 0
    while t > 0:
        r = (r * 10) + (t % 10)
        t = t // 10
    return r

def main():
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    sc = FastReader(input_stream)

    n = sc.nextInt()
    m = sc.nextInt()

    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()


import sys

class FastReader:
    def __init__(self):
        self.buf = sys.stdin.buffer
        self.bufferedReader = io.BufferedReader(self.buf)
        self.tokenizer = None

    def readline(self):
        if self.tokenizer is None:
            self.tokenizer = io.StringIO(self.bufferedReader.readline().rstrip())
        return self.tokenizer.readline()

    def read(self):
        if self.tokenizer is None:
            self.tokenizer = io.StringIO(self.bufferedReader.read())
        return self.tokenizer.read()

    def next(self):
        if self.tokenizer is None:
            self.tokenizer = io.StringIO(self.bufferedReader.readline().rstrip())
        return self.tokenizer.__next__()

    def nextLine(self):
        return self.bufferedReader.readline().rstrip()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

class pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

def modPower(x, y, mod):
    res = 1
    x %= mod

    if x == 0:
        return 0

    while y > 0:
        if y % 2 == 1:
            res = (res * x) % mod
        y = y >> 1
        x = (x * x) % mod
    return res

def main():
    in = FastReader()
    a = [0] * 4
    for i in range(4):
        a[i] = in.nextLong()
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))
    print(result)

if __name__ == '__main__':
    main()


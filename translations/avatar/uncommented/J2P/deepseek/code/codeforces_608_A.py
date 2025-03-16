import sys

class FastScanner:
    def __init__(self):
        self.data = sys.stdin.read().splitlines()
        self.index = 0

    def next(self):
        while self.index >= len(self.data) or not self.data[self.index]:
            self.index += 1
        result = self.data[self.index]
        self.index += 1
        return result

    def next_line(self):
        return self.next()

    def next_byte(self):
        return ord(self.next())

    def next_short(self):
        return int(self.next())

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

def main():
    inp = FastScanner()
    sc = FastScanner()
    o = sys.stdout

    n = sc.next_int()
    s = sc.next_int()
    max_val = 0

    for _ in range(n):
        f = sc.next_int()
        t = sc.next_int()
        if max_val < f + t:
            max_val = f + t

    o.write(str(max(max_val, s)) + '\n')
    o.flush()

if __name__ == "__main__":
    main()

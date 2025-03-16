import sys

class FastReader:
    def __init__(self):
        self.stdin = sys.stdin
        self.tokens = None

    def next(self):
        while self.tokens is None or not self.tokens:
            self.tokens = self.stdin.readline().strip().split()
        token = self.tokens[0]
        self.tokens.pop(0)
        return token

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.stdin.readline().strip()

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
    sc = FastReader()
    n = sc.next_int()
    m = sc.next_int()
    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()

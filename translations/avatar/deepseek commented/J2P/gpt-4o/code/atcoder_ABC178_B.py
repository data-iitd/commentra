import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        value = self.data[self.index]
        self.index += 1
        return value

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return ' '.join(self.data[self.index:])

def mod_power(x, y, mod):
    res = 1
    x %= mod
    if x == 0:
        return 0
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % mod
        y >>= 1
        x = (x * x) % mod
    return res

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

def main():
    reader = FastReader()
    a = [reader.next_long() for _ in range(4)]
    result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2])))
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

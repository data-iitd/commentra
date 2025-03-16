import sys
import math

class FastReader:
    def __init__(self):
        self.readline = sys.stdin.readline

    def next(self):
        return self.readline().strip()

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return self.readline().strip()

def mod_power(x, y, mod):
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

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Main function
def main():
    inp = FastReader()
    a = [0] * 4
    for i in range(4):
        a[i] = inp.next_long()
    print(max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))))

if __name__ == "__main__":
    main()

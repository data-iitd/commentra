import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            token = self.data[self.index]
            self.index += 1
            return token
        return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())  # Python's int can handle long values

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return ' '.join(self.data[self.index:])

def reverse(n):
    if n < 10:
        return n * 10

    r = 0
    while n > 0:
        r = (r * 10) + (n % 10)
        n //= 10

    return r

def main():
    sc = FastReader()
    n = sc.next_int()
    m = sc.next_int()
    t = reverse(m)
    print(t + n)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

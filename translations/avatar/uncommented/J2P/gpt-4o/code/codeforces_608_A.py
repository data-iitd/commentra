import sys

class FastScanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            value = self.data[self.index]
            self.index += 1
            return value
        return None

    def next_int(self):
        return int(self.next())

def main():
    scanner = FastScanner()
    n = scanner.next_int()
    s = scanner.next_int()
    max_sum = 0

    for _ in range(n):
        f = scanner.next_int()
        t = scanner.next_int()
        if max_sum < f + t:
            max_sum = f + t

    print(max(max_sum, s))

if __name__ == "__main__":
    main()

# <END-OF-CODE>

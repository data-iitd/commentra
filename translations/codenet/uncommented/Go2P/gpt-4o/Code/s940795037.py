import sys

class Scanner:
    def __init__(self):
        self.buffer = []
        self.index = 0
        self.read_line()

    def read_line(self):
        self.buffer = sys.stdin.readline().strip().split()
        self.index = 0

    def next(self):
        if self.index >= len(self.buffer):
            self.read_line()
        result = self.buffer[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

def main():
    sc = Scanner()
    n = sc.next_int()
    ans = 0.0
    for _ in range(n):
        tmp = 1 / float(sc.next_int())
        ans += tmp
    print(1 / ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

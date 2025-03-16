import sys

def max(a, b):
    return b if a < b else a

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
    A = sc.next_int()
    B = sc.next_int()

    mx = max(A + B, A - B)
    mx = max(mx, A * B)
    print(mx)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

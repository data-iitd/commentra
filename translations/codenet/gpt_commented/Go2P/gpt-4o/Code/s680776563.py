import sys

class FastScanner:
    def __init__(self):
        self.buffer = []
        self.position = 0

    def next(self):
        self.pre()
        start = self.position
        while self.position < len(self.buffer):
            if self.buffer[self.position] == ' ':
                break
            self.position += 1
        result = ''.join(self.buffer[start:self.position])
        self.position += 1  # Move past the space
        return result

    def next_line(self):
        self.pre()
        start = self.position
        self.position = len(self.buffer)
        return ''.join(self.buffer[start:])

    def next_int(self):
        return int(self.next())

    def pre(self):
        if self.position >= len(self.buffer):
            self.read_line()
            self.position = 0

    def read_line(self):
        self.buffer = list(sys.stdin.readline().strip())

def main():
    fsc = FastScanner()
    A = fsc.next_int()
    B = fsc.next_int()
    C = fsc.next_int()
    
    if B - A == C - B:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

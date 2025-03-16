import sys
import math

# Custom input reader class
class BufReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.index = 0

    def read_line(self):
        if self.index < len(self.buffer):
            return
        self.buffer = self.stream.readline().strip().split()
        self.index = 0

    def next(self):
        self.read_line()
        if self.index < len(self.buffer):
            word = self.buffer[self.index]
            self.index += 1
            return word
        return None

    def next_int(self):
        return int(self.next())

# Initialize the buffered reader
reader = BufReader(sys.stdin)

# Output function
def out(*args):
    print(*args)

# Main function
def main():
    solve()

# Solve function
def solve():
    N = reader.next_int()
    T = []
    A = []
    
    for _ in range(N):
        T.append(reader.next_int())
        A.append(reader.next_int())
    
    t, a = T[0], A[0]
    
    for i in range(1, N):
        r = max(math.ceil(t / T[i]), math.ceil(a / A[i]))
        t, a = T[i] * r, A[i] * r
    
    out(t + a)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

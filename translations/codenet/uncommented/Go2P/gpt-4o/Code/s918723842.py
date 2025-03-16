import sys
import math

class Scanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next_int(self):
        value = int(self.buffer[self.index])
        self.index += 1
        return value

def main():
    sc = Scanner()
    H = sc.next_int()
    W = sc.next_int()
    N = sc.next_int()

    A = max(H, W)
    print((N + A - 1) // A)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

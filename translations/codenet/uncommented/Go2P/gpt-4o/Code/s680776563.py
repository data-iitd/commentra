import sys

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin.read().split()
        self.index = 0

    def next(self):
        if self.index < len(self.buffer):
            result = self.buffer[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

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

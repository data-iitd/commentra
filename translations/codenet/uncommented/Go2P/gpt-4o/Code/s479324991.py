import sys
import bisect

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
    
    n = sc.next_int()
    arr = [float(sc.next_int()) for _ in range(n)]
    arr.sort()
    
    prev = arr[0]
    for i in range(1, len(arr)):
        prev = (prev + arr[i]) / 2

    print(prev)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

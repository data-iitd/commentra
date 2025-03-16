import sys
import io
import os
import math

class FastScanner:
    def __init__(self):
        self.buffer = sys.stdin
    
    def readline(self):
        return self.buffer.readline().strip()
    
    def read(self):
        while True:
            c = self.readline()
            if not c:
                break
            yield c
    
    def read_int(self):
        return int(self.readline())
    
    def read_ints(self):
        return list(map(int, self.readline().split()))

# Main function
def main():
    sc = FastScanner()
    n = sc.read_int()
    s = sc.read_int()
    
    max_sum = 0
    
    for _ in range(n):
        f, t = sc.read_ints()
        max_sum = max(max_sum, f + t)
    
    print(max(max_sum, s))

if __name__ == "__main__":
    main()

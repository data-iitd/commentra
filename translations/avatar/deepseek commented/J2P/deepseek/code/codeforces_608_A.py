class FastScanner:
    import sys
    input = sys.stdin.readline
    
    def __init__(self):
        self.tokens = []
    
    def next(self):
        while not self.tokens:
            self.tokens = input().split()
        return self.tokens.pop(0)
    
    def nextLine(self):
        return input().strip()
    
    def nextByte(self):
        return int(self.next())
    
    def nextShort(self):
        return int(self.next())
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return int(self.next())
    
    def nextDouble(self):
        return float(self.next())

def main():
    sc = FastScanner()
    n = sc.nextInt()
    s = sc.nextInt()
    max_sum = 0

    for _ in range(n):
        f = sc.nextInt()
        t = sc.nextInt()
        max_sum = max(max_sum, f + t)

    print(max(max_sum, s))

if __name__ == "__main__":
    main()

import sys
from collections import defaultdict

class FastScanner:
    def __init__(self):
        self.input = sys.stdin.readline
    
    def next(self):
        while not hasattr(self, 'tokenizer'):
            self.tokenizer = map(str, self.input().split())
        try:
            return next(self.tokenizer)
        except StopIteration:
            return None
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return int(self.next())
    
    def nextDouble(self):
        return float(self.next())
    
    def nextLine(self):
        return self.input().strip()

def main():
    input = FastScanner()
    n = input.nextInt()
    map = defaultdict(int)
    for i in range(n):
        val = input.nextInt()
        map[val] += 1
    max_value = max(map.values())
    unique_values = len(map)
    print(f"{max_value} {unique_values}")

if __name__ == "__main__":
    main()

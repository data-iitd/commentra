import sys
from collections import defaultdict

class FastScanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            result = self.data[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

def main():
    input = FastScanner()
    n = input.next_int()
    count_map = defaultdict(int)

    for _ in range(n):
        val = input.next_int()
        count_map[val] += 1

    max_count = max(count_map.values())
    unique_count = len(count_map)

    print(f"{max_count}{unique_count}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys
from collections import defaultdict

class FastScanner:
    def __init__(self):
        self.stdin = sys.stdin

    def next(self):
        while not hasattr(self, 'tokenizer'):
            self.tokenizer = iter(self.stdin.readline().split())
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
        return self.stdin.readline()

def main():
    input_scanner = FastScanner()
    n = input_scanner.nextInt()
    frequency_map = defaultdict(int)

    for _ in range(n):
        val = input_scanner.nextInt()
        frequency_map[val] += 1

    max_frequency = max(frequency_map.values())
    unique_integers = len(frequency_map)

    print(f"{max_frequency}{unique_integers}")

if __name__ == "__main__":
    main()

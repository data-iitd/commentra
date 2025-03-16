
import sys
from collections import defaultdict

def main():
    n = int(input())
    d = defaultdict(int)
    for _ in range(n):
        num = int(input())
        if num - 1 not in d:
            d[num] += 1
        else:
            d[num - 1] -= 1
            if d[num - 1] == 0:
                del d[num - 1]
            d[num] += 1
    print(sum(d.values()))

if __name__ == "__main__":
    main()


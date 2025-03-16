

import sys

def main():
    n = int(input())

    max_sum = 0

    for _ in range(n):
        f, t = map(int, input().split())
        max_sum = max(max_sum, f + t)

    print(max(max_sum, s))

if __name__ == "__main__":
    main()


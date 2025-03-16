

import sys

def main():
    n = int(input())
    v = list(map(int, input().split()))
    c = list(map(int, input().split()))
    max = 0
    for i in range(n):
        profit = v[i] - c[i]
        if profit > 0:
            max += profit
    print(max)

if __name__ == "__main__":
    main()


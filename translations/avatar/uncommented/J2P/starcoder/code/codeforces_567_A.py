
# <START-OF-CODE>
import sys

def main():
    n = int(raw_input())
    ar = [int(x) for x in raw_input().split()]
    max = 0
    min = 0
    for i in range(n):
        max = max(ar[i] - ar[0], ar[n-1] - ar[i])
        if i == 0:
            min = ar[i+1] - ar[i]
        elif i == n-1:
            min = ar[i] - ar[i-1]
        else:
            min = min(ar[i] - ar[i-1], ar[i+1] - ar[i])
        print min, max

if __name__ == "__main__":
    main()
# 
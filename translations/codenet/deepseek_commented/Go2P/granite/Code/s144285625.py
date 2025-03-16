
import sys
from bisect import bisect_left, bisect_right

def main():
    n = int(input())
    ar = list(map(int, input().split()))
    ar.sort()
    print(sum(ar[bisect_right(ar, ar[i] + 1) - 1] for i in range(n)))

if __name__ == "__main__":
    main()

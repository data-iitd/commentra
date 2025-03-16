
import sys
from bisect import bisect_left

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for v in a:
        x = bisect_left(b, v)
        if x == len(b):
            b.append(v)
        else:
            b[x] = v
    print(len(b))

if __name__ == '__main__':
    main()

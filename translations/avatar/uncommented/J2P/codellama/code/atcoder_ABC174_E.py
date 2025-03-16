
import sys
import math

def solve(n, k, logsLength):
    min = 1
    max = 1000000000
    while min < max:
        mid = (min + max) // 2
        if nei(mid, logsLength, k):
            max = mid
        else:
            min = mid + 1
    return min

def nei(mid, logsLength, k):
    for log in logsLength:
        k -= (log + mid - 1) // mid - 1
    return k >= 0

def main():
    n, k = map(int, sys.stdin.readline().split())
    logsLength = list(map(int, sys.stdin.readline().split()))
    print(solve(n, k, logsLength))

if __name__ == "__main__":
    main()


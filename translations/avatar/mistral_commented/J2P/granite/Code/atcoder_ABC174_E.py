
import sys
import math

def main():
    n, k = map(int, input().split())
    logs = list(map(int, input().split()))
    logs.sort()
    left, right = 1, 10**9
    while left < right:
        mid = (left + right) // 2
        days = 0
        for log in logs:
            days += math.ceil(log / mid)
        if days <= k:
            right = mid
        else:
            left = mid + 1
    print(left)

if __name__ == "__main__":
    sys.exit(main())


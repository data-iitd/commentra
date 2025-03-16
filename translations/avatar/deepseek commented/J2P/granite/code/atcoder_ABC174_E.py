
import sys
import math

def main():
    n, k = map(int, input().split())
    logs = list(map(int, input().split()))
    min_cut = 1
    max_cut = max(logs)
    while min_cut < max_cut:
        mid = (min_cut + max_cut) // 2
        if nei(mid, logs, k):
            max_cut = mid
        else:
            min_cut = mid + 1
    print(min_cut)

def nei(mid, logs, k):
    for log in logs:
        k -= math.ceil(log / mid) - 1
        if k < 0:
            return False
    return True

if __name__ == "__main__":
    main()


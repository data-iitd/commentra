
import sys

def main():
    n, k = map(int, input().split())
    logsLength = list(map(int, input().split()))
    min = 1
    max = 100000000
    while min < max:
        mid = (min + max) // 2
        if nei(mid, logsLength, k):
            max = mid
        else:
            min = mid + 1
    print(min)

def nei(mid, logsLength, k):
    for log in logsLength:
        k -= (log + mid - 1) // mid - 1
    return k >= 0

if __name__ == "__main__":
    main()


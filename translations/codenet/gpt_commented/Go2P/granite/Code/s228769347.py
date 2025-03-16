
import sys
from bisect import bisect_left

def main():
    n = int(input())
    ll = list(map(int, input().split()))
    ll.sort()
    ans = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            l = j + 1
            r = n
            while l < r:
                m = (l + r) // 2
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                else:
                    r = m
            ans += l - (j + 1)
    print(ans)

if __name__ == "__main__":
    main()


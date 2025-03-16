

import sys
import math
import bisect

MOD = 1000000007

def main():
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))
    a.sort()

    l = -10**18
    r = 10**18

    while l + 1 < r:
        c = (l + r) // 2
        if check(c):
            l = c
        else:
            r = c

    print(l)

def check(x):
    tot = 0
    for i in range(n):
        now = a[i]
        l = 0
        r = n
        if now >= 0:
            while l < r:
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1
                else:
                    r = c
            tot += l
        else:
            while l < r:
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1
                else:
                    r = c
            tot += (n - l)
        if now * now < x:
            tot -= 1
        if tot // 2 < k:
            return True
    return False

if __name__ == "__main__":
    main()


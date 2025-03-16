
import sys
import math
import bisect

# Define a large prime number for modulo operations
mod = 100000007

# Direction vectors for potential grid movements (not used in this code)
DX = [-1, 0, 1, 0]
DY = [0, -1, 0, 1]

# Variables to store the number of elements, a threshold value, and the array of long integers
n = 0
k = 0
a = []

def read():
    global n, k, a
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))

def solve():
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
    global a, n
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
    return tot // 2 < k

def main():
    t = 1
    # t = int(input())
    for i in range(t):
        read()
        solve()

if __name__ == "__main__":
    main()


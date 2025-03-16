
# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

import sys

def main():
    w = int(input())
    a = list(map(int, input().split()))
    ans = 0
    f = 0
    for i in range(w):
        if a[i] == 0:
            f |= 1
        elif a[i] < 0:
            f |= 2
        else:
            ans += a[i]
    if not ans or not (f & 1):
        print(0)
        return 0
    if not (f & 2):
        print(ans)
        return 0
    b = [0] * w
    close = 0
    f = 0
    for i in range(w):
        if a[i] == 0:
            close = 100000000
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (i-f) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = 100000000
            else:
                k = close - (i-f)
                if k < 0:
                    k = 0
                b[i] = k
    close = 0
    f = w
    for i in range(w-1, -1, -1):
        if a[i] == 0:
            close = 100000000
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (f-i) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = 100000000
            else:
                k = close - (f-i)
                if k < 0:
                    k = 0
                if k > b[i]:
                    b[i] = k
    for i in range(w):
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]
    print(ans)

if __name__ == "__main__":
    main()

Translate the above Python code to Java and end with comment "
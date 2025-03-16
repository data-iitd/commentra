
import sys

def main():
    w = int(input())
    a = list(map(int, input().split()))
    b = [0] * (w + 1)
    f = 0
    close = 0
    ans = 0

    for i in range(1, w + 1):
        if a[i - 1] == 0:
            f = 1
            continue
        if a[i - 1] < 0:
            if f == 0 or close - (i - f) > -a[i - 1]:
                close = -a[i - 1]
                f = i
        ans += a[i - 1]

    if ans == 0 or f % 2 == 1:
        print(0)
        return 0

    if f == 0:
        print(ans)
        return 0

    for i in range(w, 0, -1):
        if a[i - 1] == 0:
            close = float('inf')
            f = -1
            continue
        if a[i - 1] < 0:
            if f == 0 or close - (f - i) > -a[i - 1]:
                close = -a[i - 1]
                f = i
        else:
            b[i] = float('inf')
            if f!= 0:
                k = close - (f - i)
                if k < 0:
                    k = 0
                b[i] = k

    for i in range(1, w + 1):
        if a[i - 1] > 0:
            if b[i] > a[i - 1]:
                ans += a[i - 1]
            else:
                ans += b[i]

    print(ans)

if __name__ == "__main__":
    main()


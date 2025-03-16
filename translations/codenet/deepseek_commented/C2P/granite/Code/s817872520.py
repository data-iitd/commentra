
import sys

def main():
    w = int(input())
    a = list(map(int, input().split()))
    b = [0] * (w + 1)
    f = 0
    ans = 0
    close = 0

    for i in range(1, w + 1):
        if a[i - 1] == 0:
            f = 1
            close = 1000000000
            b[i] = 1000000000
        elif a[i - 1] < 0:
            if f == 0 or close - (i - f) > -a[i - 1]:
                close = -a[i - 1]
                f = i
        else:
            if f == 0:
                b[i] = 1000000000
            else:
                k = close - (i - f)
                if k < 0:
                    k = 0
                b[i] = k
            ans += a[i - 1]

    for i in range(w, 0, -1):
        if a[i - 1] == 0:
            f = 1
            close = 1000000000
        elif a[i - 1] < 0:
            if f == 0 or close - (f - i) > -a[i - 1]:
                close = -a[i - 1]
                f = i
        else:
            if f == 0:
                b[i] = 1000000000
            else:
                k = close - (f - i)
                if k < 0:
                    k = 0
                if k > b[i]:
                    b[i] = k

    for i in range(1, w + 1):
        if a[i - 1] > 0:
            ans += min(b[i], a[i - 1])

    print(ans)

if __name__ == "__main__":
    main()


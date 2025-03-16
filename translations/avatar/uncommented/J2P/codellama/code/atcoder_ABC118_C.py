
import sys
import math

def func(a):
    min = 0
    for i in range(len(a)):
        if a[i] == 0:
            a.pop(i)
            i -= 1
        else:
            if min != 0:
                a[i] = a[i] % min
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                min = a[i]
    a.sort()
    return a

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    a = list(map(int, sys.stdin.readline().strip().split()))
    if n == 1:
        print(a[0])
        sys.exit(0)
    for i in range(len(a)):
        if a[i] == 0:
            a.pop(i)
            i -= 1
    if len(a) == 0:
        print(0)
        sys.exit(0)
    ans = 0
    while True:
        if len(a) == 1:
            ans = a[0]
            break
        a = func(a)
    print(ans)



import sys

def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while b[i + 1] < x:
            i += 1
        while x < b[j - 1]:
            j -= 1
        if i >= j:
            break
        t = a[i]
        a[i] = a[j]
        a[j] = t
        t = b[i]
        b[i] = b[j]
        b[j] = t
    t = a[i]
    a[i] = a[r]
    a[r] = t
    t = b[i]
    b[i] = b[r]
    b[r] = t
    return i

def quicksort(a, b, n):
    l = 0
    r = n - 1
    sp = 1
    low = [0] * 100000
    high = [0] * 100000
    low[0] = l
    high[0] = r
    while sp > 0:
        sp -= 1
        l = low[sp]
        r = high[sp]
        if l >= r:
            continue
        v = part(a, b, l, r)
        if v - l < r - v:
            low[sp] = v + 1
            high[sp] = r
            low[sp + 1] = l
            high[sp + 1] = v - 1
            sp += 1
        else:
            low[sp] = l
            high[sp] = v - 1
            low[sp + 1] = v + 1
            high[sp + 1] = r
            sp += 1

def main():
    n, m = map(int, sys.stdin.readline().split())
    a = [0] * 100000
    b = [0] * 100000
    for i in range(m):
        a[i], b[i] = map(int, sys.stdin.readline().split())
    quicksort(a, b, m)
    t = 0
    cnt = 0
    for i in range(m):
        if t <= a[i]:
            t = b[i]
            cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()


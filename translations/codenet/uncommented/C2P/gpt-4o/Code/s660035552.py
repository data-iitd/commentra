def part(a, b, l, r):
    i = l - 1
    j = r
    x = b[r]

    while True:
        while i + 1 < len(b) and b[i + 1] < x:
            i += 1
        while j > l and x < b[j - 1]:
            j -= 1

        if i >= j:
            break

        a[i], a[j - 1] = a[j - 1], a[i]
        b[i], b[j - 1] = b[j - 1], b[i]

    a[i], a[r] = a[r], a[i]
    b[i], b[r] = b[r], b[i]
    return i

def quicksort(a, b, n):
    low = [0] * 200000
    high = [0] * 200000
    sp = 1
    low[0] = 0
    high[0] = n - 1

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
            sp += 2
        else:
            low[sp] = l
            high[sp] = v - 1
            low[sp + 1] = v + 1
            high[sp + 1] = r
            sp += 2

def main():
    n, m = map(int, input().split())
    a = [0] * m
    b = [0] * m

    for i in range(m):
        a[i], b[i] = map(int, input().split())

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

# <END-OF-CODE>
